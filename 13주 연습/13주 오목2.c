#define _CRT_SECURE_NO_WARNINGS
#include<stdbool.h>

#define Black 1
#define White 2
#define Space 0
#define Space_check -1



struct Node
{
    //<Data>
    int type; // 종류(가로(0), 세로(1), 오대(2), 왼대(3))


    int column;
    int row;


    struct Node* next;
};

void newNode(struct Node* head, int type, int column, int row)
{
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));

    new->next = head->next;
    head->next = new;

    new->type = type;
    new->column = column;
    new->row = row;
}

void AllDelete(struct Node* head)
{
    struct Node* save = head->next;

    while (save != NULL)
    {
        struct Node* next = save->next;

        free(save);

        save = next;
    }

    head->next = NULL;
}

void ALLprint(const char omoc[][19])
{
    printf("  ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", i);
    }
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < 19; i++)
    {
        int t = i;
        if (t >= 10)
        {
            t -= 10;
        }
        printf("%d ", t);
        for (int j = 0; j < 19; j++)
        {

            if (omoc[i][j] == Black)
            {
                printf("@ ");
            }
            else if (omoc[i][j] == White)
            {
                printf("O ");
            }
            else
            {
                printf("+ ");
            }

        }
        printf("\n");
    }
}




//선공: 사람
//후공: AI
void Attack(char omoc[][19], struct Node* headAttack1, struct Node* headAttack2, struct Node* headAttack3, struct Node* headAttack4)
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (omoc[i][j] == Space)
            {
                //가로에서 앞뒤로 연속된 돌의 개수
                int continue_Black = 0;
                //가로에서 앞뒤로 연속된 돌의 개수
                for (int t = j - 1; t >= 0; t--)
                {
                    if (omoc[i][t] == Black)
                    {
                        continue_Black++;
                    }

                    else
                    {
                        break;
                    }

                }
                for (int t = j + 1; t <= 18; t++)
                {
                    if (omoc[i][t] == Black)
                    {
                        continue_Black++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (continue_Black == 5)
                {
                    printf("검정돌이 승리하였습니다.\n");
                }
                else if (continue_Black == 4)
                {
                    newNode(headAttack4, 0, i, j);
                }
                else if (continue_Black == 3)
                {
                    newNode(headAttack3, 0, i, j);
                }
                else if (continue_Black == 2)
                {
                    newNode(headAttack2, 0, i, j);
                }
                else if (continue_Black == 1)
                {
                    newNode(headAttack1, 0, i, j);
                }

                //세로에서 앞뒤로 연속된 돌의 개수
                continue_Black = 0;

                for (int t = i - 1; t >= 0; t--)
                {
                    if (omoc[t][j] == Black)
                    {
                        continue_Black++;
                    }
                    else
                    {
                        break;
                    }
                }

                for (int t = i + 1; t <= 18; t++)
                {
                    if (omoc[t][j] == Black)
                    {
                        continue_Black++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (continue_Black == 5)
                {
                    printf("검정돌이 승리하였습니다.\n");
                }
                else if (continue_Black == 4)
                {
                    newNode(headAttack4, 1, i, j);
                }
                else if (continue_Black == 3)
                {
                    newNode(headAttack3, 1, i, j);
                }
                else if (continue_Black == 2)
                {
                    newNode(headAttack2, 1, i, j);
                }
                else if (continue_Black == 1)
                {
                    newNode(headAttack1, 1, i, j);
                }
                //오대각선에서 앞뒤로 연속된 돌의 개수
                continue_Black = 0;
                for (int column = i + 1, row = j - 1; (column <= 18 && row >= 0); column++, row--)
                {
                    if (omoc[column][row] == Black)
                    {
                        continue_Black++;
                    }
                    else
                    {
                        break;
                    }
                }

                for (int column = i - 1, row = j + 1; (column >= 0 && row <= 18); column--, row++)
                {
                    if (omoc[column][row] == Black)
                    {
                        continue_Black++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (continue_Black == 5)
                {
                    printf("검정돌이 승리하였습니다.\n");
                }
                else if (continue_Black == 4)
                {
                    newNode(headAttack4, 2, i, j);
                }
                else if (continue_Black == 3)
                {
                    newNode(headAttack3, 2, i, j);
                }
                else if (continue_Black == 2)
                {
                    newNode(headAttack2, 2, i, j);
                }
                else if (continue_Black == 1)
                {
                    newNode(headAttack1, 2, i, j);
                }
                //왼대각선에서 앞뒤로 연속된 돌의 개수
                continue_Black = 0;
                for (int column = i - 1, row = j - 1; (column >= 0 && row >= 0); column--, row--)
                {
                    if (omoc[column][row] == Black)
                    {
                        continue_Black++;
                    }
                    else
                    {
                        break;
                    }
                }
                for (int column = i + 1, row = j + 1; (column <= 18 && row <= 18); column++, row++)
                {
                    if (omoc[column][row] == Black)
                    {
                        continue_Black++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (continue_Black == 5)
                {
                    printf("검정돌이 승리하였습니다.\n");
                }
                else if (continue_Black == 4)
                {
                    newNode(headAttack4, 3, i, j);
                }
                else if (continue_Black == 3)
                {
                    newNode(headAttack3, 3, i, j);
                }
                else if (continue_Black == 2)
                {
                    newNode(headAttack2, 3, i, j);
                }
                else if (continue_Black == 1)
                {
                    newNode(headAttack1, 3, i, j);
                }

            }

        }
    }
}




void Defense(char omoc[][19], struct Node* headDefense1, struct Node* headDefense2, struct Node* headDefense3, struct Node* headDefense4)
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (omoc[i][j] == Space)
            {
                //가로에서 앞뒤로 연속된 돌의 개수
                int continue_White = 0;
                //가로에서 앞뒤로 연속된 돌의 개수
                for (int t = j - 1; t >= 0; t--)
                {
                    if (omoc[i][t] == White)
                    {
                        continue_White++;
                    }

                    else
                    {
                        break;
                    }

                }
                for (int t = j + 1; t <= 18; t++)
                {
                    if (omoc[i][t] == White)
                    {
                        continue_White++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (continue_White == 5)
                {
                    printf("하얀돌이 승리하였습니다.\n");
                }
                else if (continue_White == 4)
                {
                    newNode(headDefense4, 0, i, j);
                }
                else if (continue_White == 3)
                {
                    newNode(headDefense3, 0, i, j);
                }
                else if (continue_White == 2)
                {
                    newNode(headDefense2, 0, i, j);
                }
                else if (continue_White == 1)
                {
                    newNode(headDefense1, 0, i, j);
                }
                //세로에서 앞뒤로 연속된 돌의 개수
                continue_White = 0;

                for (int t = i - 1; t >= 0; t--)
                {
                    if (omoc[t][j] == White)
                    {
                        continue_White++;
                    }
                    else
                    {
                        break;
                    }
                }

                for (int t = i + 1; t <= 18; t++)
                {
                    if (omoc[t][j] == White)
                    {
                        continue_White++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (continue_White == 5)
                {
                    printf("하얀돌이 승리하였습니다.\n");
                }
                else if (continue_White == 4)
                {
                    newNode(headDefense4, 1, i, j);
                }
                else if (continue_White == 3)
                {
                    newNode(headDefense3, 1, i, j);
                }
                else if (continue_White == 2)
                {
                    newNode(headDefense2, 1, i, j);
                }
                else if (continue_White == 1)
                {
                    newNode(headDefense1, 1, i, j);
                }
                //오대각선에서 앞뒤로 연속된 돌의 개수
                continue_White = 0;
                for (int column = i + 1, row = j - 1; (column <= 18 && row >= 0); column++, row--)
                {
                    if (omoc[column][row] == White)
                    {
                        continue_White++;
                    }
                    else
                    {
                        break;
                    }
                }

                for (int column = i - 1, row = j + 1; (column >= 0 && row <= 18); column--, row++)
                {
                    if (omoc[column][row] == White)
                    {
                        continue_White++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (continue_White == 5)
                {
                    printf("하얀돌이 승리하였습니다.\n");
                }
                else if (continue_White == 4)
                {
                    newNode(headDefense4, 2, i, j);
                }
                else if (continue_White == 3)
                {
                    newNode(headDefense3, 2, i, j);
                }
                else if (continue_White == 2)
                {
                    newNode(headDefense2, 2, i, j);
                }
                else if (continue_White == 1)
                {
                    newNode(headDefense1, 2, i, j);
                }
                //왼대각선에서 앞뒤로 연속된 돌의 개수
                continue_White = 0;
                for (int column = i - 1, row = j - 1; (column >= 0 && row >= 0); column--, row--)
                {
                    if (omoc[column][row] == White)
                    {
                        continue_White++;
                    }
                    else
                    {
                        break;
                    }
                }
                for (int column = i + 1, row = j + 1; (column <= 18 && row <= 18); column++, row++)
                {
                    if (omoc[column][row] == White)
                    {
                        continue_White++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (continue_White == 5)
                {
                    printf("하얀돌이 승리하였습니다.\n");
                }
                else if (continue_White == 4)
                {
                    newNode(headDefense4, 3, i, j);
                }
                else if (continue_White == 3)
                {
                    newNode(headDefense3, 3, i, j);
                }
                else if (continue_White == 2)
                {
                    newNode(headDefense2, 3, i, j);
                }
                else if (continue_White == 1)
                {
                    newNode(headDefense1, 3, i, j);
                }

            }

        }
    }
}

int main(void)
{
    char omoc[19][19];

    struct Node* headAttack1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* headAttack2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* headAttack3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* headAttack4 = (struct Node*)malloc(sizeof(struct Node));

    struct Node* headDefense1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* headDefense2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* headDefense3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* headDefense4 = (struct Node*)malloc(sizeof(struct Node));

    headAttack1->next = NULL;
    headAttack2->next = NULL;
    headAttack3->next = NULL;
    headAttack4->next = NULL;

    headDefense1->next = NULL;
    headDefense2->next = NULL;
    headDefense3->next = NULL;
    headDefense4->next = NULL;

    int column; // 행
    int row; // 열

    int BlackNum = 0; // 검정돌 개수
    int WhiteNum = 0; // 하얀돌 개수


    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            omoc[i][j] = Space;
        }
    }

    while (1)
    {



        /*
        for (struct Node* i = headAttack1->next; i != NULL; i = i->next)
        {
           printf("검정1:줄:%d 열:%d\n", i->column, i->row);

        }
        printf("\n");
        for (struct Node* i = headAttack2->next; i != NULL; i = i->next)
        {
           printf("검정2:줄:%d 열:%d\n", i->column, i->row);

        }
        printf("\n");
        for (struct Node* i = headAttack3->next; i != NULL; i = i->next)
        {
           printf("검정3:줄:%d 열:%d\n", i->column, i->row);

        }
        printf("\n");
        for (struct Node* i = headAttack4->next; i != NULL; i = i->next)
        {
           printf("검정4:줄:%d 열:%d\n", i->column, i->row);

        }
        */




        if ((BlackNum + WhiteNum) % 2 == 0)
        {
            while (1)
            {

                printf("좌표 입력: ");
                if (scanf("%d %d", &column, &row) != 2)
                {
                    while (getchar() != '\n');
                    printf("잘못된 값입니다.\n");
                }
                else if (column > 18 || row > 18 || column < 0 || row < 0)
                {
                    printf("범위가 벗어난 값입니다.\n");
                }
                else if (omoc[column][row] != Space)
                {
                    printf("이미 돌이 놓여있습니다.\n");
                }
                else
                {
                    break;
                }
            }
            omoc[column][row] = Black;
            BlackNum++;
        }
        else
        {
            Attack(omoc, headAttack1, headAttack2, headAttack3, headAttack4); // 검은돌


            Defense(omoc, headDefense1, headDefense2, headDefense3, headDefense4); // 하얀돌

            if (headDefense4->next != NULL) // 하얀돌 4개
            {
                omoc[headDefense4->next->column][headDefense4->next->row] = White;
            }
            else if (headAttack4->next != NULL) // 검정돌 4개
            {
                omoc[headAttack4->next->column][headAttack4->next->row] = White;
            }
            else if (headDefense3->next != NULL) // 하얀돌 3개
            {
                omoc[headDefense3->next->column][headDefense3->next->row] = White;
            }
            else if (headAttack3->next != NULL) // 검정돌 3개
            {
                omoc[headAttack3->next->column][headAttack3->next->row] = White;
            }
            else if (headDefense2->next != NULL) // 하얀돌 2개
            {
                omoc[headDefense2->next->column][headDefense2->next->row] = White;
            }
            else if (headAttack2->next != NULL)  // 검정돌 2개
            {
                omoc[headAttack2->next->column][headAttack2->next->row] = White;
            }
            else if (headDefense1->next != NULL)  // 하얀돌 1개
            {
                omoc[headDefense1->next->column][headDefense1->next->row] = White;
            }
            else if (headAttack1->next != NULL)  // 검정돌 1개
            {
                omoc[headAttack1->next->column][headAttack1->next->row] = White;
            }
            else
            {
                omoc[9][9] = White;

            }
            WhiteNum++;
        }

        printf("Black: %d\tWhite:%d\n", BlackNum, WhiteNum);


        ALLprint(omoc);

        AllDelete(headAttack1);
        AllDelete(headAttack2);
        AllDelete(headAttack3);
        AllDelete(headAttack4);

        AllDelete(headDefense1);
        AllDelete(headDefense2);
        AllDelete(headDefense3);
        AllDelete(headDefense4);

    }
    return 0;
}