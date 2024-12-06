//classes.cpp

#include "classes.h" 
#include <assert.h> 

// AIRLINE MEMBER FUNCTIONS
Airline:: Airline(string flight_name, int fnum, int rows, int columns): num_flights(fnum){ 

int i=0; 

 

    while (flight_name[i] >='A' && flight_name[i] <='Z'){ 

  

        name += flight_name[i]; 

  

        i++; 

  

    } 

  

 

  

  


  
Flight * a= new Flight(flight_name,rows, columns);
flights = a ; 

  


 

} 

  

  

Flight * Airline:: get_flights () { return flights;} 

  

  

  
//FLIGHT MEMBER FUNCTIONS 
string Flight::get_name() const{ return id;} 

  

  

Flight::Flight(string name, int rows, int cols): id(name), num_rows(rows), num_cols(cols){
	seatmap.resize(rows);
	int r=0;
	while (r <rows){
		seatmap[r].resize(cols);
		r++;
	}
}


  

void Flight:: set_passenger_info(string fname, string lname, string phonenum ,string seat, string id) { 
	Passenger temp(fname, lname, phonenum,seat, id); 
	 
	// ensure seat is not occupied and id is unique
	long unsigned int count = 0;
	while (count<passenger_list.size()){
		assert(passenger_list[count].get_seatname() != seat);
		assert(passenger_list[count].getId() !=id);
		
		count++;
	}
	int i = 0;
	
	int row_num = 0;
	char col_char;
	while (seat[i]){
		if (isdigit(seat[i])){
			row_num += 10*row_num + seat[i] - 48;
		}
		if (isalpha(seat[i])){
			col_char = seat[i];
		}
		i++;
	}
	
	
	int col_count= 0;
	char seat_name = 'A';
	
	while (1){
		if (seat_name == col_char)break;
		seat_name++;
		col_count++;
	}


if (row_num>=10){
	temp.set_seatptr(&(seatmap[row_num-1][col_count]),1);

}

else{
	temp.set_seatptr(&(seatmap[row_num][col_count]), 1);

}



passenger_list.push_back(temp); 

 

 

 

} 

void Flight:: saveFile(){
	ofstream out_stream("flight_info.txt");
	assert(!out_stream.fail());
	out_stream.width(10); out_stream<<left<< id;
	out_stream.width(5); out_stream<<left<< num_rows; 
	out_stream.width(5); out_stream<<left<< num_cols<<endl; 
	long unsigned int r =0 ;
	while (r<passenger_list.size()){
		
		out_stream.width(20);out_stream<< left<< passenger_list[r].getFirstName();
		out_stream.width(20);out_stream<< left<<passenger_list[r].getLastName();
		out_stream.width(20);out_stream<< left<<passenger_list[r].get_phonenum();
		out_stream.width(10);out_stream<< left<<passenger_list[r].get_seatname();
		out_stream.width(10);out_stream<< left<< passenger_list[r].getId();
		
		r++;
		if (r!=passenger_list.size()){
			out_stream<<endl;
		}
		
		
	}
	out_stream.close();
}

void Flight::showSeatMap(int & map_count) {


	
    cout << "Flight Seat Map:\n";
	
	// padding enough spaces for column titles
	if (map_count !=0) cout<<"      ";
	else cout<<" ";
	map_count++;
	for (int j = 0; j<num_cols;j++)
	{
		char seat = j+65;
		cout.width(6); cout<< seat;
	}
	cout<< endl;
	
    for (int i = 0; i < num_rows; i++)		{
		cout.width(5);cout <<left<< i;
        for (int j = 0; j < num_cols; j++) {
			bool status =seatmap[i][j].get_status();
			if (status == 0){
				cout.width(6);	cout << left<< "[ ]";
			}
			else{
				cout.width(6);	cout<< left<<"[X]";
				}		 
        }
		cout<< endl;
    }
	
	
    }


       
void Flight:: showPassengersInfo() {

        
   long unsigned int r = 0; 
   cout.width(20); cout<<left<<"First Name";
   cout.width(20); cout<< left<<"Last Name";
   cout.width(20); cout<<left<< "Phone Number";
   cout.width(20); cout<< left<<"ID";
   cout.width(20); cout<<left<<"Seat";
   cout<<endl;
   cout<<"**************************************************************************************\n";
   while (r<passenger_list.size()){
	  cout.width(20);cout<< left<< passenger_list[r].getFirstName();
	  cout.width(20);cout<< left<<passenger_list[r].getLastName();
	  cout.width(20);cout<< left<<passenger_list[r].get_phonenum();
	  cout.width(20);cout<< left<<passenger_list[r].getId();
	  cout.width(20);cout<< left<< passenger_list[r].get_seatname();
		
	 
	  cout<<endl;
	  r++;
   }
  

}

void Flight::addPassenger(){
	
	//add to main
	string firstName;

    string lastName;

    string phoneNumber;

	string seat_num;


    string id;
	
	cout<<"Enter the passenger id: ";
	cin>>id;
	cout<<"\n";
	
	cout<<"Enter passenger first name: ";
	cin>> firstName;
	cout<<"\n";

	cout<<"Enter passenger last name: ";
	cin>> lastName;
	cout<<"\n";
	
	cout<<"Enter passenger phone number: ";
	cin>> phoneNumber;
	cout<<"\n";
	
	cout<<"Enter passenger's desired seat: ";
	cin>> seat_num;
	cout<<"\n";

	set_passenger_info(firstName, lastName,	phoneNumber,  seat_num, id);
	
	
	
}

void Flight::removePassenger(){
	string doomed_passenger;
	cout<< "Please enter the id of the passenger that needs to be removed: ";
	cin>> doomed_passenger;
	
	long unsigned int i = 0;


	
	
	


	while (i<passenger_list.size()){
		if (doomed_passenger == passenger_list[i].getId()){
			passenger_list[i].set_seatptr (passenger_list[i].get_assignedSeat(),0);
			
			passenger_list.erase(passenger_list.begin()+i);
			cout<<"\n[Passenger successfully removed]\n";
			return;
		}
		i++;
	}
	

	cout<<"Passenger doesn't exist.\n";
		
	


	
	
}

 

      

  

  

 

  

  

  

  



  

  

  

// PASSENGERS MEMBER FUNCTIONS 

Passenger::Passenger(string fname, string lname, string phonenum, string seat, string p_id): firstName(fname), lastName(lname),  

phoneNumber(phonenum), seat_num(seat), id(p_id){ 

 

} 

  

  
void Passenger:: set_seatptr(Seat * a,int b){
		

	assignedSeat = a;
	assignedSeat->set_status(b);
	
	

	
}



  

  

  



  
  // SEATS MEMBER FUNCTIONS



 Seat::Seat(int r, int c): row(r), seat(c), status(0){
 
	
 }
 
 void Seat:: set_status(int stat){
	 status = stat;
 }
 
 bool Seat:: get_status() const{
	 return status;
 }
 

 

