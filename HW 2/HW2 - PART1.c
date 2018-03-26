#include<stdio.h>

int fTheFunction(int x,int functionNumber);
void drawFunction(int xAxis,int yAxis,int functionNumber);

int main(){
    drawFunction(40,40, 2);
}

int fTheFunction(int x,int functionNumber){
    int y;
    if(functionNumber==1){
        y = 2*x;
        return(y);}
    if(functionNumber==2){
        y = x;
        return(y);
        }



void drawFunction(int xAxis,int yAxis,int functionNumber){
    int y, x_axis_counter, y_axis_counter, x, counter;  /* Fonksiyonumda kullanacaðým tanýmlayýcýlarý deklare ettim */
    x_axis_counter = 0;                                 /* "x_axis_counter" deðerini 0 olarak atadým */
    y_axis_counter = 0;                                 /* "y_axis_counter" deðerini 0 olarak atadým */
    while(y_axis_counter<yAxis){                        /* Bu döngü y eksenini bastýrýyor */
        if(y_axis_counter==yAxis-1){                    /* Burda kullandýðým "if" sayesinde y ekseninin sonunda yeni satýra geçmeyecek */
            printf("|");
            y_axis_counter ++;
        }
        else{                                           /* "Else" yukarda olan "if" son satýra etki ettiði için geri kalan satýrlarý yazdýrmamý saðlýyor */
            printf("|");
            for(x=1; x<xAxis; x ++){                    /* "for" loopu sayesinde x deðeri x ekseninden küçük olduðu sürece döngü devam edicek */
                y = fTheFunction(x,functionNumber);     /* Döngüden gelen x deðeri ve fonksiyonun parametresinden gelen "functionNumber" deðerlerini "fTheFunction" fonksiyonu için kullanarak y deðerlerini bulacak */
                if(y==yAxis-y_axis_counter){            /* Buradaki "if" i eðer "y" deðeri y ekseninin uzunluðunun y eksenindeki satýr sayacýnýnýn farkýndan büyükse olacak þeyleri belirtmek için kullandým */
                    for(counter = 0; counter < x-1; counter ++){   /* "for" döngüsü sayesinde "counter" deðeri "x-1" deðerinden küçük olduðu sürece devam edecek */
                        printf(" ");                               /* Boþluk býrakmamý saðlýyor */
                    }
                    printf("*");                                   /* Yeterince boþluk býraktýktan sonra "*" basmamý saðlýyor */
                }
            }
            printf("\n");                                         /* Yeni satýra geçmemizi saðlýyor */
            y_axis_counter ++;}                                   /* "While" loopunu sonlandýrmam için y_axis_counter deðerini 1 arttýrýyorum */
}
        while(x_axis_counter<xAxis){                              /* Bu döngü x eksenini ekrana basýyor */
        printf("-");                                              /* "-" karakterini ekrana basýyor */
        x_axis_counter ++;}}                                      /* Döngünün sonlanmasý için "x_axis_counter" deðerini 1 arttýrýyorum */


