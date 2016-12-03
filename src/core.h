#ifndef CORE
#define CORE

#include <vector>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>

#include "stats.h"

#include <QDebug>

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

            if (std::abs(mi) < 5 && std::abs(mi) > 0.2 && std::abs(mj) < 5 && std::abs(mj) > 0.2){
                const float x = (bi - bj) / (mj - mi);
                const float y = mi * x + bi;

                if (!isnan(x) && isfinite(x) && !isnan(y) && isfinite(y)) {
                    const cv::Vec2f point(x, y);
                    intersections.push_back(point);
                }
            }
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
            image.at<PixelT>(y, x) += 10;
        }
    }

    // KEEP LARGE
    cv::dilate(image, image, cv::getStructuringElement(cv::MORPH_ELLIPSE,cv::Size(15, 15), cv::Point(7, 7)));
}

void calculate_vanishing_point(const std::vector<cv::Vec2f> &intersections, cv::Vec2f &vanishing_point, size_t iters, float alpha) {

    const size_t N = intersections.size();

    std::vector<cv::Vec2f> regressed_intersections;
    regressed_intersections.resize(N);
    std::copy(intersections.begin(), intersections.end(), regressed_intersections.begin());

    cv::Vec2f representative;

    for (size_t t = 0; t < iters; ++t) {
        const size_t Nr = regressed_intersections.size();

        representative = cv::Vec2f(0,0);
        for (auto intersection : regressed_intersections) {
            representative += intersection;
        }

        representative /= static_cast<float>(Nr);

        std::vector<float> sqr_distances;
        sqr_distances.reserve(Nr);

        for (auto intersection : regressed_intersections) {
            const cv::Vec2f displacement = intersection - representative;
            sqr_distances.push_back(sqrt(displacement[0]*displacement[0] + displacement[1]*displacement[1]));
        }

        float mean, stdev;
        normal_distribution(sqr_distances, mean, stdev);

        std::vector<int> keep;
        zfilter(sqr_distances, mean, stdev, alpha, keep);

        const size_t Nt = keep.size();

        std::vector<cv::Vec2f> temp_regressed_intersections;
        temp_regressed_intersections.reserve(Nt);

        for (int i = 0; i < Nt; ++i) {
            temp_regressed_intersections.push_back(regressed_intersections[keep[i]]);
        }

        regressed_intersections.resize(Nt);
        std::copy(temp_regressed_intersections.begin(), temp_regressed_intersections.end(), regressed_intersections.begin());
    }

    vanishing_point = representative;
}

void calculate_parallel_lines(cv::Vec2f &vanishing_point,const std::vector<cv::Vec4i> &lines, std::vector<cv::Vec4i> &parallel_lines, float min_sim) {
    const size_t N = lines.size();
    parallel_lines.clear();
    parallel_lines.reserve(N);

    for (auto line : lines) {
        const cv::Vec2f vdis = vanishing_point - cv::Vec2f(line[0], line[1]);
        const cv::Vec2f vdir = vdis / sqrtf(vdis[0] * vdis[0] + vdis[1] * vdis[1]);
        const cv::Vec2f ldis = cv::Vec2f(line[2], line[3]) - cv::Vec2f(line[0], line[1]);
        const cv::Vec2f ldir = ldis / sqrtf(ldis[0] * ldis[0] + ldis[1] * ldis[1]);

        const float u = abs(vdir[0] * ldir[0] + vdir[1] * ldir[1]);
        if (u > min_sim) {
            parallel_lines.push_back(line);
        }
    }
}

void ground_detection(cv::Vec2f &vanishing_point,const std::vector<cv::Vec4i> &lines, std::vector<cv::Vec2i> key_points ){
    int N = lines.size();

    key_points.clear();

    std::vector<cv::Vec2f> intersections;
    intersections.reserve((N * N) / 2);

    std::vector<cv::Vec4i> detection_lines;
    detection_lines.reserve(N);

    for(int i = 0; i < N; ++i){
        const cv::Vec4i &line = lines[i];
        const float x0 = vanishing_point[0];
        const float y0 = vanishing_point[1];
        const float x1 = line{0};
        const float y1 = line[1];
        const float x2 = line[2];
        const float y2 = line[3];

        float distance = std::abs(((y2-y1)*x0 - (x2-x1)*y0 + x2*y1 - y2*x1) / std::sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1)));
        if(distance > 20){
            detection_lines.push_back(line);
        }
    }
}

#endif // CORE

