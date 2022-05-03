//Pointers
#include<iostream>
using namespace std;
//#define POINTERS_BASICS
void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	int a = 2;			//���������� ����������
	int* pa = &a;		//���������� ���������
	//p-poiner (���������� �������)
	cout << a << endl;	//����� �������� ���������� 'a' �� �����
	cout << &a << endl;	//������ ������ ���������� '�' ����� ��� ������
	cout << pa << endl;	//����� �� ����� ������ ���������� '�', ����������� � ��������� 'pa'
	cout << *pa << endl;//������������� ��������� '��' � ����� �� ����� �������� �� ������ 

	int* pb;
	int b = 3;
	pb = &b;
	cout << b << endl;
	cout << &b << endl;
	cout << pb << endl;
	cout << *pb << endl;
	//int - int 
	//int* - ��������� �� int
	//double - double
	//double* - ��������� �� double  
#endif // POINTERS_BASICS

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
	for (int* p_arr = arr; *p_arr != 0xCCCCCCCC; p_arr++)
	{
		cout << *p_arr << "\t";
	}
	cout << endl;
}
