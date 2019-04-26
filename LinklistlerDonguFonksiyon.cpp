#include<stdio.h>
#include<stdlib.h>

struct n{  //veri yapısı tanımladık
    int x;
    n * next;
};
typedef n node;  // struct yapılarını kullanmamız için n cinsinden bir node tanımladık

void bastir (node *r){ // link list değeri alıp ekrana bastıran fonksiyon
    while (r!=NULL){
        printf("%d  ", r->x);
        r=r->next;
    }
}

void ekle(node *r, int x){
        while(r ->next !=NULL){
            r = r ->next;
        }
        r->next = (node *) malloc (sizeof(node));
        r->next->x= x;
        r->next->next=NULL;
}

int main(){

    node * root; //* tipinde bir pointer
    root = (node *)malloc(sizeof(node));

    root -> next=NULL;
    root -> x =500;
    /*root -> next = (node *)malloc(sizeof(node));
    root -> next -> x=20;
    root -> next -> next = (node *)malloc(sizeof(node));
    root -> next -> next -> x=30;
    root -> next -> next -> next = NULL;

    node * iter;
    iter = root;
    printf("%d", iter->x);
    iter = iter -> next;

    printf("%d", iter->x);
    iter=root;
    */
    int i =0;

 /*   while(iter != NULL){
        i++;
        printf("%d inci eleman : %d \n",i,iter->x);
        iter = iter ->next;
    }*/
    for(i=0;i<5;i++){
        ekle(root, i*10);
        /*
        iter -> next = (node *)malloc (sizeof(node));
        iter = iter->next;
        iter -> x = i*10;
        iter -> next =  NULL;
        */
    }

    bastir(root);


}
