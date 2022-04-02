#include <iostream>
using namespace std;
#ifndef STRUCTERS_H
#define STRUCTERS_H

// ��������� ��������, �������� ��� ������� string type � ���������� ������a int count 
struct Resource
{
	string type;
	int count;
};

// ��������� ����� ������ ���� 
struct Tile
{
	Resource resource;
	bool ground;
	bool water;
	bool city; // �������� �� ����� �����
	bool npc;
	bool isEmpty; // ���� �������� �� ����������� ����������� ������ �� ������ ������
	int x;
	int y;
};

enum ActivityType
{
	ATTACK,
	MINING,
	STEP,
	DEATH,
	BORN,
	DEFENSE,
	LEVELUP
};
#endif // !STRUCTERS_H
