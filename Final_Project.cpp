#include <bits/stdc++.h>
using namespace std;

const int NUM_ROWS=5;
const int NUM_SEATS=6;

// function to print the booking template

void printSeats(char bookings[][NUM_SEATS]){
	cout<<"\t";
	for(int i=0;i<6;++i)
		cout<<char(i+65)<<" ";
	for(int i=0;i<NUM_ROWS;++i){
		cout<<"\nRow "<<i<<"   ";
		for(int j=0;j<NUM_SEATS;++j){
			cout<<bookings[i][j]<<" ";
		}
	}
	cout<<endl;
	cout<<"=================================================\n";
}


// function to reserve the seats

void reserve(char bookings[][NUM_SEATS],int row,char seat){
	int col=0;
	if(seat=='A')	col=0;
	else if(seat=='B') col=1;	
	else if(seat=='C') col=2;
	else if(seat=='D') col=3;
	else if(seat=='E') col=4;
	else
		col=5;
	// if the seat is already reserved prompt cannot reserved and try again
	
	if(bookings[row][col]=='X'){
		cout<<"Cannot reserved! The place is already taken, try again.\n";
		return;
	}
	
	// else reserve the position and display confirmation
	
	bookings[row][col]='X';
	cout<<"Reservation confirmed!!\n";
}


// to update the reservedRow array

void reserveSeats(char bookings[][NUM_SEATS],int reservedRow[NUM_ROWS]){
	for(int i=0;i<NUM_ROWS;++i){
		int cnt=0; // set count variable to zero because each row has its specific number of reserved seats 
		for(int j=0;j<NUM_SEATS;++j){
			if(bookings[i][j]=='X')
				cnt++;
		}
		reservedRow[i]=cnt; // set the answer
	}
}

int32_t main() {
	cout<<" The Final Project - CSS200 - Introduction to C++\n Name: Abdullah Alotaibi - ID:201000960\n";
	cout<<"=================================================\n";
	char bookings[NUM_ROWS][NUM_SEATS];
	for(int i=0;i<NUM_ROWS;++i)
		for(int j=0;j<NUM_SEATS;++j)
			bookings[i][j]='*';
	int reservedRow[NUM_ROWS]={0};
	printSeats(bookings);
	char wantToContinue='y';
	
	// this will continue till user do not enter 'n'
	
	while(wantToContinue=='y'){
		cout<<"Enter row (0-4 as seen in the above matrix):";
		int row=0;cin>>row;
		cout<<"\n\nEnter seat (A, B, C, D, E, F):";
		char seat=0;cin>>seat;
		reserve(bookings,row,seat-32);
		printSeats(bookings);
		cout<<"Do you want to continue (y/n)?";cin>>wantToContinue;
	}
	
	int row=0;
	cout<<"To find the number of the available seats in a row, enter the row number (0-4): ";
	cin>>row;
	reserveSeats(bookings,reservedRow);
	cout<<" The number of available seats in row "<<row<<":"<<NUM_SEATS-reservedRow[row]<<" seats\n";
	cout<<" The number of reserved seats in each row:\n";
	cout<<"=================================================\n";
	for(int i=0;i<NUM_ROWS;++i){
		cout<<"Row "<<i<<" "<<reservedRow[i]<<endl;
	}
	return 0;
}
