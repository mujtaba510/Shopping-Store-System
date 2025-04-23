#pragma once
#include<iostream>
#include"Customer.h"
#include"Inventory.h"
#include"Catalog.h"
#include"Payment.h"
using namespace std;
const char* CartfileName = "ShoppingCart.bin";

class ShoppingCart
{
private:
	
	int ID;
	int Quantity;
	//inventory i;
	char name[100];
	int Each_item_price;
	int TotalBill = 0;
	int discount;
	int count=3;
	//string f;
public:
	
	void Show_Inventory()
	{
		system("cls");
		cout << "\n ID\t\tCategory\tProduct\t\tUnits\t\tPrices\t\tQuantity\n ";
		cout << "---------------------------------------------------------------------------------\n";

		catalog i;
		
		i.Show_Products(InventoryfileName);
	}

	void Search_Buy_Products()
	{
		/*cout << "Enter file name to save cart products  : ";
		cin >> f;*/
		Show_Inventory();
		int c_counter = 0;
		int check = 1;
		bool flag = false;
		
		int i,q,e=0;

		cout << "\n\n   Search The produt that You Want Buy And Then Enter its ID and Quantity\n ";

		cout << "\n ID : ";
		cin >> i;
		cout << "\n Quantity : ";
		cin >> q;
		TotalBill = 0;
		c_counter++;

		while (check == 1)
		{
			

			catalog  t;
			flag = false;
			fstream file(InventoryfileName, ios::binary|ios::in|ios::out); //ifstream is for reading
			while (file.read((char*)&t, sizeof(t)))
			{

				if (i == t.id)
				{
					//cout << "****************************";
					TotalBill += q * t.price;
					e = q * t.price;

					flag = true;

					ShoppingCart shopping;

					//shopping.ID = i;
					strcpy_s(shopping.name, 100, t.prod);
					shopping.Quantity = q;
					shopping.Each_item_price = e;

					ofstream file1(CartfileName, ios::binary | ios::app); //ofstream is for writing
					file1.write((char*)&shopping, sizeof(shopping));
					file1.close();

					cout << "\n\n Successfully Added to Cart  ";

					t.quantity -= q;
                    int z = (int)file.tellg() - sizeof(t);          //tellg->returns current location of get(read) head,tellp ->returns current location of put(write) head
                    file.seekp(z);                                  // seek changes position of (get/put) head
                    file.write((char*)&t, sizeof(t));
                    break;
				}
			}
			file.close();

			if (flag == false)
			{
				cout << " \n\n Item not found";
			}

			cout << "\n\n Now Press 1 to Buy Another Item : ";
			cout << "\n\n Press 2 to show cart : ";
			cout << "\n\n Enter your choice : ";
			cin >> check;
			if (check == 1)
			{
				cout << "\n ID : ";
				cin >> i;
				cout << "\n Quantity : ";
				cin >> q;
			}
		}
		
		
		count = 1000;
		c_counter = TotalBill;
		system("cls");
		cout << "\n\n Name\t\tQuantity\t\tPrice\n";
		cout << "\n----------------------------------------------------\n\n";

		ShoppingCart temp;
		ifstream file1(CartfileName, ios::binary); //ifstream is for reading
		while (file1.read((char*)&temp, sizeof(temp)))
		{
			cout <<" " << temp.name << "\t\t " << temp.Quantity << "\t\t\t" << temp.Each_item_price << "\n\n";
		}
		file1.close();

		remove(CartfileName);

		cout << "\n\n Total Bill : " << TotalBill;

		discount = TotalBill;

		if (c_counter >= count)
		{
			discount = discount * 0.1;
			TotalBill -= discount;
			cout << "\n\n  AS YOU ARE OUR REGULAR CUSTOMER SO WE ARE GIVING YOU 10% discount ";
			cout << "\n\n Your Total Upadated Bill is : " << TotalBill;
		}


		cout << "\n\n Which Method do you like to choose for your payment \n Enter that choice \n  ";
		cout << "\n 1. Cash on delivery : ";
		cout << "\n 2. Cash through Credit Card : ";
		cout << "\n 3. Cash through EasyPaisa : ";
		cout << "\n 4. Cash through Jazz Cash : ";
		cout << "\n\n Enter : ";
		int p = 0;
		cin >> p;

		if (p == 1)
		{
			COD c;
			payment* p = &c;
			p->Payment(TotalBill);
		}
		else if (p == 2)
		{
			CreditCard c;
			payment* p = &c;
			p->Payment(TotalBill);
		}
		else if (p == 3)
		{
			EasyPaisa c;
			payment* p = &c;
			p->Payment(TotalBill);
		}
		else if (p == 4)
		{
			JazzCash c;
			payment* p = &c;
			p->Payment(TotalBill);
		}
    }
};
