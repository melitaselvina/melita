#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Array untuk menyimpan pilihan dalam bentuk string
const char *pilihan[] = {"Batu", "Gunting", "Kertas"};

// Fungsi untuk menentukan hasil permainan
int tentukan_pemenang(int pemain, int komputer) {
    if (pemain == komputer)
        return 0; // Seri
    else if ((pemain == 0 && komputer == 1) ||
             (pemain == 1 && komputer == 2) ||
             (pemain == 2 && komputer == 0))
        return 1; // Pemain menang
    else
        return -1; // Komputer menang
}

int main() {
    int pemain, komputer, hasil;
    char ulang;

    // Inisialisasi seed untuk angka acak
    srand(time(NULL));

    printf("=== Permainan Suit Jepang ===\n");
    printf("Pilihan:\n");
    printf("0: Batu\n1: Gunting\n2: Kertas\n");

    do {
        // Input dari pemain
        printf("Masukkan pilihan Anda (0-2): ");
        scanf("%d", &pemain);

        // Validasi input
        if (pemain < 0 || pemain > 2) {
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
            continue;
        }

        // Komputer memilih secara acak
        komputer = rand() % 3;

        printf("Anda memilih: %s\n", pilihan[pemain]);
        printf("Komputer memilih: %s\n", pilihan[komputer]);

        // Menentukan hasil
        hasil = tentukan_pemenang(pemain, komputer);

        if (hasil == 0)
            printf("Hasil: Seri!\n");
        else if (hasil == 1)
            printf("Hasil: Anda Menang!\n");
        else
            printf("Hasil: Anda Kalah!\n");

        // Menanyakan apakah ingin bermain lagi
        printf("Ingin bermain lagi? (y/n): ");
        scanf(" %c", &ulang); // Spasi sebelum %c untuk mengabaikan karakter newline

    } while (ulang == 'y' || ulang == 'Y');

    printf("Terima kasih telah bermain!\n");

    return 0;
}
