#include<stdio.h>
int sortharita[100][100],queue[100],income[100],asilsort[100];
int sayi,yol,son=1,bas=1;
void queue1()
{
	int t=1,i,j;
	for(i=1;i<=sayi;i++)
	{
		if(income[i]==0)
		{
			queue[son]=i;
			son++;
		}
	}
	while(1)
	{
		for(i=1;i<=sayi;i++)
		{
			if(sortharita[queue[bas]][i]!=0)
			{
				income[i]--;
				if(income[i]==0)
				{
					queue[son]=i;
					son++;
				}
			}
		}
		asilsort[t]=queue[bas];
		t++;
		queue[bas]=0;
		bas++;
		if(bas==son+1)
		{
			break;
		}
	}
}
void oku()
{	
	int i,em,re;
	scanf("%d %d",&sayi,&yol);
	for(i=1;i<=yol;i++)
	{
		scanf("%d %d",&em,&re);
		sortharita[em][re]=1;
		income[re]++;
	}
}
void yaz()
{
	int i,sayac=0;
	for(i=1;i<=sayi;i++)
	{
		if(income[i]!=0)
		{
			sayac++;
		}
	}
	if(sayac==0)
	{
		for(i=1;i<=sayi;i++)
		{
			printf("%d ",asilsort[i]);
		}
		printf("\n");
	}
	else if(sayac!=0)
	{
		printf("-1");
	}
}
int main ()
{
	int i,j,m,n,em,re;
	oku();
	queue1();
	yaz();
}
