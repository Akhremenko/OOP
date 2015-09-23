#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>

using namespace std;


#define SIZEOFARRAY 5 

class Airline
{
	string pointOfDestination;
	int numberOfFlight;
	string typeOfPlane;
	string timeOfFlight;
	string dayOfWeek;
	int counter;

public:
	Airline()
	{
		cout << "Работает конструктор без параметров" << endl;
	}

	Airline(string pointOfDestination, int numberOfFlight,
		string typeOfPlane, string timeOfFlight, string dayOfWeek)
	{
		this->pointOfDestination = pointOfDestination;
		this->numberOfFlight = numberOfFlight;
		this->typeOfPlane = typeOfPlane;
		this->timeOfFlight = timeOfFlight;
		this->dayOfWeek = dayOfWeek;
		cout << "Работает конструктор с параметрами" << endl;
	}
	Airline(const Airline& x)
	{
		pointOfDestination = x.pointOfDestination;
		numberOfFlight = x.numberOfFlight;
		typeOfPlane = x.typeOfPlane;
		timeOfFlight = x.timeOfFlight;
	dayOfWeek = x.dayOfWeek;
		cout << "Работает конструктор копирования" << endl;
	}

	~Airline()
	{
		cout << "Работает деструктор" << endl;
	}

	int checkTimeOfFlight(string str)
	{
		int countTime = 0;
		counter = str.length();
		if (counter == 5)
		{
			if (2 < str[0] < 0)
				return 0;
			if (4 < str[1] < 0)
				return 0;
			if (str[2] != ':')
				return 0;
			if (5 < str[3] < 0)
				return 0;
			if (9 < str[4] < 0)
				return 0;
			for (int i = 0; counter > 0; i++, counter--)
			{

				if (str[i] < '0' || str[i] > '9')// СПРОСИТЬ У САШИ
				{
					if (str[i] == ':')
					{
						if (countTime == 0)
							countTime++;
						else
							return 0;
					}
					else
					{
						cout << ":(" << endl;
						return 0;
					}
				}

			}
		}
		else
			return 0;
		return 1;
	}

	int checkInt(int x)
	{
		int y;
		while (x != 0)
		{
			if ('9' < (x % 10) < '0')
				return 0;
			else
				x = x / 10;
		}
		return 1;
	}

	int checkString(string str)
	{
		counter = str.length();
		for (int i = 0; counter > 0; i++, counter--)
		{
			if (str[i] == ' ') 
			{

			}

			else if (str[i] < 'А' || str[i] > 'я')
			{
				return 0;
			}

			else
			{
				if (str[i] <= 'Я' || str[i] >= 'а')
				{
				}
				else
				{
					return 0;
				}

			}
		}
		return 1;
	}

	void setPointOfDestination(string pointOfDestination)
	{
		if (checkString(pointOfDestination))
		{
			this->pointOfDestination = pointOfDestination;
		}
		else
		{
			cout << "Ошибка. Строка " << pointOfDestination << " :(" << endl;
		}
	}

	string getPointOfDestination()
	{
		return pointOfDestination;
	}

	void setNumberOfFlight(int numberOfFlight)
	{
		if (checkInt(numberOfFlight))
		{
			this->numberOfFlight = numberOfFlight;
		}
		else
		{
			cout << "Ошибка. Строка" << numberOfFlight << " :(" << endl;
		}
	}

	int getNumberOfFlight()
	{
		return numberOfFlight;
	}


	void setTypeOfPlane(string typeOfPlane)
	{
		if (checkString(typeOfPlane))
		{
			this->typeOfPlane = typeOfPlane;
		}
		else
		{
			cout << "Ошибка. Строка " << typeOfPlane << " :(" << endl;
		}
	}

	string getTypeOfPlane()
	{
		return typeOfPlane;
	}

	void setTimeOfFlight(string timeOfFlight)
	{
		if (checkTimeOfFlight(timeOfFlight))
		{
			this->timeOfFlight = timeOfFlight;
		}
		else
		{
			cout << "Ошибка. Время" << timeOfFlight << " :(" << endl;
		}
	}

	string getTimeOfFlight()
	{
		return timeOfFlight;
	}

	void setDayOfWeek(string dayOfWeek)
	{
		if (checkString(dayOfWeek))
		{
			this->dayOfWeek = dayOfWeek;
		}
		else
		{
			cout << "Ошибка. День" << dayOfWeek << " :(" << endl;
		}
	}

	string getDayOfWeek()
	{
		return dayOfWeek;
	}

};

