#include "trench_coat.h"
#include <sstream>
TrenchCoat::TrenchCoat()
	: size(0), colour(""), price(0), quantity(0), photo_link("")
{
}

TrenchCoat::TrenchCoat(int _size, string _colour, double _price, int _quantity, string _photo_link)
	: size(_size), colour(_colour), price(_price), quantity(_quantity), photo_link(_photo_link)
{
}

TrenchCoat::TrenchCoat(const TrenchCoat& t)
	: size(t.size), colour(t.colour), price(t.price), quantity(t.quantity), photo_link(t.photo_link)
{
}

int TrenchCoat::getSize() const
{
	return this->size;
}

string TrenchCoat::getColour() const
{
	return this->colour;
}

double TrenchCoat::getPrice() const
{
	return this->price;
}

int TrenchCoat::getQuantity() const
{
	return this->quantity;
}

string TrenchCoat::getPhotoLink() const
{
	return this->photo_link;
}

void TrenchCoat::setSize(int new_size)
{
	this->size = new_size;
}

void TrenchCoat::setColour(string new_colour)
{
	this->colour = new_colour;
}

void TrenchCoat::setPrice(double new_price)
{
	this->price = new_price;
}

void TrenchCoat::setQuantity(int new_quantity)
{
	this->quantity = new_quantity;
}

void TrenchCoat::setPhotoLink(string new_photo_link)
{
	this->photo_link = new_photo_link;
}

string  TrenchCoat::toString()
{
	stringstream s;
	string sizes[] = { "XS","S","M","L","XL","XXL" };
	s << sizes[this->size] << "," << this->colour << "," << this->price << "," << this->quantity << "," << this->photo_link << "\n";
	return s.str();
}

