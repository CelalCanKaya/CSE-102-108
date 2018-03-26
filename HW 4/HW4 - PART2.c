#include<stdio.h>

typedef enum _paddingType { ZERO, HALF, SAME} PaddingType;
int convolution(double inputArr[], int inputArraySize, double kernelArr[], int
kernelArraySize, double outputArr[], int *outputArraySize, int stride, PaddingType
padding);
void zeroPadding(double outputArr[], int outputArraySize, int paddingWidth);
void samePadding(double outputArr[], int outputArraySize, int paddingWidth);
void halfPadding(double outputArr[], int outputArraySize, int paddingWidth);


int main(){
double inputArr[] = {1, 3, 5, 7, 9, 11, 13};
double kernelArr[] = {2, 4, 6};
double outputArr[255];
int outputArrSize = 0;
convolution(inputArr, 7, kernelArr, 3, outputArr, &outputArrSize, 2, ZERO);
}

int convolution(double inputArr[], int inputArraySize, double kernelArr[], int
kernelArraySize, double outputArr[], int *outputArraySize, int stride, PaddingType
padding){
    if(kernelArraySize>inputArraySize){
        return -1;
    }
    else{
        int paddingWidth, counter, counter2, temp, startingPoint;
        double product;
        double inputArrPadding[255];
        paddingWidth = (kernelArraySize-1)/2;
        *outputArraySize = ((inputArraySize-kernelArraySize+(2*paddingWidth))/stride) + 1;
        for(counter=0; counter<inputArraySize; counter ++){
            inputArrPadding[counter]=inputArr[counter];
        }
        for(counter=inputArraySize-1; counter>=0; counter --){
            temp = inputArrPadding[counter];
            inputArrPadding[counter+paddingWidth]=temp;
        }
        switch(padding){
            case ZERO:
                zeroPadding(inputArrPadding, *outputArraySize, paddingWidth);
                break;
            case HALF:
                halfPadding(inputArrPadding, *outputArraySize, paddingWidth);
                break;
            case SAME:
                samePadding(inputArrPadding, *outputArraySize, paddingWidth);
                break;
            default:
                return -1;
        }
        for(counter=0; counter<*outputArraySize; counter ++){
            outputArr[counter]=0;
        }
        for(counter=0, startingPoint=0; counter<*outputArraySize; counter ++){
               for(counter2=0; counter2<kernelArraySize; counter2 ++){
                    product = kernelArr[counter2]*inputArrPadding[counter2+startingPoint];
                    outputArr[counter]=outputArr[counter]+product;
                }

                startingPoint = startingPoint + stride;
        }
        for(counter=0; counter<*outputArraySize; counter ++){
            printf("%f\n", outputArr[counter]);
        }
    }
    return 0;
}

void samePadding(double inputArrPadding[], int inputArraySize, int paddingWidth){
    int counter;
    for(counter=0; counter<paddingWidth; counter ++){
        inputArrPadding[counter]=inputArrPadding[paddingWidth];
        inputArrPadding[inputArraySize+paddingWidth+counter]=inputArrPadding[inputArraySize+paddingWidth-1];
    }
}


void zeroPadding(double inputArrPadding[], int inputArraySize, int paddingWidth){
    int counter;
    for(counter=0; counter<paddingWidth; counter ++){
        inputArrPadding[counter]=0;
        inputArrPadding[inputArraySize+paddingWidth+counter]=0;
    }
}

void halfPadding(double inputArrPadding[], int inputArraySize, int paddingWidth){
    int counter;
    for(counter=0; counter<paddingWidth; counter ++){
        inputArrPadding[counter]=inputArrPadding[paddingWidth]/2;
        inputArrPadding[inputArraySize+paddingWidth+counter]=inputArrPadding[inputArraySize+paddingWidth-1]/2;
    }
}
