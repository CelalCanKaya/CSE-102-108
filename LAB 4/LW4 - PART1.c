#include<stdio.h>

	typedef enum{MIN=1, MAX=2, SUM=3} operation;
	int arrOp(int *arr, int size, operation op){
		if(size==0){
			return(-3456);
		}

		else if(op==MIN){
			int min_number,counter;
			min_number=arr[0];
			for(counter=0; counter<size; counter ++){
				if(arr[counter]<min_number){
					min_number = arr[counter];
				}
			}
			return(min_number);
		}
		else if(op==MAX){
			int max_number,counter;
			max_number=arr[0];
			for(counter=0; counter<size; counter ++){
				if(arr[counter]>max_number){
					max_number = arr[counter];
				}
			}
			return(max_number);
		}
		else if(op==SUM){
			int sum_number,counter;
			sum_number = arr[0];
			for(counter=1; counter<size; counter ++){
				sum_number = sum_number + arr[counter];
			}
			return(sum_number);
		}
		if(op!=MIN || op!=MAX || op!=SUM){
			return(-9876);
		}
		return -99;
	}


int main(){
	int x,y,z;
	int array[] = {1,2,3,4,5,6,7,-99,200}, size = 9;
	x = arrOp(array, size, MAX);
	y = arrOp(array, size, MIN);
	z = arrOp(array, size, SUM);
	printf("%d\n%d\n%d\n", x,y,z);
	return 0;
}
