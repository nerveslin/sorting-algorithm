
#include "stdafx.h"
#include <iostream>
using namespace std;

void quickSort1(int* array, int begin, int end) //алгоритм быстрой сортировки в возрастающем порядке
{
	int pivot = array[begin]; //инициализация опорного элемента
	int start = begin; //начальный элемент
	int finish = end; //конечный элемент

	while (begin < end)
	{
		while ((array[end] >= pivot) && (begin < end)) end--;

		if (begin != end)
		{
			array[begin] = array[end];
			begin++;
		}

		while ((array[begin] <= pivot) && (begin < end)) begin++;

		if (begin != end)
		{
			array[end] = array[begin];
			end--;
		}
	}

	array[begin] = pivot;
	pivot = begin;
	begin = start;
	end = finish;

	if (begin < pivot) quickSort1(array, begin, pivot - 1);

	if (end > pivot) quickSort1(array, pivot + 1, end);
}

void quickSort2(int* array, int begin, int end) //алгоритм быстрой сортировки в убывающем порядке
{

	int pivot = array[begin]; //инициализация опорного элемента
	int start = begin; //начальный элемент
	int finish = end; //конечный элемент

	while (begin < end)
	{
		while ((array[end] <= pivot) && (begin < end)) end--;

		if (begin != end)
		{
			array[begin] = array[end];
			begin++;
		}

		while ((array[begin] >= pivot) && (begin < end)) begin++;

		if (begin != end)
		{
			array[end] = array[begin];
			end--;
		}
	}

	array[begin] = pivot;
	pivot = begin;
	begin = start;
	end = finish;

	if (begin < pivot) quickSort2(array, begin, pivot - 1);

	if (end > pivot) quickSort2(array, pivot + 1, end);
}

void main()
{
	setlocale(LC_ALL, "RUS");

	cout << "Введите количество элементов в массиве: ";
	int N;
	cin >> N;

	cout << "Введите элементы массива: ";
	int *array; //выделение памяти под массив
	array = new int[N];
	int odd = 0; //счет нечетных чисел
	int even = 0; //счет четных чисел
	for (int i = 0; i < N; i++)
	{
		cin >> array[i]; //введение элементов массива пользователем

		if (array[i] % 2 != 0) odd++;
		else even++;
	}

	int *evenArray;
	evenArray = new int[even]; //массив четных чисел
	int *oddArray;
	oddArray = new int[odd]; //массив нечетных чисел
	int k = 0;
	int j = 0;

	for (int i = 0; i < N; i++)
	{
		if (array[i] % 2 != 0)
		{
			oddArray[k] = array[i];
			k++;
		}
		else
		{
			evenArray[j] = array[i];
			j++;
		}
	}

	int evenBegin = 0;
	int oddBegin = 0;

	quickSort1(evenArray, evenBegin, j - 1);
	quickSort2(oddArray, oddBegin, k - 1);

	for (int i = 0; i < even; i++) cout << evenArray[i] << " ";
	for (int i = 0; i < odd; i++) cout << oddArray[i] << " ";

	delete[] array; //освобождение памяти, выделенной под массив
	delete[] evenArray;
	delete[] oddArray;
}

