#pragma once
#include<iostream>
using namespace std;
class user
{
protected:
	char Name[100];
	char Password[100];
	char Cnic[100];
	char Phone[100];
	char Gender[100];
	char Address[100];
public:

	virtual void displaymenue()
	{
		cout << "Menue";
	}

	void setCnic(char *n)
	{
		strcpy_s(Cnic, n);
	}
	void setName(char* n)
	{
		strcpy_s(Name, n);
	}
	void setPassword(char* p)
	{
		strcpy_s(Password, p);
	}
	void setPhone(char* n)
	{
		strcpy_s(Phone, n);
	}
	void setGender(char* p)
	{
		strcpy_s(Gender, p);
	}

	void setAddress(char* p)
	{
		strcpy_s(Address, p);
	}

	char* getName()
	{
        return Name;
    }
	char* getPassword()
	{
		return Password;
	}
	char* getPhone()
	{
		return Phone;
	}
	char* getAddress()
	{
		return Address;
	}
	char* getGender()
	{
		return Gender;
	}

	char* getcnic()
	{
		return Cnic;
	}
};