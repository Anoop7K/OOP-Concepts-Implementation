// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;

class delivery
{
    private:
        string cart_details;
        int num_of_items;
    public:
        string category;
        bool availability;

        void carts_info(string s,int i){
            cart_details = s;
            num_of_items = i;
            cout<<"Cart details "<<cart_details<<endl;
            cout<<"Number of items "<<num_of_items<<endl;
        }
    protected:
        int num_of_login,sub_price;
};

class swi : public delivery
{
    public:
        void set_det(int n,int p){
            num_of_login = n;
            sub_price = p;
            cout<<"Number of logins = "<<num_of_login<<endl;
            cout<<"subsription price = "<<sub_price<<endl;
        }
};

int main() {
    // Write C++ code here
    delivery obj;
    swi obj1;
    string s,c;
    int i,l,p;
    bool a;
    cout<<"Enter the cart details"<<endl;
    cin>>s;
    cout<<"Enter the number of items"<<endl;
    cin>>i;
    cout<<"The category"<<endl;
    cin>>obj.category;
    cout<<"The availability"<<endl;
    cin>>obj.availability;
    cout<<"Enter the number of logins"<<endl;
    cin>>l;
    cout<<"Enter the subscription price"<<endl;
    cin>>p;

    cout<<"Full Cart details"<<endl;
    obj.carts_info(s,i);
    cout<<"Login and subscriptions"<<endl;
    obj1.set_det(l,p);

    return 0;
}
