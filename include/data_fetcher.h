#ifndef DATA_FETCHER_H
#define DATA_FETCHER_H

#include <string>
#include <json/json.h>
#include <vector>

class DataFetcher {
public:
    static Json::Value fetchRealTimeData(const std::string& apiUrl);
    static Json::Value fetchHistoricalData(const std::string& symbol, const std::string& apiKey, long fromTimestamp, long toTimestamp);
};

#endif
