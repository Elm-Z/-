//游戏分为两个雷阵，真实雷阵和玩家界面
//rael_mine[][]  show_mine[][]
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define ROW 12
#define COL 12
#define NUM 20
char real_mine[ROW][COL];//真实雷阵
char show_mine[ROW][COL];//玩家界面
void menu()
{
	printf("####################\n");
	printf("##1.go on##0.exit##\n");
	printf("###################\n");
}
//初始化雷区
void init_game()
{
	int i,j;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			real_mine[i][j]='0';
			show_mine[i][j]='*';
		}
	}
}
//打印真实界面
void draw_real()
{
	int i,j;
	printf("0  ");
	for(i=1;i<ROW-1;i++)
	{
		printf("%-2d ",i);
	}
	printf("\n");
	for(i=1;i<COL-1;i++)
	{
		printf("%-2d ",i);
		{
			for(j=1;j<ROW-1;j++)
				printf("%-2c ",real_mine[i][j]);
			}
			printf("\n");
		}
	}
	//打印用户界面
	void draw_show()
	{
	int i,j;
	printf("0  ");
	for(i=1;i<ROW-1;i++)
	{
		printf("%-2d ",i);
	}
	printf("\n");
	for(i=1;i<COL-1;i++)
	{
		printf("%-2d ",i);
		{
			for(j=1;j<ROW-1;j++)
				printf("%-2c ",show_mine[i][j]);
			}
			printf("\n");
		}
	}
	//布雷
	void set_mine()
	{
		int x,y;//初始化坐标
		int count=NUM;
		while(count)
		{
			 x=rand()%10+1;
			 y=rand()%10+1;
			if(real_mine[x][y]=='0')
			{
				real_mine[x][y]='1';
			    count--;
			}
		}
	}
	//检测周围雷数
	int test_mine(int x,int y)
	{
		int count=0;
		if(real_mine[x][y+1]=='1')
			count++;
	    if(real_mine[x][y-1]=='1')
			count++;
	    if(real_mine[x-1][y]=='1')
			count++;
	    if(real_mine[x-1][y-1]=='1')
			count++;
	    if(real_mine[x-1][y+1]=='1')
			count++;
	    if(real_mine[x+1][y]=='1')
			count++;
	    if(real_mine[x+1][y-1]=='1')
			count++;
	    if(real_mine[x+1][y+1]=='1')
			count++;
			return count;
	}		
	//雷区展开
	void open_mine(int x,int y)
	{
		if(real_mine[x][y+1]=='0')
			show_mine[x][y+1]=test_mine(x,y+1)+'0';
			if(real_mine[x][y-1]=='0')
			show_mine[x][y-1]=test_mine(x,y-1)+'0';
			if(real_mine[x+1][y]=='0')
			show_mine[x+1][y]=test_mine(x+1,y)+'0';
			if(real_mine[x-1][y]=='0')
			show_mine[x-1][y]=test_mine(x-1,y)+'0';
			if(real_mine[x+1][y+1]=='0')
			show_mine[x+1][y+1]=test_mine(x+1,y+1)+'0';
			if(real_mine[x-1][y+1]=='0')
			show_mine[x-1][y+1]=test_mine(x-1,y+1)+'0';
			if(real_mine[x-1][y-1]=='0')
			show_mine[x-1][y-1]=test_mine(x-1,y-1)+'0';
			if(real_mine[x][y+1]=='0')
			show_mine[x][y+1]=test_mine(x,y+1)+'0';
			if(real_mine[x+1][y-1]=='0')
			show_mine[x+1][y-1]=test_mine(x+1,y-1)+'0';
		}
	//避免第一次被炸死
	void safe_swich()
		{
			int x=0;
			int y=0;
			char ch;
			int temp=1;
			printf("请输入行与列\n");
			while(1)
			{
				scanf("%d%d",&x,&y);
				if((x>0&&x<=10)&&(y>0&&y<=10))
				{
					if(real_mine[x][y]=='1')
					{
						real_mine[x][y]='0';
						ch=test_mine(x,y)+'0';
						show_mine[x][y]=ch;
						open_mine(x,y);
						while(temp)
						{
							int a=rand()%10+1;
							int b=rand()%10+1;
							if(real_mine[a][b]=='0')
							{
								real_mine[a][b]='1';
								temp--;
								break;
							}
						}break;
					}
					if(real_mine[x][y]=='0')
					{
						ch=test_mine(x,y)+'0';
						show_mine[x][y]=ch;
						open_mine(x,y);
					}break;
				}
					else
					{
						printf("输入错误，请重新输入\n");
					}
				}
			}
			//判断是否胜利
			 int test_show_mine()
			{
				int i;
				int j;
				int count=0;
				for(i=1;i<ROW-1;i++)
				{
					for(j=1;j<COL-1;j++)
					{
						if(show_mine[i][j]=='*')
						{
							count++;
						}
					}
				}
				return count;
			}
			//扫雷模块
			int sweep_mine()//踩到返回1，没有踩到返回0
			{
				int x=0;
				int y=0;
				scanf("%d%d",&x,&y);
				if((x>0&&x<=10)&&(y>0&&y<=10))
				{
					if(real_mine[x][y]=='0')//未踩雷
						show_mine[x][y]=test_mine(x,y)+'0';
						open_mine(x,y);
					if(test_show_mine()==NUM)
					{
						draw_real();
						printf("玩家赢\n");
						return 0;
					}
				else if(real_mine[x][y]=='1')//踩雷
				{
					draw_real();
					printf("玩家输\n");
					return 1;
				}
			}
				else
				{
					printf("请重新输入");
					
				}
				return 0;
			}
			//游戏函数
			void game()
			{
				init_game();
				set_mine();
				draw_real();
				printf("\n");
				draw_show();
				safe_swich();
				if(test_show_mine()==NUM)
				{
					draw_real();
					printf("玩家胜利\n");
				}
			    draw_show();
				while(1)
				{
					int flag=sweep_mine();
					if(test_show_mine()==NUM)
					{
						draw_real();
						printf("玩家胜利!\n");
						break;
					}
					if(flag)
					{
						printf("被雷炸死\n");
						draw_real();
						break;
					}
					else
						draw_show();
					}
				}
int main()
{
	srand((unsigned int)time(NULL));
	int input;
	menu();
	do
	{
		scanf("%d",&input);
		switch(input)
		{
			case 1:game();
				break;
			case 2:exit(1);
				break;
			default:
			printf("请输入正确的数字\n");
			break;
		}
		menu();
		printf("继续？\n");
	}
	while(1);
	{
		system("pause");
	}
		return 0;
	}
	