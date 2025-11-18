#include "weather_data.hpp"
#include <external/uiutils/ui_utils.hpp>

namespace weather {

WeatherLoader::WeatherLoader(df::CSVConfig config)
    : df::CSVLoader<WeatherRecord>(std::move(config)) {}

WeatherRecord WeatherLoader::create(const csv::CSVRow &row) {
  WeatherRecord record;
  record.city = row[0].get<std::string>();
  std::string dateStr = row[1].get<std::string>();
  auto dateOpt = uiutils::parseDate(dateStr);
  if (dateOpt.has_value()) {
    record.date = *dateOpt;
  } else {
    record.date = std::chrono::year{1970} / 1 / 1;
  }
  record.tempMin = row[2].get<float>();
  record.tempMax = row[3].get<float>();
  record.temp0700 = row[4].get<float>();
  record.temp1400 = row[5].get<float>();
  record.temp2100 = row[6].get<float>();
  record.elevation = row[7].get<int>();
  return record;
}

std::ostream &operator<<(std::ostream &ost, const WeatherRecord &record) {
  ost << "mesto: " << record.city << ",\tdatum: " << record.date
      << ",\tt_max: " << record.tempMax << ",\tt_min: " << record.tempMin
      << ",\tt_0700: " << record.temp0700 << ",\tt_1400: " << record.temp1400
      << ",\tt_2100: " << record.temp2100
      << ",\tnadmorska_vyska: " << record.elevation;
  return ost;
}

} // namespace weather
