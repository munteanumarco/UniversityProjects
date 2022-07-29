#include "trench_repo_files.h"
#include <iostream>
#include <fstream>

TrenchRepoFiles::TrenchRepoFiles(string _file_name) : file_name(_file_name) { this->loadFile(); }

void TrenchRepoFiles::saveFile()
{
	ofstream file;
	file.open(this->file_name);

	if (file.is_open())
	{
		vector<TrenchCoat> trenches = this->getAll();

		for (auto t : trenches)
		{
			string line = to_string(t.getSize()) + " " + t.getColour() + " " + to_string(t.getPrice()) + " " + to_string(t.getQuantity()) + " " + t.getPhotoLink();
			file << line << endl;
		}
		file.close();
	}
	else
	{
		throw TrenchRepoFilesException("File not opened!");
	}
}

vector<string> split(string str, char seperator)
{
	int i = 0;
	int startIndex = 0, endIndex = 0;
	vector <string> strings;
	while (i <= str.length())
	{
		if (str[i] == seperator || i == str.length())
		{
			endIndex = i;
			string subStr = "";
			subStr.append(str, startIndex, endIndex - startIndex);
			strings.push_back(subStr);
			startIndex = endIndex + 1;
		}
		i++;
	}
	return strings;
}

void TrenchRepoFiles::loadFile()
{
	ifstream file;
	file.open(this->file_name);

	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			vector<string> words = split(line, ' ');

			int size = stoi(words[0]);
			string colour = words[1];
			double price = stod(words[2]);
			int quantity = stoi(words[3]);
			string link = words[4];

			TrenchCoat t{ size,colour,price,quantity,link };



			this->TrenchRepo::addTrench(t);

		}
		file.close();
	}
	else
	{
		throw TrenchRepoFilesException("File not opened!");
	}
}

void TrenchRepoFiles::saveBasketCSV()
{

	ofstream csvfile;

	csvfile.open("basket.csv");

	csvfile << "Size,Colour,Price,Quantity,PhotoLink\n";

	vector<TrenchCoat> basket = this->getBasket();
	for (int i = 0; i < basket.size(); i++)
	{
		string line = to_string(basket[i].getSize()) + "," + basket[i].getColour() + "," + to_string(basket[i].getPrice()) + "," + to_string(basket[i].getQuantity()) + "," + basket[i].getPhotoLink() + "\n";
		csvfile << line;
	}
	csvfile.close();

}

void TrenchRepoFiles::saveBasketHTML()
{
	ofstream htmlfile;

	htmlfile.open("basket.html");

	htmlfile << "<!DOCTYPE html><html><head><title>Shopping Basket</title></head> <body> <table border=\"1\" <tr> <td>Size</td> <td>Colour</td> <td>Price</td> <td>Quantity</td> <td>PhotoLink</td></tr>";

	vector<TrenchCoat> basket = this->getBasket();
	for (int i = 0; i < basket.size(); i++)
	{
		string line = "<tr><td>" + to_string(basket[i].getSize()) + " </td><td>" + basket[i].getColour() + " </td><td>" + to_string(basket[i].getPrice()) + " </td><td>" + to_string(basket[i].getQuantity()) + " </td><td>" + basket[i].getPhotoLink() + "</td></tr>";
		htmlfile << line;
	}

	htmlfile << "</table></body></html>";

	htmlfile.close();

}

void TrenchRepoFiles::addTrench(const TrenchCoat& new_trench)
{
	this->TrenchRepo::addTrench(new_trench);
	this->saveFile();
}

void TrenchRepoFiles::deleteTrench(string link)
{
	this->TrenchRepo::deleteTrench(link);
	this->saveFile();
}

void TrenchRepoFiles::updateTrench(string link, const TrenchCoat& newTrench)
{
	this->TrenchRepo::updateTrench(link, newTrench);
	this->saveFile();
}

void TrenchRepoFiles::addTrenchToBasket(TrenchCoat new_coat, int data)
{

	this->TrenchRepo::addTrenchToBasket(new_coat);
	if (data == 1)
	{
		this->saveBasketCSV();
	}
	else
		if (data == 2)
		{
			this->saveBasketHTML();
		}
}

string TrenchRepoFilesException::message()
{
	return this->exception;
}
