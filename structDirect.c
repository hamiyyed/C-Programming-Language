#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct kitap {
	
	char isim[20];
	int fiyat;
	int sayfa;
	
};


int main () {
	
	struct kitap kitap1;
	strcpy(kitap1.isim , "kitapkitap");
	kitap1.fiyat=100;
	kitap1.sayfa=150;
	printf("%s , %d , %d",kitap1.isim,kitap1.fiyat,kitap1.sayfa);
	
	
	
	
	return 0;
}
