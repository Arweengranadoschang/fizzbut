#pragma once
#include <iostream>
using namespace std;

class maintenance {

private:

    //movie information
    string name;
    int year;
    int time;
    string country;
    float reviews;

    // rooms
    int roomnumber; 
    int seats[10][10];
    double price;

    // schedule
    int date;
    int startTime;
    int finalTime;

public:

    maintenance(string, int, int,string,float);
    maintenance(int,double);
    maintenance(int, int, int);

    void ShowInformation();
    void ShowRoomInformation();
    void Showschedule();
};

class booking :public maintenance {

private:

    int tiket;

public:

    booking(int);

};

class sale :public booking {

private:

    int ID;
    int card;

public:

    sale(int);

};

class menu: public sale {

private:

   string archive;

public:

    menu(string);
    void Showmenu();


};

maintenance::maintenance(string _name, int _year, int _time, string _country, float _reviews) {
    name= _name;
    year= _year;
    time= _year;
    country= _country;
    reviews = _reviews;

}

 maintenance::maintenance(int _roomnumber, double _price) {
     roomnumber = _roomnumber;
     price = _price;


}


 maintenance::maintenance(int _date, int _startTime, int _finalTime ) {
     date = _date;
     startTime = _startTime;
     finalTime = _finalTime;


 }

void maintenance::ShowInformation() {
    cout << " El nombre de la pelicula es: " << name;
    cout << " El año de estreno de la pelicula es: " << year;
    cout << " El tiempo de duracion de la pelicula es: " << time;
    cout << " El pais de la pelicula es: " << country;
    cout << " las reseñas de la pelicula son: " << reviews;
};

void maintenance::ShowRoomInformation() {

    cout << "La sala es: " << roomnumber;
    cout << " El precio de la pelicula es: " << price;
    cout << " La cantidad de butacas son 100";
 };

void maintenance::Showschedule() {

    cout << "La fecha de la pelicula es: " << date;
    cout << " El hora de inicio es: " << startTime;
    cout << " El hora de final es: " << finalTime;

};

