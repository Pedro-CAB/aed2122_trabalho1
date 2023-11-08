# Console App for Airway Company Information Management

This project consisted on the development of a simple app for consulting and managing information about an air company. It allows a user to list flights from an origin or to a destination, see available seats, buy a ticket, set their luggage up and manage occuring flights and maintenance/cleaning services in vehicles. It was developed for the course of Algorithms and Data Structures in the 2nd year of the Informatics Engineering and Computation at FEUP.

**Project Grade:** 14.88/20

## Project Developed By
- Inês Gaspar
- Manuel Tadeu
- Pedro Gomes

## Classes
### [Flight](Flight.cpp)
- Flight Number
- Departure Date
- Duration
- Origin
- Destination
- Designated Plane
### [Passenger](Passenger.cpp)
- Associated Ticket
### [Plane](Plane.cpp)
- License Plate: Xnnn Format (X -> letter and n -> 0-9)
- Capacity
- Flight Plan: List of flights the plane does
- Services to do (Cronologically Sorted Queue)
- Services Done (Cronologically Sorted Queue)
- Passenger List
- Number of Carriages in Luggage Car
- Number of Piles per Carriage of the Luggage Car
### [Service](Service.cpp)
- Type (maintenance or cleaning)
- Date
- Designated Worker
### [Ticket](Ticket.cpp)
- Associated Flight
- Automatic Luggage? (True or False)
