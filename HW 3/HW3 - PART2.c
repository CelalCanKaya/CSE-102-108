#include<stdio.h>


int main(){
double paid = 1, due = 5;
int tl1,krs50,krs25,krs10,krs5,krs1;
    if(dispenseChange(paid,due,&tl1,&krs50, &krs25, &krs10, &krs5, &krs1)) /* returns 1 */
        printf("Change: 1TL:%d, Kurus-50:%d,25:%d,10:%d,5:%d,1:%d\n",tl1,krs50,krs25,krs10,krs5,krs1);
    else
        printf("Unable to dispense change.");
}

int dispenseChange(double paid, double due, int *tl1, int *krs50, int *krs25, int
*krs10, int *krs5, int *krs1){
    int tl1_counter, krs50_counter, krs25_counter, krs10_counter, krs5_counter, krs1_counter;       /* Fonksiyonumda kullanaca��m tan�mlay�c�lar� deklare ettim */
    double change;
    tl1_counter=0;                          /* 19. Sat�ra kadar para �st�ndeki verece�im miktarlar� 0'a e�itledim */
    krs50_counter=0;
    krs25_counter=0;
    krs10_counter=0;
    krs5_counter=0;
    krs1_counter=0;
    change=(paid-due)+0.001;                /* Toplam para �st�n� �denmi� miktardan �denecek miktar� ��kararak buldum.0.001 Eklememin nedeni bazen para �st�nde 1 kuru� olmas�na ra�men para �st�n� vermiyordu.Bu sorunu ��zmek i�in bu miktar� ekledim */
    if(change>=0){                          /* E�er para �st� 0'dan b�y�kse */
            while(change>=1.00){            /* Para �st� 1 liradan b�y�kse verilecek para �st�ndeki 1 lira miktar�n� 1 artt�ran ve para �st�nden 1 lira azaltan d�ng� */
                tl1_counter ++;
                change = change-1.00;
            }
            *tl1 = tl1_counter;
            while(change>=0.5){             /* Para �st� 50 kuru�tan b�y�kse verilecek para �st�ndeki 50 kuru� miktar�n� 1 artt�ran ve para �st�nden 50 kuru� azaltan d�ng� */
                krs50_counter ++;
                change = change-0.50;
            }
            *krs50 = krs50_counter;
            while(change>=0.25){            /* Para �st� 25 kuru�tan b�y�kse verilecek para �st�ndeki 25 kuru� miktar�n� 1 artt�ran ve para �st�nden 25 kuru� azaltan d�ng� */
                krs25_counter ++;
                change = change-0.25;
            }
            *krs25 = krs25_counter;
            while(change>=0.10){            /* Para �st� 10 kuru�tan b�y�kse verilecek para �st�ndeki 10 kuru� miktar�n� 1 artt�ran ve para �st�nden 10 kuru� azaltan d�ng� */
                krs10_counter ++;
                change = change-0.1;
            }
            *krs10 = krs10_counter;
            while(change>=0.05){            /* Para �st� 5 kuru�tan b�y�kse verilecek para �st�ndeki 5 kuru� miktar�n� 1 artt�ran ve para �st�nden 5 kuru� azaltan d�ng� */
                krs5_counter++;
                change = change-0.05;
            }
            *krs5 = krs5_counter;
            while(change>=0.01){            /* Para �st� 1 kuru�tan b�y�kse verilecek para �st�ndeki 1 kuru� miktar�n� 1 artt�ran ve para �st�nden 1 kuru� azaltan d�ng� */
                krs1_counter ++;
                change = change-0.01;
            }
            *krs1 = krs1_counter;
            return(1);                      /* Para yeterli oldu�undan ve para�st� verildi�inden 1 return ediyorum */
    }
    else{                                   /* Para yetersiz oldu�u i�in yukar�da para �stlerine 0 atad���m de�erleri ve para �st� yetersiz oldu�u i�in 0 return ediyorum */
            *tl1 = tl1_counter;
            *krs50 = krs50_counter;
            *krs25 = krs25_counter;
            *krs10 = krs10_counter;
            *krs5 = krs5_counter;
            *krs1 = krs1_counter;
            return(0);
    }

}
