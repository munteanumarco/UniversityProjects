#pragma once
#include "trench_repo_files.h"
#include "trench_validator.h"
#include <vector>
#include "undoredo.h"

class TrenchControllerException : public TrenchException
{
private:
	string exception;
public:
	TrenchControllerException(string exception = "Default Controller Exception") : exception(exception) {};
	string message() override;
};

class TrenchController
{
private:
	TrenchRepoFiles repo;
	TrenchValidator validator;

	vector<shared_ptr<UndoRedoEvent>> undo;
	vector<shared_ptr<UndoRedoEvent>> redo;

public:

	//Default constructor
	TrenchController(TrenchRepoFiles _repo, TrenchValidator _validator);

	//Calls the setup data from repo
	int setup_data();

	//Calls the generating function from repository
	int generate_data_random();

	//Gets all the trench coats from repository
	vector<TrenchCoat> getAll();

	//Gets all the trench coats deleted 
	vector<TrenchCoat> getAllDeleted();

	//Returns the trench having the given link by calling the repository
	TrenchCoat findTrenchByLink(string link);

	//Adds a new trench by calling the repository
	void addTrench(const TrenchCoat& new_trench);

	//Deletes an existing trench by calling the repository
	void deleteTrench(string link_to_delete);

	//Returns the number of elements in the repository
	int getRepoLength();

	//Returns the number of elements deleted from the repository
	int getRepoLengthDeleted();

	void updateTrench(string link, int new_size, string new_colour, double new_price, int new_quantity);

	//Returns trenches with the given size by calling the repository
	vector<TrenchCoat> getTrenchesBySize(int size);

	//Returns the trenches in the basket by calling the repository
	vector<TrenchCoat> getBasket();

	//Adding a trench to the shopping basket by calling the repository
	void addTrenchToBasket(TrenchCoat new_coat, int data);

	//Return the total shopping basket price
	double getBasketPrice();

	vector<TrenchCoat> filterByString(string text);

	int getDataOption();
	void setDataOption(int data);

	void undoAction();
	void redoAction();

};