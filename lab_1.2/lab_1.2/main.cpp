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
		cout << "�������� ����������� ��� ����������" << endl;
	}

	Airline(string pointOfDestination, int numberOfFlight,
		string typeOfPlane, string timeOfFlight, string dayOfWeek)
	{
		this->pointOfDestination = pointOfDestination;
		this->numberOfFlight = numberOfFlight;
		this->typeOfPlane = typeOfPlane;
		this->timeOfFlight = timeOfFlight;
		this->dayOfWeek = dayOfWeek;
		cout << "�������� ����������� � �����������" << endl;
	}
	Airline(const Airline& x)
	{
		pointOfDestination = x.pointOfDestination;
		numberOfFlight = x.numberOfFlight;
		typeOfPlane = x.typeOfPlane;
		timeOfFlight = x.timeOfFlight;
	dayOfWeek = x.dayOfWeek;
		cout << "�������� ����������� �����������" << endl;
	}

	~Airline()
	{
		cout << "�������� ����������" << endl;
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

				if (str[i] < '0' || str[i] > '9')// �������� � ����
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

			else if (str[i] < '�' || str[i] > '�')
			{
				return 0;
			}

			else
			{
				if (str[i] <= '�' || str[i] >= '�')
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
			cout << "������. ������ " << pointOfDestination << " :(" << endl;
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
			cout << "������. ������" << numberOfFlight << " :(" << endl;
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
			cout << "������. ������ " << typeOfPlane << " :(" << endl;
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
			cout << "������. �����" << timeOfFlight << " :(" << endl;
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
			cout << "������. ����" << dayOfWeek << " :(" << endl;
		}
	}

	string getDayOfWeek()
	{
		return dayOfWeek;
	}

};

void allInfoAboutAirline(Airline *arrayOfAir, int x)
{
	cout << "����� ���������� - " << arrayOfAir[x].getPointOfDestination() << endl;
	cout << "����� �������� - " << arrayOfAir[x].getNumberOfFlight() << endl;
	cout << "��� �������� - " << arrayOfAir[x].getTypeOfPlane() << endl;
	cout << "����� ������ - " << arrayOfAir[x].getTimeOfFlight() << endl;
	cout << "���� ������ - " << arrayOfAir[x].getDayOfWeek() << endl;
}

void poiskForPoint(Airline *arrayOfAir, string pointOfDestination)
{
	for (int i = 0; i < SIZEOFARRAY; i++)
	{
		if (arrayOfAir[i].getPointOfDestination() == pointOfDestination)
		{
			cout << "� ��������, ������� " << arrayOfAir[i].getNumberOfFlight() << " ,����� ���������� - " << arrayOfAir[i].getPointOfDestination() << endl;
		}
	}
}

void poiskWitheDay(Airline *arrayOfAir, string dayOfWeek)
{
	for (int i = 0; i < SIZEOFARRAY; i++)
	{
		if (arrayOfAir[i].getDayOfWeek() == dayOfWeek)
		{
			cout << "� ��������, ������� " << arrayOfAir[i].getNumberOfFlight() << " , ���� ������ - " << arrayOfAir[i].getDayOfWeek() << endl;
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

					cout << "� ��������, ������� " << arrayOfAir[i].getNumberOfFlight() << " , ���� ������ - " << arrayOfAir[i].getDayOfWeek() <<
						" � ����� ������ - " << timeOfFlight << endl;
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
	cout << endl << "�������� ��������" << endl;
	cout << "1. �������� ���������� � ��������" << endl
		<< "2. �������� ������ ������ ��� ��������� ������ ����������" << endl
		<< "3. �������� ������ ������ ��� ��������� ��� ������" << endl
		<< "4. �������� ������ ������ ��� ��������� ��� ������, ����� ������ ��� ������� ������ ���������" << endl << endl
		<< "5. �����" << endl << endl;
}


void menu2()
{
	cout << endl << "�������� ����" << endl << endl
		<< "1. ����1" << endl << "2. ����2" << endl
		<< "3. ����3" << endl << "4. ����4" << endl
		<< "5. ����5" << endl;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Airline air1("�����", 1, "Boeing", "13:25", "�����������");
	Airline air2("�����", 14, "Boeing", "17:02", "�������");
	Airline air3("������", 23, "Airbus", "13:12", "�������");
	Airline air4("�����", 71, "Airbus", "22:19", "�������");
	Airline air5("�����", 202, "Boeing", "20:25", "�������");
	Airline arrayOfAir[SIZEOFARRAY] = { air1, air2, air3, air4, air5 };

	string samePont = "�����";
	string sameDay = "�����������";
	string presetTime = "13:25";

	int key;
	int key2;
	int cicle = 1;

	while (cicle)
	{
		menu();
		cout << "��������: ";
		cin >> key;
		switch (key)
		{
		case 1:
			menu2();
			cout << "��������: ";
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
			cout << endl << "�������� ������ ������ ��� ��������� ������ ����������" << samePont << endl;
			poiskForPoint(arrayOfAir, samePont); 
			key = 0;
			_getch();
			break;
		case 3:
			cout << endl << "�������� ������ ������ ��� ��������� ��� ������ " << sameDay << endl;
			poiskWitheDay(arrayOfAir, sameDay);
			key = 0;
			_getch();
			break;
		case 4:
			cout << endl << "�������� ������ ������ ��� ��������� ��� ������, " << sameDay <<
				" ����� ������ ��� ������� ������ ���������" << presetTime << endl;
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