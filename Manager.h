#pragma once
#include<iostream>

#include "User.h"
//#include"Catalog.h"
#include"Inventory.h"

using namespace std;
#include<fstream>
const char* mangfileName = "Manager.bin";

class manager:public user
{
private:
	inventory i;
	
public:
	
	void displaymenue()                      //Menue for manager
	{
		int c;
		bool flag = true;
		cout << "\n 1.LOGIN" << endl;
		//cout << "\n 2.REGISTER" << endl;
		cout << "\nEnter your choice :";
		cin >> c;
		if (c == 1)
		{
			system("cls");
			login();
			
			//break;
		}
		//else if (c == 2)
		//{
		//	Register();
		//	//break;
		//}
		while ((c != 1) )
		{
			cout << "\nYou entered an wrong input, Please enter your choice again : ";
			cin >> c;
			if (c == 1)
			{
				system("cls");
				login();
				
				break;
			}
			

		}

	}
	void login()            //login of manager
	{ 
		//system("cls");
		//manager m;
		string name;
		string password;
		cout << "\nUserName :";
		cin >> name;
		cout << "\nPassword :";
		cin >> password;

		manager  temp;
		ifstream file(mangfileName, ios::binary); //ifstream is for reading
		//cout << "\nHi";
		bool flag = false;
		while (file.read((char*)&temp, sizeof(temp)))
		{
			//cout << "\n ***************************** \n";
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
			cout << "\nYou entered a wrong Username and Password.\n Please enter it again  ";
			login();
		}
		/*strcpy_s(Name, 100, name.c_str());
		strcpy_s(Password, 100, password.c_str());

		strcpy_s(m.Name, 100, name.c_str());
		strcpy_s(m.Password,100, password.c_str());*/
		if (flag)
		{
			cout << "\n\n1. Islamabad Store  ";
			cout << "\n2. Lahore Store  ";
			cout << "\n3. Karachi Store  ";
			cout << "\n\n Enter your choice : ";
			int store = 0;
			cin >> store;
			int d = 0;
			cout << "\n\n Now Press 2 to show Manager Menue :  ";
			cin >> d;
			if (d == 2)
			{
				DisplayManagerMenue();

			}
		}
	}
	
	void RegisterManager()                 //Manager registration through admin
	{
		//manager m;
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

		while (counter != 13)
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
			/*if (strcmp(password.c_str(), reEnterPassword.c_str()) == 1 || count < 9 || check1 == 0 || check2 == 0)
			{
				break;
			}*/
		}
		//cout << "\n password is correct ";

		/*strcpy_s(Name, 100, name.c_str());
		strcpy_s(Phone, 100, phone.c_str());
		strcpy_s(Address, 100, address.c_str());
		strcpy_s(Gender, 100, gender.c_str());
		strcpy_s(Password, 100, password.c_str());*/

		manager ma;
		strcpy_s(ma.Cnic, 100, cnic.c_str());
		strcpy_s(ma.Name, 100, name.c_str());
		strcpy_s(ma.Phone, 100, phone.c_str());
		strcpy_s(ma.Address, 100, address.c_str());
		strcpy_s(ma.Gender, 100, gender.c_str());
		strcpy_s(ma.Password, 100, password.c_str());

		ifstream file(mangfileName, ios::binary); //ifstream is for reading

		bool flag = true;
		manager temp;
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
			RegisterManager();
		}

		else if (flag == true)
		{

			ofstream file(mangfileName, ios::binary | ios::app); //ofstream is for writing
			file.write((char*)&ma, sizeof(ma));
			file.close();
		}
		cout << "\n   Manager Registered Successfully ";


		//strcpy_s(m.Name, 100, name.c_str());
		//strcpy_s(m.Phone, phone.c_str());
		//strcpy_s(m.Address, address.c_str());
		//strcpy_s(m.Gender, gender.c_str());
		//strcpy_s(m.Password, password.c_str());
	}

	void DisplayManagerMenue()           //main menue of manager
	{

		
		system("cls");
		cout << "\n  ***** WELCOME TO Manager Menue Screen  *****\n";
		int menue;
		cout << "\n 1. p_file ";
		cout << "\n 2. Add quantities ";
		cout << "\n 3. Add items ";
		cout << "\n 4. Edit items ";                //calling diffrent functions
		cout << "\n 5. Delete items ";
		cout << "\n 6. Show All Inventory ";
		cout << "\n 7. Log Out";

		cout << "\n Enter Your Choice : ";
		cin >> menue;

		if (menue == 1)
		{
			i.p_file();
			int n = 0;
			cout << "\n Press 1 to Go Back to Manager menue : ";
			cin >> n;
			DisplayManagerMenue();
		}
		else if (menue == 2)
		{
			i.AddQuantities();
			DisplayManagerMenue();
		}

		else if (menue == 3)
		{
			i.AddItems();
			DisplayManagerMenue();
		}
		else if (menue == 4)
		{
			i.EditItems();
			int n = 0;
			cout << "\n Press 1 to Go Back to Manager menue : ";
			cin >> n;
			DisplayManagerMenue();
		}
		else if (menue == 5)
		{
			i.DeleteItems();
			int n = 0;
			cout << "\n Press 1 to Go Back to Manager menue : ";
			cin >> n;
			DisplayManagerMenue();
		}
		else if (menue == 6)
		{
			i.ShowItems();
			int n = 0;
			cout << "\n Press 1 to Go Back to Manager menue : ";
			cin >> n;
			DisplayManagerMenue();
		}
		else if (menue == 7)
		{
			system("cls");
			displaymenue();
		}
		

		


	}

	//void insertObject() {
	//	ofstream myFile(mangfileName, ios::binary | ios::app);
	//	if (myFile.write((char*)this, sizeof(this)))
	//		cout << "Object Successfully Inserted!" << endl;
	//	else
	//		cout << "Object Insertion Failed" << endl;
	//	myFile.close();
	//}

};


