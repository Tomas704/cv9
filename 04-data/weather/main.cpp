#include "weather_data.hpp"
#include <iostream>
#include <libdf/csv_config.hpp>

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  SetConsoleOutputCP(CP_UTF8);
  weather::WeatherLoader weatherL(df::CSVConfig::createDefault());
  df::DataFrame<weather::WeatherRecord> result =
      weatherL.load("../data/shmu-data-utf-8.csv");
  result.print(std::cout);
  return 0;
}
