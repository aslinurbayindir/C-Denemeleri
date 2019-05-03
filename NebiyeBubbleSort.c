#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
void bubble_sort(int dizi[], int n)
{
    int i,j,gecici;
    for(i=n-1;i>0;i--)
        for(j=0; j<i;j++)
        if(dizi[j]>dizi[j+1])
        {
            gecici=dizi[j];
            dizi[j]=dizi[j+1];
            dizi[j+1]=gecici;
        }
}
int main()
{
 int A[500000];
 int i,size; 
 time_t start,end;
 srand(time(NULL));
 
 printf("\n\t------- Bubble Sort Method -------\n\n");
 printf("Enter total no. of elements : ");
 scanf("%d",&size);
 for(i=0; i<size; i++)
 {
   A[i]=rand()%100;
   printf("%d Sayi= %d \n",i,A[i]);
 }
  	time(&start);
	bubble_sort(A,i);
	time(&end); 
	 	
  printf("\n\t------- Sorted elements -------\n\n");  
  for(i=0; i<size; i++)
  	printf("%d .inci Sayi= %d \n",i,A[i]);
 
 printf(" Aradaki zaman farki: %.2lf ",difftime(end,start));
 getch();
 return 0;
}


