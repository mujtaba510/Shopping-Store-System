#pragma once
#include<iostream>
#include<fstream>
#include"Admin.h"
//#include "Admin.h"
using namespace std;

const char* catalogfileName = "Catalog.bin";

class catalog
{

//protected:
	//admin a;
	
public:
	char prod[100], category[100], Measured_Units[100];
	int id, price, quantity;

	void Show_Products(string filename)
	{
		system("cls");
		cout << "\n ID\t\tCategory\tProduct\t\tUnits\t\tPrices\t\tQuantity\n ";
		cout << "---------------------------------------------------------------------------------\n";

		catalog Catalog;
		ifstream file(filename, ios::binary); //ifstream is for reading
		while (file.read((char*)&Catalog, sizeof(Catalog)))
		{
			cout << "\n\n " << Catalog.id << "\t\t" << Catalog.category << "\t\t" << Catalog.prod << "\t\t" << Catalog.Measured_Units << "\t\t" << Catalog.price << "\t\t" << Catalog.quantity << "\n";

		}
		file.close();
	}


	void AddProducts()
	{
		system("cls");
		Show_Catalog();

		string Prod, Category,unit;
		int Id = 0,Price=0, n = 0,Quantity=0;
		cout << "\n   Press 1. to add items into a catalog ";
		cout << "\n   Press 2 to Go Back Admin Menue ";
		cout << "\n   Enter Your Choice : ";
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
			Quantity = 0;

			catalog c;
			c.id = Id;
			c.price = Price;
			c.quantity = Quantity;
			strcpy_s(c.prod, 100, Prod.c_str());
			strcpy_s(c.category, 100, Category.c_str());
			strcpy_s(c.Measured_Units, 100, unit.c_str());

			ofstream file(catalogfileName, ios::binary | ios::app); //ofstream is for writing
			file.write((char*)&c, sizeof(c));
			file.close();

			cout << "\n   Press 1. to add more items into a catalog ";
			cout << "\n   Press 2 to Go Back Admin Menue ";
			cout << " Enter Your Choice : ";
			cin >> n;

		}

		if (n == 2)
		{
			return;
		}
	}

	void Edit_Products()
	{
		system("cls");
		Show_Catalog();

		string Prod, Category, unit;
		int Id = 0, Price = 0, n = 0;
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
		
		catalog temp;
		fstream myFile(catalogfileName, ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (temp.id == Id)
			{
				temp.price = Price;
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

		Show_Catalog();
	}

	void Delete_Products()
	{
		system("cls");
		Show_Catalog();
		int Id = 0;
		cout << "\n Enter ID of that Product that you want to delete  ";
		cout << "\n ID = ";
		cin >> Id;

		catalog temp;
		fstream myFile(catalogfileName, ios::in | ios::out | ios::binary);
		ofstream myFile_temp("temp.bin", ios::app | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.id != Id) {
				myFile_temp.write((char*)&temp, sizeof(temp));
			}
		}
		myFile.close();
		myFile_temp.close();
		remove(catalogfileName);
		rename("temp.bin", catalogfileName);

		system("cls");
		Show_Catalog();

	}

	void Show_Catalog()
	{
		system("cls");
		cout << "\n ID\t\tCategory\tProduct\t\tUnits\t\tPrices\t\tQuantity\n ";
		cout << "---------------------------------------------------------------------------------\n";

		catalog Catalog;
		ifstream file(catalogfileName, ios::binary); //ifstream is for reading
		while (file.read((char*)&Catalog, sizeof(Catalog)))
		{
			cout << "\n\n " << Catalog.id << "\t\t" << Catalog.category << "\t\t" << Catalog.prod << "\t\t" << Catalog.Measured_Units << "\t\t" << Catalog.price << "\t\t" << Catalog.quantity << "\n";

		}
		file.close();
	}

	
};
