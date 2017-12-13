#include <stdio.h>
#include<conio.h>
main() {
    int i=0;
    char kata[9]={'k','e','l','e','l','a','w','a','r'};
    char bintang[9]={'*','*','*','*','*','*','*','*','*'};
    char tebak;
    int salah=0, menang=0;
    int if_same=0;
    int jumlah_bintang=0;
    printf("Game Tebak Kata\n");
    printf("#Pertanyaan : ");
    printf("\tHewan apakah yang memiliki kemampuan ekolokasi ?\n");
    printf("_____________________________\n");
    while(salah<=3) {
        printf ("Jawaban :\n");
        for(i=0;i<9;i++) {
            printf("%c ",bintang[i]);
        }
		printf("\tJawaban salah %i kali",salah);
		printf("\n");
		printf("\tMasukkan Tebakan Anda : ");
		jumlah_bintang=0;
		for(i=0;i<9;i++) {
			if(bintang[i]=='*') {
				jumlah_bintang++;
			}
		}
        scanf("%c",&tebak);
        fflush(stdin);
        for(i=0;i<9;i++) {
            if(kata[i]==tebak) {
                bintang[i]=tebak;
                jumlah_bintang--;
                if_same++;
            }
        }
        if(if_same==0) {
            salah++;
        }
        if (salah==3) {
            printf("\nSalah tiga kali silahkan coba lagi ");
            break;
        }
        if(jumlah_bintang==0) {
            printf("\nSelamat jawaban anda benar!");
            break;
        }
        if_same=0;
    }
}
