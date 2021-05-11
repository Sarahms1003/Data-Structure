#include"Healer.h"
#include"Stack.h"

Healer::Healer(int id, int arrTime, int d) :ID(id), Arrival_time(arrTime)
{
	SetDistance(d);
}

Healer::~Healer()
{
}

int Healer::GetID() const
{
	return ID;
}


void Healer::SetStatus(ENMY_STATUS s)
{
	status = s;
}


ENMY_STATUS Healer::GetStatus() const
{
	return status;
}


void Healer::DecrementDist()
{
	if (Distance > MinDistance)
		Distance--;
}
void Healer::IncrementDist()
{
	if (Distance < MaxDistance)
	{
		Distance++;
	}
}

void Healer ::SetHealerDistance(int d)
{
	if (d >= MinDistance && d <= MaxDistance)
		Distance = d;
	else
		Distance = MaxDistance;
}

int Healer::GetHealerDistance() const
{
	return Distance;
}



int Healer::GetArrvTime() const
{
	return ArrvTime;
}

void Healer::Heal_Enemy() 
{
	Enemy* pE;
	Healer* pH;
	if ((pE->GetDistance() - pH->GetHealerDistance() == 2) || (pE->GetDistance() - pH->GetHealerDistance() < 2))
	{
		pE->SetHealth(Health + 1);
	}
}
bool Healer::isHealed() 
{
	Enemy* pE;
	if ((pE->GetStatus() == FRST) && (pE->GetStatus() == KILD))
		return false;
	
}

void Healer::Move() 
{
	if ((time) && (GetDistance() > 2))
		DecrementDist();
	else if ((time) && (GetDistance()) < 60)
		IncrementDist();
}
void Healer::Act()
{
	Enemy* pE;
	Healer* pH;
	while (Arrival_time > oB.CurrentTimeStep)
	{
		if (abs(pE->GetDistance()-pH->GetDistance() <= 2 )) //Think of the formula later
		pE->SetHealth(Health + 1);
	}

}

void Healer::kill_Healer(int arrivalTime)  //(Last come, first serve) "Stack"
{
	/*Healer* pH;
	if (arrivalTime < Arrival_time)
	{
		ENMY_STATUS k = KILD;
		pH->SetStatus(k);
	}*/
	Stack <Healer*> sG;
	Healer* sH;
	if (sH->ArrvTime < arrivalTime)
	{
		sG.pop();
	}

	
}
