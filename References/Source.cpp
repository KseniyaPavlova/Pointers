//References
#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int a = 2;
	int& ra = a; //ссылка на переменную "а"
	ra += 3;
	cout << a << endl;

}