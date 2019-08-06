#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
 void  arr_bday(int [],int);
 void arr_bday(int q[],int q_count)
{
int i=0,j=0,temp=0;
int cnt=0;

for(i=0;i<q_count;i++)
    {
        if((q[i]-(i+1))>=3)
        {
            printf("Too chaotic\n");
		return;	
        }
    /*    else if((q[i]-(i))>3)
        {
         printf("Too chaotic");
            break;   
        } */
    }
    for(i=0;i<q_count;i++)
    {
        for(j=i+1;j<q_count;j++)
        {
            if(q[i]>q[j])
            {
                temp=q[j];
                q[j]=q[i];
                q[i]=temp;
                cnt++;
            }
        }
    }
printf("%d\n",cnt);
}
int main()
{
	int iRet=0,i=0,iLength1=0,n=0,j=0;
 	int *p1=NULL;
	printf("Enter N:");
	scanf("%d",&n);
	for(j=0;j<n;j++)
	{
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
	arr_bday(p1,iLength1);
	}
	return 0;

}
