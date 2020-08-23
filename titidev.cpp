#include<iostream>
#include<cassert>
#include<cstring>

void course_credit_management();
void student_management();

using namespace std;
class date{
    public:
        int day,month,year=0;
        bool is_valid(){
            return day>0 && day <32 && month>0 && month<13 && year>1980; 
        }
        void print(){
            cout<<"Current date: "<< year<< " "<< " "<< month<< " "<< day<<"\n";
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
   char *name=new char(),*surname=new char(),*address=new char();
   int registration_number=0;
   date date_of_birth;
   course *course_marks=new course();
   student(int e,char n[],char s[],char *a,course *c,date d){
       name=n;
       registration_number=e;
       course_marks=c;
       date_of_birth=d;
       surname=s;
       address=a;
   }
   

};
void change_characteristics(student st);


int main(){

//course_credit_management();
student_management();
}

void course_credit_management(){
    cout<< "--------- Course credit management system ---------------\n";
    int m;
    cout<< "enter the value of m: ";
    cin>> m;
    assert(m>6 && "m must be bigger than 6");
    assert(m<15 && "m must be less than 15");
    int n=m+1;
    int sum=0;
    course cc[m];
    while(m>0){
        cout<<"----- Course n0"<<n-m<<" ------\n";
        cout<< "Enter the value of the credit: ";
        cin>>cc[n-m-1].credit;
        cout<< "Enter the value of the title: ";
        cin>>cc[n-m-1].title;
        sum+=cc[n-m-1].credit;
        m--;
    }
    assert(sum==30 && "Credit sum must be equal to 30");
    m=n-1;
    cout<<"\n-----------------Result-------------\n";
    while(m>0){
      cout<<"\ncourse "<<n-m<<" title: "<<cc[n-m-1].title;
      cout<<"\ncourse"<<n-m<<" credit: "<< cc[n-m-1].credit;
      m--;
    }
}
void student_management(){
    date dd;
    cout<<"-------- Student management system --------\n\n";
    cout<<"enter the year: ";
    cin>> dd.year;
    cout<<"\nenter the month: ";
    cin>> dd.month;
    cout<<"\nenter the day: ";
    cin>> dd.day;
    assert(dd.is_valid() && "the data you entered is not valid");
    dd.print();
    cout<<"\n\n----- Create a new student ----- ";
    cout<<"\n----> Enter his name: ";
    char name[20];
    cin>>name;
    cout<<"\n----> Enter the surname: ";
    char surname[20];
    cin>>surname;
    cout<<"\n----> Enter the address: ";
    char address[20];
    cin>>address;
    cout<<"----> Enter the registration number: ";
    int reg=0;
    cin>>reg;
    int m;
    cout<< "enter the number 'm' of courses: ";
    cin>> m;
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
   student st=student(reg,name,surname,address,cc,dd);
   cout<<"\n\n\n";
   cout<<"Name: "<<st.name<<"\n";
   cout<<"Surname: "<< st.surname<<"\n";
   cout<<"Address: "<< st.address<<"\n";
   cout<<"Registration number: "<< st.registration_number<<"\n";
   st.date_of_birth.print();
   cout<< "do you wish to change students characteristics?y/n";
   string answer;
   cin>>answer;
   if(answer=="yes"||answer=="y"){
       change_characteristics(st);
   }
}
void change_characteristics(student st){
    cout<<"name>";
    cin>>st.name;
    cout<<"surname>";
    cin>>st.surname;
    cout<< "address>";
    cin>>st.address;
    cout<<"Registration number>";
    cin>>st.registration_number;
    cout<<"year of birth>";
    cin>>st.date_of_birth.year;
    cout<<"month of birth>";
    cin>> st.date_of_birth.month;
    cout<<"day of birth>";
    cin>> st.date_of_birth.day;
}
