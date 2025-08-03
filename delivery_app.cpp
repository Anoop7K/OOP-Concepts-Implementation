#include <iostream>
#include <string>
using namespace std;

// Delivery App Class
class delivery_app
{
private:
    string customer;
    int items;
public:
    int price;
    bool availability;

    delivery_app()
    {
        cout << "Customer name? \n";
        getline(cin, customer);

        cout << "Number of items? \n";
        while (!(cin >> items) || items < 0)
        {
            cout << "Enter a valid number of items: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Price? \n";
        while (!(cin >> price) || price < 0)
        {
            cout << "Enter a valid price: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Available? (1 for Yes, 0 for No) \n";
        while (!(cin >> availability))
        {
            cout << "Enter 1 (Yes) or 0 (No): ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore(); // clear trailing newline.
    }

    void display()
    {
        cout << "Name: " << customer << "\n" << items << " items" << endl;
        cout << "Rs " << price << endl;
        cout << (availability ? "Product is available \n" : "Product not available \n");
    }
};

// Inherited Deliver Class
class deliver : public delivery_app
{
private:
    string address;
    int distance;
protected:
    int numlogins;

public:
    deliver()
    {
        cout << "Enter the address? \n";
        cin.ignore(); // Skip any leftover '\n'
        getline(cin, address);

        cout << "Enter the distance to reach the destination: \n";
        while (!(cin >> distance) || distance < 0)
        {
            cout << "Enter valid distance: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore(); // clear trailing newline.
    }

    void print()
    {
        display();
        cout << "Address: " << address << endl;
        cout << distance << " kilometers" << endl;
    }

    ~deliver()
    {
        cout << "Can't be delivered \n";
    }
};

// Multilevel: Rating class inherits Deliver
class rating : public deliver
{
private:
    int customer_rating;
    bool satisfactory;

protected:
    string app_name;

public:
    void review()
    {
        cout << "Enter the number of logins? \n";
        while (!(cin >> numlogins) || numlogins < 0)
        {
            cout << "Enter a valid number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore();

        try
        {
            cout << "What is the customer rating? \n";
            if (!(cin >> customer_rating) || customer_rating < 0 || customer_rating > 5)
            {
                throw "Invalid Input: You can only input a numeric value (0-5) for customer rating";
            }
        }
        catch (const char *e)
        {
            cout << e << endl;
            exit(1);
        }

        cout << "Was the experience satisfactory? (1 for Yes, 0 for No) \n";
        while (!(cin >> satisfactory))
        {
            cout << "Enter 1 (Yes) or 0 (No): ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore();

        cout << "App name? \n";
        getline(cin, app_name);
    }

    void show()
    {
        print();
        cout << numlogins << " logins"
             << "\n"
             << customer_rating << " rating" << endl;
        cout << (satisfactory ? "Yes very satisfied!!! \n" : "Not satisfied!!! \n");
    }

    ~rating()
    {
        cout << "No activity \n";
    }

    friend void app_name_comments(rating &r);
};

void app_name_comments(rating &r)
{
    cout << "The App name is: " << r.app_name << "\n";
}

class lastpart
{
protected:
    bool instamart;

public:
    virtual void last()
    {
        // Adding a default behavior so this is not a pure virtual base class.
        cout << "Default lastpart::last() \n";
    }
};

class endclass : public lastpart
{
public:
    endclass()
    {
        cout << "Is Instamart active? (1 for Yes, 0 for No): ";
        while (!(cin >> instamart))
        {
            cout << "Enter 1 (Yes) or 0 (No): ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore();
    }

    void last() override
    {
        if (instamart)
            cout << "You cannot be a part of Swiggy Instamart  \n";
        else
            cout << "You can be a part of Swiggy Instamart \n";
    }
};

int main()
{
    rating obj_1;
    obj_1.review();
    obj_1.show();
    app_name_comments(obj_1);

    lastpart *ptr = new endclass();
    ptr->last();
    delete ptr;

    return 0;
}
