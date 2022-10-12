#include "Judgment.h"

void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
Judgment::Judgment()
{
	ZeroMemory(mMap, sizeof(int) * sizeof(mMap) / sizeof(int));
	mPlayer = BlackPlayer;
	mTurn = true;
	mPre = 0;
	mwhiteCount = 0;
	mblackCount = 0;

}


Judgment::~Judgment()
{
}
//------ �Լ� �����͸� ����	------
void Judgment::SetYourFunc(
	void(*pfuncBlackAttack) (int* x, int* y),
	void(*pfuncBlackDefence)(int  x, int  y),
	void(*pfuncWhiteAttack) (int* x, int* y),
	void(*pfuncWhiteDefence)(int  x, int  y))
	//--------------------------------
{
	// �浹 �Լ�
	m_funcBlackAttack = pfuncBlackAttack;
	m_funcBlackDefence = pfuncBlackDefence;

	// �鵹 �Լ�
	m_funcWhiteAttack = pfuncWhiteAttack;
	m_funcWhiteDefence = pfuncWhiteDefence;

}
int Judgment::playBlack(int x, int y)
{
	if (0 <= x && x <= MapSize)
	{
		if (0 <= y && y <= MapSize)
		{
			if (mMap[y + 10][x + 10] == 0)
			{
				mPre = BlackPlayer;
				mPlayer = BlackPlayer;

				mMap[y + 10][x + 10] = BlackPlayer;
				mCurrentPosition.first = x + 10;
				mCurrentPosition.second = y + 10;
				mTurn = !mTurn;

				if (EndGame(mCurrentPosition) == 555)
				{
					return -555;
				}
				else
				{
					mTestPosition.first = mCurrentPosition.first;
					mTestPosition.second = mCurrentPosition.second;

					return Foul();
				}
			}
			else
			{
				return -999;

			}
		}
		else
		{
			return -888;
		}
	}
	else
	{
		return -888;
	}

}

int Judgment::playWhite(int x, int y)
{
	if (0 <= x && x <= MapSize)
	{
		if (0 <= y && y <= MapSize)
		{
			if (mMap[y + 10][x + 10] == 0)
			{
				mPre = WhitePlayer;
				mMap[y + 10][x + 10] = WhitePlayer;
				mPlayer = WhitePlayer;
				mCurrentPosition.first = x + 10;
				mCurrentPosition.second = y + 10;
				mTurn = !mTurn;

				if (EndGame(mCurrentPosition) == 555)
				{
					return 555;
				}
				else
				{
					mTestPosition.first = mCurrentPosition.first;
					mTestPosition.second = mCurrentPosition.second;

					return Foul();
				}
			}
			else
			{
				return 999;

			}
		}
		else
		{
			return 888;
		}
	}
	else
	{
		return 888;
	}
}

