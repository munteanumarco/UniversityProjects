#pragma once
#include <string>
#include "trench_coat.h"
using namespace std;


class TrenchException : public exception
{
private:
	string exception;
public:
	TrenchException(string exception = "Default Exception") : exception(exception) {};

	virtual string message();
};


class TrenchValidator
{
public:
	static void validate_trench(const TrenchCoat& t);
};

