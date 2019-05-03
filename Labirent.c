#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<ctype.h>
#include<conio.h>
#include<time.h>

void kisayol(int, int);
	int labirent[500][500];
	int yol[500][500];
	int i,j,sizeM,sizeN,engel,hesaplama;
	char stack[500][500];
	char kr;
		
int main()
{
	system("title Aslınur BAYINDIR Labirent");
	printf("\n\t------------------- Labirent Programi -------------------\n\n");
 	printf("--Matrisin Kaca Kac olmali SATIR x SUTUN  : ");
	scanf("%d",&sizeM);
	scanf("%d",&sizeN);
	printf("\n \n");
	
	hesaplama=((sizeN*sizeM)*30)/100;
	
	printf("-- Engel sayisini girin (%d 'den az olursa cikis olabilir) : ",hesaplama+1);
	scanf("%d",&engel);
	
 	for(i=0; i<sizeM; i++)
 	{
 		for(j=0; j<sizeN; j++)
 		{
			labirent[i][j]=1;
   			yol[i][j]=0;
   			stack [i][j]='X';
  		}  	
	}
	
	
	for (i=0; i<engel; i++)
  	{
  		// labirent[i][j]=rand()%2;
  		labirent [rand()%sizeM][rand()%sizeN]=0;  		
	}
	//labirent[M][N] M= Satır N=Sütun
		
	labirent[0][0]=1;
	labirent[sizeM-1][sizeN-1]=1;
	
	
	for(i=0; i<sizeM; i++)
 	{
 		for(j=0; j<sizeN; j++)
 		{
  			printf("%d\t",labirent[i][j]);
  		}
  		printf("\n");
	}
	
	kisayol(0,0);
	
	printf("\n\t------------------- Izlenilen Yolun Grafik Hali -------------------\n\n");
	
	for(i=0; i<sizeM; i++)
 	{
 		for(j=0; j<sizeN; j++)
 		{
  			if (stack[i][j]!='*')
  			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |BACKGROUND_RED | BACKGROUND_GREEN |BACKGROUND_BLUE |FOREGROUND_RED);
				printf("%c\t",stack[i][j]);
				//sleep(1);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |BACKGROUND_GREEN | FOREGROUND_BLUE);
				printf("%c\t",stack[i][j]);
				//sleep(1);
			}
  			
  		}
  		printf("\n");
	}
	
	kr=getchar();
	
	return 0;
	
}

void kisayol(int x, int y)
{
	yol[x][y]=1;
	
	printf("koordinatlar %d %d \n",x,y);
	stack[x][y]='*';
/*	
	// sola hareket
	if(x>0 && labirent[x-1][y]==1 && yol[x-1][y]==0) //yol[y][x-1]==0 anlamı daha önce gitmediği yol ise gitsin.
		kisayol(x-1,y);
	
	
	// yukarı hareket
	if(y>0 && labirent[x][y-1]==1 && yol[x][y-1]==0)
		kisayol(x,y-1);
*/

	//sağa hareket
	if(x<=sizeM && labirent[x+1][y]==1 && yol[x+1][y]==0)
		kisayol(x+1,y);
	// aşağıya hareket
	else if(y<=sizeN && labirent[x][y+1]==1 && yol[x+1][y]==0)
		kisayol(x,y+1);
		
	
}
