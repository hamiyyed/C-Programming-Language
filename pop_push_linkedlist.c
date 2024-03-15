#include<stdio.h>
#include<stdlib.h>

struct Node {
    int ogrno;
    int vize;
    int final;
    struct Node *sonraki;
};

struct Node *Push(struct Node *top, int ogrno, int vize, int final) {
    struct Node *yeni = (struct Node*)malloc(sizeof(struct Node));
    yeni->ogrno = ogrno;
    yeni->vize = vize;
    yeni->final = final;
    yeni->sonraki = NULL;
    
    if (top == NULL) {
        top = yeni;
    } else {
        yeni->sonraki = top;
        top = yeni;
    }
    
    return top;
}

struct Node *Pop(struct Node *top, int *ogrno, int *vize, int *final) {
    if (top == NULL) {
        *ogrno = 0;
        *vize = 0;
        *final = 0;
        return top;
    } else {
        struct Node *gecici;
        gecici = top;
        
        *ogrno = gecici->ogrno;
        *vize = gecici->vize;
        *final = gecici->final;
        
        top = top->sonraki;
        free(gecici);
        
        return top;
    }
}

int main(void) {
    struct Node *top = NULL;
    int ogrno, vize, final, i;
    
    for (i = 0; i < 3; i++) {
        printf("Ogr : %d ------------\n", i + 1);
        printf("Vize = ");
        scanf("%d", &vize);
        printf("Final = ");
        scanf("%d", &final);
        
        top = Push(top, i + 1, vize, final);
    }
    
    printf("\n\n");
    
    for (i = 0; i < 3; i++) {
        top = Pop(top, &ogrno, &vize, &final);
        printf("Ogr : %d   vize/final = %d/%d\n", ogrno, vize, final);
    }
    
    return 0;
}
