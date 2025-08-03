#include<iostream>
using namespace std;

int add(int a,int b)
{
    cout<<"The sum is "<<a+b<<endl;
    return a+b;
}

double add(double a,double b)
{
    cout<<"The sum of floating point number is "<<a+b<<endl;
    return a+b;
}

int main()
{
    int x,z;
    double y;

    x=add(5,10);
    y=add(7.7,10.5);
    z=add(3.3,6.9);

    return 0;
}
