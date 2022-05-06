#include<iostream>
using namespace std;
using std::cout;
using std::cin;

#define tab "\t"
//#define POINTERS
//#define DYNAMIC_ARRAY
//#define EVEN_ODD

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);
int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* insert(int arr[], int& n, int value, int index);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n,int index);

int** allocate(int rows, int cols);
void  clear(int** arr, int rows);

//#define DYNAMIC_MEMORY1
#define DYNAMIC_MEMORY2
void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY1
#ifdef POINTERS
	int n/* = 5*/;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	cout << typeid(arr).name() << endl;
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
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
	cout << endl << "Массив с четными элементами" << endl;
	for (int i = 0; i < even1; i++) cout << even[i] << tab;
	cout << endl;
	cout << endl << "Массив с нечетными элементами" << endl;
	for (int i = 0; i < odd1; i++) cout << odd[i] << tab;
	cout << endl;

	delete[] even;
	delete[] odd;
	delete[] arr;
#endif // EVEN_ODD
#ifdef DYNAMIC_ARRAY

	int n;
	cout << "Введите размер массива: "; cin >> n;
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
			cout << "Введите значение добавляемого элемента: ";
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
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value, index;
	/*cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);*/

	/*cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);
	delete[] arr;*/

	//insert
	cout << "Введите индекс добавляемого значения: "; cin >> index;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	//pop_back
	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Введите индекс удаляемого значения: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);
	delete[] arr;
#endif // DYNAMIC_MEMORY1

	int rows;	//количество строк двумерного динамического массива
	int cols;	//количество элементов строки двумерного динамического массива
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	int** arr = allocate(rows, cols);
	
	//3) Обращение к элементам двумерного динамического массива:
	FillRand(arr, rows, cols);
	//Print(arr, rows, cols);
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << *(*(arr+i)+j) << "\t";
			}
			cout << endl;
		}

	}
	clear(arr, rows);
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
int** allocate(int rows, int cols)
{
	//1) Создаем массив указателей:
	int** arr = new int*[rows];
	//2) Создаем строки двумерного массива:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
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
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
int* push_back(int arr[], int& n, int value)
{
	//1. Создаем буферный массив нужного размера, в данном случае на 1 элемент больше:
	int* buffer = new int[n + 1];
	//2. Копируем все данные из исходного массива в буферный:
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	//3. После того, как данные скопированы в новый массив, старый массив уже не нужен:
	delete[] arr;
	//4. Подменяем адрес старого массива адресом нового массива:
	arr = buffer;
	//5. Только после всего этого в новый элемент можно добавить значение:
	arr[n] = value;
	//6. После добавления элемента в массив, количество его элементов увеличится на 1:
	n++;
	//7. Mission complete - элемент добавлен
	//delete[] buffer;
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++) buffer[i+1] = arr[i];
	delete[] arr;
	arr = buffer;
	buffer[0] = value;
	n++;
	return buffer;
}
int* insert(int arr[], int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	int i = 0;
	for (; i < index; i++) buffer[i] = arr[i];
	for (; i < n; i++) buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[index] = value;
	arr = buffer;
	n++;
	return buffer;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n-1; i++) buffer[i] = arr[i];
	delete[] arr;
	n--;
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n; i++) 
		buffer[i] = arr[i+1];
	delete[] arr;
	//arr = buffer;
	n--;
	return buffer;
}
int* erase(int arr[], int& n, int index)
{
	int* buffer = new int[n - 1];
	int i = 0;
	for (; i < index; i++) buffer[i] = arr[i];
	for (; i < n; i++) buffer[i] = arr[i+1];
	delete[] arr;
	//arr = buffer;
	n--;
	return buffer;
}
void clear(int** arr, int rows)
{
	//4) Удаление массива:
	//4.1 Удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//4.2 Удаляем массив указателей:
	delete[] arr;
}