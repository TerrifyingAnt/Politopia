#include "AbstractPlayer.h"
#include <iostream>

using namespace std;


// ����������� ���
AbstractPlayer::AbstractPlayer(string type, int x, int y, int level, int step_number)
{
	// �������� ��� ���-������ �����, �������� �����������, �� �����������...
	// �������, ������ ������� �� ���-��� ��������, ��� ��� �� �������� ������
	// �������� � ���, ���
	// ����� ������� ���� ����������� ����������, ������� ����� ��������� ����� �� ���� ����
	// ����� ��� ���...
	temp_step = step_number; 
	this->type = type;
	this->level = level;
	setPos(x, y);
}


	/*
	* ����� �����������, ���:
	* NW N NE
	* W	   E
	* SW S SE
	*/

// �����, ������ �����, ������� ��������� ������ � ������������ � ������ ��� � ������ �����, ����� ����� ����� ���� ���������� ���������� 0 � 1 � ������� �����������
void AbstractPlayer::move(string direction)
{

	if (direction == "N")
		setPos(x, y + 1);
	else
		if (direction == "NE")
			setPos(x + 1, y + 1);
		else
			if (direction == "E")
				setPos(x + 1, y);
			else
				if (direction == "SE")
					setPos(x + 1, y - 1);
				else
					if (direction == "S")
						setPos(x, y - 1);
					else
						if (direction == "SW")
							setPos(x - 1, y - 1);
						else
							if (direction == "W")
								setPos(x - 1, y);
							else
								if (direction == "NW")
									setPos(x + 1, y + 1);

}


// ����� ���������� ���� --> ������ ����, ���� �� ��� ��� �����������
// UPD: ������ ���, � ���� ������ ���� ����� ���: 04.02.22, � ������� �� ��� ����� ������ 21, ����� �����))
// �����, � ����, ��� ������ ����
// #define step(*p_signal)(int x, int y, enum ACTIVITY_TYPE) --> ��� ��� �� �����?
// ���� ������� ������� � �����������
// �������� ����� ���, ��������� �� �����
// ����� �� ����� ����� ���������� ������� ���������� �����
// �������� �����, ������� �������, ��� ��� �� ����� � ��������� ����� ������, ��� � ��������� �����
// ����� ����� �� ������ ��������, ����� � �����

void AbstractPlayer::doActivityList()
{
	//do activity[i-1] step
	temp_step++;
	//return *doActivityList(1, 2, );
}


void AbstractPlayer::mineResource(Resource resource)
{
	for (int i = 0; i < backpack_size; i++)
		if (backpack[i].count == -1)
		{
			backpack[i] = resource;
			break;
		}
}


//
//�������
//

// ����� ������������� ���������� ���
void AbstractPlayer::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

// ����� ��������� ��������
void AbstractPlayer::setHealth(int health)
{
	this->health = health;
}

// ����� ��������� �����
void AbstractPlayer::setDamage(int damage)
{
	this->damage = damage;
}

// ����� ��������� ����� ���
void AbstractPlayer::setName(string name)
{
	this->name = name;
}

// ����� ������� ������ ������� ��� ��� 
void AbstractPlayer::setActivityList(int* activity)
{
	this->activity = activity;
}

//
//�������
//

 // ����� ��������� �-���������� ���
int AbstractPlayer::getPos_x()
{
	return x;
}

// ����� ��������� �-���������� ���
int AbstractPlayer::getPos_y()
{
	return y;
}

// ����� ��������� ��������
int AbstractPlayer::getHealth()
{
	return health;
}

// ����� ��������� �����
int AbstractPlayer::getDamage()
{
	return damage;
}

// ����� ��������� �����
string AbstractPlayer::getName()
{
	return name;
}

// ����� ��������� ������ �������
int* AbstractPlayer::getActivityList()
{
	return activity;
}

// ����� ��������� ������
int AbstractPlayer::getLevel()
{
	return level;
}

// ����� ��������� ��������
Resource* AbstractPlayer::getResources()
{
	return backpack;
}


