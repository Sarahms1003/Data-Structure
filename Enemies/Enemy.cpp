#include "Enemy.h"
#include "/CIE205Project_Code_S2021/BSTNode.h"
#include "/CIE205Project_Code_S2021/Fighter.h"
Enemy::Enemy(int id, int arrTime, int d):ID(id),ArrvTime(arrTime)
{
	SetDistance(d);
}




Enemy::~Enemy()
{
}

int Enemy::GetID() const
{
	return ID;
}


void Enemy::SetStatus(ENMY_STATUS s)
{
	status = s;
}


ENMY_STATUS Enemy::GetStatus() const
{
	return status;
}


void Enemy::DecrementDist()
{
	if (Distance > MinDistance)
		Distance--;
}

void Enemy::SetDistance(int d)
{
	if (d >= MinDistance && d <= MaxDistance)
		Distance = d;
	else
		Distance = MaxDistance;
}

int Enemy::GetDistance() const
{
	return Distance;
}



int Enemy::GetArrvTime() const
{
	return ArrvTime;
}

//////////////////

double Enemy::GetHealth() const
{
	return Health;
}

void Enemy::HalfSpeed()
{
	if (!INChangeSpeed)
	{
		INChangeSpeed = true;
		if (Health < GetHealth())
		{
			Speed = Speed / 2;
		}
	}
}

void Enemy::SetPower(int d)
{
	if (d > 0 )
		Power = d;
	else
		Power = 0;
}

int Enemy::GetPower() const
{
	return Power;
}

void Enemy::SetSpeed(int d)
{
	if (d >0)
		Speed = d;
	else
		Speed = 0;
}

int Enemy::GetSpeed() const
{
	return Speed;
}

void Enemy::SetReloadPeriod(int d)
{
	if (d >0)
		ReloadPeriod = d;
	else
		ReloadPeriod = 0;
}

int Enemy::GetReloadPeriod() const
{
	return ReloadPeriod;
}

void Enemy::ActiveEnm(Enemy* enmy)
{
	 BSTNode <Enemy> *AFighter;
	 BSTNode <Enemy> *AFreezer;
	 BSTNode <Enemy> *AHealer;
	 
	 if (enmy->type == FIGHTER)
	 {
		 Fighter *F;
		 F->count++;
		 BST Afighter;
		 add(arrivaltime, *F, *node);

	 }

	 if (enmy->type == HEALER)
	 {
		 Healer *H;
		 H->count++;
		 BST Ahealer;
		 add(arrivaltime, *H, *node);
	 }

	 if (enmy->type == FREEZER)
	 {
		 Frezeer *FR;
		 FR->count++;
		 BST Afrezer;
		 add(arrivaltime, *FR, *node);
	 }
}