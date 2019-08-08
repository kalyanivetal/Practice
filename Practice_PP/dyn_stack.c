#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


typedef struct node
{
	int data;
	struct node *next;
}node;

node *push(int n)
{
	int no,i=0;
	node *head=NULL;
	node *newn=NULL;
//	node *temp=NULL;
	for(i=0;i<n;i++)
	{
		newn=(node *)malloc(sizeof(node));
		printf("Enter data:");
		scanf("%d",&no);
	
		if(head==NULL)
		{
			newn->data=no;
			newn->next=NULL;
			head=newn;
		}
		else
		{
			newn->data=no;
			newn->next=head;
			head=newn;
		}
	
	}
	return head;
}

node *pop(node *head)
{
	int no=-1;
	node *temp=head;
	if(head==NULL)
	{
		printf("Stack is Empty:");
		return;
	}
	else if(head!=NULL)
	{
		no=head->data;
		temp=head;
		head=head->next;
		free(temp);
		printf("\nItem Popped: %d",no);
	}
	return head;
}

void disp(node *head)
{
	node *temp=head;
	while(temp!=NULL)
	{
		printf(" %d\t",temp->data);
		temp=temp->next;
	}
}
void isEmpty(node *head)
{
	if(head==NULL)
	{
		printf("Stack is Empty");
	}
	else
	{
		printf("Stack is Not Empty");
	}
}
int main()

{
	node *head=NULL;
	node *iRet=NULL;
	int Ret=0,ch,n;
	
	while(1)
	{
	printf("\nSelect One:");
	printf("\n1: Push");
	printf("\n2: POP");
	printf("\n3: Display");
	printf("\n4: Exit");
	printf("\n5: isEmpty");
	printf("\nEnter Your Choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		
				printf("\nEnter How many elements in the Stack:");
				scanf("%d",&n);
				iRet=push(n);
				break;
		
		case 2:
		
				iRet=pop(iRet);
	//			printf("Popped Element : %d",Ret);
				break;
		
		case 3:
				printf("Stack:");	
				disp(iRet);
				break;	
		case 4:
			
				exit(0);
				break;
		case 5:
				isEmpty(iRet);
				break;
		default:
			
				printf("\nPlease Enter Valid choice");
	}		
    }
}
