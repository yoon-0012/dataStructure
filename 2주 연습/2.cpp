#include<iostream>
#include<Windows.h>
using namespace std;
int main()
{
	int line = 0;
	cout << "����� �� ��: ";
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