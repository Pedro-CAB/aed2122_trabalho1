cmake_minimum_required(VERSION 3.20)
project(projectaed)

set(CMAKE_CXX_STANDARD 14)

add_executable(projectaed main.cpp Passenger.cpp Flight.cpp Service.cpp Plane.cpp Airport.cpp TTransportL.cpp LuggageCar.cpp LuggageCar.h)
