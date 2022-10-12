#include"10주 롤딕.h"
int main()
{
	champion_bt* head = nullptr;
	champion_dl* head2 = nullptr;
	int choose = 0;
	char position[13];
	char name[13];
	int hp;//체력
	int attack;
	int defense;
	ifstream lolDic("LOLDic.txt");
	clock_t start, end;
	double result = 0;
	int lengthSl = 0;
	int lengthDl = 0;

	if (lolDic.is_open())
	{
		//for (int i = 0; i < 4440000; ++i)  malloc 1200만씩 
		//for (int i = 0; i < 12000000; ++i)
		for (int i = 0; !lolDic.eof(); ++i)
		{
			lolDic >> position >> name >> hp >> attack >> defense;
			head = Insert_SL(head,&lengthSl,position, name, hp, attack, defense);
			//head2 = Insert_dl(head2, &lengthDl, position, name, hp, attack, defense);
		}
		lolDic.close();
	}
	while (choose != 11)
	{
		cout << endl << endl << "1. findTarget_sl" << endl;
		cout << "2. printAll_sl" << endl;
		cout << "3. sortByHp_sl" << endl;
		cout << "4. findTarget_dl" << endl;
		cout << "5. printAll_dl" << endl;
		cout << "6. sortByHp_dl" << endl;
		cout << "11. 종료" << endl;
		cout << "choose: ";
		if (!(cin >> choose))
		{
			cin.clear();
			cin.ignore(5, '\n');
		}
		switch (choose)
		{
		case 1:
			cout << "이름: ";
			cin >> name;
			start = clock();
			Search_SL(head, name);
			end = clock();
			result = (double)(end - start);
			cout << "findTarget_sl: " << result << endl;
			break;
		case 2:
			start = clock();
			PrintAll_SL(head);
			end = clock();
			result = (double)(end - start);
			cout << "printAll_sl: " << result << endl;
			break;
		case 3:
			start = clock();
			head = SortByHp_SL(head);
			end = clock();
			result = (double)(end - start);
			cout << "sortByHp_sl: " << result << endl;
			break;
		case 4:
			cout << "이름: ";
			cin >> name;
			start = clock();
			Search_DL(head2, name);
			end = clock();
			result = (double)(end - start);
			cout << "findTarget_dl: " << result << endl;
			break;
		case 5:
			start = clock();
			PrintAll_dl(head2);
			end = clock();
			result = (double)(end - start);
			cout << "printAll_dl: " << result << endl;
			break;
		case 6:
			start = clock();
			head2 = SortByHp_dl(head2);
			end = clock();
			result = (double)(end - start);
			cout << "sortByHp_dl: " << result << endl;
			break;
		case 11:
			break;
		default:
			cout << "잘못된 입력입니다." << endl << endl;
			break;
		}
	}
	return 0;
}
