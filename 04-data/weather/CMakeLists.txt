add_executable(weather)
target_sources(weather PRIVATE weather_data.cpp main.cpp)
target_link_libraries(weather PRIVATE df uiutils)
target_compile_options(weather PRIVATE -Wall -Wextra -Wpedantic)
