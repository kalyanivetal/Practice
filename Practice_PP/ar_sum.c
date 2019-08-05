#include<stdio.h>
#include<malloc.h>

void SumArray(int[],int ,int);
void SumArray(int arr[],int size,int S)
{
	int sum=0;
	sum=arr[0];
	int j=0,i=0;
    for(i=1;i<=size;i++)
    {
	if(i<size)
	{
		sum=sum+arr[i];
	}
        while(sum>S && j<i-1)
        {
            sum=sum-arr[j];
            j++;
        }
	if(sum==S)
        {
            printf ("%d %d",j,i);
	    break;
        }
	  //if(i<size)
          // sum=sum+arr[i];
 }
}

int main()
{
	int iRet=0,i=0,iLength1=0,sum=0;
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
printf("Enter Sum:");
scanf("%d",&sum);
	
SumArray(p1,iLength1,sum);
return 0;
}
