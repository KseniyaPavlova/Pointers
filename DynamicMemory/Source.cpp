#include<iostream>
using namespace std;
using std::cout;
using std::cin;

#define deliminer "\n------------------------------\n"
#define tab "\t"
//#define POINTERS
//#define DYNAMIC_ARRAY
//#define EVEN_ODD

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);
void Print1(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int** push_row_back(int** arr, int& rows, int cols);
int** push_row_front(int** arr, int& rows, int cols);

int* insert(int arr[], int& n, int value, int index);
int** insert_row(int** arr, int& rows, int cols, int index);
int** insert_col(int** arr, int rows, int& cols, int index);

int* pop_back(int arr[], int& n);
int** pop_row_back(int** arr, int& rows, int cols);
int* pop_front(int arr[], int& n);
int** pop_row_front(int** arr, int& rows, int cols);

int* erase(int arr[], int& n, int index);
int** erase_col(int** arr, int rows, int& cols, int index);
int** erase_row(int** arr, int& rows, int cols, int index);

int** push_col_back(int** arr, int rows, int& cols);
int** push_col_front(int** arr, int rows, int& cols);
int** pop_col_back(int** arr, int rows, int& cols);
int** pop_col_front(int** arr, int rows, int& cols);

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
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	cout << deliminer;
	cout << "Добавление строки в конец массива" << endl;
	Print(arr, rows, cols);

	arr = push_row_front(arr, rows, cols);
	cout << deliminer;
	cout << "Добавление строки в начало массива" << endl;
	Print(arr, rows, cols);

	int index;
	cout << "Введите индекс строки: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	cout << deliminer;
	cout << "Добавление строки в массив по указанному адресу" << endl;
	Print(arr, rows, cols);

	arr = pop_row_back(arr, rows, cols);
	cout << deliminer;
	cout << "Удаление строки в конце массива" << endl;
	Print(arr, rows, cols);

	arr = pop_row_front(arr, rows, cols);
	cout << deliminer;
	cout << "Удаление строки в начале массива" << endl;
	Print(arr, rows, cols);

	arr = push_col_back(arr, rows, cols);
	cout << deliminer;
	cout << "Добавление столбца в конец массива" << endl;
	Print(arr, rows, cols);

	arr = push_col_front(arr, rows, cols);
	cout << deliminer;
	cout << "Добавление столбца в начало массива" << endl;
	Print(arr, rows, cols);

	//int index;
	cout << "Введите индекс	столбца: "; cin >> index;
	arr = insert_col(arr, rows, cols, index);
	cout << deliminer;
	cout << "Добавление столбца в массив по указанному адресу" << endl;
	Print(arr, rows, cols);

	arr = pop_col_back(arr, rows, cols);
	cout << deliminer;
	cout << "Удаляет столбец с конца массива" << endl;
	Print(arr, rows, cols);

	arr = pop_col_front(arr, rows, cols);
	cout << deliminer;
	cout << "Удаляет столбцы с начала массива" << endl;
	Print(arr, rows, cols);

	//int index;
	cout << "Введите индекс удаляемого столбца: "; cin >> index;
	arr = erase_col(arr, rows, cols, index);
	cout << deliminer;
	cout << "Удаление столбца массивa по указанному адресу" << endl;
	Print(arr, rows, cols);

	cout << "Введите индекс удаляемой строки: "; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	cout << deliminer;
	cout << "Удаление строки из массивa по указанному адресу" << endl;
	Print(arr, rows, cols);

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
void Print1(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(arr + i) + j) << "\t";
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
int** push_row_back(int** arr, int& rows, int cols)
{
	// создаем буферный массив указателей на один элемент больше
	int** buffer = new int*[rows + 1, cols];
	// скопируем массив arr в buffer
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	//выделяем память для доп. строки и заполняем ее 
	buffer[rows] = new int[cols];
	for (int i = 0; i < cols; i++)
	{
		buffer[rows][i] = rand() % 100;
	}
	rows++;
	arr = buffer;
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++) buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	buffer[0] = value;
	n++;
	return buffer;
}
int** push_row_front(int** arr, int& rows, int cols)
{
	// создаем буферный массив указателей на один элемент больше
	int** buffer = new int*[rows + 1, cols];
	// скопируем массив arr в buffer
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	//выделяем память для доп. строки и заполняем ее 
	buffer[0] = new int[cols];
	for (int i = 0; i < cols; i++)
	{
		buffer[0][i] = rand() % 100;
	}
	rows++;
	arr = buffer;
	return arr;
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
int** insert_row(int** arr, int& rows, int cols, int index)
{
	//int** buffer = allocate(rows, cols + 1)/*new int*[rows + 1, cols]*/;
	//for (int i = 0; i < rows; i++)
	//{
	//	int j = 0;
	//	for (; j < index; i++) buffer[i][j] = arr[i][j];
	//	for (; j < cols; i++) buffer[i][j] = arr[i][j];
	//}
	//delete[] arr;
	//arr = buffer;
	//for (int i = 0; i < cols; i++)
	//{
	//	buffer[index][i] = rand() % 100;
	//}
	//rows++;
	//return arr;

	int** buffer = allocate(rows + 1, cols);
	for (int i = 0; i <= rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == index) buffer[i][j] = rand() % 100;
			if (i < index) buffer[i][j] = arr[i][j];
			if (i > index) buffer[i][j] = arr[i - 1][j];
		}
	}
	//clear(arr, rows);
	rows++;
	return buffer;
}
int** insert_col(int** arr, int rows, int& cols, int index)
{
	int** buffer = allocate(rows, cols + 1);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j <= cols; j++)
		{
			if (j == index) buffer[i][j] = rand() % 100;
			if (j < index) buffer[i][j] = arr[i][j];
			if (j > index) buffer[i][j] = arr[i][j - 1];
		}
	}
	clear(arr, rows);
	cols++;
	return buffer;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++) buffer[i] = arr[i];
	delete[] arr;
	n--;
	return buffer;
}
int** pop_row_back(int** arr, int& rows, int cols)
{
	int** buffer = new int*[rows - 1, cols];
	/*for (int i = 0; i < rows-1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;*/
	rows--;
	return arr;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n; i++)
		buffer[i] = arr[i + 1];
	delete[] arr;
	//arr = buffer;
	n--;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, int cols)
{
	int** buffer = new int*[rows - 1, cols];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	//delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}

int** push_col_back(int** arr, int rows, int& cols)
{
	/*int** buffer = allocate(rows, cols + 1);
	for (int i = 0; i < cols; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[cols] = new int[cols];
	for (int i = 0; i <= cols; i++)
	{
		buffer[i][cols] = rand() % 100;
	}
	cols++;
	arr = buffer;
	return arr;*/

	int** buffer = allocate(rows, cols + 1)/*new int*[rows, cols + 1]*/;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols + 1; j++)
		{
			if (j == cols) buffer[i][j] = rand() % 100;
			else buffer[i][j] = arr[i][j];
		}
	}
	cols++;
	return buffer;
}
int** pop_col_back(int** arr, int rows, int& cols)
{
	int** buffer = new int*[rows, cols - 1];
	for (int i = 0; i < cols; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	cols--;
	//arr = buffer;
	return buffer;
}
int** push_col_front(int** arr, int rows, int& cols)
{
	//int** buffer = new int*[rows, cols+1];
	//for (int i = 0; i < cols; i++)
	//{
	//	buffer[i + 1] = arr[i];
	//}
	//delete[] arr;
	////выделяем память для доп. строки и заполняем ее 
	//buffer[0] = new int[cols];
	//for (int i = 0; i < cols; i++)
	//{
	//	buffer[0][i] = rand() % 100;
	//}
	//cols++;
	//arr = buffer;
	//return arr;
	int** buffer = allocate(rows, cols + 1)/*new int*[rows, cols + 1]*/;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols + 1; j++)
		{
			if (j == 0) buffer[i][j] = rand() % 100;
			else buffer[i][j] = arr[i][j - 1];
		}
	}
	//clear(arr, rows);
	cols++;
	return buffer;
}
int** pop_col_front(int** arr, int rows, int& cols)
{
	int** buffer = allocate(rows, cols - 1)/*new int*[rows, cols + 1]*/;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			//if (j == 0) buffer[i][j] = rand() % 100;
			buffer[i][j] = arr[i][j + 1];
		}
	}
	//clear(arr, rows);
	cols--;
	return buffer;;
	//int** buffer = new int*[rows, cols - 1];
	//for (int i = 0; i < rows; i++)
	//{
	//	for (int j = 0; j < cols; j++)
	//	{
	//		buffer[i][j] = arr[i][j + 1];
	//	}
	//}
	//delete[] arr;
	//cols--;
	////arr = buffer;
	//return buffer;
	///*int** buffer = new int*[rows, cols - 1];
	//delete[] arr[0];
	//for (int i = 0; i < rows; i++)
	//{
	//	for (int j = 0; j < cols; j++)
	//	{
	//		buffer[i][j] = arr[i][j+1];
	//	}
	//}*/
	//delete[] arr;
	//cols--;
	//arr = buffer;
	//return buffer;
}
int* erase(int arr[], int& n, int index)
{
	int* buffer = new int[n - 1];
	int i = 0;
	for (; i < index; i++) buffer[i] = arr[i];
	for (; i < n; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	//arr = buffer;
	n--;
	return buffer;
}
int** erase_col(int** arr, int rows, int& cols, int index)
{
	int** buffer = allocate(rows, cols - 1);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			/*	if (i == index) buffer[i][j] = arr[i-1][j];*/
			if (i < index) buffer[i][j] = arr[i][j];
			if (i >= index) buffer[i][j] = arr[i][j + 1];
		}
	}
	//clear(arr, rows);
	cols--;
	return buffer;
	/*int** buffer = new int*[rows, cols - 1];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < index; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		for (int j = index; j < cols-1; j++)
		{
			buffer[i][j] = arr[i][j+1];
		}
		delete[] arr;
	}
	cols--;
	return buffer;*/
}
int** erase_row(int** arr, int& rows, int cols, int index)
{
	int** buffer = allocate(rows - 1, cols);
	for (int i = 0; i < rows - 1; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			/*	if (i == index) buffer[i][j] = arr[i-1][j];*/
			if (i < index) buffer[i][j] = arr[i][j];
			if (i >= index) buffer[i][j] = arr[i + 1][j];
		}
	}
	//clear(arr, rows);
	rows--;
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