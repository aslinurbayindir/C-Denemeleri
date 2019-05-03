#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

void hsirala(int dizi[], int sol, int sağ)
{
	register int k,j;
	int ortadaki, gecici;
	k=sol;
	j=sag;
	ortadaki=dizi[(sol+sag)/2];
	do
	{
		while (dizi[k]<ortadaki && k<sag) k++;
		while (ortadaki<dizi[j] && j>sol) j--;
		if(k<=j)
		{
			gecici=dizi[k];
			dizi[k]=dizi[j];
			dizi[j]=gecici;
			k++; j--;
		}
	}
	while(k<=j);
	if(sol<j) hsirala(dizi,sol,j);
	if(k<sag) hsirala(dizi, k ,sag);
}

int main()
{
 int A[500000];
 int i,size; 
 time_t start,end;
 srand(time(NULL));
 
 printf("\n\t------- Insortion Sort Method -------\n\n");
 printf("Enter total no. of elements : ");
 scanf("%d",&size);
 for(i=0; i<size; i++)
 {
   A[i]=rand()%100;
   printf("%d Sayi= %d \n",i,A[i]);
 }
  	time(&start);
	hsirala(A,0,i-1);
	time(&end); 
	 	
  printf("\n\t------- Sorted elements -------\n\n");  
  for(i=0; i<size; i++)
  	printf("%d .inci Sayi= %d \n",i,A[i]);
 
 printf(" Aradaki zaman farki: %.2lf ",difftime(end,start));
 getch();
 return 0;
}

