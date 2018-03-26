#include<stdio.h>

int charge(int cardType, int* monthlyUse, double* balance);

int main(){
int monthlyUse = 0;
double balance = 20.0;
if(charge(1,&monthlyUse, &balance) < 0)
printf("Insufficient balance.");
else
    printf("Remaining monthly use: %d � Remaining Balance: %.2f\n",monthlyUse,balance);
}

int charge(int cardType, int* monthlyUse, double* balance){
    switch(cardType){               /* Kullan�lacak kart tipini se�mek i�in switch fonk kulland�m */
    case 1 :
        if(*monthlyUse<1){          /* E�er ki�inin ayl�k �yeli�i yok ise   */
            if(*balance>=2.30){     /* Ve ki�inin bakiyesi 2.30'dan daha b�y�k veya e�itse paray� bakiyeden azalt�p herhangi bir hata olmad��� i�in 0 return eder */
                *balance = *balance - 2.30;
                return(0);
            }
            else{                   /* Ki�inin hem ayl�k �yeli�i olmad��� ve bakiyeside yetersiz oldu�u i�in -1 return eder */
                return(-1);
            }
        }
        else{                       /* Ki�inin ayl�k �yeli�i var ise ayl�k kullan�mdan bir d��er */
            *monthlyUse = *monthlyUse - 1;
            return(0);
        }
        break;                      /* Di�er case'lerdeki statement'leri yapmamak i�in break koydum */
    case 2 :                        /* �stteki case'le azalt�lacak bakiye miktar� hari� tamamen ayn� */
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
    case 3 :                        /* �stteki case'le azalt�lacak bakiye miktar� hari� tamamen ayn� */
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
    default :                       /* Girilen kart tipi ge�ersiz oldu�u i�in -2 return eder */
        return(-2);
    }
}
