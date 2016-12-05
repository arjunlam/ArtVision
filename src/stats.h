#ifndef STATS
#define STATS

#include <vector>
#include <QDebug>

void normal_distribution(const std::vector<float> &data, float &mean, float &stdev) {
    const float N = static_cast<float>(data.size());

    mean = stdev = 0;

    for (auto value : data) {
        mean += value;
    }

    mean = mean / N;

    for (auto value : data) {
        const float u = value - mean;
        stdev += u*u;
    }

    stdev = sqrtf(stdev / N);
}

void zfilter(const std::vector<float> &data, float mean, float stdev, float alpha, std::vector<int> &keep) {
    const size_t N = data.size();

    keep.reserve(static_cast<size_t>(alpha * N));

    for (int i = 0; i < N; ++i) {
        const float zscore = abs((data[i] - mean) / stdev);
        if (zscore < alpha) {
            keep.push_back(i);
        }
    }
}

#endif // STATS

