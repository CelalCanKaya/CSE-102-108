#include<stdio.h>

void drawRectangle(int width,int height, int startingPoint, int printLastLine);
void drawDoubleCircle(int radius, int startingPoint , int whellDistance);

int main(){
drawCar();

void drawCar();
}

/* Ödev PDF'inde "width" genişlik olmasına rağmen boy olarak alınmış.Eğer PDF'tekine göre yapılcaksa parametrelerimin yeri ters olabilir.Yazdığım koda göre "width" genişlik, "height" boy olarak aldım */


void drawRectangle(int width,int height, int startingPoint, int printLastLine){     /* Dikdörtgen çizdirme fonksiyonunu deklare ettim */

    int starting_point_counter, width_counter, height_counter;                      /* Fonksiyonda kullanacağım tanımlayıcıları deklare ettim */
    starting_point_counter = 0;                                                     /* "starting_point_counter" ı 0'a eşitledim */

    if(width>0 && height>0){                                                        /* Bu "if" sayesinde dikdörtgenin ilk satırını ekrana basıyorum. Eğer genişlik VE boy 0'dan büyükse olacaklar: */
        for(width_counter=0; width_counter<width; width_counter ++){                /* "width_counter", "width" değişkeninden küçük olduğu sürece */
            while(starting_point_counter<startingPoint){                            /* "starting_point_counter", "startingPoint" ten küçük olduğu sürece */
                printf(" ");                                                        /* Boşluk bırak */
                starting_point_counter ++;                                          /* "starting_point_counter" ı 1 arttır */
            }
            printf("*");                                                            /* "*" Bas */
        }

        for(height_counter=0; height_counter<height-2; height_counter ++){          /* Bu döngü sayesinde dikdörtgenin ilk satır harici olan satırlarını basıyorum */
            printf("\n");                                                           /* İmleç satırın sonunda olduğu için bir alt satıra geçiriyorum */
            for(starting_point_counter=0; starting_point_counter<startingPoint; starting_point_counter ++){     /* Başlangıç noktası için gereken boşluk sayısını bırakmak için gereken döngü */
                printf(" ");                                                        /* Boşluk basar */
            }
            printf("*");                                                            /* Yıldız basar */
            if(width>1){                                                            /* Bu satır sayesinde genişliği 1'e eşit olan şekillerde fazladan * basmaz */
                for(width_counter=0; width_counter<width-2; width_counter ++){      /* En başta bir * bastığından ve en sonda bir * daha basacağından "width_counter", "width-2" den küçük olana kadar boşluk bıraktıracak döngüdür */
                    printf(" ");                                                    /* Boşluk basar */
                }
                printf("*");                                                        /* * basar */
            }

        }
                        printf("\n");                                                           /* İmleç satırın sonunda olduğu için bir alt satıra geçiriyorum */

        if(height>1){                                                               /* Bu "if" altındaki kod bloğu sayesinde son satırın basılıp basılmayacağı kontrol edilir ve işlem yapılır */
            if(printLastLine==1){                                                   /* Eğer son satırı basmak istiyorsa */

                for(width_counter=0; width_counter<width; width_counter ++){                /* "width_counter", "width" değişkeninden küçük olduğu sürece */
                    while(starting_point_counter<startingPoint){                            /* "starting_point_counter", "startingPoint" ten küçük olduğu sürece */
                        printf(" ");                                                        /* Boşluk bırak */
                        starting_point_counter ++;                                          /* "starting_point_counter" ı 1 arttır */
                }
                printf("*");                                                            /* "*" Bas */

                }

            }

        printf("\n");

            }
        }
    }




void drawDoubleCircle(int radius, int startingPoint , int whellDistance){       /* İki tane daire çizdiren fonksiyonu deklare ettim */

int height,weight, counter;                                                     /* Tanımlayıcıları deklare ettim */

for(height=0;height<=radius*2;height++){                                        /* Bu döngü sayesinde çemberin satır sayısını kontrol ettim */
    for(counter = 0; counter<startingPoint; counter ++){                         /* Bu döngü sayesinde tekerleklerin kaç boşluk sonra basıldığını kontrol ettim */
        printf(" ");
    }
    for(weight=0;weight<=radius*2;weight++){                                     /* Bu döngü sayesinde çemberin genişliğini kontrol ettim */
        if(((radius-height)*(radius-height))+((radius-weight)*(radius-weight))<=(radius*radius))
            printf("* ");
        else
            printf("  ");
    }
    for(counter = 0; counter<whellDistance; counter ++){        /* Bu döngü sayesinde ikinci tekerlek ile ilk tekerlek arasındaki boşluk sayısı bırakılır */
        printf(" ");
    }
    for(weight=0;weight<=radius*2;weight++){                    /* Bu döngü sayesinde çemberin genişliğini kontrol ettim */
        if(((radius-height)*(radius-height))+((radius-weight)*(radius-weight))<=(radius*radius))
            printf("* ");
        else
            printf("  ");
    }
    printf("\n");                                               /* Yeni satıra geçerek tekerlekleri çizdirmeye devam ettim */
    }

}

void drawCar(){                         /* Araba çizdiren fonksiyonumda diğer fonksiyonları çağırdım */
    drawRectangle (40,10,11,0);
    drawRectangle (60,10,0,1);
    drawDoubleCircle(4, 7, 12);
}
