#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int cnt;

typedef struct list
{
	int data;
	struct list *next;
}list;

list *create(int n)
{
	list *head=NULL,*temp=NULL;
	list *newn=NULL;
	int icnt=0;
	for(int i=0;i<n;i++)
	{
		newn=(list *)malloc(sizeof(list));

		printf("Enter data:");
		scanf("%d",&newn->data);
		newn->next=NULL;
		if(head==NULL)
		{
			head=newn;
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				
			//	temp->next=newn;
				temp=temp->next;
			}
			temp->next=newn;
		}
		cnt++;
	}
	return head;
}
void Disp(list *head)
{

	while(head!=NULL)
	{
		
		printf("%d\t",head->data);
		head=head->next;
	}
}
/*

void *del(list **head)
{
	list *temp;
	temp=*head;
	while(*head!=NULL)
	{
		*head=(*head)->next;
		free(temp);
		temp=*head;
	}
}
*/
void Rev(list *head)
{
	list *current,*rnext,*prev,*temp;
	current=head;
	prev=NULL;
	rnext=NULL;

	while(current!=NULL)
	{
		rnext=current->next;
		current->next=prev;
		prev=current;
		current=rnext;
	}
		head=prev;
	temp=head;
    	while(temp->next!=NULL)
	{
		printf("%d \t",temp->data);
		temp=temp->next;
	} 
}
void Disp_N(list *head,int n)
{
	int i=0;
	list *temp;
	temp=head;
	for(i=0;i<cnt-n;i++)
	{
		temp=temp->next;
	}
	printf("\nNode data-> %d",temp->data);
}
void Alt_swap(list *head)
{
	int t=0;
	list *temp=head;
	while(temp!=NULL && temp->next!=NULL)
	{
	 t=temp->data;
         temp->data=temp->next->data;
         temp->next->data=t;

	 temp=temp->next->next;
	}

	printf("\nAlternate Data is:");
	temp=head;
	while(head!=NULL)
	{
		printf("%d\t",head->data);
		head=head->next;
	}
}
void *insert_at(list **head,int pos,int num)
{
	list *temp,*newn=NULL;
	temp=*head;
	int i=0;
	newn=(list *)malloc(sizeof(list));
	newn->data=num;
	newn->next=NULL;
//	int cnt=len(*head);
	if(pos==1)
	{
		newn->next=*head;
		*head=newn;
	}
	else if(pos==cnt)
	{
		temp=*head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
		newn->next=NULL;
	}
	else
	{
	for(i=0;i<pos-1;i++)
	{
		temp=temp->next;
	}
//	newn=(list *)malloc(sizeof(list));
	newn->next=temp->next;
	temp->next=newn;
	}
}
int main()
{
	list *head=NULL;
	list *ret=NULL;

	int n,pos,data,cnt=0;
	int node=0;
	printf("Enter Value of N:");
	scanf("%d",&n);
	ret=create(n);
	Disp(ret);
	// Disp N
	printf("\nEnter The Node No.");
	
	scanf("%d",&node);
	Disp_N(ret,node);

	printf("\nEnter data to insert:");
	scanf("%d",&data);
	printf("\nEnter Position:");
	scanf("%d",&pos);
	insert_at(&ret,pos,data);
	Disp(ret);
//	del(&ret);
//	Disp(ret);
	Alt_swap(ret);
	printf("\nReversed List is:");
	Rev(ret);
	Disp(ret);
//	Alt_swap(ret);
	return 0;
}
