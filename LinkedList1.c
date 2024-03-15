#include<stdio.h>
#include<stdlib.h>


// Baðlý liste bu 

struct node {
	
	int data;
	struct node *next;
	
};


// Düðümün baþý ve sonu 
struct node *ilk = NULL;
struct node *son = NULL;

// Baðlý listeye düðüm ekleme fonksiyonu

int addNode(int data){
	
	//Baðlý liste boþ olduðu durum  
	if(ilk==NULL){
		struct node *newNode = (struct node *)malloc(sizeof(struct node));
		
		//ilk data struct nodenin içindeki data ikinci data fonksiyonun içindeki
		newNode data-> data;
		newNode next = NULL;
		
		ilk = son = newNode;

		
	}
	
	//Baðlý liste dolu olduðu durum 
	
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
