#pragma once
#include"Enemies/Enemy.h"
#include <time.h>
#include "Battle.h"

class Healer : public Enemy
{
private:
	 const int ID;
	const int Arrival_time;
	double Healer_Health;
	int Healer_Power;
	int Healer_Distance;
	ENMY_STATUS Healer_Status;	    

public:
	Healer(int id, int arrTime, int d = MaxDistance);
	virtual ~Healer();

	int Healer::GetID() const;
	ENMY_STATUS GetStatus() const;
	void SetStatus(ENMY_STATUS);
	void DecrementDist();
	void IncrementDist();
	void SetHealerDistance(int);
	int GetHealerDistance() const;
	int GetArrvTime() const;
	void Heal_Enemy() ; //Healer can heal only enemies that are at most 2 meters ahead in his moving direction.
	bool isHealed() ;					 //Healer cannot heal killed enemies.Healer cannot heal frosted enemies.
	//int powerTaken(int pow) ; // If Castle kills a healer within a distance of 5 meters from the castle, it uses healer's tools to recover its health by a percentage of 3 % .
	void kill_Healer(int arrivalTime) ;   //A fresh healer who has just joined the forces is picked first.This means that healers are picked in the reverse order of their arrival
	void Move();
	void Act();
	Battle oB;
};

