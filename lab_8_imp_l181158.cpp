#include"Date_l181158.h";

//Default constructor
Date::Date(){
	day=1;
	month=1;
	year=2000;
}

//overloaded constructor
Date::Date(int x,int y,int z){
	if(x >0 && x < 13){
	month=x;
	}
	else{
	month=1;
	day=1;
	year=2000;
	return;
	}
	if(y >0 && x < 31){
	day=y;
	}
	else{
	month=1;
	day=1;
	year=2000;
	return;
	}
	if(z > 999 && x < 10000){
	year=z;
	}
	else{
	month=1;
	day=1;
	year=2000;
	return;
	}
}
//initializing static member
string Date::monthNames[13]= { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

//overloading << operator
ostream & operator<<(ostream &out,Date &d1){
	out<<d1.monthNames[d1.month]<<" ";
	out<< d1.day<<", "<< d1.year<<endl;
	return out;
}

//overloading == operator
 bool operator==(Date& d1,Date &d2){
	 if(d1.day==d2.day){
		if(d1.month==d2.month){
			if(d1.year==d2.year){
				return true;
			}
		}
	 }
	return false;
 }
 //overloading >> operator
istream & operator>>(istream &in,Date &d1){
	cout<<"Enter Day : ";
	in>>d1.day;
	cout<<"Enter month : ";
	in>>d1.month;
	cout<<"Enter year : ";
	in>>d1.year;
	return in;
}
//overloading + operator
Date Date::operator+(int x){
	for(int i=1;i<=x;i++){
		day=day+1;
		if(day==31){
			day=1;
			month=month+1;
		}
		if(month==13){
			month=1;
			year=year+1;
		}
	}
	 return *this;
}
//overloading = operator
Date Date::operator=(Date &d1){
	this->day=d1.day;
	this->month=d1.month;
	this->year=d1.year;
	return *this;
}

//overloading pre decrement
Date& Date::operator--(){
	if(day-1!=0){
	this->day=day-1;
	}
	else{
		month=month-1;
		day=30;
	}
	return*this;
}

//overloading post decrement
Date Date::operator--(int x){
	Date dummy=*this;
	if(day-1!=0){
	this->day=day-1;
	}
	else{
		month=month-1;
		day=30;
	}
	return dummy;
}

//overloading [] operator
int Date::operator[](int x){
	if(x>=0 && x<=2){
		if(x==0){
			return day;
		}
		if(x==1){
			return month;
		}
		if(x==2){
			return year;
		}
	}
}