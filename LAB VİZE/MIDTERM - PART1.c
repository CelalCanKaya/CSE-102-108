#include <stdio.h>

int ifind(char haystack[], char needle[]);
int icount(char haystack[], char needle[]);
int strnglen(char str[]);

int main(){
	char haystack[255]= "dehedehedehede", needle[255]="hede";
	printf("Position: %d, Count: %d. Needle: %s Haystack: %s\n", ifind(haystack,needle), icount(haystack,needle), needle, haystack);
	return 0;

}

int ifind(char haystack[], char needle[]){
	int hayleng, needleng, counter, counter2, position, count, status;
	position=1000000;
	counter2=0;
	status=1;
	count=0;
	hayleng=strnglen(haystack);
	needleng=strnglen(needle);
	for(counter=0; counter<hayleng; counter++){
		if(haystack[counter]>='A' && haystack[counter]<='Z')
			haystack[counter]=haystack[counter]+32;
	}
	for(counter=0; counter<needleng; counter++){
		if(needle[counter]>='A' && needle[counter]<='Z')
			needle[counter]=needle[counter]+32;
	}

	while(counter2<=(hayleng-needleng)){

		if(haystack[counter2]==needle[0]){
			for(counter=0; counter<needleng; counter++){
				if(haystack[counter2+counter]!=needle[counter]){
					status=0;
				}
			}
			if(status==1 && position==1000000){
				position=counter2;
			}
			if(status==1){
				count ++;
				counter2 = counter2 + needleng-1;
			}
		}
		counter2 ++;
		status=1;
	}
	if(status==1 && position==1000000){
		position=-1;
	}
	return position;
}

int icount(char haystack[], char needle[]){
	int hayleng, needleng, counter, counter2, position, count, status;
	position=1000000;
	counter2=0;
	status=1;
	count=0;
	hayleng=strnglen(haystack);
	needleng=strnglen(needle);
	for(counter=0; counter<hayleng; counter++){
		if(haystack[counter]>='A' && haystack[counter]<='Z')
			haystack[counter]=haystack[counter]+32;
	}
	for(counter=0; counter<needleng; counter++){
		if(needle[counter]>='A' && needle[counter]<='Z')
			needle[counter]=needle[counter]+32;
	}

	while(counter2<=(hayleng-needleng)){
		if(haystack[counter2]==needle[0]){
			for(counter=0; counter<needleng; counter++){
				if(haystack[counter2+counter]!=needle[counter]){
					status=0;
				}
			}
			if(status==1 && position==1000000){
				position=counter2;
			}
			if(status==1){
				count ++;
				counter2 = counter2 + needleng -1;
			}
		}
		counter2 ++;
		status=1;
	}
	return count;

}


int strnglen(char str[]){
	int counter;
	for(counter=0; str[counter]!='\0'; counter++){
		counter++;
	}
	return counter;

}
