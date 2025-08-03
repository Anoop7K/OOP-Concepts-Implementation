#include<iostream>
using namespace std;

class Student
{
private:
    int marks;
    string USN;
public:
    Student(string OUSN)
    {
        USN = OUSN;
        cout<<"Student "<<USN<<"is created"<<endl;
    }

    ~Student()
    {
        cout<<"Student "<<USN<<"is deleted"<<endl;
    }

    void readmarks()
    {
        cout << "Enter the marks for student " << USN << ":" << endl;
        cin >> marks;
    }
    void showmarks()
    {
        cout<<"Student "<<USN<<"marks are: "<<USN<<"\t"<<marks<<endl;
    }
};

int main()
{
    int n;
    string stud;
    cout<<"Enter the student's USN"<<endl;
    cin>>stud;

    Student students(stud);

    //Student students[5] = {Student(stud[0]), Student(stud[1]), Student(stud[2]), Student(stud[3]), Student(stud[4])};
    students.readmarks();
    students.showmarks();

    return 0;
}
