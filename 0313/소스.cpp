#include<iostream>
#include<Windows.h>
using namespace std;
#define term 80
#define obj 'C'
int main()
{
	int j = 0;
	while (j < term)
	{
		cout << obj;
		system("cls");
		for (int i = 0; i < j; ++i)
			cout << " ";
		++j;
		Sleep(100);
	}
	return 0;
}