#pragma once
#include <stdexcept>
#include <vector>

using namespace std;



/*HomeWork1
Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров и запускать исключение DivisionByZero, 
если второй параметр равен 0. В функции main выводить результат вызова функции div в консоль, 
а также ловить исключения.
*/
template <typename T1, typename T2>
auto div(T1 numerator, T2 denominator)
{
	return numerator / denominator;
}

/*HomeWork2 
Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу, 
инициализирующий x значением параметра. 
Написать класс Bar, хранящий вещественное число y (конструктор по умолчанию инициализирует его нулем) 
и имеющий метод set с единственным вещественным параметром a. Если y + a > 100, возбуждается исключение типа Ex с данными a*y, 
иначе в y заносится значение a. 
В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n. 
Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0. 
В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.
*/
class Ex
{
private:
	double x;
public:
	Ex(double input) : x(input) {}

	double getX()
	{
		return x;
	}
};

class Bar
{
private:
	double y;
public:
	Bar():y(0) {}
	void set(double a)
	{
		if (y + a > 100)
		{
			throw Ex(a * y);
		}
		else y = a;
	}
	double getY()
	{
		return y;
	}
};

/*HomeWork3
Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод, означающий задание переместиться на соседнюю позицию. 
Эти методы должны запускать классы-исключения OffTheField, если робот должен уйти с сетки, 
и IllegalCommand, если подана неверная команда (направление не находится в нужном диапазоне). 
Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения. 
Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от его методов, 
а также выводящую подробную информацию о всех возникающих ошибках.
*/
class Cell
{
private:
	int x, y;
	bool containsRobot = false;
public:
	Cell(int inputX, int inputY) : x(inputX), y(inputY) {}

	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}

	void setX(int input)
	{
		x = input;
	}

	void setY(int input)
	{
		y = input;
	}
};

class Robot
{
private:
	int fieldSize;
	Cell currentCell;
public:
	Robot(int inputSize) : fieldSize(inputSize), currentCell(0, 0) {}

	void move()
	{
		string axis, direction;
		try
		{
			cout << "Choose movement axis (x, y):";
			cin >> axis;
			if (axis != "x" && axis != "y") throw IllegalCommand();

			cout << "Choose movement direction (+, -):";
			cin >> direction;
			if (direction != "+" && direction != "-") throw IllegalCommand();
		}
		catch (IllegalCommand)
		{
		}

		int newCoord = 0;

		if (axis == "x" && direction == "+")
		{
			try
			{
				newCoord = currentCell.getX() + 1;
				if (newCoord >= fieldSize)
				{
					throw OffTheField(this, axis, direction);
				}
				else
				{
					currentCell.setX(newCoord);
				}
			}
			catch (OffTheField& e)
			{
				e.printDetails();
			}
		}

		if (axis == "x" && direction == "-")
		{
			try
			{
				newCoord = currentCell.getX() - 1;
				if (newCoord < 0)
				{
					throw OffTheField(this, axis, direction);
				}
				else
				{
					currentCell.setX(newCoord);
				}
			}
			catch (OffTheField& e)
			{
				e.printDetails();
			}
		}

		if (axis == "y" && direction == "+")
		{
			try
			{
				newCoord = currentCell.getY() + 1;
				if (newCoord >= fieldSize)
				{
					throw OffTheField(this, axis, direction);
				}
				else
				{
					currentCell.setY(newCoord);
				}
			}
			catch (OffTheField& e)
			{
				e.printDetails();
			}
		}

		if (axis == "y" && direction == "-")
		{
			try
			{
				newCoord = currentCell.getY() - 1;
				if (newCoord < 0)
				{
					throw OffTheField(this, axis, direction);
				}
				else
				{
					currentCell.setY(newCoord);
					//return true;
				}
			}
			catch (OffTheField& e)
			{
				e.printDetails();
				//return false;
			}
		}
	}

	int getCoordX()
	{
		return currentCell.getX();
	}

	int getCoordY()
	{
		return currentCell.getY();
	}

	void printCoordinates()
	{
		cout << "Current coordinates (x, y): (" << currentCell.getX() + 1 << "," << currentCell.getY() + 1 << ")\n";
	}

	class IllegalCommand
	{
	public:
		IllegalCommand()
		{
			system("cls");
			cout << "Incorrect command! Choose correct axis and direction.\n";
		}
	};

	class OffTheField
	{
	private:
		Robot* robotPtr;
		string axis, direction;
	public:
		OffTheField(Robot* robot, string inputAxis, string inputDirection) : robotPtr(robot), axis(inputAxis), direction(inputDirection) {}
		void printDetails() const
		{
			cout << "\nIncorrect input, Robot will be off the field!\nInitial coordinates (x, y): (" << robotPtr->getCoordX() + 1 << "," << robotPtr->getCoordY() + 1 << ")\n";
			cout << "Movement axis: " << axis << ", movement direction: " << direction << "\n";
		}
	};
};
