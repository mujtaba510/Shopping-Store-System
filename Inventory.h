#pragma once
#include<iostream>
#include<fstream>
#include"Manager.h"
#include"Catalog.h"

const char* InventoryfileName = "Inventory.bin";

class inventory
{
private:
	char prod[100], category[100], Measured_Units[100];
	int id, price, quantity;
	
public:
	void p_file()
	{
		catalog c;

		ifstream fo;

		fo.open(catalogfileName, ios::in|ios::binary);

		ofstream foo(InventoryfileName, ios::app|ios::binary);

		while (fo.read((char*)&c, sizeof(c)))

		{

			foo.write((char*)&c, sizeof(c));

		}

		fo.close();

		foo.close();
	}
	
	

	void ShowItems()
	{
		system("cls");
		cout << "\n ID\t\tCategory\tProduct\t\tUnits\t\tPrices\t\tQuantity\n ";
		cout << "---------------------------------------------------------------------------------\n";

		catalog i;
		//ifstream file(InventoryfileName, ios::binary); //ifstream is for reading
		//while (file.read((char*)&i, sizeof(i)))
		//{
		//	cout << "\n\n " << i.id << "\t\t" << i.category << "\t\t" << i.prod << "\t\t" << i.Measured_Units << "\t\t" << i.price << "\t\t" << i.quantity << "\n";

		//}
		//file.close();
		i.Show_Products(InventoryfileName);
	}

	void AddQuantities()
	{
		system("cls");
		ShowItems();

		int Id = 0, Quantity = 0,n = 0;;
		cout << "\n   Press 1. to add quantities into an inventory ";
		cout << "\n   Press 2 to Go Back Manager Menue ";
		cout << "\n   Enter Your Choice : ";
		cin >> n;
		while (n == 1)
		{
			cout << "\n Enter ID of that Item whose quantity you want to Add ";
			cout << "\n ID = ";
			cin >> Id;
			cout << "\n Quantity : ";
			cin >> Quantity;

			catalog temp;
			fstream myFile(InventoryfileName, ios::in | ios::out | ios::binary);
			while (myFile.read((char*)&temp, sizeof(temp)))
			{
				if (temp.id == Id)
				{

					temp.quantity += Quantity;

					int current = myFile.tellg();
					int oneblock = sizeof(temp);
					myFile.seekg(current - oneblock);
					myFile.write((char*)&temp, sizeof(temp));
					myFile.close();
				}
			}

			cout << "\n   Press 1. to add quantities into an inventory ";
			cout << "\n   Press 2 to Go Back Manager Menue ";
			cout << "\n   Enter Your Choice : ";
			cin >> n;
		}

		if (n == 2)
		{
			return;
		}
		//ShowItems();
	}

	void AddItems()
	{
		system("cls");
		ShowItems();

		string Prod, Category, unit;
		int Id = 0, Price = 0, n = 0, Quantity = 0;
		cout << "\n   Press 1. to add items into an inventory ";
		cout << "\n   Press 2 to Go Back Manager Menue ";
		cout << "\n\n Enter Your Choice : ";
		cin >> n;

		while (n == 1)
		{
			cout << "\n ID = ";
			cin >> Id;
			cout << "\n Category = ";
			cin >> Category;
			cout << "\n Product = ";
			cin >> Prod;
			cout << "\n Measured Units = ";
			cin >> unit;
			cout << "\n Price = ";
			cin >> Price;
			cout << "\n Quantity = ";
			cin >> Quantity;

			catalog c;
			c.id = Id;
			c.price = Price;
			c.quantity = Quantity;
			strcpy_s(c.prod, 100, Prod.c_str());
			strcpy_s(c.category, 100, Category.c_str());
			strcpy_s(c.Measured_Units, 100, unit.c_str());
			

			ofstream file(InventoryfileName, ios::binary | ios::app); //ofstream is for writing
			file.write((char*)&c, sizeof(c));
			//file.close();
			file.close();
			

			cout << "\n   Press 1. to add more items into an inventory ";
			cout << "\n   Press 2 to Go Back Manager Menue ";
			cout << "\n\n Enter Your Choice : ";
			cin >> n;

		}

		if (n == 2)
		{
			return;
		}
	}

	void EditItems()
	{
		system("cls");
		ShowItems();

		string Prod, Category, unit;
		int Id = 0, Price = 0, Quantity=0;
		cout << "\n Enter that information that you want to edit : ";
		cout << "\n ID = ";
		cin >> Id;
		cout << "\n Category = ";
		cin >> Category;
		cout << "\n Product = ";
		cin >> Prod;
		cout << "\n Measured Units = ";
		cin >> unit;
		cout << "\n Price = ";
		cin >> Price;
		cout << "\n Quantity = ";
		cin >> Quantity;

		catalog temp;
		fstream myFile(InventoryfileName, ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (temp.id == Id)
			{
				temp.price = Price;
				temp.quantity = Quantity;
				strcpy_s(temp.prod, 100, Prod.c_str());
				strcpy_s(temp.category, 100, Category.c_str());
				strcpy_s(temp.Measured_Units, 100, unit.c_str());
				int current = myFile.tellg();
				int oneblock = sizeof(temp);
				myFile.seekg(current - oneblock);
				myFile.write((char*)&temp, sizeof(temp));
				myFile.close();
			}
		}

		ShowItems();
	}

	void DeleteItems()
	{
		system("cls");
		ShowItems();
		int Id = 0;
		cout << "\n Enter ID of that Product that you want to delete  ";
		cout << "\n ID = ";
		cin >> Id;

		catalog temp;
		fstream myFile(InventoryfileName, ios::in | ios::out | ios::binary);
		ofstream myFile_temp("temp.bin", ios::app | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.id != Id) {
				myFile_temp.write((char*)&temp, sizeof(temp));
			}
		}
		myFile.close();
		myFile_temp.close();
		remove(InventoryfileName);
		rename("temp.bin", InventoryfileName);

		system("cls");
		ShowItems();
	}
};


