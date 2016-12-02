#ifndef CORE
#define CORE

#include <vector>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>

void calculate_intersections(const std::vector<cv::Vec4i> &lines, std::vector<cv::Vec2f> &intersections) {
    const size_t N = lines.size();

    intersections.clear();
    intersections.reserve((N * N) / 2);

    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            const cv::Vec4i &li = lines[i];
            const cv::Vec4i &lj = lines[j];

            const float mi = static_cast<float>(li[3] - li[1]) / static_cast<float>(li[2] - li[0]);
            const float bi = -mi * li[0] + li[1];

            const float mj = static_cast<float>(lj[3] - lj[1]) / static_cast<float>(lj[2] - lj[0]);
            const float bj = -mj * lj[0] + lj[1];

            const float x = (bi - bj) / (mj - mi);
            const float y = mi * x + bi;

            const cv::Vec2f point(x, y);

            intersections.push_back(point);
        }
    }
}

template <class PixelT>
void visualize_intersections(const std::vector<cv::Vec2f> &intersections, cv::Mat &image) {
    image = 0;

    for (auto intersection : intersections) {
        const int x = static_cast<int>(intersection[0]);
        const int y = static_cast<int>(intersection[1]);
        if (x > 0 && x < image.cols && y > 0 && y < image.rows) {
            image.at<PixelT>(y, x) += 1;
        }
    }

    cv::dilate(image, image, cv::getStructuringElement(cv::MORPH_ELLIPSE,cv::Size( 15, 15 ), cv::Point(7, 7)));
}

void calculate_vanishing_point(const std::vector<cv::Vec2f> &intersections, cv::Vec2f vanishing_point, size_t iters) {

    const size_t N = intersections.size();

    std::vector<cv::Vec2f> regressed_intersections;
    regressed_intersections.resize(N);
    std::copy(intersections.begin(), intersections.end(), regressed_intersections.begin());

    cv::Vec2f mean;
    cv::Vec2f stdev;

    for (size_t t = 0; t < iters; ++t) {
        const size_t Nr = regressed_intersections.size();

        mean = cv::Vec2f(0,0);
        stdev = cv::Vec2f(0,0);

        for (auto intersection : regressed_intersections) {
            mean += intersection;
        }
        mean = mean / static_cast<float>(Nr);

        for (auto intersection : regressed_intersections) {
            const cv::Vec2f u = mean - intersection;
            stdev[0] += u[0] * u[0];
            stdev[1] += u[1] * u[1];
        }
        stdev[0] = sqrtf(stdev[0] / N);
        stdev[1] = sqrtf(stdev[1] / N);

        std::vector<cv::Vec2f> temp_regressed_intersections;
        temp_regressed_intersections.reserve(9 * Nr / 10);

        for (auto intersection : regressed_intersections) {
            cv::Vec2f z = intersection - mean;
            z[0] = abs(z[0] / stdev[0]);
            z[1] = abs(z[1] / stdev[1]);

            const float u = 0.5f * erf(z[0]);
            const float v = 0.5f * erf(z[1]);

            if (u < 0.9f && v < 0.9f) {
                temp_regressed_intersections.push_back(intersection);
            }
        }

        regressed_intersections = temp_regressed_intersections;
    }

    vanishing_point = mean;
}

#endif // CORE

