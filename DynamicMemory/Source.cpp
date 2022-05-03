#include<iostream>
using namespace std;
using std::cout;

#define tab "\t"
//#define POINTERS
//#define DYNAMIC_ARRAY
//#define EVEN_ODD

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int arr[], int n, int value);
int* push_front(int arr[], int n, int value);

void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS
	int n/* = 5*/;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];
	cout << typeid(arr).name() << endl;
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	arr[n] = value;
	n++;
	Print(arr, n);
	delete[] arr;

	/*const int SIZE = 5;
	int brr[SIZE];
	FillRand(brr, SIZE);
	Print(brr, SIZE);*/
	/*for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;*/
#endif // POINTERS

#ifdef EVEN_ODD
	int n = 10;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) arr[i] = rand() % 100;
	for (int i = 0; i < n; i++) cout << arr[i] << tab;
	cout << endl;
	int even1 = 0, odd1 = 0;
	int* even = new int[even1];
	int* odd = new int[odd1];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even[even1] = arr[i];
			even1++;
		}
		if (arr[i] % 2 != 0)
		{
			odd[odd1] = arr[i];
			odd1++;
		}
	}
	cout << endl << "������ � ������� ����������" << endl;
	for (int i = 0; i < even1; i++) cout << even[i] << tab;
	cout << endl;
	cout << endl << "������ � ��������� ����������" << endl;
	for (int i = 0; i < odd1; i++) cout << odd[i] << tab;
	cout << endl;

	delete[] even;
	delete[] odd;
	delete[] arr;
#endif // EVEN_ODD
#ifdef DYNAMIC_ARRAY

	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
		//if (i == n) buffer[i] = rand() % 100;
		/*if (i == n)
		{
			cout << "������� �������� ������������ ��������: ";
			cin >> buffer[i];
		}*/
	}
	delete[] arr;
	buffer[n] = rand() % 100;
	n++;
	Print(buffer, n);
	arr = buffer;
	Print(arr, n);
	delete[] buffer;
#endif // DYNAMIC_ARRAY

	int n;
	//delete &n; //Debug Assertion Failed
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n+1);
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n+1);
	delete[] arr;

}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	cout << typeid(arr).name() << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
int* push_back(int arr[], int n, int value)
{
	//1. ������� �������� ������ ������� �������, � ������ ������ �� 1 ������� ������:
	int* buffer = new int[n + 1];
	//2. �������� ��� ������ �� ��������� ������� � ��������:
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	//3. ����� ����, ��� ������ ����������� � ����� ������, ������ ������ ��� �� �����:
	delete[] arr;
	//4. ��������� ����� ������� ������� ������� ������ �������:
	arr = buffer;
	//5. ������ ����� ����� ����� � ����� ������� ����� �������� ��������:
	arr[n] = value;
	//6. ����� ���������� �������� � ������, ���������� ��� ��������� ���������� �� 1:
	n++;
	//7. Mission complete - ������� ��������
	//delete[] buffer;
	return arr;
}
int* push_front(int arr[], int n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++) buffer[i+1] = arr[i];
	delete[] arr;
	arr = buffer;
	buffer[0] = value;
	n++;
	return buffer;
}