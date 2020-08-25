#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

void
course_credit_management();
void
student_management();
using namespace std;

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
        cout << "Current date: " << year << " "
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
    // course_credit_management();
    // student_management();
    vector<student> st = student_management_create();
    student_management_display(st, 1);
}

void
course_credit_management()
{
    cout << "--------- Course credit management system ---------------\n";
    int m;
    cout << "enter the value of m: ";
    cin >> m;
    assert(m > 6 && "m must be bigger than 6");
    assert(m < 15 && "m must be less than 15");
    int n = m + 1;
    int sum = 0;
    course cc[m];
    while (m > 0) {
        cout << "----- Course n0" << n - m << " ------\n";
        cout << "Enter the value of the credit: ";
        cin >> cc[n - m - 1].credit;
        cout << "Enter the value of the title: ";
        cin >> cc[n - m - 1].title;
        sum += cc[n - m - 1].credit;
        m--;
    }
    assert(sum == 30 && "Credit sum must be equal to 30");
    m = n - 1;
    cout << "\n-----------------Result-------------\n";
    while (m > 0) {
        cout << "\ncourse " << n - m << " title: " << cc[n - m - 1].title;
        cout << "\ncourse" << n - m << " credit: " << cc[n - m - 1].credit;
        m--;
    }
}
void
student_management()
{
    date dd;
    cout << "-------- Student management system --------\n\n";
    cout << "enter the year: ";
    cin >> dd.year;
    cout << "\nenter the month: ";
    cin >> dd.month;
    cout << "\nenter the day: ";
    cin >> dd.day;
    assert(dd.is_valid() && "the data you entered is not valid");
    dd.print();
    cout << "\n\n----- Create a new student ----- ";
    cout << "\n----> Enter his name: ";
    char name[20];
    cin >> name;
    cout << "\n----> Enter the surname: ";
    char surname[20];
    cin >> surname;
    cout << "\n----> Enter the address: ";
    char address[20];
    cin >> address;
    cout << "----> Enter the registration number: ";
    int reg = 0;
    cin >> reg;
    int m;
    cout << "enter the number 'm' of courses: ";
    cin >> m;
    assert(m > 6 && "m must be bigger than 6");
    assert(m < 15 && "m must be less than 15");
    int n = m + 1;
    course cc[m];
    while (m > 0) {
        cout << "----- Course n0" << n - m << " ------\n";
        cout << "Enter the value of the credit: ";
        cin >> cc[n - m - 1].credit;
        cout << "Enter the value of the title: ";
        cin >> cc[n - m - 1].title;
        cout << "Enter the value of the mark: ";
        cin >> cc[n - m - 1].mark;
        cout << "\n\n";
        m--;
    }
    student st = student(reg, name, surname, address, cc, dd);
    cout << "\n\n\n";
    cout << "Name: " << st.name << "\n";
    cout << "Surname: " << st.surname << "\n";
    cout << "Address: " << st.address << "\n";
    cout << "Registration number: " << st.registration_number << "\n";
    st.date_of_birth.print();
    cout << "do you wish to change students characteristics?y/n";
    string answer;
    cin >> answer;
    if (answer == "yes" || answer == "y") {
        change_characteristics(st);
    }
}
void
change_characteristics(student st)
{
    cout << "name>";
    cin >> st.name;
    cout << "surname>";
    cin >> st.surname;
    cout << "address>";
    cin >> st.address;
    cout << "Registration number>";
    cin >> st.registration_number;
    cout << "year of birth>";
    cin >> st.date_of_birth.year;
    cout << "month of birth>";
    cin >> st.date_of_birth.month;
    cout << "day of birth>";
    cin >> st.date_of_birth.day;
}
course *
marks_management_create()
{
    int m = 0;
    course *cc = new course();
    cout << "---- Course  marks management ----\n";
    cout << "Enter the number of courses\n";
    cin >> m;
    int n = m + 1;
    while (m) {
        cout << "Enter the title of the course number " << n - m << "\n";
        cin >> cc[n - m - 1].title;
        cout << "Enter the marks of the student in course number " << n - m
             << "\n";
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
        cout << "\n\n"
             << M_LENGHT - l + 1 << ".title: " << m[M_LENGHT - l].title
             << ", marks: " << m[M_LENGHT - l].mark << "\n";
        l--;
    }
}
course *
marks_management_modify(course *m, int j)
{
    cout << "new mark>";
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
    }
    return best;
}
int
marks_management_worst(course *m)
{
    int l = M_LENGHT;
    int worst = 0;
    while (l) {
        if (m[M_LENGHT - l].mark < worst) {
            worst = m[M_LENGHT - l].mark;
        }
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
    }
    return ab_av;
}
vector<student>
student_management_create()
{
    vector<student> all;
    cout << "enter the number of students";
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
        cout << "---- Student number ----" << m - n << "\n";
        cout << "Enter the name> ";
        cin >> name;
        cout << "Enter the surname> ";
        cin >> surname;
        cout << "Enter the registration number> ";
        cin >> reg_num;
        cout << "Enter the day of birth> ";
        cin >> dt.day;
        cout << "Enter the month of birth> ";
        cin >> dt.month;
        cout << "enter the year of birth> ";
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
    cout << "--- Displaying " << n << " students ----\n";
    int m = n;
    while (m) {
        cout << "Student number " << n - m + 1 << "\n";
        cout << "Name: " << v[n - m].name << "\n";
        cout << "Surame: " << v[n - m].surname << "\n";
        cout << "Address: " << v[n - m].address << "\n";
        v[n - m].date_of_birth.print();
        cout << "----  Courses  ----";
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
        cout << "Average of " << v[n - m].name << " " << v[n - m].surname
             << marks_management_av(v[n - m].course_marks);
    }
}
void
student_management_best(vector<student> v)
{
    int n = v.size();
    int m = n;
    while (m) {
        cout << "Best of " << v[n - m].name << " " << v[n - m].surname
             << marks_management_best(v[n - m].course_marks);
    }
}
void
student_management_worst(vector<student> v)
{
    int n = v.size();
    int m = n;
    while (m) {
        cout << "Worst of " << v[n - m].name << " " << v[n - m].surname
             << marks_management_worst(v[n - m].course_marks);
    }
}
