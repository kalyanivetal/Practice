#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct list
{
int data;
struct list *next,*prev;
}list;
int cnt=0;

list *createdcl(int n)
{
	list *head=NULL,*temp=NULL,*newn=NULL;
	int i=0;	
		for(i=0;i<n;i++)
	{
		newn=(list *)malloc(sizeof(list));
		printf("Enter data:");
		scanf("%d",&newn->data);
		
		newn->next=NULL;
		newn->prev=NULL;
		if(head==NULL)
		{
			head=newn;
			newn->next=head;
			newn->prev=head;
		}
		else
		{
			temp=head;
			while(temp->next!=head)	
			{
				temp=temp->next;
			}
			temp->next=newn;
			newn->prev=temp;
			head->prev=newn;
			newn->next=head;
		}
		cnt++;
	}
	return head;
}

void disp(list *head)
{
	list *temp=head;
	do
	{
		printf("%d\t",temp->data);
                temp=temp->next;
	}while(temp!=head);
}
/*
void swapdcl(list **head)
{
	int m=0,temp=0;
	list *temp1=*head,*temp2=(*head)->prev;
	while(m!=cnt/2)
	{
	temp=temp1->data;
	temp1->data=temp2->data;
	temp2->data=temp;

//	printf("%d\t",temp);

	temp1=temp1->next;
	temp2=temp2->prev;
//	head=temp2;
	}
	printf("\n");
	m++;
	temp2=*head;
	 do
        {
                printf("%d\t",temp2->data);
                temp2=temp2->next;
        }while(temp2!=*head);


}*/
void swapls(list *head){
	list *temp1,*temp2;//->prev;
	temp1=temp2=head;
	temp2=temp2->prev;
	int temp=0;
	while(temp1->prev!=temp2->next && temp1!=temp2)
	{
		temp=0;
	// temp2=temp2->prev;
	 temp=temp1->data;
         temp1->data=temp2->data;
         temp2->data=temp;
	 printf("\n temp1->data==%d temp2->data==%d",temp1->data,temp2->prev->data);
	temp1=temp1->next;
	temp2=temp2->prev;
	if(temp1!=temp2)
	{
		break;
	}
	}
	printf("\n");
	temp2=head;
	 do
         {
                 printf("\n%d\t",temp2->data);
                 temp2=temp2->next;
         }while(temp2!=head);

}
int main()
{
list *head=NULL;
list *ret=NULL;
int n=0,i=0;
 printf("Enter How many nodes:");
 scanf("%d",&n);

 ret=createdcl(n);
 disp(ret);
//swapdcl(&ret);
swapls(ret);
 printf("\n");
// disp(ret);
 return 0;
}
