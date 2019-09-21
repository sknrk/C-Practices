#include<stdio.h>
int m,n,fx,fy,px,py,enkucuk=10000;
int dizi[100][100];
void fare(int x,int y,int sayac)
{
	dizi[x][y]=-1;
	// peynirin yeriyle fareyi kontrol etmek icin if
	if(px==x && py==y)
	{
		if(sayac<enkucuk)
		{
			enkucuk=sayac;
		}
		return;
	}
	// farenin gidebilecegi yerler
	if(x-1!=0 &&  dizi[x-1][y]==0)
	{
		fare(x-1,y,sayac+1);
	}
	if(y+1!=m+1 && dizi[x][y+1]==0)
	{
		fare(x,y+1,sayac+1);
	}
	if(x+1!=n+1 && dizi[x+1][y]==0)
	{
		fare(x+1,y,sayac+1);
	}
   if(y-1!=0 && dizi[x][y-1]==0)
	{
		fare(x,y-1,sayac+1);
	}
	// geri gelmemek icin isaretlemek
	dizi[x][y]=0;
}
int main()
{
	FILE *oku ;
	int i,j;
		//labirent boyutu belirlenmesi
	scanf("%d %d",&n,&m);
		// farenin labirentinin tanimlanmasi
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf(" %d",&dizi[i][j]);
			dizi[i][j]*=-1;
		}
	}
		// yemin ve farenin yerinin belirlenmesi
	scanf(" %d %d",&fx,&fy);
	dizi[fx][fy]='1';
	scanf(" %d %d",&px,&py);

	printf("\n\n");
	// fareyi goturecek fonksiyon
	fare(fx,fy,0);
	// labirenti yazdirmak
	for(i=1;i<=n;i++)
   {
   	for(j=1;j<=m;j++)
      {
			if(dizi[i][j]==0)
			printf("0 ");
			else
      	printf("%d ",dizi[i][j]);
      }
		printf("\n");
   }
	printf("%d\n",enkucuk);
	return;
}
