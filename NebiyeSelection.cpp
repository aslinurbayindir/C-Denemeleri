#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
void selection_sort(int array[], int n)
{
  int c, d, t, position;
 
  for ( c = 0 ; c < ( n - 1 ) ; c++ )
   {
      position = c;
 
      for ( d = c + 1 ; d < n ; d++ )
      {
         if ( array[position] > array[d] )
            position = d;
      }
      if ( position != c )
      {
         t = array[c];
         array[c] = array[position];
         array[position] = t;
      }
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
	selection_sort(A,i);
	time(&end); 
	 	
  printf("\n\t------- Sorted elements -------\n\n");  
  for(i=0; i<size; i++)
  	printf("%d .inci Sayi= %d \n",i,A[i]);
 
 printf(" Aradaki zaman farki: %.2lf ",difftime(end,start));
 getch();
 return 0;
}
