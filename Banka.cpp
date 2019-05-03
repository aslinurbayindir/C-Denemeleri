#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<ctype.h>
#include<conio.h>
#include<time.h>
	
int main()
{

	system("title Nebiye Aslınur BAYINDIR Borc Hesaplama");
	printf("\n\t---------------- Nebiye Aslınur BAYINDIR Borc Hesaplama ----------------\n\n");
 	
 	int secim; // int yani integer demek tam sayı değerleri için kullanılır.
	float borc,odeme,toplam_devreden_borc,kalan,gecikme_faizi,vergi;   // float virgüllü sayı değerleri atayabilmek içindir.
	int sayac; 
	char yonlendirme;  //harf ifadeler için kullanılır
	
 	//programbasi:
 	 	
 	sayac=0;	 
	 
	printf(" \n Toplam Borc mitarinizi girin  : "); // printf yazdırma komutudur
	scanf("%f",&borc); // klavyeden giriş amacıyla scanf kullanılır. float sayı girişi
	   
	printf("\n\n---------------- Odeme seklinizi seciniz : ----------------\n\n"); //   \n işlevi enter gibi çalışmak
	printf("* Odeme Sekli 1 (Asgari Odeme - Borcun %%30'unu Odeme) \n"); // % değer yazılırken %% yazılır
	printf("* Odeme Sekli 2 (Borcun %%50'sini Odeme) \n\n");
 	printf("Odeme seklinizi belirleyin (1 veya 2 yazmaniz gerekmekte) : ");
 	scanf("%d",&secim); // tam sayı girişi
 	
 	// Secim yanlışsa seçimi kontrol etmek için döngüye sokuyoruz
 	// döngü başı
 	
	 while(secim!=1 && secim!=2) // != anlamı eşit değilse 1'e veya 2'ye eşit değilse çalıştır && ve anlamına gelir
 	{
 		printf("\n --------------------------------------------------------\n");
 		printf("Yanlis secim yaptiniz (1 veya 2 yazmaniz gerekmekte) \n");
 		printf("Odeme seklinizi belirleyin : ");
 		scanf("%d",&secim);
	}
 	// döngü bitti
 	
 	//Secim 1 olarak belirlendiyse yapılacaklar
 	if(secim==1) // eğer seçim 1 se
 	{
 		system("CLS"); // ekranı temizle
 		printf(" \n\n---------------- Odeme Sekli 1 (Asgari Odeme) 'i sectiniz ----------------\n\n");
 		
		// hesaplatma işlemleri
 		odeme= borc*30/100;    //odeme hasaplatma kısmı
		kalan= borc-odeme;    //kalan borcu hesaplama
		gecikme_faizi= kalan*(202/100)/100; //gecikme faizi %2,02
		vergi= gecikme_faizi*20/100; // vergi= faizin %20'si
		 
		toplam_devreden_borc= kalan+gecikme_faizi+vergi;
			
		//Şuan ödemeniz gereken miktar
		
		printf("Toplam Borc: %.2f \n", borc); // %.2f virgülden sonra sadece 2 basamak göster
		printf("---------------------------------------\n");
 		printf("Odemeniz gereken miktar : %.2f \n", odeme);
 		printf("Kalan borc miktari : %.2f \n", kalan);
 		printf("Gecikme faizi : %.2f \n", gecikme_faizi);
 		printf("Vergi : %.2f \n", vergi);
 		printf("Toplam devreden borc : %.2f \n \n", toplam_devreden_borc);
 		
 		while(borc>20)
 		{
 			sayac++;
 			odeme= borc*30/100;    //odeme hasaplatma kısmı
			kalan= borc-odeme;    //kalan borcu hesaplama
			gecikme_faizi= kalan*(202/100)/100; //gecikme faizi %2,02
			vergi= gecikme_faizi*20/100; // vergi= faizin %20'si
			
			toplam_devreden_borc= kalan+gecikme_faizi+vergi;
			printf("%d. odeme - Borc  %.2f -Bu borcun gecikme faizi %.2f - Vergisi %.2f kadar \n", sayac,toplam_devreden_borc,gecikme_faizi,vergi);
			borc=toplam_devreden_borc;
		}
		printf("\n %d AYDA BORCUNUZ BITMIS OLACAK." , sayac);
		
 		/* printf("\n Basa donmek icin b tusuna basiniz");
 		scanf("%c",&yonlendirme);
 		
 		if (yonlendirme='b')
		 {
		 	yonlendirme=' ';
		 	goto programbasi;
		 }
		*/
		 
	}
	
	//Secim 2 olarak belirlendiyse yapılacaklar
 	if(secim==2)
 	{
 		system("CLS");
 		printf(" \n\n------------- Odeme Sekli 2 (Borcun %%50'sini Odeme)'i sectiniz -------------\n\n");
 	
		// hesaplatma işlemleri
 		odeme= borc*50/100;    //odeme hasaplatma kısmı
		kalan= borc-odeme;    //kalan borcu hesaplama
		gecikme_faizi= kalan*(202/100)/100; //gecikme faizi %2,02
		vergi= gecikme_faizi*20/100; // vergi= faizin %20'si
		 
		toplam_devreden_borc= kalan+gecikme_faizi+vergi;
			
		//Şuan ödemeniz gereken miktar
		
		printf("Toplam Borc: %.2f \n", borc); // %.2f virgülden sonra sadece 2 basamak göster
		printf("---------------------------------------\n");
 		printf("Odemeniz gereken miktar : %.2f \n", odeme);
 		printf("Kalan borc miktari : %.2f \n", kalan);
 		printf("Gecikme faizi : %.2f \n", gecikme_faizi);
 		printf("Vergi : %.2f \n", vergi);
 		printf("Toplam devreden borc : %.2f \n \n", toplam_devreden_borc);
 		
 		while(borc>20)
 		{
 			sayac++;
 			odeme= borc*50/100;    //odeme hasaplatma kısmı
			kalan= borc-odeme;    //kalan borcu hesaplama
			gecikme_faizi= kalan*(202/100)/100; //gecikme faizi %2,02
			vergi= gecikme_faizi*20/100; // vergi= faizin %20'si
			
			toplam_devreden_borc= kalan+gecikme_faizi+vergi;
			printf("%d. odeme - Borc  %.2f -Bu borcun gecikme faizi %.2f - Vergisi %.2f kadar \n", sayac,toplam_devreden_borc,gecikme_faizi,vergi);
			borc=toplam_devreden_borc;
		}
		printf("\n %d AYDA BORCUNUZ BITMIS OLACAK.", sayac);
 		/* printf("\n Basa donmek icin b tusuna basiniz");
 		scanf("%c",&yonlendirme);
 		
 		if (yonlendirme='b')
		 {
		 	goto programbasi;
		 }
		*/ 
	}
	printf("\n\n\n");
	return 0;
	
	
	
}

