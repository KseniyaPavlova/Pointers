//Pointers
#include<iostream>
using namespace std;
//#define POINTERS_BASICS
void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	int a = 2;			//объ€вление переменной
	int* pa = &a;		//объ€вление указател€
	//p-poiner (¬енгерска€ нотаци€)
	cout << a << endl;	//вывод значени€ переменной 'a' на экран
	cout << &a << endl;	//вз€тие адреса переменной 'а' пр€мо при выводе
	cout << pa << endl;	//вывод на экран адреса переменной 'а', хран€щегос€ в указателе 'pa'
	cout << *pa << endl;//разыменование указател€ 'ра' и вывод на экран значени€ по адресу 

	int* pb;
	int b = 3;
	pb = &b;
	cout << b << endl;
	cout << &b << endl;
	cout << pb << endl;
	cout << *pb << endl;
	//int - int 
	//int* - указатель на int
	//double - double
	//double* - указатель на double  
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
