#include <stdio.h>
#include <limits.h>
int dizi[1000][1000] ;
int film[1000][1000] ;
int dizi2[1000] ;
int bx,by,sehir,yol ;
void upheap(int i)
{
	int tut,tut2 ;
	if(i/2==0)
		return ;
	if(dizi[i][1]<dizi[i/2][1])
	{
		tut=dizi[i][0] ;
		tut2=dizi[i][1] ;
		dizi[i][0]=dizi[i/2][0] ;
		dizi[i][1]=dizi[i/2][1] ;
		dizi[i/2][0]=tut ;
		dizi[i/2][1]=tut2 ;
		upheap(i/2);
	}
}
void downheap(int i)
{
	if(!dizi[i*2][1] && !dizi[i*2+1][1])
		return ;
	int tut,tut2;
	if( dizi[i*2][1]<=dizi[i*2+1][1] && dizi[i*2+1][1])
	{
		if(dizi[i*2][1]<dizi[i][1])
		{
			tut=dizi[i][0] ;
			tut2=dizi[i][1] ;
			dizi[i][0]=dizi[i*2][0] ;
			dizi[i][1]=dizi[i*2][1] ;
			dizi[i*2][0]=tut ;
			dizi[i*2][1]=tut2 ;
			downheap(i*2) ;
		}
	}
   else if(dizi[i*2+1][1]<=dizi[i*2][1] && dizi[i*2+1][1])
	{
		if(dizi[i*2+1][1]<dizi[i][1])
		{
			tut=dizi[i][0] ;
			tut2=dizi[i][1] ;
			dizi[i][0]=dizi[i*2+1][0] ;
			dizi[i][1]=dizi[i*2+1][1] ;
			dizi[i*2+1][0]=tut ;
			dizi[i*2+1][1]=tut2 ;
			downheap(i*2+1);
		}
	}

}
void enkisa()
{
	int temp,deger,son=1 ;
	while(temp!=by)
	{	
		int i,j ;
		deger=dizi[1][1] ;
		temp=dizi[1][0] ;
		if(deger<dizi2[temp] || dizi2[temp]==0)
			dizi2[temp]=deger ;
		if(temp==by)
			break ;
		dizi[1][1]=dizi[son][1] ;
		dizi[1][0]=dizi[son][0] ;
		dizi[son][1]=0 ;
		dizi[son][0]=0 ;
		son-- ;
		downheap(1) ;

		for(i=1;i<=yol;i++)
		{
			if(film[temp][i]!=0 && (dizi2[i]==0 || film[temp][i]+deger<dizi2[i]))
			{
				son++ ;
				dizi[son][1]=deger+film[temp][i];
				dizi[son][0]=i;
				upheap(son);
			}
		}
	}
	printf("\n%d\n",dizi2[by]);
}
int main()
{
	int i,m,n,k,l,x,y,z ;
	scanf("%d %d",&sehir,&yol);
	for(i=1;i<=yol;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		film[x][y]=z ;
		film[y][x]=z ;
	}
	scanf("%d %d",&bx,&by);
	dizi[1][0]=bx ;
	dizi[1][1]=film[bx][bx] ;
	dizi2[bx]=-1 ;
	enkisa();
	printf("\n");
}
