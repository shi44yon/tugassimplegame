#include <stdio.h>
#include <conio.h>
//#include <iostream>

//using namespace std;

main() {
    int i=0;
    char kata[9]={'k','e','l','e','l','a','w','a','r'};
    char bintang[9]={'*','*','*','*','*','*','*','*','*'};
    char tebak;
    int kesempatan=3;
    int if_same=0;
    int jumlah_bintang=0;
    printf("Game Tebak Kata\n");
    printf("#Pertanyaan : ");
    printf("Hewan apakah yang memiliki kemampuan ekolokasi ?\n");
    printf(" ____________________________________________________________\n");
    while(kesempatan>=0) {
        printf ("\nJawaban :\n");
        for(i=0;i<9;i++) {
            printf("%c",bintang[i]);
        }
		printf("\tKesempatan menjawab %i kali",kesempatan);
		printf("\n");
		printf("\tMasukkan Tebakan Anda :");
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
        if(!if_same) {
            kesempatan--;
        }
        if (kesempatan==0) {
            printf("\nKesempatan habis, silahkan coba lagi!");
            break;
        }
        if(jumlah_bintang==0) {
            printf("\nSelamat jawaban anda benar!");
            printf("\nJawaban :\nkelelawar");
            break;
        }
        if_same=0;
    }
}
