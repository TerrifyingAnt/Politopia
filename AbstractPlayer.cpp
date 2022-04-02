#include "AbstractPlayer.h"
#include <iostream>

using namespace std;


// конструктор нпс
AbstractPlayer::AbstractPlayer(string type, int x, int y, int level, int step_number)
{
	// придумай там что-нибудь потом, проблема простенькая, ты разберешься...
	// долбоеб, спустя полгода ты еле-еле вспомнил, что это за проблема вообще
	// проблема в том, что
	// нужно создать ожну глобавльную переменную, которая будет счетчиком ходов во всей игре
	// блять или нет...
	temp_step = step_number; 
	this->type = type;
	this->level = level;
	setPos(x, y);
}


	/*
	* метод перемещения, где:
	* NW N NE
	* W	   E
	* SW S SE
	*/

// блятб, допиши метод, который переводит строку с направлением в длеьта икс и дельта игрек, тогда можно будет тупо прибавлять полученные 0 и 1 к текущим координатам
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


// метод выполнения хода --> должен быть, пока не ебу как реализовать
// UPD: теперь ебу, и даже запишу дату этого дня: 04.02.22, а начинал ты эту хуйню осенью 21, гений мысли))
// ладно, к тому, как делать ходы
// #define step(*p_signal)(int x, int y, enum ACTIVITY_TYPE) --> Что это за херня?
// твои любимые сигналы и обработчики
// создаешь новый тип, указатель на метод
// тогда по таким общим параметрам сможешь передавать метод
// написать метод, который смотрит, что там за херня в указателе будет просто, как и выполнить метод
// гений мысли на ебучем безделии, держу в курсе

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
//сеттеры
//

// метод устанавливает координаты нпс
void AbstractPlayer::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

// метод установки здоровья
void AbstractPlayer::setHealth(int health)
{
	this->health = health;
}

// метод установки урона
void AbstractPlayer::setDamage(int damage)
{
	this->damage = damage;
}

// метод установки имени нпс
void AbstractPlayer::setName(string name)
{
	this->name = name;
}

// метод создает список заданий для нпс 
void AbstractPlayer::setActivityList(int* activity)
{
	this->activity = activity;
}

//
//геттеры
//

 // метод получения х-координаты нпс
int AbstractPlayer::getPos_x()
{
	return x;
}

// метод получения у-координаты нпс
int AbstractPlayer::getPos_y()
{
	return y;
}

// метод получения здоровья
int AbstractPlayer::getHealth()
{
	return health;
}

// метод получения урона
int AbstractPlayer::getDamage()
{
	return damage;
}

// метод получения имени
string AbstractPlayer::getName()
{
	return name;
}

// метод получения списка заданий
int* AbstractPlayer::getActivityList()
{
	return activity;
}

// метод получения уровня
int AbstractPlayer::getLevel()
{
	return level;
}

// метод получения ресурсов
Resource* AbstractPlayer::getResources()
{
	return backpack;
}


