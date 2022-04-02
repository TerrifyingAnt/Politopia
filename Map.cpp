#include <iostream>
#include <iomanip>
#include <time.h>
#include "Map.h"
using namespace std;

// �����������
Map::Map()
{
	map = generateMap();
}

// ����� ��������� �����
Tile** Map::generateMap()
{
	srand(time(NULL));
	int x_start, x_end, y_start, y_end, temp;

	Tile** field = new Tile* [MAP_SIZE + 2];
	for (int i = 0; i < MAP_SIZE + 2; i++)
		field[i] = new Tile[MAP_SIZE + 2];

	// �������� ������ � ����� �� ������� � ��������� ������, ���� ������� �� �� �����������?) 04.02.22
	// ���������� ������ ���� �����
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



	// ������� ������� �������
	temp = rand() % MAP_SIZE; // �������� �� ���-�� ����� ����������
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

// ����� ������ �����
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



//�������

// ����� ���������� ���� isEmpty ������ ������
bool Map::isEmpty(Tile tile)
{
	return tile.isEmpty;
}

// ����� ���������� ������� � ������ ������
Resource Map::getResource(Tile tile)
{
	return tile.resource;
}

// ����� ���������� ������� ������� ������ ������
int Map::getPos_x(Tile tile)
{
	return tile.x;
}

// ����� ���������� ��������� ������� ������ ������
int Map::getPos_y(Tile tile)
{
	return tile.y;
}


//�������

// ����� ������������� ���� isEmpty ������ ������
void Map::setEmpty(Tile tile)
{
	map[tile.y][tile.x].isEmpty = false;
}

// ����� ������������� ������� ��� ������ ������
void Map::setResource(Tile tile, Resource resource)
{
	map[tile.y][tile.x].resource = resource;
}

// ����� ������������� ����� � ������ ������
void Map::setGround(Tile tile)
{
	map[tile.y][tile.x].ground = true;
}

// ����� ������������� ���� � ������ ������
void Map::setWater(Tile tile)
{
	map[tile.y][tile.x].water = true;
}

// ����� ������ ����� � ������ ������
void Map::setCity(Tile tile)
{
	map[tile.y][tile.x].city = true;
}