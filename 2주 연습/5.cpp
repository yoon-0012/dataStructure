#include<iostream>
#include<Windows.h>
using namespace std;
void printStars(int);
int main()
{
	int line = 0;
	cout << "출력할 줄 수: ";
	cin >> line;
	for (int i = 1; i <= line; ++i)
	{
		printStars(i);
		cout << endl;
	}
	return 0;
}
void printStars(int line)
{

	for (int h = 0; h < line; ++h)
	{
		cout << "*";
		Sleep(1000);
	}

}