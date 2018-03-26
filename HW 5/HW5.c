#include<stdio.h>
#define GRIDSIZE 4

typedef enum {mined,
empty,
flaggedMined,
flaggedEmpty,
closedEmpty,
closedMined,
}cell;

/* Burada fonksiyonlarımın prototiplerini yazdım */
void printGrid (cell grid[][GRIDSIZE]);
int openCell(cell grid[][GRIDSIZE], int x, int y);
void flagCell(cell grid[][GRIDSIZE], int x, int y);
int isCellEmpty(cell grid[][GRIDSIZE], int x, int y);
int isLocationLegal(int x, int y);
int asMain();
void initGrid(cell grid[][GRIDSIZE]);

int main(){
    int row, column, status, result, all_empty_cells_found, counter, counter2, move_counter;
    char operation;
    cell grid[GRIDSIZE][GRIDSIZE];          /* GRIDSIZE x GRIDSIZE boyutunda bir array tanımladım */
    initGrid(grid);                         /* Bu array, doldurmak için initgrid fonksiyonunu çağırdım */
    printf("How To Play?\n\n");
    printf("You will see the %d x %d gameboard.Each time you must enter row and column number between 0 and %d.\n", GRIDSIZE, GRIDSIZE, GRIDSIZE-1);
    printf("Then, you must enter a operation which is Open or Flag. Enter 'O' or 'o' to open a cell.Enter 'F' or 'f' to flag/unflag a cell.\n");
    printf("If you open a mined cell, you will lose the game.If you open all the empty cells you will win the game.\n");
    printf("While you are playing you will see the number of your moves.Try your best.\n\n");
    printf("GOOD LUCK!\n\n\n");
    move_counter=0;                         /* Yaptığımız hamle sayısını tutacak olan countera 0 atadım. */
    status=1;
    do{                                     /* Do-while döngüsünün başlangıcı */
    all_empty_cells_found=1;
    printf("\n***********");
    printf("\n*MOVES = %d*\n", move_counter);
    printf("***********\n");
    printGrid(grid);                        /* Oyun alanını ekrana basan fonksiyonu çağırdım */
    printf("Row; ");
    scanf("%d", &row);                      /* Kullanıcıdan satır değerini aldım */
    printf("Column: ");
    scanf("%d", &column);                   /* Kullanıcıdan sütun değerini aldım. */
    while(status==1){                       /* Bu döngü ile kullanıcının yazdığı operasyonları kontrol ettim*/
        printf("Operation[O or F]; ");
        scanf(" %c", &operation);           /* Yapılacak operasyonu kullanıcıdan istedim */
        switch(operation){                  /* Switch yapısıyla kullanılıcak operasyonu seçip o operasyona uygun fonksiyonları çağırdım ve eğer geçerli bir hamle ise hamle counterımı 1 arttırdım */
            case 'O':
                result=(openCell(grid,row,column));
                if(result==1){
                    move_counter ++;
                }
                status=0;
                break;
            case 'o':
                result=(openCell(grid,row,column));
                if(result==1){
                    move_counter ++;
                }
                status=0;
                break;
            case 'F':
                flagCell(grid,row,column);
                if(isLocationLegal(row, column)==1 && (grid[row][column]!=empty)){
                    move_counter ++;
                }
                status=0;
                break;
            case 'f':
                flagCell(grid,row,column);
                if(isLocationLegal(row, column)==1 && (grid[row][column]!=empty)){
                    move_counter ++;
                }
                status=0;
                break;
            default:                    /* Eğer geçerli bir operasyon girilmemişse uyarı yazısı gösteriyorum ve statusu değiştirmediğimm için kullanıcıdan yeni bir operasyon istemek için döngünün başına dönüyoruz */
                printf("\nPlease, enter a valid operation.'O' or 'o' for open cell, 'F' or 'f' for flag/unflag cell.\n");
            }
    }
    status=1;               /* Do-while döngüsü başa döndüğünde while döngüsüne tekrar girmesi için status'u 1'e eşitledim. */
    for(counter=0; counter<GRIDSIZE; counter ++){           /* Bu for döngüleriyle açılmamış empty cell olup olmadığını kontrol ettim. */
        for(counter2=0; counter2<GRIDSIZE; counter2 ++){
            if(grid[counter][counter2]==closedEmpty || grid[counter][counter2]==flaggedEmpty){
                all_empty_cells_found=0;
            }
        }
    }
    if(all_empty_cells_found==1){               /* Eğer bütün empty cell'ler açılmış ise ekrana gerekli mesajı bastırıp result değerini -3'e eşitleyerek do-while döngüsünün sonlanmasını sağladım. */
        printf("\nCONGRULATIONS! You Win The Game With %d Moves!\n", move_counter);
        printGrid(grid);
        result=-3;
    }
    }
    while(result!=-3);                          /* do-while döngüsü result -3'e eşit olduğu sürece devam edecek */
    return 0;                                   /* asMain fonksiyonu bir return değeri beklediğinden 0 return ettim. */
}

