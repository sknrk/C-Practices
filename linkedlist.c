#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
	int data;
	struct node *next,*prev ;
}node;
node *head,*tail,*current,*previous ;
void sil(int aranan)
{
	for(current=head;current->next!=NULL && current->next->data!=aranan;current=current->next);
	previous=current;
	current=current->next;
	previous->next=current->next ;
	free(current);
}
void listele()
{
	for(current=head;current!=NULL;current=current->next)
	{
		printf("%d ",current->data);
	}
}
void ekle(int m)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=m;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		return;
	}
	if(temp->data < head->data)
	{
		temp->next=head;
		head=temp ;
		return ;
	}		
	for(current=head;current->next!=NULL && temp->data>current->next->data;current=current->next);
	if(current->next==NULL)
	{
		current->next=temp ;
		return ;
	}
	temp->next=current->next ;
	current->next=temp  ;	
}
int main ()
{
	int i,j,m,n,z,aranan;
	for(;1;)	
	{
		printf("\n1-Ekle\n2-Listele\n3-Sil\n4-Kapat\n");
		scanf("%d",&z);
		if(z==1)
		{
			scanf("%d",&n);
			for(i=1;i<=n;i++)
			{
				scanf("%d",&m);
				ekle(m);
			}
		}
		if(z==2)
		{
			listele();
			printf("\n");
		}
		if(z==3)
		{
			scanf("%d",&aranan);
			sil(aranan);
		}
		if(z==4)
		{
			break ;
		}
	}
	return 0;
}
