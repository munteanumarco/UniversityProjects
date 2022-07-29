#pragma once
#include <string>
#include <iostream>
using namespace std;

class TrenchCoat {

private:

	int size;
	string colour;
	double price;
	int quantity;
	string photo_link;

public:


	//Default constructor
	TrenchCoat();
	//Parametrized construcor
	TrenchCoat(int, string, double, int, string);
	//Copy constructor
	TrenchCoat(const TrenchCoat& t);

	//Get the size of the trench coat
	int getSize() const;
	//Get the colour of the trench coat
	string getColour() const;
	//Get the price of the trench coat
	double getPrice() const;
	//Get the quantity of the trench coat
	int getQuantity() const;
	//Get the photo link of the trench coat
	string getPhotoLink() const;

	//Set the current size of the trench coat to a new size
	void setSize(int new_size);
	//Set the current colour of the trench coat to a new colour
	void setColour(string new_colour);
	//Set the current price of the trench coat to a new price
	void setPrice(double new_price);
	//Set the current quantity of the trench coat to a new quantity
	void setQuantity(int new_quantity);
	//Set the current link of the trench coat to a new link
	void setPhotoLink(string new_photo_link);
	//Convert object to string
	string toString();

};