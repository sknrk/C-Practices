#include<stdio.h>
#include<limits.h>
int dizih[3][1000];
int dizi3[100][100];
int dizi2[10000];
int sayac,s,f,tut,top;
void upheap(int i)
{
	if(i/2==0)
			  return;
	if(dizih[2][i]<dizih[2][i/2])
	{
  		tut=dizih[2][i];
		dizih[2][i]=dizih[2][i/2];
		dizih[2][i/2]=tut;
		tut=dizih[1][i];
		dizih[1][i]=dizih[1][i/2];
		dizih[1][i/2]=tut;
		upheap(i/2);
	}
}
void downheap (int k)
{
	int tut;
	if(dizih[2][2*k]==0 && dizih[2][2*k+1]==0)
			  return;
	if(dizih[2][2*k+1] && (dizih[2][2*k]<=dizih[2][2*k+1]))
	{
			  if(dizih[2][2*k]<dizih[2][k])
			  {
						 tut=dizih[1][k];
						 dizih[1][k]=dizih[1][2*k];
						 dizih[1][2*k]=tut;
						 tut=dizih[2][k];
						 dizih[2][k]=dizih[2][2*k];
						 dizih[2][2*k]=tut;
						 downheap(2*k);
			  }
	}
	else if(dizih[2][2*k+1] && dizih[2][k*2+1]<dizih[2][k*2])
	{
			  if(dizih[2][2*k+1]<dizih[2][k])
			  {
						 tut=dizih[1][k];
						 dizih[1][k]=dizih[1][2*k+1];
						 dizih[1][2*k+1]=tut;
						 tut=dizih[2][k];
						 dizih[2][k]=dizih[2][2*k+1];
						 dizih[2][2*k+1]=tut;
						 downheap(2*k+1);
			  }
	}
}
void enkisa(int sehir,int yol)
{
	int temp,son=1,i,deger;
	while(sayac!=sehir)
	{
		temp=dizih[1][1];
		deger=dizih[2][1];
		dizih[1][1]=dizih[1][son];
		dizih[2][1]=dizih[2][son];
		dizih[1][son]=0;
		dizih[2][son]=0;
		son--;
		downheap(1);
		if(dizi2[temp]!=1)
		{
			top+=deger;
			//printf("%d %d",deger,temp);
			dizi2[temp]=1;
			sayac++;
		}
		else
		{
			continue;
		}
		for(i=1;i<=sehir;i++)
		{
			if(dizi3[temp][i]!=0)
			{
				son++;
				dizih[2][son]=dizi3[temp][i];
				dizih[1][son]=i;
				upheap(son);
			}
		}
	}
}
int main()
{
 int sehir,yol,i,j,a,b,c,fs;
 scanf(" %d %d",&sehir,&yol);
 for(i=0;i<yol;i++)
 {
			scanf(" %d %d %d",&a,&b,&c);
			dizi3[a][b]=c;
			dizi3[b][a]=c;
 }
 scanf("%d",&s);
 dizi2[s]=0;
 dizih[1][1]=s;
 dizih[2][1]=dizi3[s][s]; 
 enkisa(sehir,yol);
 printf("%d\n",top);
}
