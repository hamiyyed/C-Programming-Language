#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLO_BOYUTU 10
#define MAX_DENEME 10
#define FILENAME "kargolar.txt"

typedef struct {
    int takipNo;
    char gonderici[100];
    char alici[100];
    char kargoDurum[100];
} Kargo;

Kargo* hash_tablo[TABLO_BOYUTU];

int hash_func1(int takipNo) {
    return takipNo % TABLO_BOYUTU;
}

int hash_func2(int takipNo) {
    return 7 - (takipNo % 7);
}

int double_hashing(int index, int deneme) {
    return (index + deneme * hash_func2(index)) % TABLO_BOYUTU;
}

void ekle(Kargo* kargo) {
    int index1 = hash_func1(kargo->takipNo);
    int index = index1;

    int deneme = 1;
    while (hash_tablo[index] != NULL && deneme <= MAX_DENEME) {
        index = double_hashing(index1, deneme);
        deneme++;
    }

    if (deneme > MAX_DENEME) {
        printf("Tablo dolu, ekleme basarisiz!\n");
        return;
    }

    hash_tablo[index] = (Kargo*)malloc(sizeof(Kargo));
    *hash_tablo[index] = *kargo;
}

void dosyadanOkuVeEkle() {
    FILE* dosya = fopen(FILENAME, "r");

    if (dosya == NULL) {
        printf("Dosya acma hatasi!\n");
        return;
    }

    Kargo kargo;
    while (fscanf(dosya, "%d %s %s %s", &kargo.takipNo, kargo.gonderici, kargo.alici, kargo.kargoDurum) != EOF) {
        ekle(&kargo);
    }

    fclose(dosya);
}

void kargoTakipDurumu(int takipNo) {
    int index1 = hash_func1(takipNo);
    int index = index1;

    int deneme = 1;
    while (hash_tablo[index] != NULL && hash_tablo[index]->takipNo != takipNo && deneme <= MAX_DENEME) {
        index = double_hashing(index1, deneme);
        deneme++;
    }

    if (hash_tablo[index] == NULL) {
        printf("Kargo bulunamadi.\n");
        return;
    }

    printf("Kargo %d numarali takip numarasiyla %d adimda bulundu.\n", takipNo, deneme);
    printf("Kargo Bilgileri:\nTakip No: %d\nGonderici: %s\nAlici: %s\nDurum: %s\n", hash_tablo[index]->takipNo,
           hash_tablo[index]->gonderici, hash_tablo[index]->alici, hash_tablo[index]->kargoDurum);
}

void kargolariListele() {
    for (int i = 0; i < TABLO_BOYUTU; ++i) {
        if (hash_tablo[i] != NULL) {
            int takipNo = hash_tablo[i]->takipNo;
            int index1 = hash_func1(takipNo);
            int index = index1;
            int deneme = 1;

            while (hash_tablo[index] != NULL && hash_tablo[index]->takipNo != takipNo && deneme <= MAX_DENEME) {
                index = double_hashing(index1, deneme);
                deneme++;
            }

            printf("Index %d: TakipNo %d, Gonderici %s, Alici %s, Durum %s - Bulundu: %d adimda\n",
                   i, takipNo, hash_tablo[i]->gonderici, hash_tablo[i]->alici, hash_tablo[i]->kargoDurum, deneme);
        } else {
            printf("Index %d: Bos\n", i);
        }
    }
}

int main() {
    dosyadanOkuVeEkle();

    
    printf("Hash tablosundaki kargolarin listesi:\n");
    kargolariListele();

    return 0;
}