void Judgment::GamePlay()
{
	int result = 0;
	int posX, posY;
	bool game = 1;
	vector<pair<int, int>> positions;
	vector<int> stones;

	int key2 = 0;

	while (game)
	{

		game = 0;
		if (mTurn)
			stones.push_back(WhitePlayer);
		else
			stones.push_back(BlackPlayer);
		if (mTurn)
		{
			/* �浹 ���� */
			gotoxy(0, 0);
			cout << "�浹 ����" << endl << endl << endl;;
			auto start = high_resolution_clock::now();

			m_funcBlackAttack(&posX, &posY);

			auto duration = high_resolution_clock::now() - start;
			cout << "���ѽð� " << Timeout / 1000.0f << "�� ��  " << duration_cast<milliseconds>(duration).count();
			cout << " msec ��ŭ ���                                  " << endl;

			m_funcWhiteDefence(posX, posY);
			if (duration_cast<milliseconds>(duration).count() >= Timeout)
				result = -3000;
			else
				result = playBlack(posX, posY);

			mblackCount++;

		}
		else
		{
			/* �鵹 ���� */
			gotoxy(0, 0);
			cout << "�鵹 ����" << endl << endl << endl;;
			auto start = high_resolution_clock::now();

			m_funcWhiteAttack(&posX, &posY);

			auto duration = high_resolution_clock::now() - start;
			cout << "���ѽð� " << Timeout / 1000.0f << "�� ��  " << duration_cast<milliseconds>(duration).count();
			cout << " msec ��ŭ ���                           " << endl;
			m_funcBlackDefence(posX, posY);

			if (duration_cast<milliseconds>(duration).count() >= Timeout)
				result = 3000;
			else
				result = playWhite(posX, posY);
			mwhiteCount++;

		}

		gotoxy(0, 4);

		positions.push_back(make_pair(posX, posY));
		displayMap();

		if (key2 != 27)
		{
			gotoxy(35, 0);
			cout << "��ŵ�� ���Ͻø� ESC " << endl;
			cout << "���� ���� ������ �ƹ�Ű�� ��������.";
			key2 = _getch();
		}
		else
		{
			gotoxy(27, 0);
			cout << "                                                                  " << endl;
		}
		gotoxy(0, 24);
		switch (result)
		{
		case 33:
			cout << "�� ��� ��Ģ ��." << endl;
			break;
		case 44:
			cout << "�� ��� ��Ģ ��." << endl;
			break;
		case -66:
			cout << "�� ���� ��Ģ ��." << endl;
			break;
		case 66:
			cout << "�� ���� ��." << endl;
			break;
		case 555:
			cout << "�� ��." << endl;
			break;
		case -555:
			cout << "�� ��." << endl;
			break;
		case -999:
			cout << "�浹�� �̹� �ٸ����� �ִ� �ڸ��� ���ұ� ������ �й�." << endl;
			break;
		case -888:
			cout << "�浹�� �ٵ��� �ۿ��� ���ұ� ������ �й�." << endl;
			break;
		case 999:
			cout << "�鵹�� �̹� �ٸ����� �ִ� �ڸ��� ���ұ� ������ �й�." << endl;
			break;
		case 888:
			cout << "�鵹�� �ٵ��� �ۿ��� ���ұ� ������ �й�." << endl;
			break;
		case -3000:
			cout << "�浹�� �ð� ������ �Ѱ� �й�." << endl;
			break;
		case 3000:
			cout << "�浹�� �ð� ������ �Ѱ� �й�." << endl;
			break;
		default:
			game = 1;
			break;
		}
	}

	int key = 1;
	int count = positions.size() - 1;
	int preStone;

	pair<int, int> temp = positions[count];;

	gotoxy(0, 26);
	cout << " �� : ���� �� ����  , �� : ���� �� ����" << endl;

	if (stones[count] == BlackPlayer)
		mMap[temp.second + 10][temp.first + 10] = 3;

	if (stones[count] == WhitePlayer)
		mMap[temp.second + 10][temp.first + 10] = 4;

	gotoxy(0, 27);
	displayMap();

	mMap[temp.second + 10][temp.first + 10] = 0;

	while (key != 27)
	{
		fflush(stdin);
		key = _getch();


		if (key == 77)
		{
			count++;
			if (count >= positions.size())
			{
				count = positions.size() - 1;

			}
			else
				mTurn = !mTurn;
		}
		else if (key == 75)
		{
			count--;
			if (count <= 0)
			{
				count = 0;

			}
			else
				mTurn = !mTurn;

		}
		if (key == 77)
		{
			cout << count << endl;

			mMap[temp.second + 10][temp.first + 10] = stones[count];
		}
		if (key == 75)
		{
			mMap[temp.second + 10][temp.first + 10] = 0;
		}

		temp = positions[count];

		if (stones[count] == BlackPlayer)
			mMap[temp.second + 10][temp.first + 10] = 3;

		if (stones[count] == WhitePlayer)
			mMap[temp.second + 10][temp.first + 10] = 4;

		gotoxy(0, 27);
		displayMap();

		cout << count << " / " << positions.size() - 1 << "                     " << endl;


	}
}
int Judgment::Foul()
{
	int foul = 0;

	foul = Foul66(mTestPosition, 1);
	if (mPlayer == BlackPlayer)
	{
		if (0 == foul)
			foul = Foul44(mTestPosition, 1);

		if (0 == foul)
			foul = Foul33(mTestPosition, 1);
	}
	return foul;
}

