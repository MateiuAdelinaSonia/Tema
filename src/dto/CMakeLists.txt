add_library(
    dto
    src/vehicle.cpp
    src/car.cpp
    src/driver.cpp
)

target_include_directories(dto PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")