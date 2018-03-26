#include<stdio.h>

void alphabeticalSort(char* arr, int size){
	int i, j;
	char temp;
	for(i=1; i<size; i ++){
		j=i;
		while(j>0 && arr[j-1]>arr[j]){
			temp=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=temp;
			j = j-1;
		}
	}
}

int main(){
	int i;
	char arr[] = {'m', 'e', 'r', 'h', 'a', 'b', 'a', 'a', 'l', 'i'};
	alphabeticalSort(arr,10);
	for(i = 0; i<10; i ++)
		printf("%c", arr[i]);
	printf("\n");
}