int	Judgment::Foul33(pair<int, int> position, bool flag)
{
	int movePoint[8][2] = { { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 } };
	int tempX, tempY;
	int PretempX, PretempY;
	int PosttempX, PosttempY;
	int foulLine33 = 0;

	bool empty;
	float attackPoint[8] = { 0, };
	pair<int, int> Point[8];
	pair<int, int> emptyPos;
	bool check[8] = { false, };
	float checkWeight[8] = { 0.0f, };

	/* ���� �ΰ��� ��� */
	for (int way = 0; way < 8; ++way)
	{
		tempX = position.first;
		tempY = position.second;
		empty = true;

		for (int move = 0; move < 6; ++move)
		{

			tempX += movePoint[way][0];
			tempY += movePoint[way][1];

			PosttempX = tempX + movePoint[way][0];
			PosttempY = tempY + movePoint[way][1];

			PretempX = tempX - movePoint[way][0];
			PretempY = tempY - movePoint[way][1];

			if (VirtualMapMin <= tempX && tempX <= VirtualMapMax && VirtualMapMin <= tempY && tempY <= VirtualMapMax)
			{
				/* ���� �ڸ��� �÷��̾� ���� �ִٸ� */
				if (mMap[tempY][tempX] == mPlayer)
				{
					/* ���� ��ĭ�� �������� �ʾҴٸ� first�� ���� ������Ų��.*/
					if (empty)
						Point[way].first++;
					else /* ��ĭ�� �����Դٸ� second ����. */
						Point[way].second++;
				}
				/* ���� �ڸ��� ��ĭ �̶�� */
				else if (mMap[tempY][tempX] == 0)
				{
					/* ���� ��ĭ�� �������� �ʾҴٸ� */
					if (empty)
					{
						/* ��ĭ �ڸ��� ���� */
						emptyPos.first = tempX;
						emptyPos.second = tempY;

						if (flag)
						{
							/* �� ��ĭ�� ��ȿ�� �ڸ��� �ƴ϶�� ���ڸ� �� �̻� ���� �ʴ´�. */
							if (Foul44(make_pair(tempX, tempY), 0) || Foul33(make_pair(tempX, tempY), 0) || Foul66(make_pair(tempX, tempY), 0))
							{
								checkWeight[way] = 1.0f;
								break;
							}
							/* ��ȿ�� �ڸ���� �׳� ��ĭ�� �����Դٰ� ǥ���ϰ� */
							/* ���� �ڸ��� ��� �� �̶�� ������ ������ ���ӵǿ� �ִٴ� �Ҹ��� ������ ���� ����Ʈ�� �ȴ�.*/
							else
							{
								//	if (mMap[PosttempY][PosttempX] != 0 && mMap[PosttempY][PosttempX] != mPlayer)
									/* ���� �ڸ��� ���� �ƴ϶�� ��� ���̸� */
								if (10 <= PosttempX && PosttempX <= 27 && 10 <= PosttempY && PosttempY <= 27)
								{
									attackPoint[way] = 0.5f;
								}
								else
								{

								}
								empty = false;
							}
						}
						/* ���ڸ��� ��ȿ���� Ȯ���Ҷ��� ���ڸ��� �׳� ���ڸ���. */
						else
							empty = false;
					}
					/* �̹� ��ĭ�� �ѹ� �����Դٸ� */
					else
					{
						/* ��ĭ�� ����ĭ�� �ٸ� �÷��̾��� ����ġ 0.5�� ������ ǥ���Ѵ�. */
						/* ���� ĭ�� ��ĭ�̳� ���� ���̶�� ������ �ʾҴ�. */
						if (flag)
						{
							if (mMap[PosttempY][PosttempX] == mPlayer && mMap[PretempY][PretempX] == mPlayer)
								mMap[emptyPos.second][emptyPos.first] = mPlayer;
							/*��ȿ���� �ʴٸ� ���� üũ. */
							if (Foul44(make_pair(tempX, tempY), 0) || Foul33(make_pair(tempX, tempY), 0) || Foul66(make_pair(tempX, tempY), 0))
							{
								checkWeight[way] = 1.5f;
							}
							if (mMap[PosttempY][PosttempX] == mPlayer && mMap[PretempY][PretempX] == mPlayer)
								mMap[emptyPos.second][emptyPos.first] = 0;

							if (mMap[PosttempY][PosttempX] != 0 && mMap[PosttempY][PosttempX] != mPlayer)
							{
								checkWeight[way] = 0.5f;
							}
						}
						break;

					}
				}
				/* �ٸ� �÷��̾� ���� �����ٸ�  */
				else
				{
					/* ���� ���� ��ĭ�̶�� */
					if (mMap[PretempY][PretempX] == 0)
					{
						/* ��ĭ�ڿ� �ٸ� ���ε� �տ� ���� ���� �ϳ��� ���ٸ� ���� 1.5 */
						if (Point[way].first == 0)
							checkWeight[way] = 1.5f;
						else if (Point[way].first == 1)
							checkWeight[way] = 1.0f;
						else
							checkWeight[way] = 0.5f;
					}
					else
						checkWeight[way] = 1.5f;
					break;
				}
			}
			/* ĭ�� �Ѿ. */
			else
			{
				/* �Ѿ�� �� ���� �÷��̾�̶�� �������� ǥ���Ѵ�.*/
				if (mMap[PretempY][PretempX] == mPlayer)
					checkWeight[way] = 1.5f;
				else
					checkWeight[way] = 0.5f;

				break;
			}
		}
	}


	//cout << "flag  " << flag << "   weight  ";
	for (int i = 0; i < 4; ++i)
	{
		/*	if (flag)
			{
				cout << checkWeight[i] << " " << checkWeight[i + 4] << " ";
				cout << attackPoint[i] << " " << attackPoint[i + 4] << "     ";
			}*/
		if (checkWeight[i] + checkWeight[i + 4] - attackPoint[i] - attackPoint[i + 4] >= 0.5f)
			check[i] = true;
	}
	/*if (flag)
		cout << endl;*/

	int count = 0;
	int count1 = 0;
	int count2 = 0;
	int c = 0;

	for (int i = 0; i < 4; ++i)
	{
		/*	if (flag)
			{
				cout << i << "  " << Point[i].first << "  " << Point[i].second << "  " << check[i] << endl;
				cout << i << "  " << Point[i + 4].first << "  " << Point[i + 4].second << "  " << check[i + 4] << endl;
			}*/
		count = Point[i].first + Point[i + 4].first;
		if (count < 2)
		{
			count1 = Point[i].first + Point[i].second + Point[i + 4].first;
			if (2 == count1)
			{
				count = count1;


			}
			count2 = Point[i + 4].first + Point[i + 4].second + Point[i].first;
			if (2 == count2)
			{
				count = count2;

			}
		}


		if (2 == count)
		{
			if (Point[i].first + Point[i].second + Point[i + 4].first > 2)
				foulLine33--;
			else if (Point[i].first + Point[i + 4].second + Point[i + 4].first > 2)
				foulLine33--;

			foulLine33++;
			if (check[i])
				c++;
			if (check[i + 4])
				c++;
		}
	}

	if (foulLine33 - c <= 1)
		foulLine33 = 0;
	if (1 < foulLine33)
		return 33;
	else
		return 0;

}
int	Judgment::Foul44(pair<int, int> position, bool flag)
{
	int movePoint[8][2] = { { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 } };
	int tempX, tempY;
	int PretempX, PretempY;
	int PosttempX, PosttempY;
	int foulLine44 = 0;

	bool empty;
	pair<int, int> Point[8];
	pair<int, int> emptyPos;

	int attackPoint[8] = { 0 , };

	bool check[8] = { false, };
	/*���� 44�� 44��. */
	for (int way = 0; way < 8; ++way)
	{
		tempX = position.first;
		tempY = position.second;
		empty = true;
		for (int move = 0; move < 6; ++move)
		{
			tempX += movePoint[way][0];
			tempY += movePoint[way][1];

			PosttempX = tempX + movePoint[way][0];
			PosttempY = tempY + movePoint[way][1];

			PretempX = tempX - movePoint[way][0];
			PretempY = tempY - movePoint[way][1];

			if (VirtualMapMin <= tempX && tempX <= VirtualMapMax && VirtualMapMin <= tempY && tempY <= VirtualMapMax)
			{
				/* ���� �ڸ��� �÷��̾� ���� �ִٸ� */
				if (mMap[tempY][tempX] == mPlayer)
				{
					/* ���� ��ĭ�� �������� �ʾҴٸ� first�� ���� ������Ų��.*/
					if (empty)
						Point[way].first++;
					else /* ��ĭ�� �����Դٸ� second ����. */
						Point[way].second++;
				}
				/* ���� �ڸ��� ��ĭ �̶�� */
				else if (mMap[tempY][tempX] == 0)
				{
					/* ���� ��ĭ�� �������� �ʾҴٸ� */
					if (empty)
					{
						/* ��ĭ �ڸ��� ���� */
						emptyPos.first = tempX;
						emptyPos.second = tempY;

						if (flag)
						{
							/* �� ��ĭ�� ��ȿ�� �ڸ��� �ƴ϶�� ���ڸ� �� �̻� ���� �ʴ´�. */
							if (Foul44(make_pair(tempX, tempY), 0) || Foul33(make_pair(tempX, tempY), 0) || Foul66(make_pair(tempX, tempY), 0))
							{
								check[way] = true;
								break;
							}
							else
							{
								empty = false;
								/* ��ĭ ������ �÷��̾� ���� �ְų� ������ �÷��̾� ���� ������ (���ӵ� ���� �ȴٸ�) �����Ҽ� �ִ� �ڸ���� �����Ѵ�. */
								/* ��ĭ ���� ��ĭ�� �ҿ� �����Ƿ� &&�� �ɸ���. */
								if ((mMap[PosttempY][PosttempX] == mPlayer || mMap[PretempY][PretempX] == mPlayer) && mMap[PosttempY][PosttempX] != 0)
									attackPoint[way]++;
							}
						}
						/* ��ĭ�� ��ȿ�� �ڸ���� ��ĭ�� ���� �Դٰ� ǥ���Ѵ�. */
						else
							empty = false;
					}
					/* �̹� ��ĭ�� �ѹ� �����Դٸ� */
					else
					{
						/* �̹� ������ ���� ������ 2����� ��ĭ�� ���� ��ȿ �˻縦 �ؾ��Ѵ�. ���⿡ ������ ���� �Ǹ� �����ɷ� ģ��. */
						if (Point[way].first + Point[way].second == 2)
						{
							/* ���� �ι�° ��ĭ ����ĭ�� �÷��̾� ���̶�� ������ ��ĭ�� �÷��̾��� ���� ä�� ������ �˻��Ѵ�. (6���� �˻��ϱ�����) */
							/* ����ĭ�� �÷��̾�� ���µ� ��ĭ�� ���� �ΰ� �ݴ��� 6������ ���� ������ �߻��Ҽ� ����. */
							if (mMap[PosttempY][PosttempX] == mPlayer)
							{
								mMap[emptyPos.second][emptyPos.first] = mPlayer;
							}
							if (flag)
							{						/*��ȿ���� �ʴٸ� ���� üũ. */
								if (Foul44(make_pair(tempX, tempY), 0) || Foul33(make_pair(tempX, tempY), 0) || Foul66(make_pair(tempX, tempY), 0))
									check[way] = true;
							}
							/* ��ĭ�� �ӽ÷� �־��� ���� �ٽ� ��ĭ���� �����. */
							if (mMap[PosttempY][PosttempX] == mPlayer)
							{
								mMap[emptyPos.second][emptyPos.first] = 0;
							}
						}
						/* �ι�° ��ĭ���� ������ ���� 3����� �ι�° ��ĭ�� ��ȿ�ϴ� �ƴϴ� �������. ù��° ��ĭ�� ��ȿ �˻簡 �ʿ��ϴ�. */
						else if (Point[way].first + Point[way].second == 3)
						{
							/* ��ȿ���� �ʴٸ� ù��° ��ĭ �ڿ� ���� ���ڴ� ���ǹ��ϴ�.*/
							if (flag)
							{
								if (Foul44(make_pair(emptyPos.first, emptyPos.second), 0) || Foul33(make_pair(emptyPos.first, emptyPos.second), 0) || Foul66(make_pair(emptyPos.first, emptyPos.second), 0))
								{
									check[way] = true;
									/* ��ĭ ������ ���� 0���� ����. */
									Point[way].second = 0;
								}
							}
						}
						break;
					}
				}
				/* ��ĭ�� �ƴϰ� �� ���� �ƴϸ� ���� ���̶�� ��*/
				else
				{
					check[way] = true;
					break;
				}

			}
			else /* ������ �Ѿ �� üũ*/
			{
				/*44�� ������ ��ĭ ������������ ���� ���� ǥ�� ���ص� �ɵ���.
				������ �Ѿ�µ� ������ ���� �÷��̾� ���̸� �����ٰ� ǥ���Ѵ�. */
				if (mMap[PretempY][PretempX] == mPlayer)
					check[way] = true;

				/* ������ �Ѿ���� ���̻� �̵��� �ʿ� ����. */
				break;
			}
		}
	}
	int count = 0;
	int count1 = 0;
	int count2 = 0;
	int c = 0;
	for (int i = 0; i < 4; ++i)
	{
		/*	if (flag)
			{
				cout << i << "  " << Point[i].first << "  " << Point[i].second << "  " << check[i] << endl;
				cout << i << "  " << Point[i + 4].first << "  " << Point[i + 4].second << "  " << check[i + 4] << endl;
			}*/

		count = Point[i].first + Point[i + 4].first;

		if (count < 3)
		{
			count1 = Point[i].first + Point[i].second + Point[i + 4].first;
			if (3 == count1)
			{
				foulLine44++;
				if (check[i])
					c++;
				if (check[i + 4])
					c *= 2;
				if (attackPoint[i])
					c--;
				if (attackPoint[i + 4])
					c--;
			}
			count2 = Point[i + 4].first + Point[i + 4].second + Point[i].first;
			if (3 == count2)
			{
				foulLine44++;
				if (check[i + 4])
					c++;
				if (check[i])
					c *= 2;
				if (attackPoint[i])
					c--;
				if (attackPoint[i + 4])
					c--;
			}
		}
		if (3 == count)
		{
			foulLine44++;
			if (abs((check[i] - attackPoint[i]) > 0) && abs((check[i + 4] - attackPoint[i + 4]) > 0))
			{
				foulLine44--;
			}
			else
			{
				if (check[i])
					c++;
				if (check[i + 4])
					c++;
				if (attackPoint[i])
					c--;
				if (attackPoint[i + 4])
					c--;
			}
		}
	}
	if (c < 0)
		c = 0;
	//if (flag)
//		cout << "44 : " << foulLine44 << "  " << c << "   " <<   endl;
	if (abs(foulLine44 * 2 - c) <= 1)
	{
		foulLine44 = 0;
	}

	if (1 < foulLine44)
		return 44;
	else
		return 0;
}
int	Judgment::Foul66(pair<int, int> position, bool flag)
{
	int movePoint[8][2] = { { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 } };
	int tempX, tempY;
	int foulLine66 = 0;

	bool empty;
	pair<int, int> Point[8];
	bool check[8] = { false, };

	for (int way = 0; way < 8; ++way)
	{
		tempX = position.first;
		tempY = position.second;
		empty = true;
		for (int move = 0; move < 6; ++move)
		{
			tempX += movePoint[way][0];
			tempY += movePoint[way][1];
			if (VirtualMapMin <= tempX && tempX <= VirtualMapMax && VirtualMapMin <= tempY && tempY <= VirtualMapMax)
			{
				if (mMap[tempY][tempX] == mPlayer)
					Point[way].first++;
				else
					break;
			}
			else
			{
				check[way] = true;
				break;
			}
		}
	}

	/* ���� �ٸ� ���� �پ������� 0���� ����� ���� �����ؾ���. �ƴϸ� �¸� �˻� �Լ��� ���� �������*/
	int count;

	int c = 0;

	for (int i = 0; i < 4; ++i)
	{
		//if (flag)
		//{
		//	cout << i << "  " << Point[i].first << "  " << Point[i].second << "  " << check[i] << endl;
		//	cout << i << "  " << Point[i + 4].first << "  " << Point[i + 4].second << "  " << check[i + 4] << endl;
		//}
		count = Point[i].first + Point[i + 4].first;
		if (5 <= count)
			break;
	}
	/*if (flag)
		cout << "66 : " << foulLine66 << "  " << c << endl;*/


	if (5 <= count)
	{
		if (mPlayer == BlackPlayer)
			return -66;
		if (mPlayer == WhitePlayer)
			return 66;

		return 0;
	}
	else
		return 0;
}