void allInfoAboutAirline(Airline *arrayOfAir, int x)
{
	cout << "Пункт назначения - " << arrayOfAir[x].getPointOfDestination() << endl;
	cout << "Номер самолета - " << arrayOfAir[x].getNumberOfFlight() << endl;
	cout << "Тип самолета - " << arrayOfAir[x].getTypeOfPlane() << endl;
	cout << "Время вылета - " << arrayOfAir[x].getTimeOfFlight() << endl;
	cout << "День вылета - " << arrayOfAir[x].getDayOfWeek() << endl;
}

void poiskForPoint(Airline *arrayOfAir, string pointOfDestination)
{
	for (int i = 0; i < SIZEOFARRAY; i++)
	{
		if (arrayOfAir[i].getPointOfDestination() == pointOfDestination)
		{
			cout << "У самолета, номером " << arrayOfAir[i].getNumberOfFlight() << " ,пункт назначения - " << arrayOfAir[i].getPointOfDestination() << endl;
		}
	}
}

void poiskWitheDay(Airline *arrayOfAir, string dayOfWeek)
{
	for (int i = 0; i < SIZEOFARRAY; i++)
	{
		if (arrayOfAir[i].getDayOfWeek() == dayOfWeek)
		{
			cout << "У самолета, номером " << arrayOfAir[i].getNumberOfFlight() << " , день вылета - " << arrayOfAir[i].getDayOfWeek() << endl;
		}
	}
}

void poiskWithTimeAndDay(Airline *arrayOfAir, string dayOfWeek, string timeOfFlight)
{
	string time;

	for (int i = 0; i < SIZEOFARRAY; i++)
	{
		if (arrayOfAir[i].getDayOfWeek() == dayOfWeek)
		{
			time = arrayOfAir[i].getTimeOfFlight();
			for (int x = 0; x < 5; x++)
			{
				if (time[x] > timeOfFlight[x])
				{

					cout << "У самолета, номером " << arrayOfAir[i].getNumberOfFlight() << " , день вылета - " << arrayOfAir[i].getDayOfWeek() <<
						" и время вылета - " << timeOfFlight << endl;
					break;
				}
				else if (timeOfFlight[x] > time[x])
				{
					break;
				}
			}
		}
	}
}

void menu()
{
	cout << endl << "Выберете операцию" << endl;
	cout << "1. Показать информацию о самолете" << endl
		<< "2. Показать список рейсов для заданного пункта назначения" << endl
		<< "3. Показать список рейсов для заданного дня недели" << endl
		<< "4. Показать список рейсов для заданного дня недели, время вылета для которых больше заданного" << endl << endl
		<< "5. Выйти" << endl << endl;
}


void menu2()
{
	cout << endl << "Выберете рейс" << endl << endl
		<< "1. рейс1" << endl << "2. рейс2" << endl
		<< "3. рейс3" << endl << "4. рейс4" << endl
		<< "5. рейс5" << endl;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Airline air1("Минск", 1, "Boeing", "13:25", "Понедельник");
	Airline air2("Брест", 14, "Boeing", "17:02", "Вторник");
	Airline air3("Гомель", 23, "Airbus", "13:12", "Суббота");
	Airline air4("Минск", 71, "Airbus", "22:19", "Вторник");
	Airline air5("Брест", 202, "Boeing", "20:25", "Пятница");
	Airline arrayOfAir[SIZEOFARRAY] = { air1, air2, air3, air4, air5 };

	string samePont = "Минск";
	string sameDay = "Понедельник";
	string presetTime = "13:25";

	int key;
	int key2;
	int cicle = 1;

	while (cicle)
	{
		menu();
		cout << "Выберете: ";
		cin >> key;
		switch (key)
		{
		case 1:
			menu2();
			cout << "Выберете: ";
			cin >> key2;
			if (key2 == 1)
				allInfoAboutAirline(arrayOfAir, 0);
			if (key2 == 2)
				allInfoAboutAirline(arrayOfAir, 1);
			if (key2 == 3)
				allInfoAboutAirline(arrayOfAir, 2);
			if (key2 == 4)
				allInfoAboutAirline(arrayOfAir, 3);
			if (key2 == 5)
				allInfoAboutAirline(arrayOfAir, 4);
			_getch();
			key = 0;
			break;
		case 2:
			cout << endl << "Показать список рейсов для заданного пункта назначения" << samePont << endl;
			poiskForPoint(arrayOfAir, samePont); 
			key = 0;
			_getch();
			break;
		case 3:
			cout << endl << "Показать список рейсов для заданного дня недели " << sameDay << endl;
			poiskWitheDay(arrayOfAir, sameDay);
			key = 0;
			_getch();
			break;
		case 4:
			cout << endl << "Показать список рейсов для заданного дня недели, " << sameDay <<
				" время вылета для которых больше заданного" << presetTime << endl;
			poiskWithTimeAndDay(arrayOfAir, sameDay, presetTime);
			key = 0;
			_getch();
			break;
		case 5:
			cicle = 0;
			_getch();


		}
		system("cls");

	}
}