#ifndef DATA_PROCESSOR_H
#define DATA_PROCESSOR_H

#include <vector>
#include <utility> // For std::pair

class DataProcessor {
public:
    // Static methods
    static double calculateMovingAverage(const std::vector<double>& prices, size_t period);
    static std::vector<double> detectOutliers(const std::vector<double>& prices, double threshold);
    static std::vector<std::pair<double, double>> calculateBollingerBands(const std::vector<double>& prices, size_t period, double multiplier);
};

#endif // DATA_PROCESSOR_H
