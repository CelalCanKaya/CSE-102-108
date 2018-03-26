#include <stdio.h>

void addPadding(double inputArr[], int inputArraySize, double outputArr[], int *outputArraySize, int paddingWidth, void paddingMethod(double[], int, int));
void zeroPadding(double outputArr[], int outputArraySize, int paddingWidth);
void samePadding(double outputArr[], int outputArraySize, int paddingWidth);
void halfPadding(double outputArr[], int outputArraySize, int paddingWidth);

int main(){
double inputArr[] = {5, 6, 7, 8, 9};
double outputArr[255];
int outputArraySize = 3;
addPadding(inputArr, 5 , outputArr, &outputArraySize, 4, halfPadding);
}

void addPadding(double inputArr[], int inputArraySize, double outputArr[], int
*outputArraySize, int paddingWidth, void paddingMethod(double[], int, int)){
    int counter, temp;
    *outputArraySize = inputArraySize + (paddingWidth*2);
    for(counter=0; counter<inputArraySize; counter ++){
        outputArr[counter]=inputArr[counter];
    }
    for(counter=inputArraySize-1; counter>=0; counter --){
        temp = outputArr[counter];
        outputArr[counter+paddingWidth]=temp;
    }
    paddingMethod(outputArr, *outputArraySize, paddingWidth);

    for(counter=0; counter<*outputArraySize; counter ++){
        printf("%.2f ", outputArr[counter]);
    }
}

void samePadding(double outputArr[], int outputArraySize, int paddingWidth){
    int counter;
    for(counter=0; counter<paddingWidth; counter ++){
        outputArr[counter]=outputArr[paddingWidth];
        outputArr[outputArraySize-counter-1]=outputArr[outputArraySize-paddingWidth-1];
    }
}

void zeroPadding(double outputArr[], int outputArraySize, int paddingWidth){
    int counter;
    for(counter=0; counter<paddingWidth; counter ++){
        outputArr[counter]=0;
        outputArr[outputArraySize-counter-1]=0;
    }
}

void halfPadding(double outputArr[], int outputArraySize, int paddingWidth){
    int counter;
    for(counter=0; counter<paddingWidth; counter ++){
        outputArr[counter]=outputArr[paddingWidth]/2;
        outputArr[outputArraySize-counter-1]=outputArr[outputArraySize-paddingWidth-1]/2;
    }
}
