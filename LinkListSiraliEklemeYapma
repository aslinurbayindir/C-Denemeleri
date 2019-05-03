#include<stdio.h>
#include<stdlib.h>

struct n{  //veri yapısı tanımladık
    int x;
    n * next;
};
typedef n node;  // struct yapılarını kullanmamız için n cinsinden bir node tanımladık

void bastir (node *r){ // link list değeri alıp ekrana bastıran fonksiyon
    while (r!=NULL){
        printf("%d  \n", r->x);
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
node * ekleSirali(node *r, int x){
        if(r==NULL){                              // LinkList boşsa kutu yap değer at
            r = (node *) malloc (sizeof(node));
            r -> next = NULL;
            r -> x = x;
            return r;
        }
        
        if(r->x > x){                              // ilk elemandan küçük durumuysa rootu değiştiriyoruz. yeni kutu yapıyoruz ve root bu kutu oluyot.
        		node * temp =(node *) malloc (sizeof(node));
				temp -> x = x;
				temp -> next = r;
				return temp;
		}
        node * iter = r; //elimizde iterator değeri kalabilsin diğerlerinin üzerinde hareket ediyoruz.
        
        while (iter->next != NULL && iter->next-> x <x ){  // LinkListteki değer elimizdeki düğümdeki değerden daha büyükse devam et yeni kutuyu ekle
        	iter=iter->next;
        	
		}
		
		node * temp =(node *) malloc (sizeof(node));
		temp -> next = iter -> next;
		iter -> next = temp;
		temp -> x = x;
		
		return r;
		       
}
	
int main(){

    node * root; //* tipinde bir pointer
    root = NULL;
    
    root =ekleSirali(root,400);
    root =ekleSirali(root,40);
	  root =ekleSirali(root,4);
    root =ekleSirali(root,450);
    root =ekleSirali(root,50);
    
	bastir(root);
	
