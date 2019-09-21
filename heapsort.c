#include<stdio.h>
int dizi[100],tut;
void upheap(int i)
{
	if(dizi[i]>dizi[i/2])
	{
		if(i/2==0)
		{
			return;
		}
		if(dizi[i]>dizi[i/2])
		{
			tut=dizi[i];
			dizi[i]=dizi[i/2];
			dizi[i/2]=tut;
			upheap(i/2);
		}
	}
}
void downheap(int i)
{
	if(dizi[i*2]==0)
	{
		return ;
	}
	if(dizi[i*2]>dizi[(i*2)+1])
	{
		if(dizi[i*2]>dizi[i])
		{
			tut=dizi[i];
			dizi[i]=dizi[i*2];
			dizi[i*2]=tut;
			downheap(i*2);
		}
	}
	else
	{
		if(dizi[(i*2)+1]>dizi[i])
		{
			tut=dizi[i];
			dizi[i]=dizi[(i*2)+1];
			dizi[(i*2)+1]=tut;
			downheap((i*2)+1);
		}
	}
}
int main()
{
	int i,n,m;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&dizi[i]);
		upheap(i);
	}
	for(i=1;i<=n;i++)
	{
		printf("%d ",dizi[1]);
		dizi[1]=dizi[n-i+1];
		dizi[n-i+1]=0;
		downheap(1);
	}
	printf("\n");
}
