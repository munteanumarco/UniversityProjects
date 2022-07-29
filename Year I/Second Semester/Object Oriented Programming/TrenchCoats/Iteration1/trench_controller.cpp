#include "trench_controller.h"
#include "trench_validator.h"
#include <iostream>

TrenchController::TrenchController(TrenchRepoFiles _repo, TrenchValidator _validator)
	: repo(_repo), validator(_validator)
{
}

int TrenchController::setup_data()
{
	return this->repo.setup_data();
}

int TrenchController::generate_data_random()
{
	return this->repo.generate_data_random();
}

vector<TrenchCoat> TrenchController::getAll()
{
	return this->repo.getAll();
}

vector<TrenchCoat> TrenchController::getAllDeleted()
{
	return this->repo.getAllDeleted();
}

TrenchCoat TrenchController::findTrenchByLink(string link)
{
	return this->repo.findTrenchByLink(link);
}

void TrenchController::addTrench(const TrenchCoat& new_trench)
{
	if (this->repo.findTrenchByLink(new_trench.getPhotoLink()).getPhotoLink() == "")
	{
		this->validator.validate_trench(new_trench);
		this->repo.addTrench(new_trench);
		shared_ptr<UndoRedoEvent> action = make_shared<UndoRedoAdd>(new_trench, this->repo);
		this->undo.push_back(action);
	}
	else
	{
		throw(TrenchControllerException("Duplicated Trench!\n"));
	}
}

void TrenchController::deleteTrench(string link_to_delete)
{
	TrenchCoat deletedTrench = this->repo.findTrenchByLink(link_to_delete);
	if (deletedTrench.getPhotoLink() != "")
	{
		this->repo.deleteTrench(link_to_delete);
		shared_ptr<UndoRedoEvent> action = make_shared<UndoRedoDelete>(deletedTrench, this->repo);
		this->undo.push_back(action);
	}
	else
	{
		throw TrenchControllerException("Non existing Trench !\n");
	}
}

int TrenchController::getRepoLength()
{
	return repo.getLength();
}

int TrenchController::getRepoLengthDeleted()
{
	return this->repo.getLengthDeleted();
}

void TrenchController::updateTrench(string link, int new_size, string new_colour, double new_price, int new_quantity)
{
	TrenchCoat oldTrench = this->repo.findTrenchByLink(link);
	TrenchCoat newTrench = TrenchCoat(new_size, new_colour, new_price, new_quantity, link);
	this->repo.updateTrench(link, newTrench);
	shared_ptr<UndoRedoEvent> action = make_shared<UndoRedoUpdate>(oldTrench, newTrench, this->repo);
	this->undo.push_back(action);
}

vector<TrenchCoat> TrenchController::getTrenchesBySize(int size)
{
	return this->repo.getTrenchesBySize(size);
}

vector<TrenchCoat> TrenchController::getBasket()
{
	return this->repo.getBasket();
}

void TrenchController::addTrenchToBasket(TrenchCoat new_coat, int data)
{
	this->repo.addTrenchToBasket(new_coat, data);
}

double TrenchController::getBasketPrice()
{
	return this->repo.getBasketPrice();
}

vector<TrenchCoat> TrenchController::filterByString(string text)
{
	return this->repo.filterByString(text);
}

int TrenchController::getDataOption()
{
	return this->repo.getDataOption();
}

void TrenchController::setDataOption(int data)
{
	this->repo.setDataOption(data);
}

void TrenchController::undoAction()
{
	if (this->undo.empty())
	{
		throw exception("No action to undo!");
	}
	this->undo.back()->undo();
	this->redo.push_back(this->undo.back());
	this->undo.pop_back();
}

void TrenchController::redoAction()
{
	if (this->redo.empty())
	{
		throw exception("No action to redo!");
	}
	this->redo.back()->redo();
	this->undo.push_back(this->redo.back());
	this->redo.pop_back();
}

string TrenchControllerException::message()
{
	return this->exception;
}
