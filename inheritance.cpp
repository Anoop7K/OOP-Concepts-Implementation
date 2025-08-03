#include<iostream>
using namespace std;

class player
{
    char name[10];
    int id;
public:
    void details()
    {
        cout<<"Enter the name\n";
        cin>>name;
        cout<<"Enter the id\n";
        cin>>id;
    }
    void display_p()
    {
        cout<<name<<"\t"<<id<<endl;
    }
};

class stud:private player
{
    int marks;
public:
    void det()
    {
        cout<<"Enter the marks\n";
        cin>>marks;
    }
    void display_s()
    {
        cout<<marks<<endl;
    }
};
int main()
{
    player p;
    stud s;
    p.details();
    p.display_p();
    s.det();
    s.display_s();
    return 0;
}
