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
    int tl1_counter, krs50_counter, krs25_counter, krs10_counter, krs5_counter, krs1_counter;       /* Fonksiyonumda kullanacağım tanımlayıcıları deklare ettim */
    double change;
    tl1_counter=0;                          /* 19. Satıra kadar para üstündeki vereceğim miktarları 0'a eşitledim */
    krs50_counter=0;
    krs25_counter=0;
    krs10_counter=0;
    krs5_counter=0;
    krs1_counter=0;
    change=(paid-due)+0.001;                /* Toplam para üstünü ödenmiş miktardan ödenecek miktarı çıkararak buldum.0.001 Eklememin nedeni bazen para üstünde 1 kuruş olmasına rağmen para üstünü vermiyordu.Bu sorunu çözmek için bu miktarı ekledim */
    if(change>=0){                          /* Eğer para üstü 0'dan büyükse */
            while(change>=1.00){            /* Para üstü 1 liradan büyükse verilecek para üstündeki 1 lira miktarını 1 arttıran ve para üstünden 1 lira azaltan döngü */
                tl1_counter ++;
                change = change-1.00;
            }
            *tl1 = tl1_counter;
            while(change>=0.5){             /* Para üstü 50 kuruştan büyükse verilecek para üstündeki 50 kuruş miktarını 1 arttıran ve para üstünden 50 kuruş azaltan döngü */
                krs50_counter ++;
                change = change-0.50;
            }
            *krs50 = krs50_counter;
            while(change>=0.25){            /* Para üstü 25 kuruştan büyükse verilecek para üstündeki 25 kuruş miktarını 1 arttıran ve para üstünden 25 kuruş azaltan döngü */
                krs25_counter ++;
                change = change-0.25;
            }
            *krs25 = krs25_counter;
            while(change>=0.10){            /* Para üstü 10 kuruştan büyükse verilecek para üstündeki 10 kuruş miktarını 1 arttıran ve para üstünden 10 kuruş azaltan döngü */
                krs10_counter ++;
                change = change-0.1;
            }
            *krs10 = krs10_counter;
            while(change>=0.05){            /* Para üstü 5 kuruştan büyükse verilecek para üstündeki 5 kuruş miktarını 1 arttıran ve para üstünden 5 kuruş azaltan döngü */
                krs5_counter++;
                change = change-0.05;
            }
            *krs5 = krs5_counter;
            while(change>=0.01){            /* Para üstü 1 kuruştan büyükse verilecek para üstündeki 1 kuruş miktarını 1 arttıran ve para üstünden 1 kuruş azaltan döngü */
                krs1_counter ++;
                change = change-0.01;
            }
            *krs1 = krs1_counter;
            return(1);                      /* Para yeterli olduğundan ve paraüstü verildiğinden 1 return ediyorum */
    }
    else{                                   /* Para yetersiz olduğu için yukarıda para üstlerine 0 atadığım değerleri ve para üstü yetersiz olduğu için 0 return ediyorum */
            *tl1 = tl1_counter;
            *krs50 = krs50_counter;
            *krs25 = krs25_counter;
            *krs10 = krs10_counter;
            *krs5 = krs5_counter;
            *krs1 = krs1_counter;
            return(0);
    }

}
