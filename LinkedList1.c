#include<stdio.h>
#include<stdlib.h>


// Ba�l� liste bu 

struct node {
	
	int data;
	struct node *next;
	
};


// D���m�n ba�� ve sonu 
struct node *ilk = NULL;
struct node *son = NULL;

// Ba�l� listeye d���m ekleme fonksiyonu

int addNode(int data){
	
	//Ba�l� liste bo� oldu�u durum  
	if(ilk==NULL){
		struct node *newNode = (struct node *)malloc(sizeof(struct node));
		
		//ilk data struct nodenin i�indeki data ikinci data fonksiyonun i�indeki
		newNode data-> data;
		newNode next = NULL;
		
		ilk = son = newNode;

		
	}
	
	//Ba�l� liste dolu oldu�u durum 
	
	else {
		
		struct node *newNode = (struct node *)malloc(sizeof(struct node));
		newNode->data = data;
		newNode->next = NULL;
		
		son->next= newNode;
		
		son = newNode;
	}
	
		
	
	
	return 0;
}


int main () {
	
	addNode(10);
	addNode(14);
	addNode(16);
	addNode(18);
	addNode(20);

	
	
	return 0;
}
