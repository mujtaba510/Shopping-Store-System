#pragma once
#include<iostream>
#include"Customer.h"
#include"Shopping_Cart.h"
using namespace std;

class payment
{
public:
	virtual void Payment(int UpdatedBill)
	{
		cout << "Payment";
	}
};

class COD :public payment
{
public:
	
	void Payment(int UpdatedBill)
	{
		int m;
		cout << "\n\n 1. COD is in the same city  ";
		cout << "\n 2. COD is in the diffrent city  ";
		cout << "\n\n Enter Your Choice : ";
		cin >> m;

		if (m == 1)
		{
			UpdatedBill += 30;
			cout << "\n\n As you are paying your bill at delivery in the same city, So we are adding charges of 30Rs. in your bill \n ";
			cout << "\n So Your Updated Total Bill is : ";
			cout << UpdatedBill;
			cout << "\n\n Payment Paid Sucessfully ";
			return;
		}

		else
		{
			UpdatedBill += 50;
			cout << "\n\n As you are paying your bill at delivery in Diffrent City, So we are adding charges of 50Rs. in your bill \n ";
			cout << "\n So Your Updated Total Bill is : ";
			cout << UpdatedBill;

			cout << "\n\n Payment Paid Sucessfully ";
			return;
		}
	}
	
};

class CreditCard :public payment
{
public:
	void Payment(int UpdatedBill)
	{
		cout << "\n\n "<< UpdatedBill<<"Rs. Paid Sucessfully ";
		return;
	}
};

class EasyPaisa :public payment
{
public:
	void Payment(int UpdatedBill)
	{
		cout << "\n\n " << UpdatedBill << "Rs. Paid Sucessfully ";
		return;
	}
};

class JazzCash :public payment
{
public:
	void Payment(int UpdatedBill)
	{
		cout << "\n\n " << UpdatedBill << "Rs. Paid Sucessfully ";
		return;
	}
};

