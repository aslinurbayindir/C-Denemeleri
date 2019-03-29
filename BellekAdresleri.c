#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tut, *adr;
    adr=&tut;

    tut=888;
    printf("-------------------Hello world!-----------------------\n\n");

    printf("Degiskenin adresi  :%p \n",&tut);
    printf("Degiskenin degeri  :%d \n \n",tut);

    printf("Isaretcinin degeri (adres) :%p \n",adr);
    printf("Isaret ettigi deger: %d \n\n",*adr);


    printf("Hello world!\n");
    return 0;
}
