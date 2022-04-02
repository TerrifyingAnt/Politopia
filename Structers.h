#include <iostream>
using namespace std;
#ifndef STRUCTERS_H
#define STRUCTERS_H

// структура ресурсов, содержит тип ресурса string type и количество ресурсa int count 
struct Resource
{
	string type;
	int count;
};

// структура ожной клетки поля 
struct Tile
{
	Resource resource;
	bool ground;
	bool water;
	bool city; // Изменить на класс потом
	bool npc;
	bool isEmpty; // флаг отвечает за возможность наступления игрока на данную клетку
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
