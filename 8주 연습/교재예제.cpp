#include<iostream>
#include<cstdlib>
using namespace std;
#define MAX_STACK_SIZE 361
struct order
{
	char rock;
	int y;
	int x;
};
order stack[MAX_STACK_SIZE];
int top = -1;

int empty()
{
	return (top == -1);
}
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}
void push(order item)
{
	if (is_full())
	{
		cout << "스택 포화 에러" << endl;
		return;
	}
	else
		stack[++top] = item;
}
order pop()
{
	if (empty())
	{
		cout << "스택 공백 에러" << endl;
		exit(1);
	}
	else
		return stack[top--];
}
order peek()
{
	if (empty())
	{
		cout << "스택 공백 에러" << endl;
		exit(1);
	}
	else
		return stack[top];
}
int main()
{
	order ie = { 'b',
	7,
	7 };
	order oe;
	oe = pop();
	cout << oe.rock << endl;
	cout << oe.y << endl;
	cout << oe.x << endl;
	return 0;
}