#include<iostream>
#include<stdarg.h>
using namespace std;

int sum(int count, int number, ...);
int product(int number...);
void print(int value...);

void main()
{
	setlocale(LC_ALL, "");
	cout << "�����: " << sum(5, 3, 5, 8, 13, 21) << endl;
	cout << "������������: " << product(3, 5, 8, 13, 21, 0) << endl;
	void print(int)
}

int sum(int count, int number, ...)
{
	//count - ���������� ���������� � ������ ����������
	//number - ������ ���������
	int sum = 0;
	int* p_number = &number; //�������� ����� ������� ����������
	for (int i = 0; i < count; i++)
	{
		sum += *p_number;
		p_number++;
	}
	return sum;
}

int product(int number...)
{
	int product = 1;
	for (int* p_number = &number; *p_number != 0; p_number++)
	{
		product *= *p_number;
	}
	return product;
}

void print(int value...)
{
	va_list list;
	va_start(list, value); //���������� ������ ������ ����������
	for (int i = value; i != 0; i = va_arg(list, int))
	{
		cout << i << "\t";
	}
	va_end(list);
}