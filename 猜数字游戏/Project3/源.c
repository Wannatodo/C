#include<stdio.h>
#include<stdlib.h>
void menu()
{
	printf("***************************************\n");
	printf("**************  1.play   **************\n");
	printf("**************  2.exit   **************\n");
	printf("***************************************\n");
}
void game()
{
	int ret=rand()%100+1;
	int num = 0;
	printf("��Ϸ��ʼ,����������\n");
	
	while (1)
	{
		scanf("%d", &num);
		if (num == ret)
		{
			printf("��ϲ��¶���");
			break;
		}
		else if (num < ret)
		{
			printf("��С��\n");
		}
		else
		{
			printf("�´���\n");
		}
	}
}
int main()
{
	int num = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:)\n");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			game();
			break;
		case 2:
			printf("���˳���Ϸ");
			break;
		default:
			printf("��������������");
			scanf("%d", &num);
			break;
		}
		return 0;
	} while (num == 2);
	return 0;
}
