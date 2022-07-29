#pragma once
#include "trench_repo.h"
#include "trench_validator.h"

class TrenchRepoFilesException : public TrenchException
{
private:
	string exception;
public:
	TrenchRepoFilesException(string exception = "Default RepoFilesException") : exception(exception) {};
	string message();
};

class TrenchRepoFiles : public TrenchRepo
{
private:
	string file_name;
public:
	TrenchRepoFiles(string _file_name = "default.txt");

	void saveFile();
	void loadFile();

	void  saveBasketCSV();
	void saveBasketHTML();

	void addTrench(const TrenchCoat& new_trench);
	void deleteTrench(string link);

	void updateTrench(string link, const TrenchCoat& newTrench);

	//Adding a trench to the shopping basket
	void addTrenchToBasket(TrenchCoat new_coat, int data);
};