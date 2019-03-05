#include<stdio.h>
typedef struct {
	int yas;
	char * isim;
	enum {bay,bayan} cinsiyet;
	} insan;


int main() {

    insan ali;
    ali.yas = 27;
    printf("alinin yasi :%d", ali.yas);

    return 0;
}
