#include <iostream>
#include "homework8.h"

using namespace std;

void obzac()
{
	cout << "\n\n//====================================HomeWork====================================//\n\n";
}
void obzac1()
{
	cout << "\n\n//======================================END======================================//\n\n";
}
void obzac2()
{
	cout << "\n\n//-------------------------------------------------------------------------------//\n\n";
}



int main()
{
	//HomeWork1 ===============================================================================================
	{
		obzac();
		cout << "Task 1:\n";
		int numerator = 10;
		double denominator = 18;
		try
		{
			if (denominator == 0) throw overflow_error("Division by zero");
			cout << numerator << " / " << denominator << " = " << div(numerator, denominator);
		}
		catch (overflow_error)
		{
			cout << "Division by zero!";
		}
		obzac2();
	}

	//HomeWork2 ===============================================================================================
	{
		obzac();
		cout << "\n\nTask 2:\n";
		Bar* bar = new Bar();
		int n = 0;
		try
		{
			bool nNotZero = true;
			while (nNotZero)
			{
				cout << "Enter n: ";
				cin >> n;
				if (n != 0)
				{
					bar->set(n);
				}
				else nNotZero = false;
			}
		}
		catch (Ex& e)
		{
			cout << "Exception thrown, code " << e.getX();
		}
		delete bar;
		obzac2();
	}

	//HomeWork3 ===============================================================================================
	{
		obzac();
		cout << "\nTask 3:\n";
		int fieldSize = 10;
		Robot* robot = new Robot(fieldSize);

		while (true)
		{
			robot->printCoordinates();
			robot->move();
		}
		delete robot;
		obzac1();
	}
}
