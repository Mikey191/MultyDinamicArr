#include <iostream>
using namespace std;

//�������� ������ �������, �������� ��� ������ ������� �������


void fillArray(int* const arr, const int size) { //��� ���� const? ��� ��������� �� �������� ��������� ����������� ������������ � ���� �������
	for (int i = 0;  i < size;  i++)
	{
		arr[i] = rand() % 10;
	}
}

void showArray(const int* const arr, const int size) {//������ const ���������� ��� ������ ��� ������� �� ������
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

//��������� ������� � ����� �������
void push_back(int*& arr, int& size,const int value) { //value �������� �������� ������� ����� ��������
	int* newArray= new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}

	newArray[size] = value;

	size++;

	delete[] arr; //������� ������ � ������ �������

	arr = newArray;//������ ��������� � ��������� �� ������ ������ ������ �� ����� ������

}

void pop_back(int*& arr, int& size) {//������� ��������� ������� �������
	size--;
	int* newArray = new int[size];

	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}

	delete[] arr;

	arr = newArray;
}

void push_start(int*& arr, int& size, const int value) {//���������� �������� � ������ �������
	int* newArray = new int[size + 1];

	for (int i = 1; i < size + 1; i++)
	{
		newArray[i] = arr[i - 1];
	}

	newArray[0] = value;

	size++;

	delete[] arr;

	arr = newArray;
}

void pop_start(int*& arr, int& size) {//�������� �������� � ������ �������
	size--;
	int* newArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i + 1];
	}

	delete[] arr;

	arr = newArray;
}

void main() 
{
	int size = 5;
	int* arr = new int[size];

	fillArray(arr, size);

	showArray(arr, size);

	push_back(arr, size, 111);

	showArray(arr, size);

	pop_back(arr, size);

	showArray(arr, size);

	push_start(arr, size, 222);

	showArray(arr, size);

	pop_start(arr, size);

	showArray(arr, size);

	delete[] arr;
}