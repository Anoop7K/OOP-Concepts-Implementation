#include<iostream>
using namespace std;

class complexnum
{
private:
    int real;
    int img;

public:
    complexnum(int r=0,int i=0)
    {
        real = r;
        img = i;
        cout<<"Real part "<<real<<endl;
        cout<<"Imaginary part "<<img<<endl;
    }

    complexnum operator+(complexnum const& c)

    {
        complexnum ret;
        ret.real = real + c.real;
        ret.img = img + c.img;
        return ret;
    }

    void display()
    {
        cout<<real<<"+"<<img<<"i"<<endl;
    }
};

int main()
{
    complexnum c1(3,5) , c2(7,2);
    complexnum c3 = c1+c2;
    c3.display();

    return 0;
}
