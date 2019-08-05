#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int MissingArray(int[],int);
int MissingArray(int arr[],int size)
{
	int i=0;

	for(i=1;i<size;i++)
	{
		if(arr[i]+1==arr[i+1]-1)
		{
			break;
		}
	}
	return arr[i]+1;
}
int main()
{
	int iRet=0,i=0,iLength1=0;
 	int *p1=NULL;
printf("Enter No. of Elements in ARRAY: \n");
scanf("%d",&iLength1);

p1=(int *)malloc(iLength1*sizeof(int));
if(p1==NULL)
{
    return -1;    
}

printf("Enter Elements of ARRAY: \n");
for(i=0;i<iLength1;i++)
{
    scanf("%d",&p1[i]);
}
	
iRet=MissingArray(p1,iLength1);
printf("Missing No From Array is: %d",iRet);
    return 0;
}
