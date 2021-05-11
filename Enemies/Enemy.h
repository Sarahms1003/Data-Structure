#pragma once
#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "/CIE205Project_Code_S2021/BSTNode.h"
#include "/CIE205Project_Code_S2021/Battle.h"
class GUI;
// Enemy is the base class of each type of enemy
// Enemy should be an abstract class in next phases
class Enemy
{

protected:
	const int ID;         //Each enemy has a unique ID (sequence number)
	const int ArrvTime;	//arrival time (time it starts to join battle)

	ENMY_STATUS status;	    //status of the enemy (inactive, inactive, frosted, killed)
	int Distance;	//Horizontal distance between enemy & the tower of its region
	                //Always positive (ranges from 2 to 60)
	double Health;	//Enemy health

	
	//
	// TODO: Add More Data Members As Needed
	//
	ENMY_TYPE type;

public:
	Enemy();
	Enemy(int id, int arrTime, int d = MaxDistance);
	virtual ~Enemy();

	int Enemy::GetID() const;
	ENMY_STATUS GetStatus() const;
	void SetStatus(ENMY_STATUS);
	
	void DecrementDist();

	void SetDistance(int );
	int GetDistance() const;

	int GetArrvTime() const;


	// Virtual Functions: ----------------

	virtual void Move() = 0;	//All enemies can move
	virtual void Act() = 0;	//Acting means fighting or healing

	

	//
	// TODO: Add More Member Functions As Needed
	//
	int Speed;
	static bool INChangeSpeed;
	int Power;
	int ReloadPeriod;

	double GetHealth() const;
	void HalfSpeed();
	void SetSpeed(int);
	int GetSpeed() const;
	void SetPower(int);
	int GetPower() const;
	void SetReloadPeriod(int);
	int GetReloadPeriod() const;

	void ActiveEnm(Enemy* enmy);
};

