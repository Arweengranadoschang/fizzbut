#include "cinema.h"
#include <iostream>
using namespace std;


int main() {
    maintenance cinema;
    booking room;
    Schedule schedule;
    sale reservation;

    int choice;
    do {
        cout << "Bienvenidos a CINEMA SA. Que desea realizar?" << endl;

        cout << "0) Salir" << endl;

        cout << "1) Archivo" << endl;

        cout << "2) Mantenimiento" << endl;

        cout << "3) Reserva" << endl;

        cout << "4) Venta" << endl;

        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Saliendo del sistema..." << endl;
            break;

        case 1:
            int option;

            cout << "1) Acerca de" << endl;

            cout << "2) Salir" << endl;

            cin >> option;

            if (option == 1) {

                cout << "este sistema fue desarrollado por Arween Granados Chang." << endl;
            }
            else if (option == 2) {
                cout << "Saliendo del sistema..." << endl;
            }
            break;
        case 2:

            cout << "1) Peliculas" << endl;

            cout << "2) Salas" << endl;

            cout << "3) Horarios" << endl;

            int secondoption;

            cin >> secondoption;

            if (secondoption == 1) {
                cinema.entermovie();
            }
            else if (secondoption == 2) {
                room.enterRooms();
            }
            else if (secondoption == 3) {
                schedule.enterSchedule();
            }
            break;
        case 3:

            cinema.ShowInformation();

            room.showRooms();

            room.initializeSeats();

            schedule.showSchedule();

            reservation.makeReservation(cinema, room, schedule);

            break;
        case 4:

            int ticketID;

            cout << "Ingrese el ID del ticket: ";

            cin >> ticketID;

            reservation.processSale(ticketID);

            break;
        default:
            cout << "Opcion no valida por favor intente de nuevo." << endl;
        }
    } while (choice != 0);

    return 0;
}


