#include<iostream>
#include"Admin.h"
#include"Manager.h"
#include"Customer.h"

using namespace std;


int main()
{
    //user* u1 = new admin;
    //user* u2 = new customer;
    admin a1;
    customer c1;
    manager m1;

    int a;
    cout << "\n  ***** WELCOME TO Grocery Store *****\n";
    cout << endl;
    cout << endl;
    cout << "        ***MAIN MENU***\n";
    cout << endl;
    cout << "  Press 1 to enter as an Admin\n";
    cout << "  Press 2 to enter as a  Manager\n";
    cout << "  Press 3 to enter as a  Customer\n";
    cin >> a;

    if (a == 1)
    {
        user* u = &a1;
        u->displaymenue();
        //a1.displaymenue();
       // a1.insertObject();
    }
    else if (a == 2)
    {
        user* u = &m1;
        u->displaymenue();
        //m1.displaymenue();
        //m1.insertObject();
    }
    else
    {
        user* u = &c1;
        u->displaymenue();
        //c1.displaymenue();
        //c1.insertObject();
        //cout << "\n Hello ";
    }

    

}
