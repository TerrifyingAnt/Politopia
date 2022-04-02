#pragma once
#include <iostream>
#include "Structers.h"

#ifndef MAP_H
#define MAP_H

int const MAP_SIZE = 16;

class Map
{
private:
	Tile** map; // �����


public:
	Map(); // �����������
	Tile** generateMap(); // ����� ��������� �����
	void show(); // ����� ������ �����

	//�������
	bool isEmpty(Tile tile); // ����� ���������� ���� isEmpty ������ ������
	Resource getResource(Tile tile); // ����� ���������� ������� � ������ ������
	int getPos_x(Tile tile); // ����� ���������� ������� ������� ������ ������
	int getPos_y(Tile tile); // ����� ���������� ��������� ������� ������ ������


	//�������
	void setEmpty(Tile tile); // ����� ������������� ���� isEmpty ������ ������
	void setResource(Tile tile, Resource resource ); // ����� ������������� ������� ��� ������ ������
	void setGround(Tile tile); // ����� ������������� ����� � ������ ������
	void setWater(Tile tile); // ����� ������������� ���� � ������ ������
	void setCity(Tile tile); // ����� ������ ����� � ������ ������
};

/*
* ����� � �� ������ �������...
* � ��� ����
* ������ ������ ��� ����� � ������� ��������� ����
* ������ ����� ���� � ����� ������ ������������ ����� ��������� ��������, � ������ ����� ���� �����
* ����� ���������, ��� � ��� ��� � �������� ��������
* �� ���� ������������ ����� � ����
* ����� � ������� ���� ���, ��� ��� ��� �������� ��� ������������� ����� ����� �����
* ���� ������ ����� �� �������� ��������
* ���� ������ ����������� ������� ������ ���� �����
* ����� ��������� ���� �������� ������� �� ���������
* ������� � ������� �������� ���� ����� ������� ���� � ����, ��� ����� ����� �������� �������
*
* ��������� �� �������� ����� �� ������� �� ���������
* ������������� � �������� ������ ��� ������� � �����, � � ������ ��������� ����� ������ �������� ����� � "�����"
*/

#endif


