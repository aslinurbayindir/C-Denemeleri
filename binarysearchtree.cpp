#include <stdio.h>
#include <stdlib.h>      // malloc kullanacağımız için çağırdığımız kütüphane

struct n{				// yeni bir veri tipi oluşturuyoruz
	int data;
	n * sol;
	n * sag;
};

typedef n node;        // oluşturulan veri tipini tanımlayıp bu tipte bir fonksiyon yazıyoruz.

node * ekle (node *agac,int x){         // ağacımızı burada oluşturuyoruz
	
	if(agac == NULL){
		node *root= (node *)malloc(sizeof(node));    // node'un hafızada kaplayacağı kadart alan ayır
		root -> sol = NULL;
		root -> sag = NULL;
		root -> data = x;
		return root;
	}
	
	if(agac->data < x){        //eğer ekleyeceğimiz x değeri datamızdan daha büyükse sağ'a yerleştir.
		agac->sag = ekle(agac->sag,x);
		return agac;
	}
	agac->sol = ekle (agac->sol,x); // değilse zaten sol'a yerleştir.
	return agac;
}
void dolas(node *agac){   // void olabilir sadece sonuç döndürücez.
	if(agac == NULL)
		return;
	printf("%d ",agac->data);
	dolas(agac->sag);
	dolas(agac->sol);
}

void kucuktenbuyuge(node *agac){   // önce soldan başla git bastır küçük > büyüğe
	if(agac == NULL)
		return;
	dolas(agac->sol);	
	printf("%d ",agac->data);
	dolas(agac->sag);
}

void buyuktenkucuge(node *agac){   // önce sağdan git bastır büyük > küçüğe
	if(agac == NULL)
		return;
	dolas(agac->sag);
	printf("%d ",agac->data);
	dolas(agac->sol);
}

int bul (node * agac,int aranan){
	if(agac == NULL)
		return -1;
	if(agac->data == aranan)
		return 1;
	if(bul(agac->sag,aranan)==1)
		return 1;
	if(bul(agac->sol,aranan)==1)
		return 1;
	return -1;
}
int max(node *agac){  // max değer bulma için ağacın en sağına gitmemiz yeter

	while(agac->sag!=NULL)
		agac=agac->sag;
	return agac->data;
}
int min(node *agac){  // min değer için ağacın en soluna gitmemiz gerekli
	while(agac->sol!=NULL)
		agac=agac->sol;
	return agac->data;
}

node * sil(node *agac,int x){
	if(agac==NULL)
		return NULL;
	if(agac->data == x){
		if(agac->sol==NULL && agac->sag==NULL) //düğümün altında solunda ve sağında değer yoksa o değeri komple sil 
			return NULL;
			
		if(agac->sag!=NULL){  // sağda düğüm varsa
			agac->data = min(agac->sag); 
			agac->sag = sil(agac->sag, min(agac->sag));
			return agac;
		}
		agac->data = max(agac->sol);
		agac->sol = sil(agac->sol,max(agac->sol));
		return agac;
	}
		
	if(agac->data < x){
		agac->sag = sil(agac->sag,x);
		return agac;
	}
	agac->sol= sil(agac->sol,x);
	return agac;
	

}
int main(){
	node * agac=NULL;
	agac=ekle(agac,56);
	agac=ekle(agac,200);
	agac=ekle(agac,26);
	agac=ekle(agac,190);
	agac=ekle(agac,213);
	agac=ekle(agac,18);
	agac=ekle(agac,28);
	agac=ekle(agac,12);
	agac=ekle(agac,24);
	agac=ekle(agac,27);
	printf("\n Agacin dogal yapisi         --> ");
	dolas(agac);
	printf("\n Kucukten -> Buyuge siralama --> ");
	kucuktenbuyuge(agac);
	printf("\n Buyukten -> Kucuge siralama --> ");
	buyuktenkucuge(agac);
		
	printf("\n arama sonucu var/yok : %d",bul(agac,24));
	printf("\n\n max = %d min = %d ",max(agac),min(agac));
	
	agac= sil(agac,56);
	dolas(agac);
}
