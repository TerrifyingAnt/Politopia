#pragma once
#include <iostream>
#include "Structers.h"
using namespace std;
#ifndef ABSTRACTPLAYER_H
#define ABSTRACTPLAYER_H


// � ���� ��� ������, ������ ��� �� ��� ��� �����, ��������� �� ������ ��� �������

#define step void(*method)(int delta_x, int delta_y, ENUM Activity);

class AbstractPlayer
{
private:
	string type; // ��� ���
	
	// ��� ��� ��� � ������������
	int x, y; // ���������� ��� �� ����
	int health; // ���������� �� ���
	int damage; // ���� ���
	int level; // ������� ���
	string name; // ��� ���
	int temp_step; // ������� ���
	//�� ���� ���

	// ����� ������������ �����������
	int mineAbility; // ����������� �������� ������� �� ���
	Resource* backpack; // ������
	int backpack_size; // ������ �������
	int* activity; // ������ ��������, ������� ��� ������ ������� �� ���



public:
	AbstractPlayer(string type, int x, int y, int level, int step_number); // �����������
	virtual void move(string direction); // ����� ����������� ���
	//virtual int attack(int damage); // ����� ����� ���
	//virtual void defense(int damage); // ����� ��������� �����
	//virtual void levelUp(); // ����� ��������� ������ ���
	virtual void doActivityList(); // ����� ���������� ���� --> ������ ����, ���� �� ��� ��� �����������: UPD: � ������� ����� ��� step, ��������� �� �����. ������ ����, ��-�������� � ������ ���� ������������ �������� ������ ����
	virtual void mineResource(Resource resource); // ����� ������ ��������

	//�������
	virtual void setPos(int x, int y); // ����� ������������� ���������� ���
	virtual void setHealth(int health); // ����� ��������� ��������
	virtual void setDamage(int damage); // ����� ��������� �����
	virtual void setName(string name); // ����� ��������� ����� ���
	virtual void setActivityList(int* activity); // ����� ������� ������ ������� ��� ��� 

	//�������
	virtual int getPos_x(); // ����� ��������� �-���������� ���
	virtual int getPos_y(); // ����� ��������� �-���������� ���
	virtual int getHealth(); // ����� ��������� ��������
	virtual int getDamage(); // ����� ��������� �����
	virtual string getName(); // ����� ��������� �����
	virtual int* getActivityList(); // ����� ��������� ������ �������
	virtual int getLevel(); // ����� ��������� ������
	virtual Resource* getResources(); // ����� ��������� ��������
};

/*
* �����:
* ������� ��� ������ �������, �������������� ����, �������� � ���������
* ��� ������ ����������� �� �������, ������, ����� ������ ����� �����, � ������� ���� ����� �������� � ����� ������
* ������� �������� ������� �� �����, ��� � �������
* ������ attack, defense � levelUp ������ � ����������� ������ ����� �� �����
*	UPD: ������ mineResources, ����, ����
* � ����������� �������� ������ ��������� level, x, y, ��������� �������� ����� ������������
* �������� ����������� ��������, ������� ����� ������� ������� ��� �� ���� ����, � ����� ��������� ��������, �������� ������� ��� ������� ���
* �����? ���� � ���� ���������� �������� ������� � �������, �� ������ �������� ������� ����� �����
* ����� � ���� �����, ������ �� ��� ���� �������� �� ��� (���� ����������� - ��������� != 0)
* ����� ����� ����� ���������, ��� ����� ����������� ����� ������ � �����
* 
*/
#endif // !ABSTRACTPLAYER_H
