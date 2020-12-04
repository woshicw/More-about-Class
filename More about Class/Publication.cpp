/*
Wei Chen
CIS 1202
11/18/2020
*/

#include<iostream>
#include<string>
#include "Publication.h"

using namespace std;

void Publication::storePublication(string itemTitle, string itemPublisher, double itemPrice, int itemYear, PublicationType itemType, int itemStock)
{
    title = itemTitle;
    publisher = itemPublisher;
    price = itemPrice;
    type = itemType;
    year = itemYear;
    stock = itemStock;
}
void Publication::displayInfo()
{
    cout << "\nTitle: " << title;
    cout << "\nPublisher: " << publisher;
    cout << "\nPrice: " << price;
    cout << "\nYear: " << year;
    if (type == 0)
    {
        cout << "\nBook";
    }
    else if (type == 1)
    {
        cout << "\nMagazine";
    }
    else if (type == 2)
    {
        cout << "\nNewspaper";
    }
    else if (type == 3)
    {
        cout << "\nAudio";
    }
    else if (type == 4)
    {
        cout << "\nVideo";
    }
    cout << "\nStock: " << stock << endl;

    cout << endl;
}
void Publication::checkOut()
{

    if (stock > 0)
    {
        stock--;
    }


}
void Publication::checkIn()
{


    stock++;


}
string Publication::getTitle()
{
    return title;
}
int Publication::getStock()
{

    return stock;

}