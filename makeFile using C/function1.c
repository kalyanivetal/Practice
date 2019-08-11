#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#include "function1.h"



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
	//	cnt++;
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
	list *temp1=head,*temp2=head->prev;
	int temp=0;
	while(temp1!=temp2)
	{
	 temp=temp1->data;
         temp1->data=temp2->prev->data;
         temp2->data=temp;
	

	// printf("\ntemp1->data=%d and temp2->data=%d",temp1->data,temp2->data);
//	printf("temp2->data=%d",temp2->data);
//	printf("temp2->prev->data=%d",temp2->prev->data);
	temp1=temp1->next;
	temp2=temp2->prev;
	}
	printf("\n");
	 do
         {
                 printf("\n %d\t",temp2->data);
                 temp2=temp2->next;
         }while(temp2!=head);

}
