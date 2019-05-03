#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
 

void mergesort(int a[],int i,int j)
{
    int mid;
        
    if(i<j)
    {
        mid=(i+j)/2;
        mergesort(a,i,mid);        //left recursion
        mergesort(a,mid+1,j);    //right recursion
        merge(a,i,mid,mid+1,j);    //merging of two sorted sub-arrays
    }
}
 
void merge(int a[],int i1,int j1,int i2,int j2)
{
    int temp[250000];    //array used for merging
    int i,j,k;
    i=i1;    //beginning of the first list
    j=i2;    //beginning of the second list
    k=0;
    
    while(i<=j1 && j<=j2)    //while elements in both lists
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    
    while(i<=j1)    //copy remaining elements of the first list
        temp[k++]=a[i++];
        
    while(j<=j2)    //copy remaining elements of the second list
        temp[k++]=a[j++];
        
    //Transfer elements from temp[] back to a[]
    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];
}
 
int main()
{
	time_t start,end;
	srand(time(NULL));
	
    int a[250000],n,i;
    printf("\n\t------- Merge Sort Method -------\n\n");
	printf("Enter no of elements:");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        a[i]=rand()%100;
		printf("%d inci Sayi= %d \n",i,a[i]);
	}
	
    time(&start);
	mergesort(a,0,n-1);
	time(&end);
	printf("\n\t------- Sorted elements -------\n\n");

    for(i=0;i<n;i++)
    	printf("%d .inci Sayi= %d \n",i,a[i]);

    printf(" Aradaki zaman farki: %.2lf ",difftime(end,start));    
    getch();
	return 0;
}
 

