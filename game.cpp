#include <stdio.h>
#include<conio.h>
main() {
    int i=0;
    char kata[9]={'k','e','l','e','l','a','w','a','r'};
    char bintang[9]={'*','*','*','*','*','*','*','*','*'};
    char tebak;
    int salah=0,kesempatan=3,menang=0;
    printf("\n\tGame Tebak Kata\n");
    printf("\t\n\t#Pertanyaan : \n");
    printf("\t\tHewan apakah yang memiliki kemampuan ekolokasi ?\n");
    printf("_____________________________\n\n");
    while(salah<=3) {
        if(salah==3) {
            kesempatan=0;
            break;
        }
        int jumlah_bintang=0;
        printf ("==> Apakah Jawabannya ? <==\n\n");
        for(i=0;i<9;i++) {
            printf("%c ",bintang[i]);
        }
		printf("\tKesempatan Menebak Masih %i kali",kesempatan);
		printf("\n\n");
		int if_same=0;
		printf("\tMasukkan Tebakan Anda : ");
		for(i=0;i<9;i++) {
			if(bintang[i]=='*') {
				jumlah_bintang++;
			}
		}
        if(jumlah_bintang==0) {
            printf("\n\n Selamat jawaban anda benar!\n");
            printf("\n________Congratulation________");
            break;
        }
        scanf("%c",&tebak);
        fflush(stdin);
        for(i=0;i<9;i++) {
            if(kata[i]==tebak) {
                bintang[i]=tebak;
                if_same+=1;
            }
        }
        if(if_same==0) {
            salah++;
            kesempatan--;
        }
        if (salah==3) {
            printf("\nMaaf anda harus mencoba lagi !");
            break;
       }
    }
}
