#include<stdio.h>
int son,dizi[10000][10000],dizi2[1000000][3],fx,fy,px,py,n,m;
void fare(int fx,int fy)
{
	while(son>0)
	{
		fx=dizi2[son][1];
		fy=dizi2[son][2];
		son--;
      if(fy+1!=m+1 &&(dizi[fx][fy]+1<dizi[fx][fy+1] || dizi[fx][fy+1]==0))
		{
         son++;
			dizi2[son][1]=fx;
         dizi2[son][2]=fy+1;
			dizi[fx][fy+1]=dizi[fx][fy]+1;
      }
		if(fx+1!=n+1 && (dizi[fx][fy]+1<dizi[fx+1][fy] || dizi[fx+1][fy]==0))
		{
			son++;
			dizi2[son][1]=fx+1;
			dizi2[son][2]=fy;
			dizi[fx+1][fy]=dizi[fx][fy]+1;
		}
		if(fy-1!=0 &&(dizi[fx][fy]+1<dizi[fx][fy-1] || dizi[fx][fy-1]==0))
      {
         son++;
         dizi2[son][1]=fx;
         dizi2[son][2]=fy-1;
			dizi[fx][fy-1]=dizi[fx][fy]+1;
      }
		if(fx-1!=0 &&(dizi[fx][fy]+1<dizi[fx-1][fy] || dizi[fx-1][fy]==0))
      {
         son++;
         dizi2[son][1]=fx-1;
         dizi2[son][2]=fy;
			dizi[fx-1][fy]=dizi[fx][fy]+1;
      }
	}
}
int main ()
	{
	int i,j;
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
	 // farenin koordinatlari
   scanf(" %d %d",&fx,&fy);
	dizi[fx][fy]=1;
   dizi2[1][1]=fx;
	dizi2[1][2]=fy;
	// peynir koordinatlari
   scanf(" %d %d",&px,&py);
	son=1;
	//
	fare(fx,fy);
	// peynirin bulundugu yerin numarasini yazdiriyor. bu peynirin kac adimda bulunacagini gosteriyor
	printf("%d",dizi[px][py]);
}
