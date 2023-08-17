#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set) 
{
	int i=0;
	int j=0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0;j < cols;j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----------ɨ����Ϸ-----------\n");
	for (j = 0;j <= col;j++)
	{
		printf("%d  ",j );
	}
	printf("\n");
	for ( i = 1; i <= row; i++)
	{
		printf("%d  ",i);
		for (j = 1;j <= col;j++)
		{
			printf("%c  ",board[i][j]);
		}
		printf("\n");
	}
	printf("----------ɨ����Ϸ-----------\n");
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = 10;
	while (count)
	{
		int x=rand()%row+1;
		int y=rand()%col+1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char board[ROWS][COLS], int x, int y)
{
	return (board[x - 1][y] +
		board[x - 1][y - 1] +
		board[x][y - 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] +
		board[x][y + 1] +
		board[x - 1][y + 1] -
		8 * '0');
}

int Water(char mine[ROWS][COLS],char show[ROWS][COLS],int x,int y,char mine1[ROWS][COLS])
{
	show[x][y] = get_mine_count(mine, x, y) + '0';
	if (show[x][y] == '0')
	{
		int i = 1;
		int j = 1;
				if (x+i >= 1 && x+i <= ROWS && y+j >= 1 && y+j <= COLS)
				{
					while (mine1[x][y] !='2')
					{
						mine1[x][y] = '2';
						Water(mine, show, x - i, y - j, mine1);
						Water(mine, show, x + i, y + j, mine1);
						Water(mine, show, x - i, y + j, mine1);
						Water(mine, show, x + i, y - j, mine1);
						Water(mine, show, x , y + j, mine1);
						Water(mine, show, x - i, y , mine1);
						Water(mine, show, x + i, y , mine1);
						Water(mine, show, x , y - j,mine1);
					}
				}
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, char mine1[ROWS][COLS])
{
	int x = 0;
	int y = 0;
	int count;
	count = 0;
	do
	{
		printf("������Ҫ�Ų�����꣬���Ҫ���������0 0\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*' && show[x][y] != 'X')
			{
				printf("�����걻�Ų���ˣ������ظ��Ų�\n");
			}
			else
			{
				//����
				if (mine[x][y] == '1')
				{
					printf("���ź�����ȵ�����\n");
					DisplayBoard(mine, row, col);
					break;
				}
				//������
				else
				{
					Water(mine, show, x, y, mine1);
					DisplayBoard(show, ROW, COL);
				}
			}
		}
			else if (x == 0 && y == 0)
			{
				printf("������Ҫ��ǵ�����\n");
				scanf("%d%d", &x, &y);
				if (x >= 1 && x <= row && y >= 1 && y <= col)
				{

					while (show[x][y] != '*' && show[x][y] != 'X')
					{
						printf("���ݷǷ�����������������\n");
						scanf("%d%d", &x, &y);
					}
					if (show[x][y] == 'X')
					{
						show[x][y] = '*';
					}
					else
					{
						show[x][y] = 'X';
						DisplayBoard(show, row, col);
					}
				}
			}
		else
		{
			printf("���ݷǷ�������������\n");
		}
		count = 0;
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				if (show[i][j]=='X')
				{
					count++;
				}
			}
		}
	} while (count<10);
	if (count == 10)
	{
		printf("���׳ɹ���\n");
		DisplayBoard(mine, ROW, COL);
	}
}
