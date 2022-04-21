#include <stdio.h>
#include <math.h>

#define Maxsize 20  

int M[Maxsize]; //глобальная переменная

int maximum(int n) //максимум
{
	int max = M[0];
	for (int i = 1; i < n; i++)
	{
		if (M[i] > max) //сравниваем данный элемент с макс
		{
			max = M[i];
		}
	}
	return max;
}

int minimum(int n) //минимум
{
	int min = M[0];
	for (int i = 1; i < n; i++)
	{
		if (M[i] < min) //сравниваем данный элемент с мин
		{
			min = M[i];
		}
	}
	return min;
}

double average(int n) //среднее значение
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += M[i]; //сумма всех элементов
	}
	return (double)sum / n; //среднее 
}

double StandartDeviation(int n) //среднеквадратичное отклонение
{
	int sqsum = 0;
	double aver = average(n); 
	for (int i = 0; i < n; i++)
	{
		sqsum += pow((M[i] - aver), 2); //формула среднеквад отклонения
	}
	return sqrt((double)sqsum / n);
}

int main()
{int n;
	printf("enter the number of elements you want in your array: N= \n");
	scanf_s("%d", &n);
	if (n > Maxsize || n < 1) //проверка на корректность ввода
	{
		printf("Enter size from 1 to %i.\n", Maxsize);
		return 13; 
	}
	for (int i = 0; i < n; i++) //создаем массив
	{
		printf("M[%d]=", i);
		scanf_s("%d", &M[i]);
	}
	printf("min: %i\n", minimum(n)); //вывод значений
	printf("max: %i\n", maximum(n));
	printf("average: %f\n", average(n));
	printf("StandartDeviation:  %f\n", StandartDeviation(n));
	return 0;
}
