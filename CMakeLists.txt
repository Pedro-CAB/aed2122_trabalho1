cmake_minimum_required(VERSION 3.20)
project(projectAED)

set(CMAKE_CXX_STANDARD 14)

add_executable(projectAED main.cpp Plane.cpp Plane.h Service.cpp Service.h Passenger.cpp Passenger.h Airport.cpp Airport.h Ticket.cpp Ticket.h Flight.cpp Flight.h BST.h TTransportL.h TTransportL.cpp)
