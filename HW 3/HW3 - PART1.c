#include <stdio.h>

int isPrime(int num);
int goldbach(int num, int *p1, int *p2);


int main()
{
int num = 6, p1, p2;
if(goldbach(num,&p1,&p2))
printf("%d = %d + %d",num,p1,p2); /* may print 824 = 821 + 3 */
else
printf("You should provide even number.");
}

int isPrime(int num){                               /* Asal say� bulan fonksiyonumu deklare ettim */

    int counter, status;                            /* Fonksiyonumda kullanaca��m tan�mlay�c�lar� deklare ettim */
    if(num<2){                                      /* 2'den k���k say�lar asal say� olmayaca��ndan: */
        status = 0;                                 /* Return edece�im de�eri 0'a e�itledim */
    }
    else{                                           /* Say� 2'den b�y�kse */
        status = 1;                                 /* Return edece�im de�eri 1'e e�itledim */
    }
    for(counter=2; counter<num; counter ++){        /* 2'den ba�layarak istenen say�n�n bir eksi�ine kadar kontrol edecek bir d�ng� yazd�m */
        if(num%counter==0){                         /* Kontrol etti�imiz say�y� d�ng� sayesinde kendinden eksik olan say�ya kadar olan say�lara tam b�l�n�p b�l�nmedi�ini kontrol ediyor */
            status = 0;                             /* E�er herhangi bir say�ya tam b�l�nm�� ise return edece�im de�eri 0'a e�itliyor */
            break;                                  /* Ve say� asal olmad���ndan d�ng�y� sonland�r�yor */
        }
    }
    return(status);                                 /* Say� asal ise 1, asal de�ilse 0 return ediliyor */
}

int goldbach(int num, int *p1, int *p2){
    int status, pnumber_1, pnumber_2;               /* Fonksiyonumda kullanaca��m tan�mlay�c�lar� deklare ettim */
    status = 0;
    pnumber_1 = 0;
    pnumber_2 = 0;
    if(num%2==1 || num<=2){                         /* E�er say� 2'ye tam b�l�nm�yorsa yada say� 2 ve 2'den k���kse Goldbach'a uymayaca��ndan status'u ve asal say�lar� 0 olarak return eder */
        *p1 = pnumber_1;
        *p2 = pnumber_2;
        return(status);
    }
     else{
        status = 1;
        pnumber_1 = 1;
        pnumber_2 = 1;
        while(1){                                   /* Break kullanana kadar devam edecek bir d�ng� yazd�m */
            while(pnumber_1<=num/2){                /* �lk say� Goldbach'taki kontrol etti�imiz say�n�n yar�s�na ula�ana kadar d�ng� devam eder */
                pnumber_1 ++;                       /* Say�y� birer birer artt�r�r */
                if(isPrime(pnumber_1)==1){          /* E�er ilk kontrol etti�imiz say� bir asal say�ysa d�ng�y� durdurur */
                    break;
                }
            }
            while(pnumber_2<=num-2){                /* �kinci say� Goldbach'taki kontrol etti�imiz say�n�n 2 eksi�ine ula�ana kadar d�ng� devam eder.*/
                pnumber_2 ++;                       /* Say�y� birer birer artt�r�r */
                if(isPrime(pnumber_2)==1 && num==pnumber_1+pnumber_2){  /* E�er say� bir asal say�ysa ve �nceki say�yla toplam� Goldbach'ta kontrol etti�imiz say�n�n toplam�na e�itse d�ng�y� durdurur */
                    *p1 = pnumber_1;
                    *p2 = pnumber_2;
                    break;
                }
            }
            if(num==pnumber_1+pnumber_2){           /* E�er say�lar�n toplam� Goldbach'taki kontrol etti�imiz say�ya e�itse while(1) d�ng�s�n� durdurur */
                break;
            }
            pnumber_2 = 1;                          /* Say�lar�n toplam� Goldbach'taki kontrol etti�imiz say�ya e�it de�ilse ba�ka say�lar denemek i�in ikinci say�y� 1'e e�itliyorum */
        }
        return(status);                             /* Say�m�z Goldbach'a uydu�undan status'taki 1 de�erini return ediyorum */
    }
}
