#pragma once
#include <iostream>
#include<string>
#include <fstream>
#include <string>
#ifndef PUBLICATION_H
#define PUBLICATION_H

using namespace std;
enum PublicationType { BOOK, MAGAZINE, NEWSPAPER, AUDIO, VIDEO };

class Publication
{


    string title, publisher;
    double price;
    int year, stock;
    PublicationType type;

public:
    void storePublication(string itemTitle, string itemPublisher, double itemPrice, int itemYear, PublicationType itemType, int itemStock);
    void displayInfo();
    void checkOut();
    void checkIn();
    string getTitle();
    int getStock();
};
#endif

