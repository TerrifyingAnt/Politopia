#pragma once
#include <iostream>
#include "Structers.h"
using namespace std;
#ifndef ABSTRACTPLAYER_H
#define ABSTRACTPLAYER_H


// я пока что пробую, потому что ну хуй его знает, указатели на методы это страшно

#define step void(*method)(int delta_x, int delta_y, ENUM Activity);

class AbstractPlayer
{
private:
	string type; // тип нпс
	
	// вот это все в конструкторе
	int x, y; // координаты нпс на поле
	int health; // количество хп нпс
	int damage; // урон нпс
	int level; // уровень нпс
	string name; // имя нпс
	int temp_step; // текущий ход
	//до сюда вот

	// после наследования реализовать
	int mineAbility; // способность добывать ресурсы за ход
	Resource* backpack; // рюкзак
	int backpack_size; // размер рюкзака
	int* activity; // список действий, который нпс должен сделать за ход



public:
	AbstractPlayer(string type, int x, int y, int level, int step_number); // конструктор
	virtual void move(string direction); // метод перемещения нпс
	//virtual int attack(int damage); // метод атаки нпс
	//virtual void defense(int damage); // метод получения урона
	//virtual void levelUp(); // метод повышения уровня нпс
	virtual void doActivityList(); // метод выполнения хода --> должен быть, пока не ебу как реализовать: UPD: я объявил новый тип step, указатель на метод. Такого типа, по-хорошему и должно быть возвращаемое значение метода хода
	virtual void mineResource(Resource resource); // метод добычи ресурсов

	//сеттеры
	virtual void setPos(int x, int y); // метод устанавливает координаты нпс
	virtual void setHealth(int health); // метод установки здоровья
	virtual void setDamage(int damage); // метод установки урона
	virtual void setName(string name); // метод установки имени нпс
	virtual void setActivityList(int* activity); // метод создает список заданий для нпс 

	//геттеры
	virtual int getPos_x(); // метод получения х-координаты нпс
	virtual int getPos_y(); // метод получения у-координаты нпс
	virtual int getHealth(); // метод получения здоровья
	virtual int getDamage(); // метод получения урона
	virtual string getName(); // метод получения имени
	virtual int* getActivityList(); // метод получения списка заданий
	virtual int getLevel(); // метод получения уровня
	virtual Resource* getResources(); // метод получения ресурсов
};

/*
* Мысли:
* Сделать три класса игроков, соответственно воин, защитник и разведчик
* Все классы наследовать от данного, понять, какие методы нужны точно, а которые есть смысл дописать в самом классе
* Геттеры очевидно трогать не стоит, как и сеттеры
* Методы attack, defense и levelUp писать в абстрактном классе думаю не стоит
*	UPD: методы mineResources, кста, тоже
* В конструктор засунуть только установку level, x, y, остальное допилить после наследования
* Добавить статическое свойство, которое будет хранить текущий ход по всей игре, а также локальное свойство, хранящее текущий ход данного нпс
* Зачем? Если я буду записывать действия игроков в массивы, то индекс элемента массива будет ходом
* Тогда я буду знать, сделал ли нпс свои действия за ход (если статическое - локальной != 0)
* После такой штуки придумать, как можно реализовать класс города и карты
* 
*/
#endif // !ABSTRACTPLAYER_H
