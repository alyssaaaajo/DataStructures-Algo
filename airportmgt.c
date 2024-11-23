#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FLIGHTS 30

typedef char AirportName[40];

typedef struct {
    int hour;
    int minute;
} FlightTime;

typedef struct {
    int priority;
    AirportName name;
} Location;

typedef struct {
    int flightNumber;
    AirportName planeType;
    FlightTime departureTime;
    Location destination;
} AirTravel;

typedef struct {
    AirTravel flights[MAX_FLIGHTS];
    int totalFlights;
} FlightQueue, FlightList;

FlightTime createTime(int hour, int minute);
Location createLocation(int priority, AirportName locationName);
AirTravel createAirTravel(int flightNumber, AirportName planeType, FlightTime departureTime, Location destination);
void addFlightToQueue(FlightQueue *queue, AirTravel flight);
void removeFlightFromQueue(FlightQueue *queue);
void showFlightDetails(AirTravel flight);
void displayAllFlights(FlightQueue queue);

int main() {
    Location manila = createLocation(1, "Ninoy Aquino International Airport");
    Location clark = createLocation(2, "Clark International Airport");
    Location davao = createLocation(2, "Francisco Bangoy International Airport");
    Location iloilo = createLocation(2, "Iloilo International Airport");
    Location panglao = createLocation(3, "Panglao International Airport");
    Location sibulan = createLocation(3, "Sibulan Airport");
    Location siquijor = createLocation(3, "Siquijor Airport");
    Location bicol = createLocation(4, "Bicol International Airport");
    Location tacloban = createLocation(4, "Daniel Z. Romualdez Airport");
    Location gen_santos = createLocation(4, "General Santos International Airport");
    Location zamboanga = createLocation(4, "Zamboanga International Airport");
    Location bantayan = createLocation(5, "Bantayan Airport");
    Location bulan = createLocation(5, "Bulan Airport");
    Location iba = createLocation(5, "Iba Airport");
    Location hilongos = createLocation(5, "Hilongos Airport");
    Location alto_field = createLocation(6, "Alto Airfield");
    Location amoroy = createLocation(6, "Amoroy Airstrip");

    AirTravel flight1 = createAirTravel(100, "Airbus", createTime(4, 30), manila);
    AirTravel flight2 = createAirTravel(101, "Boieng", createTime(7, 00), davao);
    AirTravel flight3 = createAirTravel(102, "Convair", createTime(12, 15), bicol);
    AirTravel flight4 = createAirTravel(103, "Douglas", createTime(2, 45), zamboanga);
    AirTravel flight5 = createAirTravel(104, "Airbus", createTime(6, 20), alto_field);
    AirTravel flight6 = createAirTravel(105, "Convair", createTime(1, 40), bantayan);
    AirTravel flight7 = createAirTravel(106, "Airbus", createTime(4, 15), gen_santos);
    AirTravel flight8 = createAirTravel(107, "Douglas", createTime(3, 35), iba);
    AirTravel flight9 = createAirTravel(108, "Boieng", createTime(10, 30), panglao);
    AirTravel flight10 = createAirTravel(109, "Airbus", createTime(9, 00), sibulan);
    AirTravel flight11 = createAirTravel(110, "Boieng", createTime(7, 30), hilongos);

    FlightQueue flightQueue;
    flightQueue.totalFlights = 0;

    addFlightToQueue(&flightQueue, flight1);
    addFlightToQueue(&flightQueue, flight2);
    addFlightToQueue(&flightQueue, flight3);
    addFlightToQueue(&flightQueue, flight4);
    addFlightToQueue(&flightQueue, flight5);
    addFlightToQueue(&flightQueue, flight6);
    addFlightToQueue(&flightQueue, flight7);
    addFlightToQueue(&flightQueue, flight8);
    addFlightToQueue(&flightQueue, flight9);
    addFlightToQueue(&flightQueue, flight10);
    addFlightToQueue(&flightQueue, flight11);

    displayAllFlights(flightQueue);

    return 0;
}

FlightTime createTime(int hour, int minute) {
    FlightTime time;
    time.hour = hour;
    time.minute = minute;
    return time;
}

Location createLocation(int priority, AirportName locationName) {
    Location loc;
    loc.priority = priority;
    strcpy(loc.name, locationName);
    return loc;
}

AirTravel createAirTravel(int flightNumber, AirportName planeType, FlightTime departureTime, Location destination) {
    AirTravel travel;
    travel.flightNumber = flightNumber;
    strcpy(travel.planeType, planeType);
    travel.departureTime = departureTime;
    travel.destination = destination;
    return travel;
}

void displayAllFlights(FlightQueue queue) {
    if (queue.totalFlights == 0) {
        printf("No flights available.\n");
        return;
    }

    printf("Flight Number\t|\tPlane Type\t|\tDeparture Time\t|\tDestination\t\t\t|\tPriority\n");
    printf("-----------------------------------------------------------------------------------------\n");

    for (int i = 0; i < queue.totalFlights; i++) {
        showFlightDetails(queue.flights[i]);
    }
}

void showFlightDetails(AirTravel flight) {
    printf("%-15d\t|\t%-12s|\t%02d:%02d\t\t|\t%-32s\t|\t%d\n",
           flight.flightNumber, flight.planeType, flight.departureTime.hour, flight.departureTime.minute,
           flight.destination.name, flight.destination.priority);
}

void addFlightToQueue(FlightQueue *queue, AirTravel flight) {
    if (queue->totalFlights >= MAX_FLIGHTS) {
        printf("Queue is full. Cannot add more flights.\n");
        return;
    }

    int i = queue->totalFlights - 1;
    while (i >= 0 && queue->flights[i].destination.priority > flight.destination.priority) {
        queue->flights[i + 1] = queue->flights[i];
        i--;
    }
    queue->flights[i + 1] = flight;
    queue->totalFlights++;
}

void removeFlightFromQueue(FlightQueue *queue) {
    if (queue->totalFlights == 0) {
        printf("Queue is empty. No flights to remove.\n");
        return;
    }

    printf("Removed Flight:\n");
    showFlightDetails(queue->flights[0]);

    for (int i = 1; i < queue->totalFlights; i++) {
        queue->flights[i - 1] = queue->flights[i];
    }
    queue->totalFlights--;
}
