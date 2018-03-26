#include<stdio.h>

int charge(int cardType, int* monthlyUse, double* balance);

int main(){
int monthlyUse = 0;
double balance = 20.0;
if(charge(1,&monthlyUse, &balance) < 0)
printf("Insufficient balance.");
else
    printf("Remaining monthly use: %d – Remaining Balance: %.2f\n",monthlyUse,balance);
}

int charge(int cardType, int* monthlyUse, double* balance){
    switch(cardType){               /* Kullanýlacak kart tipini seçmek için switch fonk kullandým */
    case 1 :
        if(*monthlyUse<1){          /* Eðer kiþinin aylýk üyeliði yok ise   */
            if(*balance>=2.30){     /* Ve kiþinin bakiyesi 2.30'dan daha büyük veya eþitse parayý bakiyeden azaltýp herhangi bir hata olmadýðý için 0 return eder */
                *balance = *balance - 2.30;
                return(0);
            }
            else{                   /* Kiþinin hem aylýk üyeliði olmadýðý ve bakiyeside yetersiz olduðu için -1 return eder */
                return(-1);
            }
        }
        else{                       /* Kiþinin aylýk üyeliði var ise aylýk kullanýmdan bir düþer */
            *monthlyUse = *monthlyUse - 1;
            return(0);
        }
        break;                      /* Diðer case'lerdeki statement'leri yapmamak için break koydum */
    case 2 :                        /* Üstteki case'le azaltýlacak bakiye miktarý hariç tamamen ayný */
        if(*monthlyUse<1){
            if(*balance>=1.15){
                *balance = *balance - 1.15;
                return(0);
            }
            else{
                return(-1);
            }
        }
        else{
            *monthlyUse = *monthlyUse - 1;
            return(0);
        }
        break;
    case 3 :                        /* Üstteki case'le azaltýlacak bakiye miktarý hariç tamamen ayný */
        if(*monthlyUse<1){
            if(*balance>=1.65){
                *balance = *balance - 1.65;
                return(0);
            }
            else{
                return(-1);
            }
        }
        else{
            *monthlyUse = *monthlyUse - 1;
            return(0);
        }
        break;
    default :                       /* Girilen kart tipi geçersiz olduðu için -2 return eder */
        return(-2);
    }
}
