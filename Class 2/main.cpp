/*
Wei Chen
CIS 1202
*/

#include "Publication.h"
#include <string>
#include <iostream>
using namespace std;

void getPublications(Publication[], int&);
void displayPublications(Publication[], int);
void displayTitles(Publication[], int);
int findPublication(Publication[], int, string);
int getMenuChoice();

int main()
{
	
	Publication publications[6];
	int arraySize = 6;
	getPublications(publications, arraySize);

	int index;
	int choice = 0;
	string title;
	
	while (choice != 6) 
	{
		choice = getMenuChoice();
		switch (choice)
		{

		case 1:
				displayPublications(publications, arraySize);
				break;

		case 2:
				displayTitles(publications, arraySize);
				break;

		case 3:
			cout << "Publication title: ";
			cin.ignore();
			getline(cin, title);

			index = findPublication(publications, arraySize, title);
			if (index < 0) 
			{
				cout << "Sorry! " << title << " was not found";
				cout << endl;
			}
			else 
			{
				publications[index].displayInfo();
			}
			break;

		case 4:
				cout << "Publication title: ";
				cin.ignore();
				getline(cin, title);

				index = findPublication(publications, arraySize, title);
				if (index < 0) 
				{
					cout << title << " was not found" << endl;
				}
				else 
				{
					publications[index].checkOut();
				}
				break;

		case 5:
				cout << "Publication title? ";
				cin.ignore();
				getline(cin, title);

				index = findPublication(publications, arraySize, title);
				if (index < 0) 
				{
					cout << title << " was not found" << endl;
				}
				else 
				{
					publications[index].checkIn();
				}
				break;
		case 6:
			cout << "\nProgram end";
			exit(0);
			break;
		}
	}

	cout << endl << endl;
	system("pause");
	return 0;

}
int getMenuChoice() {
	int choice;
	cout << "1. Display all publications" << endl;
	cout << "2. Display publication titles" << endl;
	cout << "3. Find a publication" << endl;
	cout << "4. Check out" << endl;
	cout << "5. Check in" << endl;
	cout << "6. Exit";
	cout << "\nEnter your choice: ";
	cin >> choice;
	if (choice < 1 || choice > 6) {
		cout << "\nInvalid selection. Please enter a number 1-6: " << endl;
		cin >> choice;
	}
	return choice;
}
void getPublications(Publication publications[], int& arraySize) {

	string title, publisher;
	double price;
	int year, enum_type, stock;
	
	ifstream inFile("publications.txt", ios::in);

	if (!inFile) {
		cout << "Can not open publications.txt file";
		
	}
	
	for (int i = 0; i < arraySize; i++)
	{

		getline(inFile, title);
		getline(inFile, publisher);
		inFile >> price;
		inFile >> year;
		inFile >> enum_type;
		inFile >> stock;
	
		publications[i].storePublication(title, publisher, price, year,
			(PublicationType)(enum_type), stock);
		getline(inFile, title);

	}
	inFile.close();
	
}
void displayPublications(Publication publications[], int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		publications[i].displayInfo();
	}
}
void displayTitles(Publication publications[], int arraySize) {

	int count = 1;
	cout << endl;
	for (int i = 0; i < arraySize; i++) {
		cout << count++  << "." << publications[i].getTitle() << endl;
	}
	cout << endl;
}
int findPublication(Publication publications[], int arraySize, string title) {
	for (int i = 0; i < arraySize; i++) {
		if (publications[i].getTitle() == title) {
			return i;
		}
	}
	return -1;
}
