#pragma once
#include "Enemies\Enemy.h"
#include "Castle\Castle.h"
#include "PriorityQueue.h"
#include <time.h>

class Fighter :
	public Enemy
{
	double Priority;

public:
	Fighter();
	Fighter(int id, int arrTime, int d = MaxDistance);
	~Fighter();
	void Move();
	void Act();
	Castle F_Castle;
	void Reload();
	int count;
	void SetPriority();
	double GetPriority() const;

	int StatusValue;

	void SetStatusValue();
	int GetStatusValue();

	//Priority Queue Implementation
	PriorityQueue PQ;
	void AddFighter();
	double GetHighestPriority();

	Battle Manage;
};

