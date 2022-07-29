#pragma once
#include "Participant.h"
#include "Question.h"
#include <vector>

class RepoParticipants {
private:
	vector<Participant> participants;
	void loadData();
public:
	RepoParticipants();
	~RepoParticipants();

	vector<Participant>& getParticipants();
	void updateParticipantScore(Question q, string answer, Participant& p);
};