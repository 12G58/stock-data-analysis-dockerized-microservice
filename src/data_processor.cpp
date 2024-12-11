#include "data_processor.h"
#include <numeric>
#include <cmath>
#include <vector>

double DataProcessor::calculateMovingAverage(const std::vector<double>& prices, size_t period) {
    if (prices.size() < period) return 0.0;
    double sum = std::accumulate(prices.end() - period, prices.end(), 0.0);
    return sum / period;
}

std::vector<double> DataProcessor::detectOutliers(const std::vector<double>& prices, double threshold) {
    std::vector<double> outliers;
    if (prices.empty()) return outliers;

    double mean = std::accumulate(prices.begin(), prices.end(), 0.0) / prices.size();
    double sumOfSquares = 0;

    for (double price : prices) {
        sumOfSquares += (price - mean) * (price - mean);
    }

    double standardDeviation = std::sqrt(sumOfSquares / prices.size());

    for (double price : prices) {
        if (std::abs(price - mean) > threshold * standardDeviation) {
            outliers.push_back(price);
        }
    }

    return outliers;
}

std::vector<std::pair<double, double>> DataProcessor::calculateBollingerBands(const std::vector<double>& prices, size_t period, double multiplier) {
    std::vector<std::pair<double, double>> bands;
    if (prices.size() < period) return bands;

    for (size_t i = period; i <= prices.size(); ++i) {
        double mean = std::accumulate(prices.begin() + i - period, prices.begin() + i, 0.0) / period;
        double sumOfSquares = 0;

        for (size_t j = i - period; j < i; ++j) {
            sumOfSquares += (prices[j] - mean) * (prices[j] - mean);
        }

        double stdDev = std::sqrt(sumOfSquares / period);
        bands.emplace_back(mean + multiplier * stdDev, mean - multiplier * stdDev);
    }

    return bands;
}
