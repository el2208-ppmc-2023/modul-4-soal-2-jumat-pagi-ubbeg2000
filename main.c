/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>

typedef struct complex {
    int real;
    int imag;
} complex;

int main() {

    int baris, kolom;
    scanf("%d %d",&baris, &kolom);

    int is_hermitian=1;
    int is_skew_hermitian=1;

    // jika baris tidak sama dengan kolom, sudah pasti bukan matriks cantik genap
    if(baris!=kolom) {
        printf("Matriks bukan merupakan keduanya\n");
    }
    else {
        //deklarasi matrices of struct
        complex matriks[baris][kolom];
        complex conjugate_transpose[kolom][baris];

        for (int i=0;i<baris;i++) {
            for(int j=0;j<baris;j++) {
                scanf("%d %d", &matriks[i][j].real, &matriks[i][j].imag);
            }
        }
        //melakukan conjugate transpose matriks
        for (int i=0; i<baris;i++) {
            for(int j=0;j<kolom;j++) {
                conjugate_transpose[j][i].real=matriks[i][j].real;
                conjugate_transpose[j][i].imag=(-1)*matriks[i][j].imag;
            }
        }
        for(int i=0;i<baris;i++) {

            for(int j=0;j<kolom;j++) {
                if(is_hermitian==1) { //cek apakah suatu matriks masih hermitian
                    if(conjugate_transpose[i][j].real!=matriks[i][j].real || conjugate_transpose[i][j].imag!=matriks[i][j].imag) {
                        is_hermitian=0;
                    }
                }
                if(is_skew_hermitian==1) {
                    if(conjugate_transpose[i][j].real!=-1*matriks[i][j].real || conjugate_transpose[i][j].imag!= -1*matriks[i][j].imag) {
                        is_skew_hermitian=0;
                    }
                }
                if(is_hermitian==0 && is_skew_hermitian==0) {
                    printf("Matriks bukan merupakan keduanya\n");
                    return 0;
                }
            }   
        }
        
        //sudah menyelesaikan loop di atas, artinya semua komponen sama, matriks merupakan matriks cantik genap
        
        if(is_hermitian==1) {
            if(is_skew_hermitian==1) {
                printf("Matriks merupakan matriks cantik genap dan matriks cantik ganjil\n");
            }
            else {
                printf("Matriks merupakan matriks cantik genap\n");
            }
        }
        else {
            if(is_skew_hermitian==1) {
                printf("Matriks merupakan matriks cantik ganjil\n");
            }
            else {
                printf("Matriks bukan merupakan keduanya\n");
            }
        }
    }
}
