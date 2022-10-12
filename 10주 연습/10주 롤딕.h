#pragma once
#include<iostream>
#include<fstream>
#include <time.h>
using namespace std;
struct champion_bt
{
	char position[13];
	char name[13];
	int hp = 0;//체력
	int attack = 0;
	int defense = 0;
	champion_bt* left;
};
struct champion_dl
{
	char position[13];
	char name[13];
	int hp;//체력
	int attack = 0;
	int defense = 0;
	champion_dl* pre;
	champion_dl* next;
};

champion_bt* Insert_SL(champion_bt* head, int* lengthSl, char position[], char name[], int hp, int attack, int defense);
champion_dl* Insert_dl(champion_dl* head2, int* lengthDl, char position[], char name[], int hp, int attack, int defense);

void Search_SL(champion_bt* head, char name[]);
void PrintAll_SL(champion_bt* head);
champion_bt* SortByHp_SL(champion_bt* head);

void Search_DL(champion_dl* head, char name[]);
void PrintAll_dl(champion_dl* head2);
champion_dl* SortByHp_dl(champion_dl* head2);
