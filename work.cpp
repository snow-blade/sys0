#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include "TextTable.h"
#include "rang.hpp"
#include "progress.h"
using namespace std;
using namespace rang;

void
course_credit_management();
void
student_management();
void
menu_display();
void
handle(int n);
void
print_vec(std::vector<int> v);
void
marks_menu();
int M_LENGHT = 0;
class date
{
   public:
    int day, month, year = 0;
    bool
    is_valid()
    {
        return day > 0 && day < 32 && month > 0 && month < 13 && year > 1980;
    }
    void
    print()
    {
        cout << fg::green << "Current date: " << year << " "
             << " " << month << " " << day << "\n";
    }
};
class course
{
   public:
    int credit = 0;
    char title[20] = "";
    int mark = 0;
};
class student
{
   public:
    char *name = new char(), *surname = new char(), *address = new char();
    int registration_number = 0;
    date date_of_birth;
    course *course_marks = new course();
    student(int e, char n[], char s[], char *a, course *c, date d)
    {
        name = n;
        registration_number = e;
        course_marks = c;
        date_of_birth = d;
        surname = s;
        address = a;
    }
};
void
change_characteristics(student st);
vector<student>
student_management_create();
void
student_management_display(vector<student>, int j);
void student_management_av(vector<student>);
void student_management_best(vector<student>);
void student_management_best_mark_by_course(vector<student>);
void student_management_worst_mark_by_course(vector<student>);
void student_management_best_by_course(vector<student>);
void student_management_display_by_av(vector<student>);

course *
marks_management_create();
void
marks_management_display(course *m);
course *
marks_management_modify(course *m, int j);
int
marks_management_av(course *m);
int
marks_management_best(course *m);
int
marks_management_worst(course *m);
vector<int>
marks_management_bel_av(course *m);
vector<int>
marks_management_ab_av(course *m);

int
main()
{   
    int N = 2000;
    tqdm bar;
    cout<<fg::green<<"Loading..."<<endl;
    bar.set_theme_braille();
    for(int i = 0; i < N; i++) {
    	bar.progress(i, N);
    	usleep(1000);
    }
    bar.finish();
    cout<< fg::cyan<<"School Managemt system"<<"\n";
    menu_display();
    cout << fg::red << " Enter your choice> ";
    int n;
    cin >> n;
    handle(n);
}

