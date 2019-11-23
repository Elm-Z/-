//��Ϸ��Ϊ����������ʵ�������ҽ���
//rael_mine[][]  show_mine[][]
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define ROW 12
#define COL 12
#define NUM 20
char real_mine[ROW][COL];//��ʵ����
char show_mine[ROW][COL];//��ҽ���
void menu()
{
	printf("####################\n");
	printf("##1.go on##0.exit##\n");
	printf("###################\n");
}
//��ʼ������
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
//��ӡ��ʵ����
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
	//��ӡ�û�����
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
	//����
	void set_mine()
	{
		int x,y;//��ʼ������
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
	//�����Χ����
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
	//����չ��
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
	//�����һ�α�ը��
	void safe_swich()
		{
			int x=0;
			int y=0;
			char ch;
			int temp=1;
			printf("������������\n");
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
						printf("�����������������\n");
					}
				}
			}
			//�ж��Ƿ�ʤ��
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
			//ɨ��ģ��
			int sweep_mine()//�ȵ�����1��û�вȵ�����0
			{
				int x=0;
				int y=0;
				scanf("%d%d",&x,&y);
				if((x>0&&x<=10)&&(y>0&&y<=10))
				{
					if(real_mine[x][y]=='0')//δ����
						show_mine[x][y]=test_mine(x,y)+'0';
						open_mine(x,y);
					if(test_show_mine()==NUM)
					{
						draw_real();
						printf("���Ӯ\n");
						return 0;
					}
				else if(real_mine[x][y]=='1')//����
				{
					draw_real();
					printf("�����\n");
					return 1;
				}
			}
				else
				{
					printf("����������");
					
				}
				return 0;
			}
			//��Ϸ����
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
					printf("���ʤ��\n");
				}
			    draw_show();
				while(1)
				{
					int flag=sweep_mine();
					if(test_show_mine()==NUM)
					{
						draw_real();
						printf("���ʤ��!\n");
						break;
					}
					if(flag)
					{
						printf("����ը��\n");
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
			printf("��������ȷ������\n");
			break;
		}
		menu();
		printf("������\n");
	}
	while(1);
	{
		system("pause");
	}
		return 0;
	}
	