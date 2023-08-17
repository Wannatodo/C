#include "game.h"


void InitBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0;j < col;j++)
		{
			board[i][j] = ' ';
		}

	}
}

void DispalyBoard(char board[ROW][COL], int row, int col)
{
	for ( int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			if(j<col-1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int i = 0; i < row; i++)
			{
				printf("---");
				if (i < row - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("请玩家输入坐标\n");
	while (1)
	{
		scanf("%d %d", &x, &y);
		//坐标合法的判断
		if (x >= 1 && x <= row && y <= col && y >= 1)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else 
			{
				printf("坐标被占用");
			}
		}
		else
		{
			printf("数据非法，重新输入");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋\n");
	int x = 0;
	int y = 0;

	while (1)
	{
		x = rand() % row;//0~2
		y = rand() % col;
		if (board[1][1] == ' ')
		{
			board[1][1] = '#';
			break;
		}
			else if (board[x][y] == ' '&&board[1][1]!=' ')
			{
				board[x][y] = '#';
				break;
			}
	}
}

int IsFull(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i=0;i<row;i++) 
	{
		for (j = 0;j < col;j++) 
		{
			if (board[i][j] == ' ') 
			{
				return 0;
			}
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)//行
	{
		if (board[i][0] == board[i][1] &&board[i][1]== board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
		for (int j = 0; j < col; j++)//列
	{
		if (board[0][j] == board[1][j] && board[1][j]==board[2][j] && board[1][j] != ' ')
		{
			return board[0][j];
		}
	}
		if (board[0][0] == board[1][1] && board[1][1]==board[2][2] && board[1][1] != ' ')
		{
			return board[1][1];
		}
		//没有人赢
		if (IsFull(board,row,col))
		{
			return 'Q';
		}
		return 'C';
}
