#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct kitap{
	char isim[20];
	int fiyat;
	int sayfa;
};


int main () {
	
	struct kitap *kitap2 = (struct kitap *)malloc(sizeof(struct kitap));
	
	strcpy(kitap2->isim, "kitap2");
	kitap2->fiyat=200;
	kitap2->sayfa=300;
	
	printf("Bilgiler = %s , %d , %d",kitap2->isim,kitap2->fiyat,kitap2->sayfa);
	
	
	return 0;
}
