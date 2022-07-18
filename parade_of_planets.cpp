#include <iostream>
using namespace std;

class planet
{
public:

	int time;      //Время прохождения планеты одного градуса
	int  degree;   //Счетчик градусов
	int day;       //Счетчик времени

	planet(int a, int b = 0)
	{
		time = a;
		degree = b;
		day = 0;
	}

	void set_degree()
	{
		degree++;

		if (degree > 359) degree = 0;
	}
	
};


void main()
{
	system("chcp 1251>nul");

	cout << "\t\t\tРасчет парада планет" << endl;

	const int numberOfPlanets = 4;
	int year = 0;

	planet Mercury(2, 20), Venus(4), Earth(6), Mars(8);
	planet Sol[numberOfPlanets]{ Mercury, Venus, Earth, Mars };

	for (;;)
	{
		int count = 1;

		for (int i = 0; i < numberOfPlanets; i++)
		{
			Sol[i].day++;
		}

		for (int i = 0; i < numberOfPlanets; i++)
		{
			if (Sol[i].day >= Sol[i].time)
			{
				Sol[i].set_degree();
				Sol[i].day = 0;
			}
		}

		if (Sol[0].degree == 0) year++;

		for(int i = 1; i < numberOfPlanets; i++)
		{
			int a = Sol[0].degree - Sol[i].degree;

			if (0 <= a && a <= 10) count++;
			else if (0 >= a && a >= -10) count++;
			else if (-359 <= a && a <= -349) count++;
			else if (359 >= a && a >= 349) count++;
		}

		if (count == numberOfPlanets)
		{
			cout << year << endl;
			break;
		}
	}

}
