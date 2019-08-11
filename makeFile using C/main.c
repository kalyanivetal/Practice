#include<stdio.h>
#include "function1.h"


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