void printGrid (cell grid[][GRIDSIZE]){
    int counter_x, counter_y, counter;
    for(counter_x=0; counter_x<GRIDSIZE; counter_x ++){             /* Burada for döngüleriyle ızgaramın bir kısmını bastırdım */
        printf("\n");
        for(counter=0; counter<GRIDSIZE; counter ++){
            printf(" -----");
        }
        printf("\n");
        printf("|");
        for(counter_y=0; counter_y<GRIDSIZE; counter_y ++){         /* Burada for döngüsüyle kullanıcıya gösterilcek oyun alanı için cell içindeki değerlere karşılık gelen karakterleri bastırdım */
            if(grid[counter_x][counter_y]==empty){
                printf("  e  |");
            }
            if(grid[counter_x][counter_y]==flaggedEmpty || grid[counter_x][counter_y]==flaggedMined){
                printf("  f  |");
            }
            if(grid[counter_x][counter_y]==closedEmpty || grid[counter_x][counter_y]==closedMined){
                printf("  .  |");
            }
            if(grid[counter_x][counter_y]==mined){
                printf("  m  |");
            }
        }
    }
    printf("\n");
        for(counter=0; counter<GRIDSIZE; counter ++){       /* Bu for döngüsüyle ızgaramın en alt kısmını bastırdım */
            printf(" -----");
        }
    printf("\n\n");
}

int isLocationLegal(int x, int y){                  /* Bu fonksiyonla girilen satır sütun değerlerinin ızgaranın içinde olup olmadığını kontrol ediyorum */
    if(x>=GRIDSIZE || x<0 || y>=GRIDSIZE || y<0){
        return 0;
    }
    else{
        return 1;
    }
}

int isCellEmpty(cell grid[][GRIDSIZE], int x, int y){          /* Bu fonksiyonla girilen satır sütun değerlerine karşılık gelen hücrenin closedEmpty olup olmadığını kontrol ettim */
    if(grid[x][y]==closedEmpty){
        return 1;
    }
    else{
        return 0;
    }
}

int openCell(cell grid[][GRIDSIZE], int x, int y){
    int counter, counter2;
    if(isLocationLegal(x,y)==0 || grid[x][y]==flaggedMined || grid[x][y]==flaggedEmpty || grid[x][y]==empty){           /* Eğer girilen satır ve sütun değerlerindeki hücre açılamıyorsa hata mesajını basıp -2 return ediyorum */
            printf("\nPlease, Enter a Valid Location!\n");
            return -2;
    }
    else{
        if(grid[x][y]==closedMined){                        /* Eğer girilen satır ve sütun değerindeki hücre mayınlı ise mesaj bastırıp closedMined hücreleri mined'a çevirip kullanıcının mayınların nerde olduğunu görmesini sağlıyorum */
            printf("\n\n\nYOU LOST! YOU HIT THE MINE!\n");
            for(counter=0; counter<GRIDSIZE; counter ++){               /* Bu döngü ile closedMined'ları mined'a çeviriyorum.Bu sayede printGrid fonksiyonu kullanıcıya mayınların yerini gösteriyor. */
                for(counter2=0; counter2<GRIDSIZE; counter2 ++){
                    if(grid[counter][counter2]==closedMined || grid[counter][counter2]==flaggedMined){
                        grid[counter][counter2]=mined;
                    }
                }
            }
            printGrid(grid);
            return -3;                      /* Mayına bastığı için main'deki do-while döngüsü sonlansın diye -3 return ediyorum */
        }
        else{
            grid[x][y]=empty;               /* Yukardaki conditionlar gerçekleşmediği takdirde girilen satır ve sütundaki hücreyi empty yapıyorum */
            for(counter=-1; counter<2; counter ++){         /* Buradaki for döngüleriyle açılan hücrenin etrafındaki hücreleri kontrol ediyorum */
                for(counter2=-1; counter2<2; counter2 ++){
                    if(isLocationLegal(x+counter,y+counter2)==1 && isCellEmpty(grid, x+counter, y+counter2)==1){
                        grid[x+counter][y+counter2]=empty;
                    }
                }
            }
        }
        return 1;                       /* openCell fonksiyonum doğru çalıştığı için 1 return ediyorum */
    }
}

void flagCell(cell grid[][GRIDSIZE], int x, int y){
    if(isLocationLegal(x,y)==1 && grid[x][y]==closedEmpty){             /* Eğer girilen satır ve sütun değeri oyun alanının içindeyse ve closedEmpty ise flaggedEmpty'e çeviriyorum */
        grid[x][y]=flaggedEmpty;
    }
    else if(isLocationLegal(x,y)==1 && grid[x][y]==closedMined){        /* Eğer girilen satır ve sütun değeri oyun alanının içindeyse ve closedMined ise flaggedMined'e çeviriyorum */
        grid[x][y]=flaggedMined;
    }
    else if(isLocationLegal(x,y)==1 && grid[x][y]==flaggedEmpty){       /* Eğer girilen satır ve sütun değeri oyun alanının içindeyse ve flaggedEmpty ise closedEmpty'e çeviriyorum */
        grid[x][y]=closedEmpty;
    }
    else if(isLocationLegal(x,y)==1 && grid[x][y]==flaggedMined){       /* Eğer girilen satır ve sütun değeri oyun alanının içindeyse ve flaggedMined ise closedMined'e çeviriyorum */
        grid[x][y]=closedMined;
    }
    else if(isLocationLegal(x,y)==0){                                   /* Eğer girilen satır ve sütun değeri oyun alanının içinde değilse uyarı mesajı bastırıyorum */
        printf("\nPlease, Enter a Valid Location!\n");
    }
}

void initGrid(cell grid[][GRIDSIZE]){
    int counter, counter2;
    for(counter=0; counter<GRIDSIZE; counter++){                /* Buradaki for döngüleriyle oyun alanımın bütün hücrelerini closedEmpty'e eşitliyorum */
        for(counter2=0; counter2<GRIDSIZE; counter2++){
        grid[counter][counter2]=closedEmpty;
        }
    }

    /* Burada ise bütün hücreler closedEmpty olduğu için seçtiğim bölgelerdeki closedEmpty hücreleri closedMined ile değiştiriyorum */
    grid[3][2]=closedMined;
    grid[1][1]=closedMined;
    grid[0][3]=closedMined;

}

