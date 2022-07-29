#pragma once
#include "trench_repo.h"

class UndoRedoEvent {
public:
	virtual void undo() = 0;
	virtual void redo() = 0;
	virtual ~UndoRedoEvent() = default;

};

class UndoRedoAdd : public UndoRedoEvent {
private:
	TrenchCoat addedTrench;
	TrenchRepo& repo;
public:
	UndoRedoAdd(const TrenchCoat& t, TrenchRepo& repo);
	void undo() override;
	void redo() override;
	~UndoRedoAdd() override = default;
};

class UndoRedoDelete : public UndoRedoEvent {
private:
	TrenchCoat deletedTrench;
	TrenchRepo& repo;
public:
	UndoRedoDelete(const TrenchCoat& t, TrenchRepo& repo);
	void undo() override;
	void redo() override;
	~UndoRedoDelete() override = default;
};

class UndoRedoUpdate : public UndoRedoEvent {
private:
	TrenchCoat oldTrench;
	TrenchCoat newTrench;
	TrenchRepo& repo;
public:
	UndoRedoUpdate(const TrenchCoat& oldTrench, const TrenchCoat& newTrench, TrenchRepo& repo);
	void undo() override;
	void redo() override;
	~UndoRedoUpdate() override = default;
};