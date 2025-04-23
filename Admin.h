#pragma once

#include<iostream>
#include<fstream>
#include "User.h"
#include "Manager.h"
#include"Catalog.h";
//#include "Feedback.h"
using namespace std;
const char* fileName = "Admin.bin";
const char* FeedbacksfileName = "Feedbacks.bin";
//#include"Feedback.h"

class Feedbacks
{
private:
	char Str[100];
	int num;
public:
	
	void give_feedback()
	{
		string str;
		int number;
		cout << "\n\nEnter any number that reprsent your feedback : ";
		cin >> number;
		cout << "\n\n Now Enter Your Feedback  : ";

		//bool flag = false;

		cin >> str;

		Feedbacks f;

		strcpy_s(f.Str, 100, str.c_str());
		f.num = number;

		ofstream file2(FeedbacksfileName, ios::binary | ios::app); //ofstream is for writing
		file2.write((char*)&f, sizeof(f));
		file2.close();
	}

	void ShowFeedbacks()
	{
		Feedbacks temp;
		ifstream file2(FeedbacksfileName, ios::binary); //ifstream is for reading
		cout << "\n\n";
		while (file2.read((char*)&temp, sizeof(temp)))
		{
			cout << " " << temp.num << ". " << temp.Str << endl;
		}

		file2.close();

	}

	void DeleteFeedbacks()
	{
		system("cls");
		ShowFeedbacks();

		int I = 0;
		cout << "\n Enter ID of that customer Feedback that you want to delete  ";
		cout << "\n ID = ";
		cin >> I;

		Feedbacks temp;
		fstream file2(FeedbacksfileName, ios::in | ios::out | ios::binary);
		ofstream myFile_temp("temp.bin", ios::app | ios::binary);
		while (file2.read((char*)&temp, sizeof(temp))) {
			if (temp.num != I) {
				myFile_temp.write((char*)&temp, sizeof(temp));
			}
		}
		file2.close();
		myFile_temp.close();
		remove(FeedbacksfileName);
		rename("temp.bin", FeedbacksfileName);

		system("cls");
		ShowFeedbacks();
	}
};

class admin :public user
{
private:
	manager m;
	catalog c;
	//Feedbacks four;
public:
	//manager m;
	
