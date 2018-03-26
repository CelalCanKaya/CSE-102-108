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
    int y, x_axis_counter, y_axis_counter, x, counter;  /* Fonksiyonumda kullanaca��m tan�mlay�c�lar� deklare ettim */
    x_axis_counter = 0;                                 /* "x_axis_counter" de�erini 0 olarak atad�m */
    y_axis_counter = 0;                                 /* "y_axis_counter" de�erini 0 olarak atad�m */
    while(y_axis_counter<yAxis){                        /* Bu d�ng� y eksenini bast�r�yor */
        if(y_axis_counter==yAxis-1){                    /* Burda kulland���m "if" sayesinde y ekseninin sonunda yeni sat�ra ge�meyecek */
            printf("|");
            y_axis_counter ++;
        }
        else{                                           /* "Else" yukarda olan "if" son sat�ra etki etti�i i�in geri kalan sat�rlar� yazd�rmam� sa�l�yor */
            printf("|");
            for(x=1; x<xAxis; x ++){                    /* "for" loopu sayesinde x de�eri x ekseninden k���k oldu�u s�rece d�ng� devam edicek */
                y = fTheFunction(x,functionNumber);     /* D�ng�den gelen x de�eri ve fonksiyonun parametresinden gelen "functionNumber" de�erlerini "fTheFunction" fonksiyonu i�in kullanarak y de�erlerini bulacak */
                if(y==yAxis-y_axis_counter){            /* Buradaki "if" i e�er "y" de�eri y ekseninin uzunlu�unun y eksenindeki sat�r sayac�n�n�n fark�ndan b�y�kse olacak �eyleri belirtmek i�in kulland�m */
                    for(counter = 0; counter < x-1; counter ++){   /* "for" d�ng�s� sayesinde "counter" de�eri "x-1" de�erinden k���k oldu�u s�rece devam edecek */
                        printf(" ");                               /* Bo�luk b�rakmam� sa�l�yor */
                    }
                    printf("*");                                   /* Yeterince bo�luk b�rakt�ktan sonra "*" basmam� sa�l�yor */
                }
            }
            printf("\n");                                         /* Yeni sat�ra ge�memizi sa�l�yor */
            y_axis_counter ++;}                                   /* "While" loopunu sonland�rmam i�in y_axis_counter de�erini 1 artt�r�yorum */
}
        while(x_axis_counter<xAxis){                              /* Bu d�ng� x eksenini ekrana bas�yor */
        printf("-");                                              /* "-" karakterini ekrana bas�yor */
        x_axis_counter ++;}}                                      /* D�ng�n�n sonlanmas� i�in "x_axis_counter" de�erini 1 artt�r�yorum */


