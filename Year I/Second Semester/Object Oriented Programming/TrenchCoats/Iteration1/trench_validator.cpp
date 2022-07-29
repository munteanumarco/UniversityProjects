#include "trench_validator.h"

string TrenchException::message()
{
	return this->exception;
}

void TrenchValidator::validate_trench(const TrenchCoat& t)
{
	string errors;

	if (t.getColour().size() == 0)
	{
		errors.append("Colour can't be empty!\n");
	}
	if (t.getSize() < 0)
	{
		errors.append("Invalid size!\n");
	}
	if (t.getPhotoLink().size() == 0)
	{
		errors.append("Photo link can't be empty!\n");
	}
	if (t.getPrice() < 0)
	{
		errors.append("Price can't be negative!\n");
	}
	if (t.getQuantity() < 0)
	{
		errors.append("Quantity can't be negative!\n");
	}
	if (errors.size() != 0)
	{
		throw TrenchException(errors);
	}
}