	/*void Managerdisplaymenue()
	{
		m.displaymenue();
	}*/
	void displaymenue()          //display menu of admin
	{

		int c;
		bool flag = true;

		cout << "\n 1.LOGIN" << endl;
		cout << "\n 2.REGISTER" << endl;
		cout << "\nEnter your choice :";
		cin >> c;
		if (c == 1)
		{
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
	
	void login()                    //login function for admin
	{
		//system("cls");
		string name;
		string password;
		//admin Admin;
		//int e = 0;
		//int n = 0;
		cout << "\nUserName :";
		cin >> name;
		cout << "\nPassword :";
		cin >> password;

		admin  temp;
		ifstream file(fileName, ios::binary); //ifstream is for reading
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
			cout << "\nYou entered an wrong Username and Password.\n Please enter it again  ";
			login();
		}

		/*strcpy_s(Name,100, name.c_str());
		strcpy_s(Password,100, password.c_str());

		strcpy_s(Admin.Name, 100, name.c_str());
		strcpy_s(Admin.Password, password.c_str());*/

		int d = 0;
		cout << "\n Press 1 if you want to register new manager :";
		cout << "\n Press 2 if you don't want to register manager : \n";
		cout << "\n  Enter Your Choice :";
		cin >> d;

		if (d == 1)
		{
			system("cls");
			m.RegisterManager();
			cout << "\n\n Now Press 2 to show admin menue ";
			cin >> d;
		}
	    if ( d== 2)
		{
			DisplayAdminMenue();

		}
		while (d != 1 && d != 2)
		{
			cout << "\n You entered an wrong input  ";
			cout << "\n Press 1 if you want to register new manager  ";
			cout << "\n Press 2 if you don't want to register manager  ";
			cout << "\nEnter Your Choice :";
			cin >> d;
			if (d == 1)
			{
				system("cls");
				m.RegisterManager();
				break;
			}
			else if (d == 2)
			{
				DisplayAdminMenue();
			}
		}
		
		
	}
	void Register()                     //Registration for admin
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
				break;
			}
		}

		for (int i = 0; i < password.size(); i++)
		{
			ASCII = int(password[i]);
			if (ASCII >= 48 && ASCII <= 57)
			{
				//cout << "digit";
				check2 = true;
				break;
			}
		}

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

			for (int i = 0; i < password.size(); i++)         //checker for password
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



		/*strcpy_s(Name,100, name.c_str());
		strcpy_s(Phone,100, phone.c_str());
		strcpy_s(Address, 100, address.c_str());
		strcpy_s(Gender, 100, gender.c_str());
		strcpy_s(Password,100, password.c_str());*/

		admin Admin;
		strcpy_s(Admin.Cnic, 100, cnic.c_str());
		strcpy_s(Admin.Name, 100, name.c_str());
		strcpy_s(Admin.Phone, 100, phone.c_str());
		strcpy_s(Admin.Address, 100, address.c_str());
		strcpy_s(Admin.Gender, 100, gender.c_str());
		strcpy_s(Admin.Password, 100, password.c_str());

		admin temp;
		ifstream file(fileName, ios::binary); //ifstream is for reading

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

		else if(flag == true)
		{
			ofstream file(fileName, ios::binary | ios::app); //ofstream is for writing
			file.write((char*)&Admin, sizeof(Admin));
			file.close();
		}
		cout << "\n   Admin Registered Successfully \n";

		int t = 0;
		cout << "\n Now Press 1. to login as an admin : ";
		cin >> t;
		if (t == 1)
		{
			login();
		}

		while (t != 1)
		{
			cout << "\n  Please Press 1. to login as an admin : ";
			cin >> t;
			if (t == 1)
			{
				login();
			}

		}

		//int n = 0;
		//cout << "\n Press 1 if you want to register new manager :";
		//cout << "\n Press 2 if you don't want to register manager : \n";
		//cout << "Enter Your Choice :";
		//cin >> n;

		//if (n == 1)
		//{
		//	m.RegisterManager();
		//}
		//else if (n == 2)
		//{
		//	return;
		//}
		//while (n != 1 && n != 2)
		//{
		//	cout << "\n You entered an wrong input Please press 1 to register a new manager :";
		//	cout << "\n Press 2 if you don't want to register manager : ";
		//	cout << "\nEnter Your Choice :";
		//	cin >> n;
		//	if (n == 1)
		//	{
		//		m.RegisterManager();
		//		break;
		//	}
		//	else if (n == 2)
		//	{
		//		return;
		//	}
		//}
	}

	void DisplayAdminMenue()
	{
		system("cls");
		cout << "\n  ***** WELCOME TO Admin Menue Screen  *****\n";
		int menue;
		cout << "\n 1. Add Products ";
		cout << "\n 2. Edit Products ";
		cout << "\n 3. Delete Products ";
		cout << "\n 4. Show Products ";
		cout << "\n 5. Show Feedbacks ";
		cout << "\n 6. Delete Feedbacks ";
		cout << "\n 7. Log Out";

		cout << "\n Enter Your Choice : ";
		cin >> menue;

		if (menue == 1)
		{
			c.AddProducts();
			
			DisplayAdminMenue();
		}
		else if (menue == 2)
		{
			c.Edit_Products();
			int n = 0;
			cout << "\n Press 1 to Go Back to Admin menue : ";
			cin >> n;
			DisplayAdminMenue();
		}
		else if (menue == 3)
		{
			c.Delete_Products();
			int n = 0;
			cout << "\n Press 1 to Go Back to Admin menue : ";
			cin >> n;
			DisplayAdminMenue();
		}
		else if (menue == 4)
		{
			c.Show_Catalog();
			int n = 0;
			cout << "\n Press 1 to Go Back to Admin menue : ";
			cin >> n;
			DisplayAdminMenue();
		}
		else if (menue == 7)
		{
			system("cls");
			displaymenue();
		}

		else if (menue == 5)
		{
			system("cls");
			Feedbacks four;
			four.ShowFeedbacks();
			int n = 0;
			cout << "\n Press 1 to Go Back to Admin menue : ";
			cin >> n;
			DisplayAdminMenue();
		}

		else if (menue == 6)
		{
			Feedbacks four;
			four.DeleteFeedbacks();
			int n = 0;
			cout << "\n Press 1 to Go Back to Admin menue : ";
			cin >> n;
			DisplayAdminMenue();
		}
	}

	

	//void RegisterManager()
	//{
	//	//manager m;
	//	//system("cls");
	//	string name;
	//	string password;
	//	string reEnterPassword;
	//	string phone;
	//	string gender;
	//	string address;

	//	cout << "\nUserName :";
	//	cin >> name;
	//	cout << "\nGender :";
	//	cin >> gender;
	//	cout << "\nPhone Number :";
	//	cin >> phone;
	//	cout << "\nAddress :";
	//	cin >> address;

	//	cout << "\nEnter your CNIC ";
	//	cout << "\nInstruction about CNIC , Your CNIC number must contain 13 digits ";
	//	cout << "\nCNIC : ";
	//	cin >> cnic;

	//	while (cnic <= 999999999999 || cnic > 9999999999999)
	//	{
	//		cout << "\nYour CNIC is incorrect and first read the instructions carefully ";
	//		cout << "\n Please enter it again : ";
	//		cout << "\nCNIC :";
	//		cin >> cnic;
	//	}

	//	cout << "\n Enter Your Password \n Instruction about password , Your password must be of 9 characters and it must contain one uppercase letter and one digit ";
	//	cout << "\nPassword :";
	//	cin >> password;
	//	cout << "\n ReEnter Password :";
	//	cin >> reEnterPassword;
	//	int count = 0;

	//	for (int i = 0; i < password.size(); i++)
	//	{
	//		++count;
	//	}
	//	//cout << count << endl;

	//	int ASCII = 0;
	//	bool check1 = false, check2 = false;

	//	for (int i = 0; i < password.size(); i++)
	//	{
	//		ASCII = int(password[i]);
	//		if (ASCII >= 65 && ASCII <= 90)
	//		{
	//			//cout << "alphabhet";
	//			check1 = true;
	//		}
	//		if (ASCII >= 48 && ASCII <= 57)
	//		{
	//			//cout << "digit";
	//			check2 = true;

	//		}
	//	}




	//	//cout << strcmp(password.c_str(), reEnterPassword.c_str()) << endl << "count:" << count << " Check1:" << check1 << " Check2:" << check2 << endl;
	//	while (strcmp(password.c_str(), reEnterPassword.c_str()) == 1 || count < 9 || check1 == 0 || check2 == 0)
	//	{
	//		//cout << strcmp(password.c_str(), reEnterPassword.c_str()) << endl << "count:" << count << " Check1:" << check1 << " Check2:" << check2 << endl;
	//		cout << "\nYour Password is incorrect ";
	//		cout << "\nPlease enter your password again and first read the instructions carefully : ";
	//		cout << "\nPassword :";
	//		cin >> password;
	//		cout << "\n ReEnter Password :";
	//		cin >> reEnterPassword;
	//		count = 0;

	//		for (int i = 0; i < password.size(); i++)
	//		{
	//			++count;
	//		}
	//		//cout << count << endl;

	//		int ASCII = 0;
	//		check1 = false;
	//		check2 = false;

	//		for (int i = 0; i < password.size(); i++)
	//		{
	//			ASCII = int(password[i]);
	//			if (ASCII >= 65 && ASCII <= 90)
	//			{
	//				//cout << "**************check1****************" << endl;
	//				check1 = true;
	//			}
	//			if (ASCII >= 48 && ASCII <= 57)
	//			{
	//				//cout << "digit";
	//				check2 = true;

	//			}
	//		}
	//		/*if (strcmp(password.c_str(), reEnterPassword.c_str()) == 1 || count < 9 || check1 == 0 || check2 == 0)
	//		{
	//			break;
	//		}*/
	//	}
	//	//cout << "\n password is correct ";

	//	/*strcpy_s(Name, 100, name.c_str());
	//	strcpy_s(Phone, 100, phone.c_str());
	//	strcpy_s(Address, 100, address.c_str());
	//	strcpy_s(Gender, 100, gender.c_str());
	//	strcpy_s(Password, 100, password.c_str());*/

	//	admin m;
	//	m.cnic = cnic;
	//	strcpy_s(m.Name, 100, name.c_str());
	//	strcpy_s(m.Phone, 100, phone.c_str());
	//	strcpy_s(m.Address, 100, address.c_str());
	//	strcpy_s(m.Gender, 100, gender.c_str());
	//	strcpy_s(m.Password, 100, password.c_str());

	//	ifstream file(mangfileName, ios::binary); //ifstream is for reading

	//	bool flag = true;
	//	admin temp;
	//	while (file.read((char*)&temp, sizeof(temp)))
	//	{

	//		if (strcmp(name.c_str(), temp.Name) == 0 && strcmp(password.c_str(), temp.Password) == 0)
	//		{
	//			flag = false;
	//			break;
	//		}
	//	}

	//	file.close();

	//	if (flag == false)
	//	{
	//		cout << "\n You entered an wrong information, this account is already registered. \n Please enter your information correctly ;\n";
	//		Register();
	//	}

	//	else if (flag == true)
	//	{

	//		ofstream file(mangfileName, ios::binary | ios::app); //ofstream is for writing
	//		file.write((char*)&m, sizeof(m));
	//		file.close();
	//	}
	//	cout << "\n   Manager Registered Successfully ";


	//	//strcpy_s(m.Name, 100, name.c_str());
	//	//strcpy_s(m.Phone, phone.c_str());
	//	//strcpy_s(m.Address, address.c_str());
	//	//strcpy_s(m.Gender, gender.c_str());
	//	//strcpy_s(m.Password, password.c_str());
	//}
	//void insertObject() 
	//{
	//	ofstream myFile(fileName, ios::binary | ios::app);
	//	if (myFile.write((char*)this, sizeof(this)))
	//		cout << "Object Successfully Inserted!" << endl;
	//	else
	//		cout << "Object Insertion Failed" << endl;
	//	myFile.close();
	//}
};