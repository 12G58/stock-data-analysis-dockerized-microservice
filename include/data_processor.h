#ifndef DATA_PROCESSOR_H
#define DATA_PROCESSOR_H

#include <vector>

class DataProcessor {
public:
    static double calculateMovingAverage(const std::vector<double>& prices, size_t period);
    static std::vector<double> detectOutliers(const std::vector<double>& prices, double threshold = 1.5);
};

#endif // DATA_PROCESSOR_H
