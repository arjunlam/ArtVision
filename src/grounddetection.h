#ifndef GROUNDDETECTION_H
#define GROUNDDETECTION_H



#include <vector>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>


void ground_detection1(cv::Vec2f &vanishing_point,const std::vector<cv::Vec4i> &lines, std::vector<cv::Vec2i> key_points ){
    int N = lines.size();

    key_points.clear;

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
            detection_lines.push(line);
        }



    }


}

#endif // GROUNDDETECTION_H
