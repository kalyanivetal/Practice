#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
 
#define TRUE 1
#define FALSE 0
struct stack{
	int data;
	struct stack *next;
}stack;

struct stack *create(void){
	struct stack *stack=(struct stack*)malloc(sizeof(struct stack));
//	stack->data=NULL;
//	stack->next=NULL;

}

void push(struct stack **top,int no){
	struct stack *temp;
	temp=malloc(sizeof(struct stack));
	temp->data=no;
	temp->next=*top;
	*top=temp;
}

int pop(struct stack **top){
	if((*top)==NULL)
		return 0;

	int no;
	struct stack *temp;
	temp=*top;
	(*top)=(*top)->next;
	no=temp->data;
	free(temp);
	return no;
}

int isEmptyStack(struct stack **top){
	if(*top==NULL)
		return TRUE;
	else
		return FALSE;
}

int top_el(struct stack *top){
	int no;
	if(top==NULL)
		return 0;
	else
		no=top->data;
	return no;
}

void deleteStack(struct stack **top){
	struct stack *temp;
	temp=*top;
	while(*top!=NULL){
		(*top)=(*top)->next;
		free(temp);
		temp=*top;
	}
}
int main(void){
	struct stack *S1=NULL;
       //  stack *iRet=NULL;
	int Ret=0,ch,n,num;
	while(1){
		printf("\n_____________________\n");
		printf("\nSelect One:");
		printf("\n1: Push");
		printf("\n2: POP");
		printf("\n3: Top");
		printf("\n4: isEmpty");
		printf("\n5: Delete Stack");
		printf("\n6: Exit");
		printf("\n______________________\n");
		printf("\nEnter Your Choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter data:");
				scanf("%d",&num);
				push(&S1,num);
				break;                                                                                               
			case 2:
				Ret=pop(&S1);
				if(Ret==0)
					printf("Stack is Empty... Cant POP more....!!");
				else
					printf("Popped Element : %d",Ret);
				break;
/*			case 3:
                       	printf("Stack:");
                        disp(&top);
                        break;
   */              
   			case 3:
				Ret=top_el(S1);
				if(Ret==0)
					printf("Stack is Empty..! No Elements in The Stack...!");
				else
					printf("Top Element : %d",Ret);
				break;
			case 4:
				Ret=isEmptyStack(&S1);
				if(Ret==0)
					printf("Stack is NOT Empty");
				else
					printf("stack is Empty");
				break;
			case 5:
				deleteStack(&S1);
				printf("Stack Deleted SuccessFully..!");
				break;
			case 6:
				exit(0);
			default:
				printf("\nPlease Enter Valid choice");
		}
	}
}

