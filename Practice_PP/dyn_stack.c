#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


struct stack
{
	int data;
	struct stack *next;
}stack;

struct stack *createStack(void)
{

}


void push(struct stack **top,int data)
{
	int no,i=0;
	stack *top=NULL;
	stack *newn=NULL;
//	node *temp=NULL;
		newn=(stack *)malloc(sizeof(stack));
		printf("Enter data:");
		scanf("%d",&no);
	
		if(head==NULL)
		{
			newn->data=no;
			newn->next=NULL;
			top=newn;
		}
		else
		{
			newn->data=no;
			newn->next=top;
			top=newn;
		}
	return top;
}

stack *pop(stack *top)
{
	int no=-1;
	stack *temp=top;
	if(head==NULL)
	{
		printf("Stack is Empty:");
		return;
	}
	else if(top!=NULL)
	{
		no=top->data;
		temp=top;
		head=top->next;
		free(temp);
		printf("\nItem Popped: %d",no);
	}
	return top;
}

void disp(stack *top)
{
	stack *temp=top;
	while(temp!=NULL)
	{
		printf(" %d\t",temp->data);
		temp=temp->next;
	}
}
void isEmpty(stack *top)
{
	if(top==NULL)
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
	stack *top=NULL;
	stack *iRet=NULL;
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
				push();
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
