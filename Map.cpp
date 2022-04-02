#include <iostream>
#include <iomanip>
#include <time.h>
#include "Map.h"
using namespace std;

// конструктор
Map::Map()
{
	map = generateMap();
}

// метод генерации карты
Tile** Map::generateMap()
{
	srand(time(NULL));
	int x_start, x_end, y_start, y_end, temp;

	Tile** field = new Tile* [MAP_SIZE + 2];
	for (int i = 0; i < MAP_SIZE + 2; i++)
		field[i] = new Tile[MAP_SIZE + 2];

	// скромный вопрос а нахуй ты геттеры с сеттерами сделал, если активно их не используешь?) 04.02.22
	// заполнение землей всей карты
	for (int y = 1; y < MAP_SIZE + 1; y++)
	{
		for (int x = 1; x < MAP_SIZE + 1; x++)
		{
			field[y][x].ground = true;
			field[y][x].water = false;
			field[y][x].city = false;
			field[y][x].npc = false;
			field[y][x].x = x;
			field[y][x].y = y;
		}
	}



	// попытка создать водоемы
	temp = rand() % MAP_SIZE; // изменить на что-то более прикольное
	for (int i = 0; i < temp; i++)
	{
		x_start = rand() % MAP_SIZE;
		y_start = rand() % MAP_SIZE;
		field[y_start][x_start].ground = false;
		field[y_start][x_start].water = true;
		field[y_start][x_start + 1].ground = false;
		field[y_start][x_start + 1].water = true;
		field[y_start + 1][x_start + 1].ground = false;
		field[y_start + 1][x_start + 1].water = true;
		field[y_start + 1][x_start].ground = false;
		field[y_start + 1][x_start].water = true;
	}


	return field;
}

// метод вывода карты
void Map::show()
{
	for (int i = 1; i < MAP_SIZE; i++) 
	{
		for (int j = 1; j < MAP_SIZE; j++)
		{
			if (map[i][j].water)
				cout << setw(2) << "~";
			else
				if (map[i][j].ground)
					cout << setw(2) << "#";
		}
		cout << endl;
	}
}



//геттеры

// метод возварщает флаг isEmpty данной клетки
bool Map::isEmpty(Tile tile)
{
	return tile.isEmpty;
}

// метод возвращает ресурсы с данной клетки
Resource Map::getResource(Tile tile)
{
	return tile.resource;
}

// метод возвращает иксовую позицию данной клетки
int Map::getPos_x(Tile tile)
{
	return tile.x;
}

// метод возвращает игриковую позицию данной клетки
int Map::getPos_y(Tile tile)
{
	return tile.y;
}


//сеттеры

// метод устанавливает флаг isEmpty данной клетки
void Map::setEmpty(Tile tile)
{
	map[tile.y][tile.x].isEmpty = false;
}

// метод устанавливает ресурсы для данной клетки
void Map::setResource(Tile tile, Resource resource)
{
	map[tile.y][tile.x].resource = resource;
}

// метод устанавливает землю в данную клетку
void Map::setGround(Tile tile)
{
	map[tile.y][tile.x].ground = true;
}

// метод устанавливает воду в данную клетку
void Map::setWater(Tile tile)
{
	map[tile.y][tile.x].water = true;
}

// метод строит город в данной клетке
void Map::setCity(Tile tile)
{
	map[tile.y][tile.x].city = true;
}