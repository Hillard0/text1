#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 30 
int main ()
{
	void aver(int NUM[],double score[],int num);
	void del(int NUM[],double score[],int num);
	void select(int NUM[],double score[],int num);
	void max(int NUM[],double score[],int num);
	void cover();
	int add (int NUM[] ,double score[],int n);
	void paiming(int NUM[] ,double score[],int n);
	int choose;
	int num;
	int t,i,j,l,NUM[N];
	double score[N];
	int n;
	
	cover();
	
	while (1)
	{
		printf ("请输入您想要进行的操作 ： \n");
		printf ("1、添加学生 ； 2、排名 ； 3、最高分 ； 4、查询 ； 5、删除 ；6、平均分 ; 0、退出\n");
		scanf ("%d",&choose);
		
		switch (choose)
		{
			case 1 : num = add (NUM ,score,n) ;   break;
			case 2 : paiming(NUM , score,num);  break;
			case 3 : max(NUM,score,num) ; break;
			case 4 : select(NUM,score,num) ;break;
			case 5 : del(NUM,score,num) ;  break;
			case 6 : aver(NUM,score,num)  ;  break;
			case 0 :  printf ("欢迎下次使用！ ！ ！\n");  exit(0);   
		}
	}
}

void cover()
{
	printf ("\n\n*************************\n\n\n");
	printf ("欢迎来到学生管理系统! ! ! \n");
	printf ("\n\n*************************\n\n\n");
}

int add (int NUM[] ,double score[],int n)       //1、添加操作完成
{
	int i;
	printf ("请输入学生人数 ： \n");
	scanf ("%d",&n);
	for (i=0 ;i<n ;i++)
	{
		printf ("学号 ： ");
		scanf ("%d",&NUM[i]);
		printf ("分数 ： ");
		scanf ("%lf",&score[i]);
		
	}
	return n;
}

void paiming(int NUM[] ,double score[],int n)    //排名操作完成
{
	//printf ("%d\n",n);
	int i,j,t,l;
	double k;
	for (i=0;i<n-1;i++)
	{
		for (j=0;j<n-1-i;j++)
		{
			if (score[j]<score[j+1])
			{
				t=score[j];score[j]=score[j+1];score[j+1]=t;
				k=NUM[j];NUM[j]=NUM[j+1];NUM[j+1]=k;	
			}
			
		}
	}
	printf ("学生排名如下 ： \n");
	for ( i=0 ;i< n;i++)
	{
		printf ("%d --> %.2f\n",NUM[i],score[i]);
	}
}

void max(int NUM[],double score[],int num)   //最大值操作完成； 
{
	double max =0 ;
	int i,nmax;
	for (i=0 ;i<num ;i++)
	{
		if (score[i] >max)
		{
			max = score[i];
		}
	}
	for (i=0 ;i< num ;i++)
	{
		if (score[i] == max)
		printf ("成绩最高的是%d同学，分数为%.2f分\n",NUM[i],score[i]);
	}
}

void select(int NUM[],double score[],int num)  //查询操作完成；
{
	int i,a,cnt=0;
	printf ("请输入您想要查找的学生的学号 ：  \n");
	scanf ("%d",&a);
	for (i=0 ;i< num ;i++)
	{
		if (NUM [i]  == a)
		{
			cnt++;
			printf ("%d同学的分数为%.2f\n",a,score[i]);
		}
	}
	if (cnt ==0)
	{
		printf ("您输入的学号有误。\n");
	}
 } 
 
  void del(int NUM[],double score[],int num)   //删除操作完成
 {
 	int i,j,l,a,t;
 	printf ("请输入您要删除的学生的学号 ： \n");
 	scanf ("%d",&a);
 	for (i=0 ;i <num ;i++)
 	{
 		if (NUM[i] == a)
 		{
 			t=i;
		 }
	 }
	 printf ("删除后的学生名单如下 ： \n");
	for (i =0 ;i<= t-1 ;i++)
	{
		printf ("%d----> %.2f\n",NUM[i],score[i]);
	}
 	for (i=t+1 ;i < num;i++)
 	{
 		printf ("%d----> %.2f\n",NUM[i],score[i]);
	}
 }
 
void aver(int NUM[],double score[],int num)    //求平均分操作完成 
{
	double sum=0,ave=0;
	int i;
	for (i=0 ;i<num;i++)
	{
		sum += score[i]  ;
	}
	ave = sum / num*1.0 ;
	printf ("学生们的平均分是%.2f分\n",ave);
}