int Judgment::EndGame(pair<int, int> position)
{
	int movePoint[8][2] = { { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 } };
	int tempX, tempY;
	int foulLine66 = 0;

	bool empty;
	pair<int, int> Point[8];
	bool check[8] = { false, };

	for (int way = 0; way < 8; ++way)
	{
		tempX = position.first;
		tempY = position.second;
		empty = true;
		for (int move = 0; move < 6; ++move)
		{
			tempX += movePoint[way][0];
			tempY += movePoint[way][1];
			if (10 <= tempX && tempX <= 27 && 10 <= tempY && tempY <= 27)
			{
				if (mMap[tempY][tempX] == mPlayer)
					Point[way].first++;
				else
					break;
			}
			else
			{
				check[way] = true;
				break;
			}
		}
	}

	int count;
	int result = 0;
	int c = 0;

	for (int i = 0; i < 4; ++i)
	{
		count = Point[i].first + Point[i + 4].first;

		if (4 <= count)
		{
			if (count == 4)
			{
				result = 4;
			}
		}


	}
	if (result == 4)
	{
		return 555;
	}
	else
		return 0;
}



void Judgment::displayMap()
{
	cout << "   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8" << endl;
	for (int i = 0; i <= MapSize; ++i)
	{
		cout << i % 10 << " ";
		for (int j = 0; j <= MapSize; ++j)
		{

			if (mMap[i + 10][j + 10] == 0)
			{
				cout << "��";
			}
			else if (mMap[i + 10][j + 10] == BlackPlayer)
			{
				cout << "��";
			}
			else if (mMap[i + 10][j + 10] == WhitePlayer)
			{
				cout << "��";
			}
			else if (mMap[i + 10][j + 10] == BlackCursor)
			{
				cout << "��";
			}
			else if (mMap[i + 10][j + 10] == WhiteCursor)
			{
				cout << "��";
			}
		}
		cout << endl;
	}
}