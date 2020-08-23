#include<iostream>
#include<cassert>

void course_credit_management();
void student_management();
using namespace std;
class date{
    public:
        int day,month,year=0;
        bool is_valid(){
            return day>0 && day <32 && month>0 && month<13 && year>1980; 
        }

};
class course{
   public:
       int credit=0;
       char title[20];
       int mark=0;
};
class student{
public:
   char name[20],surname[20],address[20];
   int registration_number=0;
   date date_of_birth;
   course course_marks[200];
   student(int e,char n[],course c,date d){
       *name=*n;
       registration_number=e;
       course_marks[0]=c;
       date_of_birth=d;
   }
   

};

int main(){

//course_credit_management();
student_management();
}

course course_credit_management(int m){
    cout<< "--------- Course credit management system ---------------\n";
    cout<< "enter the value of m: ";
    assert(m>6 && "m must be bigger than 6");
    assert(m<15 && "m must be less than 15");
    int n=m+1;
    course cc[m];
    while(m>0){
        cout<<"----- Course n0"<<n-m<<" ------\n";
        cout<< "Enter the value of the credit: ";
        cin>>cc[n-m-1].credit;
        cout<< "Enter the value of the title: ";
        cin>>cc[n-m-1].title;
        cout<< "Enter the value of the mark: ";
        cin>>cc[n-m-1].mark;
        cout<< "\n\n";
        m--;
    }
    m=n-1;
    cout<<"\n-----------------Result-------------\n";
    while(m>0){
      cout<<"\ncourse "<<n-m<<" title: "<<cc[n-m-1].title;
      cout<<"\ncourse"<<n-m<<" credit: "<< cc[n-m-1].credit;
      cout<<"\ncourse "<<n-m<<" mark: "<<cc[n-m-1].mark;
      m--;
    }
    return *cc;
}
void student_management(){
    date dd;
    cout<<"-------- Student management system --------\n";
    cout<<"enter the year: ";
    cin>> dd.year;
    cout<<"\nenter the month: ";
    cin>> dd.month;
    cout<<"\n enter the day: ";
    cin>> dd.day;
    assert(dd.is_valid() && "the data you entered is not valid");
    cout<< "the date is "<< dd.year <<" "<<dd.month<<" "<< dd.day;
    cout<<"\n\n ----- Create a new student ----- ";
    cout<<"\n ---- Enter his name: ";
    char name[20];
    cin>>name;
    cout<<"\n---- Enter the surname: ";
    char surname[20];
    cin>>surname;
    cout<<"\n---- Enter the address: ";
    char address[20];
    cin>>address;
    cout<<"\n---- Enter the registration number: ";
    int reg=0;
    cin>>reg;
    cout<<"\n---- Enter the number of courses: ";
    int m=0;
    cin>>m;
    course c=course_credit_management(m);







}
