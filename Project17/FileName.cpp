#include <iostream>
#include <Windows.h>

void Data(int year, int month, int day, int yearTwo, int monthTwo, int dayTwo)
{
	int sumOneData = day;
	int sumTwoData = dayTwo;
	int result = sumOneData - sumTwoData;

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		sumOneData += 31;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		sumOneData += 30;
	}
	else if (month == 2)
	{
		sumOneData += 28;
	}


	if (monthTwo == 1 || monthTwo == 3 || monthTwo == 5 || monthTwo == 7 || monthTwo == 8 || monthTwo == 10 || monthTwo == 12)
	{
		sumTwoData += 31;
	}
	else if (monthTwo == 4 || monthTwo == 6 || monthTwo == 9 || monthTwo == 11)
	{
		sumTwoData += 30;
	}
	else if (monthTwo == 2)
	{
		sumTwoData += 28;
	}


	if (year != yearTwo)
	{
		result += (year - yearTwo) * 365;
	}

	if (result < 0)
	{
		result *= -1;
	}

	std::cout << "Разница между датами: " << result << " дней\n\n";
}

void LeapYear(int year, int yearTwo)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 100 == 0 && year % 400 == 0)
	{
		std::cout << year << " год является високосным!";

	}
	else if (yearTwo % 4 == 0 && yearTwo % 100 != 0 || yearTwo % 100 == 0 && yearTwo % 400 == 0)
	{
		std::cout << yearTwo << " год является високосным!";
	}
}


void Arifmetic(int mass[], const int size)
{
	double summa = 0;
	double result;

	for (int i = 0; i < size; i++)
	{
		mass[i] = rand() % 11;
		std::cout << mass[i] << " ";
	}

	std::cout << "\n";

	for (int i = 0; i < size; i++)
	{
		summa += mass[i];
	}

	result = summa / size;

	std::cout << result;
}



void Array(int array[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "Введите " << i + 1 << "-е число: ";
		std::cin >> array[i];
	}
}

void ArrayElements(int array[], const int size)
{
	int positive = 0, negative = 0, zero = 0;

	for (int i = 0; i < size; i++)
	{
		if (array[i] > 0)
		{
			positive++;
		}
		else if (array[i] < 0)
		{
			negative++;
		}
		else
		{
			zero++;
		}
	}

	std::cout << "Положительных значений: " << positive << "\nОтрицательных значений: " << negative << "\nНулевых значений: " << zero;
}


int TaskOne()
{
	int a;
	std::cout << "Введите год: ";
	std::cin >> a;

	int b;
	std::cout << "Введите месяц: ";
	std::cin >> b;

	int c;
	std::cout << "Введите день: ";
	std::cin >> c;


	int z;
	std::cout << "Введите год: ";
	std::cin >> z;

	int x;
	std::cout << "Введите месяц: ";
	std::cin >> x;

	int y;
	std::cout << "Введите день: ";
	std::cin >> y;

	Data(a, b, c, z, x, y);

	LeapYear(a, z);

	return 0;
}

int TaskTwo()
{
	srand(time(NULL));

	const int num = 5;
	int array[num];

	Arifmetic(array, num);

	std::cout << "\n";

	return 0;
}

int TaskTree()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int size = 5;
	int mass[size];

	Array(mass, size);
	ArrayElements(mass, size);

	std::cout << "\n";

	return 0;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true)
	{
		int num;
		std::cout << "Выберите задание...\n1) Даты\n2) Среднее арифметическое\n3) Кол-во чисел\nВведите 0 для завершения задания...\n>> ";
		std::cin >> num;

		if (num == 1)
		{
			TaskOne();
		}
		else if (num == 2)
		{
			TaskTwo();
		}
		else if (num == 3)
		{
			TaskTree();
		}
		else if (num == 0)
		{
			break;
		}
	}

	return 0;
}