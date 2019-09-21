#include<stdio.h>
int ulke[1000][1000],sehir,yol;
void floyd()
{
	int k,i,j,f;
	for(k=1;k<=sehir;k++)
	{
		for(i=1;i<=sehir;i++)
		{
			if(k==i)
			{
				continue ;
			}
			for(j=1;j<=sehir;j++)
			{
				if(k==j || i==j)
				{
					continue ;
				}
				if((ulke[i][j]>ulke[i][k]+ulke[k][j] && ulke[k][j]!=0 && ulke[i][k]!=0) || ulke[i][j]==0)
				{
					ulke[i][j]=ulke[i][k]+ulke[k][j];
					ulke[j][i]=ulke[i][j];
				}
			}
		}
	}
}
int main ()
{
	int g1,g2,i,j,maliyet;
	// graphtaki sehir ve yol sayisi
	scanf("%d %d",&sehir,&yol);
	// graphda yollarin maliyeti
	for(i=1;i<=yol;i++)
	{
		scanf("%d %d %d",&g1,&g2,&maliyet);
		ulke[g1][g2]=maliyet;
		ulke[g2][g1]=maliyet;
	}
	// floyd warshall algoritmasi
	floyd();
	// sonucu yazdiran dongu
	for(i=1;i<=sehir;i++)
	{
		for(j=i;j<=sehir;j++)
		{
			if(ulke[i][j]!=0)
			{
				printf("%d %d %d\n",i,j,ulke[i][j]);
			}
		}
	}
}