void
course_credit_management()
{
    cout << fg::green
         << "--------- Course credit management system ---------------\n";
    int m;
    cout << fg::green << "enter the value of m: ";
    cin >> m;
    assert(m > 6 && "m must be bigger than 6");
    assert(m < 15 && "m must be less than 15");
    int n = m + 1;
    int sum = 0;
    course cc[m];
    while (m > 0) {
        cout << fg::green << "----- Course n0" << n - m << " ------\n";
        cout << fg::green << "Enter the value of the credit: ";
        cin >> cc[n - m - 1].credit;
        cout << fg::green << "Enter the value of the title: ";
        cin >> cc[n - m - 1].title;
        sum += cc[n - m - 1].credit;
        m--;
    }
    assert(sum == 30 && "Credit sum must be equal to 30");
    m = n - 1;
    cout << fg::green << "\n-----------------Result-------------\n";
    while (m > 0) {
        cout << fg::green << "\ncourse " << n - m
             << " title: " << cc[n - m - 1].title;
        cout << fg::green << "\ncourse" << n - m
             << " credit: " << cc[n - m - 1].credit;
        m--;
    }
}
void
student_management()
{
    date dd;
    cout << fg::green << "-------- Student management system --------\n\n";
    cout << fg::green << "enter the year: ";
    cin >> dd.year;
    cout << fg::green << "\nenter the month: ";
    cin >> dd.month;
    cout << fg::green << "\nenter the day: ";
    cin >> dd.day;
    assert(dd.is_valid() && "the data you entered is not valid");
    dd.print();
    cout << fg::green << "\n\n----- Create a new student ----- ";
    cout << fg::green << "\n----> Enter his name: ";
    char name[20];
    cin >> name;
    cout << fg::green << "\n----> Enter the surname: ";
    char surname[20];
    cin >> surname;
    cout << fg::green << "\n----> Enter the address: ";
    char address[20];
    cin >> address;
    cout << fg::green << "----> Enter the registration number: ";
    int reg = 0;
    cin >> reg;
    int m;
    cout << fg::green << "enter the number 'm' of courses: ";
    cin >> m;
    assert(m > 6 && "m must be bigger than 6");
    assert(m < 15 && "m must be less than 15");
    int n = m + 1;
    course cc[m];
    while (m > 0) {
        cout << fg::green << "----- Course n0" << n - m << " ------\n";
        cout << fg::green << "Enter the value of the credit: ";
        cin >> cc[n - m - 1].credit;
        cout << fg::green << "Enter the value of the title: ";
        cin >> cc[n - m - 1].title;
        cout << fg::green << "Enter the value of the mark: ";
        cin >> cc[n - m - 1].mark;
        cout << fg::green << "\n\n";
        m--;
    }
    student st = student(reg, name, surname, address, cc, dd);
    cout << fg::green << "\n\n\n";
    cout << fg::green << "Name: " << st.name << "\n";
    cout << fg::green << "Surname: " << st.surname << "\n";
    cout << fg::green << "Address: " << st.address << "\n";
    cout << fg::green << "Registration number: " << st.registration_number
         << "\n";
    st.date_of_birth.print();
    cout << fg::green << "do you wish to change students characteristics?y/n";
    string answer;
    cin >> answer;
    if (answer == "yes" || answer == "y") {
        change_characteristics(st);
    }
}
void
change_characteristics(student st)
{
    cout << fg::green << "name>";
    cin >> st.name;
    cout << fg::green << "surname>";
    cin >> st.surname;
    cout << fg::green << "address>";
    cin >> st.address;
    cout << fg::green << "Registration number>";
    cin >> st.registration_number;
    cout << fg::green << "year of birth>";
    cin >> st.date_of_birth.year;
    cout << fg::green << "month of birth>";
    cin >> st.date_of_birth.month;
    cout << fg::green << "day of birth>";
    cin >> st.date_of_birth.day;
}
course *
marks_management_create()
{
    M_LENGHT = 0;
    int m = 0;
    course *cc = new course();
    cout << fg::green << "---- Course  marks management ----\n";
    cout << fg::green << "Enter the number of courses\n";
    cin >> m;
    int n = m + 1;
    while (m) {
        cout << fg::green << "Enter the title of the course number " << n - m
             << "\n";
        cin >> cc[n - m - 1].title;
        cout << fg::green << "Enter the marks of the student in course number "
             << n - m << "\n";
        cin >> cc[n - m - 1].mark;
        M_LENGHT += 1;
        m--;
    }
    return cc;
}
void
marks_management_display(course *m)
{
    int l = M_LENGHT;
    while (l) {
        cout << fg::green << "\n\n"
             << M_LENGHT - l + 1 << ".title: " << m[M_LENGHT - l].title
             << ", marks: " << m[M_LENGHT - l].mark << "\n";
        l--;
    }
}
course *
marks_management_modify(course *m, int j)
{
    cout << fg::green << "new mark>";
    cin >> m[j].mark;
    return m;
}
int
marks_management_av(course *m)
{
    int l = M_LENGHT;
    int total = 0;
    while (l) {
        total += m[M_LENGHT - l].mark;
        l--;
    }
    return total / M_LENGHT;
}
int
marks_management_best(course *m)
{
    int l = M_LENGHT;
    int best = 0;
    while (l) {
        if (m[M_LENGHT - 1].mark > best) {
            best = m[M_LENGHT - 1].mark;
        }
        l--;
    }
    return best;
}
int
marks_management_worst(course *m)
{
    int l = M_LENGHT;
    int worst = m[0].mark;
    while (l) {
        if (m[M_LENGHT - l].mark < worst) {
            worst = m[M_LENGHT - l].mark;
        }
        l--;
    }
    return worst;
}
vector<int>
marks_management_bel_av(course *m)
{
    vector<int> bel_av;
    int l = M_LENGHT;
    int av = marks_management_av(m);
    while (l) {
        if (m[M_LENGHT - l].mark < av) {
            bel_av.push_back(m[M_LENGHT - l].mark);
        }
        l--;
    }
    return bel_av;
}
vector<int>
marks_management_ab_av(course *m)
{
    vector<int> ab_av;
    int l = M_LENGHT;
    int av = marks_management_av(m);
    while (l) {
        if (m[M_LENGHT - l].mark < av) {
            ab_av.push_back(m[M_LENGHT - l].mark);
        }
        l--;
    }
    return ab_av;
}
vector<student>
student_management_create()
{
    vector<student> all;
    cout << fg::green << "enter the number of students";
    int n;
    cin >> n;
    int m = n + 1;
    int reg_num = 0;
    char *name = new char();
    char *surname = new char();
    char *address = new char();
    date dt;
    course *course_marks = new course();
    assert(n > 0 && "n must be greater than 0");
    while (n) {
        cout << fg::green << "---- Student number ----" << m - n << "\n";
        cout << fg::green << "Enter the name> ";
        cin >> name;
        cout << fg::green << "Enter the surname> ";
        cin >> surname;
        cout << fg::green << "Enter the registration number> ";
        cin >> reg_num;
        cout << fg::green << "Enter the day of birth> ";
        cin >> dt.day;
        cout << fg::green << "Enter the month of birth> ";
        cin >> dt.month;
        cout << fg::green << "enter the year of birth> ";
        cin >> dt.year;
        course_marks = marks_management_create();
        all.push_back(
            student(reg_num, name, surname, address, course_marks, dt));
        n--;
    }
    return all;
}
void
student_management_display(vector<student> v, int n)
{
    cout << fg::green << "--- Displaying " << n << " students ----\n";
    int m = n;
    while (m) {
        cout << fg::green << "Student number " << n - m + 1 << "\n";
        cout << fg::green << "Name: " << v[n - m].name << "\n";
        cout << fg::green << "Surame: " << v[n - m].surname << "\n";
        cout << fg::green << "Address: " << v[n - m].address << "\n";
        v[n - m].date_of_birth.print();
        cout << fg::green << "----  Courses  ----";
        marks_management_display(v[n - m].course_marks);
        m--;
    }
}
void
student_management_av(vector<student> v)
{
    int n = v.size();
    int m = n;
    while (m) {
        cout << fg::green << "Average of " << v[n - m].name << " "
             << v[n - m].surname << marks_management_av(v[n - m].course_marks);
    }
}
void
student_management_best(vector<student> v)
{
    int n = v.size();
    int m = n;
    while (m) {
        cout << fg::green << "Best of " << v[n - m].name << " "
             << v[n - m].surname
             << marks_management_best(v[n - m].course_marks);
    }
}
void
student_management_worst(vector<student> v)
{
    int n = v.size();
    int m = n;
    while (m) {
        cout << fg::green << "Worst of " << v[n - m].name << " "
             << v[n - m].surname
             << marks_management_worst(v[n - m].course_marks);
    }
}

