#include<iostream>
#include<Windows.h>
using namespace std;
int main()
{
	int line = 0;
	cout << "출력할 줄 수: ";
	cin >> line;
	for (int i = 0; i < line; ++i)
	{
		for (int h = 0; h <= i; ++h)
		{
			cout << "*";
			Sleep(1000);
		}
		cout << endl;
	}
	return 0;
}