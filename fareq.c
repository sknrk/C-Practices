#include<stdio.h>
int bas,son,dizi[10000][10000],q[3][1000000];
int px,py,n,m,fx,fy;
void fare(int x,int y)
{
	while(bas<=son)
   {
      fx=q[1][bas];
      fy=q[2][bas];
		bas++;
      if(fy+1!=m+1 &&(dizi[fx][fy]+1<dizi[fx][fy+1] || dizi[fx][fy+1]==0))
      {
         son++;
         q[1][son]=fx;
         q[2][son]=fy+1;
         dizi[fx][fy+1]=dizi[fx][fy]+1;
      }
      if(fx+1!=n+1 && (dizi[fx][fy]+1<dizi[fx+1][fy] || dizi[fx+1][fy]==0))
      {
         son++;
         q[1][son]=fx+1;
         q[2][son]=fy;
         dizi[fx+1][fy]=dizi[fx][fy]+1;
      }
      if(fy-1!=0 &&(dizi[fx][fy]+1<dizi[fx][fy-1] || dizi[fx][fy-1]==0))
      {
         son++;
        	q[1][son]=fx;
         q[2][son]=fy-1;
         dizi[fx][fy-1]=dizi[fx][fy]+1;
      }
      if(fx-1!=0 &&(dizi[fx][fy]+1<dizi[fx-1][fy] || dizi[fx-1][fy]==0))
      {
         son++;
         q[1][son]=fx-1;
         q[2][son]=fy;
         dizi[fx-1][fy]=dizi[fx][fy]+1;
      }
	}
}
int main ()
{
	int i,j;
	FILE *oku;
	// varsa labirent icin txt
	oku=fopen("labirent.out","r");
	// labirent buyuklugu
	scanf("%d %d",&n,&m);
	// labirent tanimlama
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=m;j++)
      {
         scanf(" %d",&dizi[i][j]);
         dizi[i][j]*=-1;
      }
   }
	 // fare kordinati
   scanf("%d %d",&fx,&fy);
   dizi[fx][fy]=1;
   q[1][1]=fx;
   q[2][1]=fy;
	bas=1;
	son=1;
	// peynir kordinati
   scanf(" %d %d",&px,&py);
	 // peynirin yerini fareyle bulan fonksiyon
	fare(fx,fy);
	// labirentin yeniden yazdirildigi kisim
	for(i=1;i<=n;i++)
   {
      for(j=1;j<=m;j++)
      {
        printf(" %d\t",dizi[i][j]);
      }
      printf("\n");
   }
	//printf("%d",dizi[px][py]);
}
