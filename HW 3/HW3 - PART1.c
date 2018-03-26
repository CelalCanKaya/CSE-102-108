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

int isPrime(int num){                               /* Asal sayý bulan fonksiyonumu deklare ettim */

    int counter, status;                            /* Fonksiyonumda kullanacaðým tanýmlayýcýlarý deklare ettim */
    if(num<2){                                      /* 2'den küçük sayýlar asal sayý olmayacaðýndan: */
        status = 0;                                 /* Return edeceðim deðeri 0'a eþitledim */
    }
    else{                                           /* Sayý 2'den büyükse */
        status = 1;                                 /* Return edeceðim deðeri 1'e eþitledim */
    }
    for(counter=2; counter<num; counter ++){        /* 2'den baþlayarak istenen sayýnýn bir eksiðine kadar kontrol edecek bir döngü yazdým */
        if(num%counter==0){                         /* Kontrol ettiðimiz sayýyý döngü sayesinde kendinden eksik olan sayýya kadar olan sayýlara tam bölünüp bölünmediðini kontrol ediyor */
            status = 0;                             /* Eðer herhangi bir sayýya tam bölünmüþ ise return edeceðim deðeri 0'a eþitliyor */
            break;                                  /* Ve sayý asal olmadýðýndan döngüyü sonlandýrýyor */
        }
    }
    return(status);                                 /* Sayý asal ise 1, asal deðilse 0 return ediliyor */
}

int goldbach(int num, int *p1, int *p2){
    int status, pnumber_1, pnumber_2;               /* Fonksiyonumda kullanacaðým tanýmlayýcýlarý deklare ettim */
    status = 0;
    pnumber_1 = 0;
    pnumber_2 = 0;
    if(num%2==1 || num<=2){                         /* Eðer sayý 2'ye tam bölünmüyorsa yada sayý 2 ve 2'den küçükse Goldbach'a uymayacaðýndan status'u ve asal sayýlarý 0 olarak return eder */
        *p1 = pnumber_1;
        *p2 = pnumber_2;
        return(status);
    }
     else{
        status = 1;
        pnumber_1 = 1;
        pnumber_2 = 1;
        while(1){                                   /* Break kullanana kadar devam edecek bir döngü yazdým */
            while(pnumber_1<=num/2){                /* Ýlk sayý Goldbach'taki kontrol ettiðimiz sayýnýn yarýsýna ulaþana kadar döngü devam eder */
                pnumber_1 ++;                       /* Sayýyý birer birer arttýrýr */
                if(isPrime(pnumber_1)==1){          /* Eðer ilk kontrol ettiðimiz sayý bir asal sayýysa döngüyü durdurur */
                    break;
                }
            }
            while(pnumber_2<=num-2){                /* Ýkinci sayý Goldbach'taki kontrol ettiðimiz sayýnýn 2 eksiðine ulaþana kadar döngü devam eder.*/
                pnumber_2 ++;                       /* Sayýyý birer birer arttýrýr */
                if(isPrime(pnumber_2)==1 && num==pnumber_1+pnumber_2){  /* Eðer sayý bir asal sayýysa ve önceki sayýyla toplamý Goldbach'ta kontrol ettiðimiz sayýnýn toplamýna eþitse döngüyü durdurur */
                    *p1 = pnumber_1;
                    *p2 = pnumber_2;
                    break;
                }
            }
            if(num==pnumber_1+pnumber_2){           /* Eðer sayýlarýn toplamý Goldbach'taki kontrol ettiðimiz sayýya eþitse while(1) döngüsünü durdurur */
                break;
            }
            pnumber_2 = 1;                          /* Sayýlarýn toplamý Goldbach'taki kontrol ettiðimiz sayýya eþit deðilse baþka sayýlar denemek için ikinci sayýyý 1'e eþitliyorum */
        }
        return(status);                             /* Sayýmýz Goldbach'a uyduðundan status'taki 1 deðerini return ediyorum */
    }
}
