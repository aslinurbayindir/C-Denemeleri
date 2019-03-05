#include<stdio.h>
typedef enum{
	bay, // 0
	bayan //1
}cinsiyet;

typedef enum{ // enuminator tipi numaralandırmak için kullanılır.
	pazartesi,
	sali,
	carsamba,
	persembe,
	cuma,
	cumartesi,
	pazar
}gunler;

typedef struct {
	int yas;
	char * isim;
	cinsiyet c;
	gunler tatilgunu;
	} insan;


int main() {
	insan ali;
   	ali.yas = 27;
	ali.tatilgunu = persembe;
	
	printf("alinin yasi :%d %u tatil gunu %u", ali.yas, ali.c,ali.tatilgunu); //ali.c değer olarak 0 gönderir.

    return 0;
}
