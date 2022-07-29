#include "undoredo.h"

UndoRedoAdd::UndoRedoAdd(const TrenchCoat& t, TrenchRepo& repo) : addedTrench(t), repo(repo)
{
}

void UndoRedoAdd::undo()
{
	string link = this->addedTrench.getPhotoLink();
	this->repo.deleteTrench(link);
}

void UndoRedoAdd::redo()
{
	this->repo.addTrench(this->addedTrench);
}

UndoRedoDelete::UndoRedoDelete(const TrenchCoat& t, TrenchRepo& repo) : deletedTrench(t), repo(repo)
{
}

void UndoRedoDelete::undo()
{
	this->repo.addTrench(this->deletedTrench);
}

void UndoRedoDelete::redo()
{
	string link = this->deletedTrench.getPhotoLink();
	this->repo.deleteTrench(link);
}

UndoRedoUpdate::UndoRedoUpdate(const TrenchCoat& oldTrench, const TrenchCoat& newTrench, TrenchRepo& repo)
	: oldTrench(oldTrench), newTrench(newTrench), repo(repo)
{
}

void UndoRedoUpdate::undo()
{
	string link = this->newTrench.getPhotoLink();
	this->repo.updateTrench(link, this->oldTrench);
}

void UndoRedoUpdate::redo()
{
	string link = this->oldTrench.getPhotoLink();
	this->repo.updateTrench(link, this->newTrench);
}
