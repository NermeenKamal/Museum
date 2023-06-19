#include <bits/stdc++.h>
#include <fstream>
using namespace std;
fstream outTicket; //write
void WelcomeMessage(){
cout<<endl;
cout<<"       <><><><><><><><><><><><><><><><><><>";
cout<<"\n\t** Welcome to Our Museum System **"<<endl;
cout<<"\t    ** Hope you Enjoy!!! **"<<endl;
cout<<"       <><><><><><><><><><><><><><><><><><>";
cout<<endl<<endl;
cout<<"\t\t1-Booking Ticket."<<endl;
cout<<"\t\t2-View Tickets."<<endl;
cout<<"\t\t3-Working Hours."<<endl;
cout<<"\t\t4-Museum Map."<<endl;
cout<<"\t\t5-Information."<<endl;
cout<<"\t\t6-Exit."<<endl<<endl;
}
class Museum{
    protected:
string NameOfMuseum="The Egyptian Museum.";
    public:
void setName(){
  NameOfMuseum=" ";
        }
void getName(){
  cout<<NameOfMuseum;
        }
void Working_Hours(){
ifstream HOURS;
HOURS.open("HOURS.txt");
string line;
while(getline(HOURS,line)){
cout<<line<<endl;}
HOURS.close();
}
void View(){   //Map
    ifstream Map;
    Map.open("Map.txt");
    string lines;
    cout<<"     <><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<"          "<<"HELLO, HOPE OUR MAP HELP YOU: "<<endl;
    cout<<"     <><><><><><><><><><><><><><><><><><><><>"<<endl;
    while(getline(Map,lines)){
      cout<<lines<<endl;
    }
    Map.close();
    }
void Exit(){
  cout<<endl<<"       +=+=+=+=+= Thank You!!! +=+=+=+=+=+ "<<endl;
  exit(1);
}
};
class Ticket:public Museum{
    protected:
string Name;
string id;
int age;
string Time;
int Price;
    public:
void setName(string s){
      Name=s;
        }
void setid(string d){
    id=d;
        }
void setage(int e){
    age=e;
        }
void setTime(string m){
    Time=m;
        }
void setPrice(int p){
    Price=p;
        }
void getName(){
    cout<<Name;
        }
void getid(){
    cout<<id;
        }
void getage(){
    cout<<age;
        }
void getTime(){
    cout<<Time;
        }
void getPrice(){
    cout<<Price;
        }
void booking(int num){
    cout<<"Please Enter Name: ";
    string s;  cin>>s;
    setName(s);
    cout<<"Please Enter Id: ";
    string d;   cin>>d;
    setid(d);
    cout<<"Please Enter Age: ";
    int e;   cin>>e;
    setage(e);
    if(e>10){
      setPrice(30);
    }
    else if(e<=10){
      setPrice(20);
    }
    cout<<"Please Enter The Time Of The Visiting: ";
    string m;   cin>>m;
    setTime(m);
    outTicket<<"Name: "<<s<<endl;
    outTicket<<"Id: "<<d<<endl;
    outTicket<<"Age: "<<e<<endl;
    outTicket<<"Time: "<<m <<endl;
    outTicket<<"Price: "<<Price<<endl;
    cout<<"--_-_-_The Ticket Has Been Added-_-_-_-_-"<<endl;
}
void View(){   //overloading
   cout<<"\t<><><><><><><><><><><><><><><><><><>"<<endl;
   cout<<"\t\t  Your Tickets: "<<endl;
   cout<<"\t<><><><><><><><><><><><><><><><><><>"<<endl;
   string line;
   cout<<"           Museum: "<<NameOfMuseum<<endl;
   while(getline(outTicket,line)){
     cout<<"\t   "<<line<<"      "<<endl;
}
}
};
class service:public Museum{
    private:
int code;
    public:
void setCode(int n){
    code=n;
    }
void getCode(){
    cout<<code;
    }
void Info(){
   cout<<"  Please choose one option: "<<endl;
   cout<<"  1-Tour Guide          2-About Museum"<<endl;
   cin>>code;
   if(code==1){
   TourGuide();
  }
  else if(code==2){
   show();
  }}
void show(){
    string line;
    ifstream Show;
    Show.open("Show.txt");
    while(getline(Show,line)){
        cout<<line<<endl;
    }
    Show.close();
   }
void TourGuide(){
    string line;
    ifstream tourGuide;
    tourGuide.open("tourGuide.txt");
    while(getline(tourGuide,line)){
        cout<<line<<endl;
    }
    tourGuide.close();
   }
};
int main()
{
  WelcomeMessage();
  Museum M;
  Ticket arr[10];  //array of objects
  service A;
  outTicket.open("outTicket.txt");
  cout<<"\t   Please Enter your choice:  ";
  int n; int num;  cin>>n;
  switch (n){
  case 1:{
    cout<<"How Many Tickets do you want to buy? "<<endl;
     cin>>num;
    for(int i=0;i<num;i++){
    arr[i].booking(num);
    }
    break;}
  case 2:{
    arr[n].View();
    break;}
  case 3:{
    cout<<"\t<><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<"\t\t  Working Hours: "<<endl;
    cout<<"\t<><><><><><><><><><><><><><><><><><>"<<endl;
    M.Working_Hours();
    break;}
  case 4:{
    M.View();
    break;}
  case 5:{
    A.Info();
    break;}
  case 6:{
    M.Exit();
    break;}
  }
  outTicket.close();
    return 0;
}
