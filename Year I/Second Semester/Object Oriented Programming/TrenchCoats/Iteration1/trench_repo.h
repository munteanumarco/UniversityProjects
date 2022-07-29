#pragma once
#include "trench_coat.h"
#include "trench_validator.h"
#include <vector>
#include <string>
#include <algorithm>

class TrenchRepoException : public TrenchException
{
private:
	string exception;
public:
	TrenchRepoException(string exception = "Default Trench Exception") : exception(exception) {};
	string message();
};

class TrenchRepo
{
private:
	vector<TrenchCoat> vec;
	vector<TrenchCoat> deleted_elems;
	vector<TrenchCoat> basket;
	double basket_price;
	int data_option;
public:

	//Default constructor
	TrenchRepo();


	//Setup good data with real photo links

	int setup_data();

	//Generates the default data in the repo at the start of the program
	int generate_data_random();

	//Returns all the trench coats in the repository
	vector<TrenchCoat> getAll() const;

	//Returns all the trench coats deleted
	vector<TrenchCoat> getAllDeleted() const;

	//Returns the length of the deletes elems of the repository
	int getLengthDeleted();

	//Returns the length of the repository
	int getLength();

	//Finds a trench coat that has the given link
	TrenchCoat findTrenchByLink(string link);

	//Add the new trench given as parameter to the repoistory
	virtual void addTrench(const TrenchCoat& new_trench);

	//Deletes existing trench coat having the link given as parameter
	virtual void deleteTrench(string link);

	virtual void updateTrench(string link, const TrenchCoat& newTrench);

	//Returns trenches with the given size
	vector<TrenchCoat> getTrenchesBySize(int size);

	//Returns the trenches in the basket
	vector<TrenchCoat> getBasket();

	//Adding a trench to the shopping basket
	virtual void addTrenchToBasket(TrenchCoat new_coat);

	//Return the total shopping basket price
	double getBasketPrice();

	vector<TrenchCoat> filterByString(string text)
	{
		vector<TrenchCoat> result;
		for (auto t : this->vec)
		{
			if (t.toString().find(text) != string::npos)
			{
				result.push_back(t);
			}
		}
		return result;
	}

	int getDataOption();
	void setDataOption(int data);
};
