#include "Fighter.h"
#include "Battle.h"


Fighter::Fighter(int id, int arrTime, int d = MaxDistance)
{
	SetDistance(d);
	
}


Fighter::~Fighter()
{
}

void Fighter::Move()
{
	Fighter *F;
	if (F->ArrvTime > Manage.CurrentTimeStep && Distance <= 60 && Distance >= 2)
	{
		DecrementDist();
	}
}

void Fighter::Act()
{
	Fighter *F;

	while (F->ArrvTime > Manage.CurrentTimeStep && Distance <=60 && Distance >=2)
	{
		int attacktime = ArrvTime;
		if (Manage.CurrentTimeStep = (attacktime + ReloadPeriod + 1))
		{

			if (INChangeSpeed)
			{
				F_Castle.SetHealth((1 / Distance)*Power);
			}
			if (!INChangeSpeed)
			{
				F_Castle.SetHealth((0.5 / Distance)*Power);
			}
			attacktime = ArrvTime + ReloadPeriod + 1;
		}
	}
}

void Fighter::Reload()
{
	Move();
}
void Fighter::SetStatusValue()
{
	if (status == INAC || status== KILD)
		StatusValue == 0;
	if (status == ACTV)
		StatusValue == .80;
	if (status == INAC)
		StatusValue == .20;
}
int Fighter::GetStatusValue()
{

}
void Fighter::SetPriority()
{
	Priority = StatusValue*0.4 + ((MaxDistance - Distance) / 60)*0.2 + (Health / GetHealth())*0.2 + (Power / 100)*0.2;
}

double Fighter::GetPriority() const
{
	return Priority;
}
void Fighter::AddFighter()
{
	Fighter NewFighter;
	NewFighter.PQ.insert(ID, Priority);
}

double Fighter::GetHighestPriority() 
{
	Fighter NewFighter;
	double max = NewFighter.Priority;
	for (int i = 0; i++; i < count)
	{
		if (max < NewFighter.Priority)
		{
			max == Priority;
		}
	}
	return max;
}