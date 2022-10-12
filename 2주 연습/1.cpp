#include<iostream>
#include<Windows.h>
using namespace std;
int main()
{
	for (int i = 0; i < 4; ++i)
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