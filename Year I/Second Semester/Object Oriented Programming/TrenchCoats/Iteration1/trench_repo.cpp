#include "trench_repo.h"
#include <cstdlib>
#include <iostream>
TrenchRepo::TrenchRepo()
	:vec(), deleted_elems(), basket(), basket_price(0), data_option(1)
{

}

int TrenchRepo::setup_data()
{
	TrenchCoat t1{ 1,"Beige",250,20,"https://hips.hearstapps.com/vader-prod.s3.amazonaws.com/1643985855-P00533169.jpg?crop=1xw:1xh;center,top&resize=768:*" };
	TrenchCoat t2{ 2,"Brown",600,10,"https://hips.hearstapps.com/vader-prod.s3.amazonaws.com/1631285008-ezgif-com-gif-maker-2021-09-10t154240-911-1631284977.jpg?crop=1xw:1xh;center,top&resize=768:*" };
	TrenchCoat t3{ 3,"Black",750,15,"https://hips.hearstapps.com/vader-prod.s3.amazonaws.com/1610551676-1063621_in_2000_q80.jpg?crop=1xw:1xh;center,top&resize=768:*" };
	TrenchCoat t4{ 4,"White",599.99,45,"https://hips.hearstapps.com/vader-prod.s3.amazonaws.com/1643986943-P00380122.jpg?crop=1xw:1xh;center,top&resize=768:*" };
	TrenchCoat t5{ 5,"Grey",449.23,12,"https://hips.hearstapps.com/vader-prod.s3.amazonaws.com/1631285911-ezgif-com-gif-maker-2021-09-10t155813-497-1631285898.jpg?crop=1xw:1xh;center,top&resize=768:*" };
	TrenchCoat t6{ 6,"Pink",125.60,60,"https://hips.hearstapps.com/hmg-prod.s3.amazonaws.com/images/evangeline-patch-pocket-wrap-coat-camel-175-1631374351.jpg?crop=1xw:1xh;center,top&resize=980:*" };
	TrenchCoat t7{ 1,"Brown",190.99,90,"https://hips.hearstapps.com/vader-prod.s3.amazonaws.com/1643985676-P00627118.jpg?crop=1xw:1xh;center,top&resize=768:*" };
	TrenchCoat t8{ 2,"Black",200.10,14,"https://hips.hearstapps.com/vader-prod.s3.amazonaws.com/1643985577-P00356509.jpg?crop=1xw:1xh;center,top&resize=768:*" };
	TrenchCoat t9{ 3,"Beige",770.50,21,"https://hips.hearstapps.com/vader-prod.s3.amazonaws.com/1643988382-hmgoepprod.jpg?crop=1xw:1xh;center,top&resize=768:*" };
	TrenchCoat t10{ 4,"Beige",400,77,"https://hips.hearstapps.com/vader-prod.s3.amazonaws.com/1643985975-P00552468.jpg?crop=1xw:1xh;center,top&resize=768:*" };
	this->vec.push_back(t1);
	this->vec.push_back(t2);
	this->vec.push_back(t3);
	this->vec.push_back(t4);
	this->vec.push_back(t5);
	this->vec.push_back(t6);
	this->vec.push_back(t7);
	this->vec.push_back(t8);
	this->vec.push_back(t9);
	this->vec.push_back(t10);
	return 0;
}

int TrenchRepo::generate_data_random()
{
	//Generate random trenches
	srand((unsigned)time(0));
	int i = 0;
	string colours[] = { "Red","Blue","Green","Black","White","Pink","Grey","Yellow","Purple","Brown" };
	int sizes[] = { 1,2,3,4,5,6 };
	double price;
	int quantity;
	while (i < 10)
	{
		int color = (rand() % 9);
		int size = (rand() % 5);
		price = ((rand() % 1000) + 1) + (rand() % 99 + 1) / 100;
		quantity = ((rand() % 500) + 1);
		string link = "link";
		string index = to_string(i);
		link.append(index);
		TrenchCoat t{ sizes[size],colours[color],price,quantity,link };
		this->addTrench(t);
		i++;
	}

	return 0;
}

vector<TrenchCoat> TrenchRepo::getAll() const
{
	return this->vec;
}

vector<TrenchCoat> TrenchRepo::getAllDeleted() const
{
	return this->deleted_elems;
}

int TrenchRepo::getLengthDeleted()
{
	return this->deleted_elems.size();
}

int TrenchRepo::getLength()
{
	return this->vec.size();
}

double TrenchRepo::getBasketPrice()
{
	return this->basket_price;
}

int TrenchRepo::getDataOption()
{
	return this->data_option;
}

void TrenchRepo::setDataOption(int data)
{
	this->data_option = data;
}

class checkLink
{
private:
	string _link;
public:
	checkLink(string link) : _link(link) {}

	bool operator()(TrenchCoat t)
	{
		return this->_link == t.getPhotoLink();
	}
};

TrenchCoat TrenchRepo::findTrenchByLink(string link)
{
	vector<TrenchCoat>::iterator it = find_if(this->vec.begin(), this->vec.end(), checkLink(link));
	if (it != this->vec.end())
	{
		return *it;
	}
	return TrenchCoat();
}

void TrenchRepo::addTrench(const TrenchCoat& new_trench)
{
	this->vec.push_back(new_trench);
}

void TrenchRepo::deleteTrench(string link)
{
	TrenchCoat t;
	int len = this->vec.size();
	int position_to_delete = 0;
	for (int i = 0; i < len; i++)
	{
		t = this->vec[i];
		if (t.getPhotoLink() == link)
		{
			position_to_delete = i;
			break;
		}
	}
	this->vec.erase(vec.begin() + position_to_delete);

	this->deleted_elems.push_back(t);
}

void TrenchRepo::updateTrench(string link, const TrenchCoat& newTrench)
{
	int len = this->vec.size();
	for (int i = 0; i < len; i++)
	{
		if (vec[i].getPhotoLink() == link)
		{
			vec[i] = newTrench;
			return;
		}
	}

	throw TrenchRepoException("Trench not found !");
}

class filter_size
{
private:
	int size;
public:
	filter_size(int _size) : size(_size) {}

	bool operator()(TrenchCoat t)
	{
		return this->size == t.getSize();
	}
};

vector<TrenchCoat> TrenchRepo::getTrenchesBySize(int size)
{
	vector<TrenchCoat> trenches(this->vec.size());

	copy_if(this->vec.begin(), this->vec.end(), trenches.begin(), filter_size(size));

	return trenches;
}

vector<TrenchCoat> TrenchRepo::getBasket()
{
	vector<TrenchCoat> copy_basket = this->basket;
	return copy_basket;
}

void TrenchRepo::addTrenchToBasket(TrenchCoat new_coat)
{
	this->basket.push_back(new_coat);
	this->basket_price += new_coat.getPrice();
}

string TrenchRepoException::message()
{
	return this->exception;
}
