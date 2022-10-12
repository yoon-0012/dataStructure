#include<iostream>
#include<Windows.h>
using namespace std;
void recur(int);
int main()
{
	int line = 0;
	cout << "출력할 줄 수: ";
	cin >> line;
	for (int i = 1; i <= line; ++i)
	{
		recur(i);
		cout << endl;
	}
	return 0;
}
void recur(int line)
{
	if (line == 1)
	{

		cout << "*";
		Sleep(1000);
	}
	else
	{
		cout << "*";
		Sleep(1000);
		recur(line - 1);
	}
}