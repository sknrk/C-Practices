#include<stdio.h>
int sayi[100000],dizi[10000],sirala[10000];
int n;
void yaz(int f2)
{
	int i ;	
	if((f2-1)%2==0)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",sirala[i]);
		}
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",sayi[i]);	
		}
	}
}
void sirala2()
{
	int i,m=1,f,j,t=1,sayac=0;
	for(f=1;f<=40000;f++,m*=10)
	{
		for(i=0;i<=9;i++)
		{
			sayac=0;
			for(j=1;j<=n;j++)
			{
				if(f%2==1)
				{
					if(sayi[j]/m==0)
					{
						sayac++;
					}
					if((sayi[j]/m)%10==i)
					{
						sirala[t]=sayi[j];
						t++;
					}
				}
				if(f%2==0)
				{
					if(sirala[j]/m==0)
					{
						sayac++;
					}
					if((sirala[j]/m)%10==i)
					{
						sayi[t]=sirala[j];
						t++;
					}	
				}
			}
			if(sayac==n)
			{
				yaz(f);
				return ;
			}
		}
		t=1;
		
	}
}
int main ()
{
   int i,j,f,t=1,m=1,sayac=0;
   scanf("%d",&n);	
   for(i=1;i<=n;i++)
   {
      scanf("%d",&dizi[i]);
      sayi[i]=dizi[i];
   }
	sirala2();
	printf("\n");
}
