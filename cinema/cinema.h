#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class maintenance {

private:


    string name[10];
    int year[10];
    int time[10];
    string country[10];
    float reviews[10];

    

public:

    void entermovie();
    void ShowInformation();

};

class booking {

private:

    int roomnumber[10];
    int seats[10][10];
    double price[10];
 

public:

    void enterRooms();
    void showRooms();
    void initializeSeats();

};

class Schedule {
private:
    int date[10];
    int startTime[10];
    int finalTime[10];

public:
    void enterSchedule();
    void showSchedule();
};


class sale {
private:
    struct Reservationinformation {
        int movieIndex;
        int roomIndex;
        int scheduleIndex;
        int ticketID;
    };

    vector<Reservationinformation> reservations;
    int nextTicketID = 1;

public:
    void makeReservation(maintenance& cinema, booking& room, Schedule& schedule);
    void processSale(int ticketID);
    void showReservations();
};


 void maintenance::entermovie() {
     
     int movies;
    
         cout << "ingrese la cantidad de peliculas que desea ingresar";
         cin >> movies;

         for (int i = 0; i < movies; i++)
         {
             cout << "ingrese la pelicula que desea proyectar:  ";

             cin >> name[i];

             cout << "ingrese la fecha de estreno de la pelicula:  ";

             cin >> year[i];

             cout << "ingrese el tiempo de duracion en minutos: ";

             cin >> time[i];

             cout << "ingrese el pais de la pelicula ";

             cin >> country[i];

             cout << "ingrese la puntuacion de la pelicula ";

             cin >> reviews[i];
         }
 };

void maintenance::ShowInformation() {


    cout << " las peliculas disponibles son: ";

    for (int i = 0; i <10 ; i++) {
        if (!(name[i] == "")) {
        cout<< name[i];

        cout << "la fecha de estreno de la pelicula es: ";

        cout << year[i];

        cout << "el tiempo de duracion es: ";

        cout << time[i];

        cout << " el pais de la pelicula es: ";

        cout << country[i];

        cout << "la puntuacion de la pelicula es: ";

        cout << reviews[i];
        }
    }

};
void booking::enterRooms(){

    int Room;

    cout << "ingrese la cantidad de salas que desea ingresar";
    cin >> Room;

    for (int i = 0; i < Room; i++)
    {
        cout << "ingrese el numero de sala ";

        cin >> roomnumber[i];

        cout << "ingrese el precio de venta de los tiketes ";

        cin >> price[i];

        cout << "Ingrese la cantidad de butacas en la sala: ";

        initializeSeats();
    }
};

void booking::showRooms() {

    for (int i = 0; i < 10; ++i) {
        if (roomnumber[i] != 0) {
            cout << "la sala es: " << roomnumber[i] << ", el precio es: " << price[i] << endl;
        }
    }
}

void booking ::initializeSeats() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            seats[i][j] = 0; 
        }
    }
}

void Schedule::enterSchedule() {

    int numSchedules;

    cout << "Ingrese la cantidad de horarios que desea ingresar: ";

    cin >> numSchedules;
     
    for (int i = 0; i < numSchedules; ++i) {

        cout << "Ingrese la fecha ( de la manera YYYYMMDD): ";

        cin >> date[i];

        cout << "Ingrese la hora de inicio (de la manera HHMM): ";

        cin >> startTime[i];

        cout << "Ingrese la hora final ( de la manera HHMM): ";

        cin >> finalTime[i];
    }
}

void Schedule::showSchedule() {

    for (int i = 0; i < 10; ++i) {

        if (date[i] != 0) {

            cout << "la fecha es: " << date[i] << ",la hora de inicio es: " << startTime[i] << ", la hora de finalizacion es: " << finalTime[i] << endl;
        }
    }
}

void sale::makeReservation(maintenance& cinema, booking& room, Schedule& schedule) {

    int movieIndex, roomIndex, scheduleIndex;

    cout << "Seleccione una pelicula ( del 0 al 9): ";

    cin >> movieIndex;

    cout << "Seleccione la sala ( del 0 al 9): ";

    cin >> roomIndex;

    cout << "Seleccione el horario (del 0 al 9): ";

    cin >> scheduleIndex;

    if (movieIndex < 0 || movieIndex >= 10 || roomIndex < 0 || roomIndex >= 10 || scheduleIndex < 0 || scheduleIndex >= 10) {

        cout << "la opcion no es valida por favor intente otra." << endl;

        return;
    }

    int ticketID = nextTicketID++;

    reservations.push_back({ movieIndex, roomIndex, scheduleIndex, ticketID });

    cout << "su reservacion fue realizada con exito el ID del ticket: " << ticketID << endl;
}


void sale::processSale(int ticketID) {

    auto reservation = find_if(reservations.begin(), reservations.end(), [ticketID](const Reservationinformation & res) {
        return res.ticketID == ticketID;
        });

    if (reservation != reservations.end()) {
        cout << "la venta fue  realizada el ticket ID: " << ticketID << endl;
        reservations.erase(reservation);
    }
    else {
        cout << "el ticket ID no fue encontrado." << endl;
    }
}

void sale::showReservations() {

    for (const auto& res : reservations) {

        cout << "la pelicula: " << res.movieIndex << ", la sala: " << res.roomIndex << ", el horario: " << res.scheduleIndex << ", el ticket ID: " << res.ticketID << endl;
    }
}
