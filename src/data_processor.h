#ifndef DATA_PROCESSOR_H
#define DATA_PROCESSOR_H

#include <vector>
#include <utility> // For std::pair>
#include <stdexcept> // For exception handling

class DataProcessor {
public:
    // Calculate moving average over a specified period
    static double calculateMovingAverage(const std::vector<double>& prices, size_t period);

    // Detect outliers in the price data using a threshold multiplier
    static std::vector<double> detectOutliers(const std::vector<double>& prices, double threshold);

    // Compute Bollinger Bands for price data
    static std::vector<std::pair<double, double>> calculateBollingerBands(const std::vector<double>& prices, size_t period, double multiplier);

    // Additional processing methods can be added here for future use
};

#endif // DATA_PROCESSOR_H
