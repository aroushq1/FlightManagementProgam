#include <iostream>

#include <fstream>

#include <vector>

#include <string>

#include <fstream>


#ifndef CLASSES
#define CLASSES
using namespace std;

class Seat {

public:

Seat(): row(0), seat(0), status(0){	};
Seat(int r, int c);
void set_status(int stat);
int get_seat() const;
bool  get_status() const;


private:

    int row;

    int seat;

    bool status; //occupied & unoccupied seats
	
 

};
class Passenger {

public:


Passenger(): firstName(0), lastName(0), phoneNumber(0), seat_num(0), id(0){};
Passenger(string fname, string lname, string phonenum, string seat, string p_id);
Seat *  get_assignedSeat(){return assignedSeat;}
string get_seatname(){return seat_num;}
string getId()  const{return id;}
string getFirstName() const {return firstName;}
string getLastName() const {return lastName;}
string get_phonenum()const {return phoneNumber;}

void set_seatptr(Seat* a, int b);

 

private:

    string firstName;

    string lastName;

    string phoneNumber;

	string seat_num;

	Seat* assignedSeat; // Pointer to a Seat object

    string id;

 

};
class Flight {

public:

	Flight(string name, int rows, int cols);
	string get_name() const;
	void showSeatMap(int & map_count);
	void showPassengersInfo();
	void addPassenger();
	void removePassenger();
	void set_passenger_info( string fname, string lname, string phonenum, string id, string seat);
	void saveFile();

private:

    string id;

    int num_rows;

    int num_cols;

	vector<vector<Seat>> seatmap; 

    vector<Passenger> passenger_list;

};

class Airline{

public:

Airline(string flightname, int num_flights, int rows, int cols);

 Flight * get_flights ();
 
   

private:

    string name;
	

	Flight * flights;
    int num_flights;

};


#endif