#include "data_processor.h"
#include <numeric>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdexcept>

// Calculate the moving average over a given period
double DataProcessor::calculateMovingAverage(const std::vector<double>& prices, size_t period) {
    if (prices.size() < period || period == 0) {
        throw std::invalid_argument("Insufficient data or invalid period for moving average calculation.");
    }
    return std::accumulate(prices.end() - period, prices.end(), 0.0) / period;
}

// Detect outliers based on a threshold of standard deviations from the mean
std::vector<double> DataProcessor::detectOutliers(const std::vector<double>& prices, double threshold) {
    if (prices.empty() || threshold <= 0) {
        throw std::invalid_argument("Invalid data or threshold for outlier detection.");
    }

    double mean = std::accumulate(prices.begin(), prices.end(), 0.0) / prices.size();
    double sumOfSquares = 0.0;
    for (double price : prices) {
        sumOfSquares += (price - mean) * (price - mean);
    }
    double stdDev = std::sqrt(sumOfSquares / prices.size());

    std::vector<double> outliers;
    for (double price : prices) {
        if (std::abs(price - mean) > threshold * stdDev) {
            outliers.push_back(price);
        }
    }
    return outliers;
}

// Calculate Bollinger Bands
std::vector<std::pair<double, double>> DataProcessor::calculateBollingerBands(const std::vector<double>& prices, size_t period, double multiplier) {
    if (prices.size() < period || period == 0 || multiplier <= 0) {
        throw std::invalid_argument("Invalid data, period, or multiplier for Bollinger Bands calculation.");
    }

    std::vector<std::pair<double, double>> bands;

    for (size_t i = period; i <= prices.size(); ++i) {
        double mean = std::accumulate(prices.begin() + i - period, prices.begin() + i, 0.0) / period;
        double sumOfSquares = 0.0;
        for (size_t j = i - period; j < i; ++j) {
            sumOfSquares += (prices[j] - mean) * (prices[j] - mean);
        }
        double stdDev = std::sqrt(sumOfSquares / period);

        bands.emplace_back(mean + multiplier * stdDev, mean - multiplier * stdDev);
    }

    return bands;
}
