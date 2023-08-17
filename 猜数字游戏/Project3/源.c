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
	printf("游戏开始,请输入数字\n");
	
	while (1)
	{
		scanf("%d", &num);
		if (num == ret)
		{
			printf("恭喜你猜对了");
			break;
		}
		else if (num < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("猜大了\n");
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
		printf("请选择:)\n");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			game();
			break;
		case 2:
			printf("已退出游戏");
			break;
		default:
			printf("错误，请重新输入");
			scanf("%d", &num);
			break;
		}
		return 0;
	} while (num == 2);
	return 0;
}
