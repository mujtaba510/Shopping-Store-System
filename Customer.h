#pragma once
#include<iostream>
#include "User.h"
#include"Shopping_Cart.h"
//#include"Feedback.h"
using namespace std;
#include<fstream>
const char* customerfileName = "Customer.bin";

class customer:public user
{

private:
	ShoppingCart cart;
	Feedbacks* obj;
public:
	int c_counter;
	void displaymenue()
	{
		int c;
		bool flag = true;
		cout << "\n 1.LOGIN" << endl;
		cout << "\n 2.REGISTER" << endl;
		cout << "\nEnter your choice :";
		cin >> c;
		if (c == 1)
		{
			//bool s = false;
			system("cls");
			login();
			
			//break;
		}
		else if (c == 2)
		{
			system("cls");
			Register();
			
			//break;
		}
		while ((c != 1) && (c != 2))
		{
			cout << "\nYou entered an wrong input, Please enter your choice again : ";
			cin >> c;
			if (c == 1)
			{
				system("cls");
				login();
				
				break;
			}
			else if (c == 2)
			{
				system("cls");
				Register();
				
				
				break;
			}
			
		}
		
	}
	void login()
	{
		
		string name;
		string password;
		//customer cust;
		cout << "\nUserName :";
		cin >> name;
		cout << "\nPassword :";
		cin >> password;
		//strcpy_s(Name, 100, name.c_str());
		//strcpy_s(Password, 100, password.c_str());

		//strcpy_s(cust.Name, 100, name.c_str());
		//strcpy_s(cust.Password, 100, password.c_str());

		customer  temp;
		ifstream file(customerfileName, ios::binary); //ifstream is for reading
		
		bool flag = false;
		while (file.read((char*)&temp, sizeof(temp)))
		{
			
			if (strcmp(name.c_str(), temp.Name) == 0 && strcmp(password.c_str(), temp.Password) == 0)
			{
				cout << "\n    Login Successfully \n";
				
				flag = true;
				break;
			}
		}
		
		file.close();
		if (flag == false)
		{
			cout << "\nYou entered an wrong Username and Password.\n Please enter it again  ";
			login();
		}
		
		if (flag)
		{
			int d = 0;
			cout << "\n\n Now Press 2 to show Customer Menue :  ";
			cin >> d;
			if (d == 2)
			{
				DisplayCustomerMenue();

			}
		}
	}
	void Register()
	{
		//system("cls");
		string name;
		string password;
		string reEnterPassword;
		string phone;
		string gender;
		string address;
		string cnic;

		cout << "\nUserName :";
		cin >> name;
		cout << "\nGender :";
		cin >> gender;
		cout << "\nPhone Number :";
		cin >> phone;
		cout << "\nAddress :";
		cin >> address;

		cout << "\nEnter your CNIC ";
		cout << "\nInstruction about CNIC , Your CNIC number must contain 13 digits ";
		cout << "\nCNIC : ";
		cin >> cnic;
		int counter = 0;
		for (int i = 0; i < cnic.size(); i++)
		{
			++counter;
		}

		while (counter!=13)
		{
			counter = 0;
			cout << "\nYour CNIC is incorrect and first read the instructions carefully ";
			cout << "\n Please enter it again : ";
			cout << "\nCNIC :";
			cin >> cnic;
			for (int i = 0; i < cnic.size(); i++)
			{
				++counter;
			}
		}

		cout << "\n Enter Your Password \n Instruction about password , Your password must be of 9 characters and it must contain one uppercase letter and one digit ";
		cout << "\nPassword :";
		cin >> password;
		cout << "\n ReEnter Password :";
		cin >> reEnterPassword;
		int count = 0;

		for (int i = 0; i < password.size(); i++)
		{
			++count;
		}
		//cout << count << endl;

		int ASCII = 0;
		bool check1 = false, check2 = false;

		for (int i = 0; i < password.size(); i++)
		{
			ASCII = int(password[i]);
			if (ASCII >= 65 && ASCII <= 90)
			{
				//cout << "alphabhet";
				check1 = true;
			}
			if (ASCII >= 48 && ASCII <= 57)
			{
				//cout << "digit";
				check2 = true;

			}
		}




		//cout << strcmp(password.c_str(), reEnterPassword.c_str()) << endl << "count:" << count << " Check1:" << check1 << " Check2:" << check2 << endl;
		while (strcmp(password.c_str(), reEnterPassword.c_str()) != 0 || count < 9 || check1 == 0 || check2 == 0)
		{
			//cout << strcmp(password.c_str(), reEnterPassword.c_str()) << endl << "count:" << count << " Check1:" << check1 << " Check2:" << check2 << endl;
			cout << "\nYour Password is incorrect ";
			cout << "\nPlease enter your password again and first read the instructions carefully : ";
			cout << "\nPassword :";
			cin >> password;
			cout << "\n ReEnter Password :";
			cin >> reEnterPassword;
			count = 0;

			for (int i = 0; i < password.size(); i++)
			{
				++count;
			}
			//cout << count << endl;

			int ASCII = 0;
			check1 = false;
			check2 = false;

			for (int i = 0; i < password.size(); i++)
			{
				ASCII = int(password[i]);
				if (ASCII >= 65 && ASCII <= 90)
				{
					//cout << "**************check1****************" << endl;
					check1 = true;
				}
				if (ASCII >= 48 && ASCII <= 57)
				{
					//cout << "digit";
					check2 = true;

				}
			}

			//cout << strcmp(password.c_str(), reEnterPassword.c_str()) << endl << "count:" << count << " Check1:" << check1 << " Check2:" << check2 << endl;
			/*if (strcmp(password.c_str(), reEnterPassword.c_str()) == 1 || count < 9 || check1 == 0 || check2 == 0)
			{
				break;
			}*/
		}
		/*strcpy_s(Name, 100, name.c_str());
		strcpy_s(Phone, 100, phone.c_str());
		strcpy_s(Address, 100, address.c_str());
		strcpy_s(Gender, 100, gender.c_str());
		strcpy_s(Password, 100, password.c_str());*/

		customer cust;
		strcpy_s(cust.Cnic, 100, cnic.c_str());
		strcpy_s(cust.Name, 100, name.c_str());
		strcpy_s(cust.Phone, 100, phone.c_str());
		strcpy_s(cust.Address, 100, address.c_str());
		strcpy_s(cust.Gender, 100, gender.c_str());
		strcpy_s(cust.Password, 100, password.c_str());

		customer  temp;
		ifstream file(customerfileName, ios::binary); //ifstream is for reading

		bool flag = true;
		while (file.read((char*)&temp, sizeof(temp)))
		{

			if (strcmp(name.c_str(), temp.Name) == 0 && strcmp(password.c_str(), temp.Password) == 0)
			{
				flag = false;
				break;
			}
		}

		file.close();

		if (flag == false)
		{
			cout << "\n You entered an wrong information, this account is already registered. \n Please enter your information correctly ;\n";
			Register();
		}
		if (flag == true)
		{
			ofstream file(customerfileName, ios::binary | ios::app); //ofstream is for writing
			file.write((char*)&cust, sizeof(cust));
			file.close();

			cout << "\n   Customer Registered Successfully \n";
		}

		int t = 0;
		cout << "\n Now Press 1. to login as an Customer : ";
		cin >> t;
		if (t == 1)
		{
			login();
		}

		while (t != 1)
		{
			cout << "\n  Please Press 1. to login as an Customer : ";
			cin >> t;
			if (t == 1)
			{
				login();
			}

		}
	}

	void DisplayCustomerMenue()
	{
		system("cls");
		cout << "\n  ***** WELCOME TO Customer Menue Screen  *****\n";
		int menue;
		
		cout << "\n\n 1. Search and Buy Items ";
		cout << "\n\n 2. Log Out";

		cout << "\n\n Enter Your Choice : ";
		cin >> menue;

		if (menue == 1)
		{
			cart.Search_Buy_Products();
			int n = 0;
			cout << "\n\n Press 1 to Go Back to Customer menue  ";
			cout << "\n Press 2 to give Feedback  ";
			cout << "\n\n Enter your choice : ";
			cin >> n;
			if (n == 1)
			{
				DisplayCustomerMenue();
			}

			else
			{
				obj->give_feedback();
				cout << "\n\n  Enter any number to Go Back to Customer menue : ";
				cin >> n;
				DisplayCustomerMenue();
			}

		}

		else if (menue==2)
		{
			system("cls");
			displaymenue();
		}
	}
};
