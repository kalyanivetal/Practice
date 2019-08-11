#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
struct list
{
	int data;
	struct list *next;
}list;

struct queue
{
	struct list *front;
	struct list *rear;
}queue;

struct queue *create(){

	struct queue *queue=(struct queue*)malloc(sizeof(struct queue));
	struct list *list=(struct list*)malloc(sizeof(struct list));
	queue->front=queue->rear=NULL;
	return queue;

}

void enQueue(struct queue **head,int num){
	struct list *newn;
	newn=(struct list *)malloc(sizeof(struct list));
	newn->data=num;
	newn->next=NULL;
	if((*head)->rear==NULL)
	{
		 (*head)->front=(*head)->rear=newn;

/*		(*head)->rear->next=newn;
		(*head)->rear=newn; */
	}
	else
	{
		(*head)->rear->next=newn;
		(*head)->rear=newn;
	}
	
}
int deQueue(struct queue **head){
	int n;
	struct list *temp;
	if((*head)->front==NULL)
	{
	//	printf("\n Nothing in Queue");
		return 0;
	}
	else
	{
		temp=(*head)->front;
		n=(*head)->front->data;
		(*head)->front=(*head)->front->next;
		free(temp);
	}
	return n;
}

void delQ(struct queue **head){
	struct list *temp=NULL;
	int n=0;
	if((*head)->front==NULL)
	{
		printf("Queue is ALREADY empty.....");
	}
	else
	{
		temp=(*head)->front;
		while((*head)->front!=NULL)
		{
			(*head)->front=(*head)->front->next;
			free(temp);
			(*head)->front=temp;
		}	
	}
}
int isEmptyQ(struct queue *head)
{
	if(head->front==NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
int main()
{
	struct queue *head=create();
//	struct queue *Ret=NULL;
	int n=0,ch=0,ret=0,num=0;
	
	while(1)
	{

		printf("\n________________\n");
		printf("\n 1: ENQUEUE");
		printf("\n 2: DEQUEUE");
		printf("\n 3: isEmpty ");
		printf("\n 4: Delete");
		printf("\n 5: Exit ");
		printf("\n ________________\n");

		printf("\nEnter Your Choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("Enter Data:");
				scanf("%d",&num);
				enQueue(&head,num);
				break;
			case 2:
				ret=deQueue(&head);
				if(ret==0)
				{
					printf("Empty Queue..\n");
				}
				else
				{
					printf("Deleted Element is: %d",ret);
				}
					break;
			case 3:
				ret=isEmptyQ(head);
				if(ret==0)
				{
					printf("Queue is NOT Empty");

				}
				else
				{
					printf("Queue is Empty");
				}
				break;
			
			case 4:
				delQ(&head);
				break;
			case 5:
				printf("Exiting...!!");
				exit(0);
			default:
				printf("\nPlease Enter Valid choice:\n");

		}
	}
}

