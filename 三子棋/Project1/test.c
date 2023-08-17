#include "game.h"
void menu()
{
	printf("******************************\n");
	printf("********    1.play      ******\n");
	printf("********    2.exit      ******\n");
	printf("******************************\n");
}

void game()
{
	char ret = 0;
	char board[ROW][COL] = {0};
	//��ʼ�����̵ĺ���
	InitBoard(board, ROW, COL);
	DispalyBoard(board,ROW,COL);
	//����
	while (1)
	{
		PlayerMove(board,ROW,COL);
		DispalyBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		DispalyBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret!='C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int input=0;
	do
	{
		menu();//��ӡ�˵�
		printf("������:>");
		scanf("%d",&input);
		switch (input)
		{
		case 1://��ʼ��Ϸ	��ӡ����
			game();
			break;
		case 2://�˳�
			printf("�˳���Ϸ\n");
			break;
		default:printf("��������������\n");
			scanf("%d", &input);
			break;
		}
	} while (input==1);
}