#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()
{
	printf("****************************\n");
	printf("******     1.play     ******\n");
	printf("******     0.exit     ******\n");
	printf("****************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char mine1[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化
	InitBoard(mine1, ROWS, COLS, '0');
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//设置雷
	SetMine(mine1, ROW, COL);
	SetMine(mine,ROW,COL);
	DisplayBoard(show, ROW, COL);
	//排查雷
	FindMine(mine,show,ROW,COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入:\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("已退出游戏\n");
			break;
		default:
			printf("选择错误请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}