void
menu_display()
{
    TextTable t('-', '|', '#');
    t.add("List Of Available Operations");
    TextTable menu('-', ' ', ' ');
    t.endOfRow();
    menu.add("Enter 1 for");
    menu.add("Course Credit Management");
    menu.endOfRow();
    menu.add("Enter 2 for");
    menu.add("Student Management");
    menu.endOfRow();
    menu.add("Enter 3 for");
    menu.add("Course Marks Management");
    menu.endOfRow();
    menu.add("Enter 4 for");
    menu.add("Class student Management");
    menu.endOfRow();
    menu.setAlignment(0, TextTable::Alignment::LEFT);
    t.setAlignment(2, TextTable::Alignment::LEFT);
    cout << fg::green << t << fg::blue << menu;
}
void
handle(int n)
{
    switch (n) {
        case 1:
            course_credit_management();
            break;
        case 2:
            student_management();
            break;
        case 3:
            marks_menu();
    }
}
void
print_vec(std::vector<int> v)
{
    int r = v.size();
    int n = r;
    while (n) {
        cout << v[r - n];
        n--;
    }
    cout << "\n";
}
void
marks_menu()
{
    course *marks;
    std::vector<int> v;
    bool loop = true;
    int capture;
    TextTable t('-', '|', '#');
    t.add("Marks Management Menu");
    TextTable menu('-', ' ', ' ');
    t.endOfRow();
    menu.add("Enter 1 for");
    menu.add("Marks Management Creation");
    menu.endOfRow();
    menu.add("Enter 2 for");
    menu.add("Marks Management Displaying");
    menu.endOfRow();
    menu.add("Enter 3 for");
    menu.add("Marks Management Average");
    menu.endOfRow();
    menu.add("Enter 4 for");
    menu.add("Marks Management Best");
    menu.endOfRow();
    menu.add("Enter 5 for");
    menu.add("Marks Management Worst");
    menu.endOfRow();
    menu.add("Enter 6 for");
    menu.add("Marks Management Above Average");
    menu.endOfRow();
    menu.add("Enter 7 for");
    menu.add("Marks Management Below Average");
    menu.add("Enter 8 to");
    menu.add("CLose");
    menu.endOfRow();
    menu.setAlignment(0, TextTable::Alignment::LEFT);
    t.setAlignment(2, TextTable::Alignment::LEFT);
    cout << fg::green << t << fg::blue << menu;
    int choice;
    while (loop) {
        cout << fg::blue << "Enter your choice> ";
        cin >> choice;
        switch (choice) {
            case 1:
                marks = marks_management_create();
                break;
            case 2:
                marks_management_display(marks);
                break;
            case 3:
                capture = marks_management_av(marks);
                cout << fg::cyan << "The Average mark is" << capture << "\n";
                break;
            case 4:
                capture = marks_management_best(marks);
                cout << fg::cyan << "The best mark is" << capture << "\n";
                break;
            case 5:
                capture = marks_management_worst(marks);
                cout << fg::cyan << "The Worst mark is" << capture << "\n";
                break;
            case 6:
                print_vec(marks_management_ab_av(marks));
                break;
            case 7:
                print_vec(marks_management_bel_av(marks));
                break;
            case 8:
                loop = false;
                break;
            default:
                continue;
                break;
        }
    }
}
