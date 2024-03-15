#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	char isim[39];
	int yas;
} yazar ;

int main () {
	
	//typedef Direct
	yazar yazar1;
	strcpy(yazar1.isim,"isim isim");
	yazar1.yas=90;
	printf("%s , %d \n\n\n",yazar1.isim,yazar1.yas);
	
	//typedef Unirect
	yazar *yazar2 = (yazar *)malloc(sizeof(yazar));
	strcpy(yazar2->isim,"isim2 isim2");
	yazar2->yas=99;
	printf("%s , %d",yazar2->isim,yazar2->yas);
	
	
	return 0;
}
 
