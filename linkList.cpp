#include<stdio.h>
#include<stdlib.h>

struct n{  //veri yapısı tanımladık
    int x;
    n * next;
};
typedef n node;  // struct yapılarını kullanmamız için n cinsinden bir node tanımladık

int main(){

    node * root; //* tipinde bir pointer
    root = (node *)malloc(sizeof(node));

    root -> x =10;
    root -> next = (node *)malloc(sizeof(node));
    root -> next -> x=20;
    root -> next -> next = (node *)malloc(sizeof(node));
    root -> next -> next -> x=30;

    node * iter;
    iter = root;
    printf("%d", iter->x);
    iter = iter -> next;

    printf("%d", iter->x);
}
