cmake_minimum_required(VERSION 3.20)
project(projectaed)

set(CMAKE_CXX_STANDARD 14)

add_executable(projectaed main.cpp Passenger.cpp Flight.cpp Ticket.cpp Service.cpp Plane.cpp Airport.cpp TTransportL.cpp)
