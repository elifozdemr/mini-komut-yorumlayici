#include <stdio.h>
#include <errno.h>
#include <string.h>
int degiskenSayisi=0;
typedef struct {
    char isim[20];
    int deger;
}Degisken;
Degisken Degiskenler[100];
void degiskenAta() {
    int tane;
    FILE* fptr;
    fptr=fopen("deger.txt","a");
    if(fptr==NULL) {
        printf("%s\n",strerror(errno));
        return;
    }
    printf("Kac tane isim ve deger girmek istiyorsunuz: ");
    scanf("%d",&tane);
    for (int i=0;i<tane;i++) {
    printf("Degisken ismini giriniz: ");
    scanf("%s",Degiskenler[degiskenSayisi].isim);
    printf("Degiskenin degerini giriniz: ");
    scanf("%d",&Degiskenler[degiskenSayisi].deger);
    fprintf(fptr,"%s %d\n",Degiskenler[degiskenSayisi].isim,Degiskenler[degiskenSayisi].deger);
        degiskenSayisi++;
        printf("Degiskenler basariyla atandi\n");
    }
    fclose(fptr);

}
void degiskenGoser() {
    FILE* fptr;
    fptr=fopen("deger.txt","r");
    if(fptr==NULL) {
        printf("%s\n",strerror(errno));
        return;
    }
    while (fscanf(fptr,"%s %d",Degiskenler[degiskenSayisi].isim,&Degiskenler[degiskenSayisi].deger)==2) {
        printf("Degiskenler gosteriliyor: %s %d\n",Degiskenler[degiskenSayisi].isim,Degiskenler[degiskenSayisi].deger);
    }
fclose(fptr);
}
void ifadeHesaplama() {
    int sec;
    int sayi1,sayi2;
    FILE* fptr;
    fptr=fopen("islemler.txt","a");
    if(fptr==NULL) {
        printf("%s\n",strerror(errno));
        return;
    }
        printf("Kullanacaginiz mevcut iki degeri giriniz: ");
        scanf("%d %d",&sayi1,&sayi2);
        printf("Lutfen 1 ile 4 arasinda bir secim yapiniz: ");
        printf("1-Toplama\n2-Cikarma\n3-Bolme\n4-Carpma\n");
        scanf("%d",&sec);
        switch (sec) {
            case 1:printf("Toplama sonucu:%d\n",sayi1+sayi2);
                fprintf(fptr,"%d %d %d\n",sayi1,sayi2,sayi1+sayi2);
                break;
            case 2:printf("Cikarma sonucu:%d\n",sayi1-sayi2);
                fprintf(fptr,"%d %d %d\n",sayi1,sayi2,sayi1-sayi2);
                break;
                case 3:if (sayi2==0 ){
                    printf("Sıfır olamaz,tanimsiz cikar\n");
                    break;
                }
                printf("Bolme sonucu:%d\n",sayi1/sayi2);
                fprintf(fptr,"%d %d %d\n",sayi1,sayi2,sayi1/sayi2);
                break;
            case 4:printf("Carpma sonucu:%d\n",sayi1*sayi2);
                fprintf(fptr,"%d %d %d\n",sayi1,sayi2,sayi1*sayi2);
                break;
        }
    fclose(fptr);
}
void dosyadanYuke() {
    degiskenSayisi=0;
    FILE* fptr;
    fptr=fopen("deger.txt","r");
    if(fptr==NULL) {
        printf("%s\n",strerror(errno));
        return;
    }

        while (fscanf(fptr,"%s %d",Degiskenler[degiskenSayisi].isim,&Degiskenler[degiskenSayisi].deger)==2) {
            degiskenSayisi++;
        }
    fclose(fptr);
    printf("Degiskenler dosyadan basariyla yuklendi\n");
}
void cikis() {
    printf("Cikis yapilmistir\n");
}
int komutIsle() {
    int sec;
    printf("Hangi komutu kullanmak istiyorsunuz;\n");
    printf("1-Degisken atama\n");
    printf("2-Degiskeni goster\n");
    printf("3-İfade hesaplama\n");
    printf("4-Dosyadan yukle\n");
    printf("5-Cikis\n");
    printf("1-5 arasinda bir secim yapiniz: ");
    scanf("%d",&sec);
    switch (sec) {
        case 1:
            degiskenAta();
            break;
            case 2:
           degiskenGoser();
            break;
            case 3:
            ifadeHesaplama();
            break;
            case 4:
            dosyadanYuke();
            break;
            case 5:
            cikis();
            return 0;
        default:printf("Gecersiz komut!\n");
    }
    return 1;
}
int main() {
    while (komutIsle()==1) {
    }
    return 0;
}