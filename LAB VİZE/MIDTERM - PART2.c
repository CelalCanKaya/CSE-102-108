#include<stdio.h>

char* reverse(char str[], char rev[]);
int strnglen(char str[]);
/*char* tostr(int num, char str[]);*/
char *combine(char str1[], char str2[], char str3[], char res[]);


int main(){
	char str[255] = "herhalde5314513451345423636535756745684678467564634653546346546", str2[255]="turta", str3[255]="donmus", res[255];
	/*int dec = 65109;*/
	printf("reverse of %s: %s\n", str, reverse(str, res) );
	/*printf("tostr(%d):%s\n", dec, tostr(dec, res) );*/
	printf("combine(%s, %s, %s):%s\n", str,str2,str3,combine(str,str2,str3,res));
	return 0;

}

char* reverse(char str[], char rev[]){
	int counter, x;
	x = strnglen(str);
	for(counter=0; counter<x; counter++){
		rev[x-counter-1]=str[counter];
	}
	return rev;
}

int strnglen(char str[]){
	int counter;
	for(counter=0; str[counter]!='\0'; counter++){
		counter++;
	}
	return counter;

}

char *combine(char str1[], char str2[], char str3[], char res[]){
	int counter, c1, c2, c3, s1, s2, s3;
	counter=0;
	s1=1;
	s2=1;
	s3=1;
	c1=0;
	c2=0;
	c3=0;
	while(s1!=0 || s2!=0 || s3!=0){
		if(s1!=0){
			if(str1[c1]=='\0'){
				s1=0;
			}
			else{
			res[counter]=str1[c1];
			c1 ++;
			counter ++;
			}
		}
		if(s2!=0){
			if(str2[c2]=='\0'){
				s2=0;
			}
			else{
			res[counter]=str2[c2];
			c2 ++;
			counter ++;
			}
		}
		if(s3!=0){
			if(str3[c3]=='\0'){
				s3=0;
			}
			else{
			res[counter]=str3[c3];
			c3 ++;
			counter ++;
			}
		}
	}
	res[counter]='\0';
	return res;
}



/*
char* tostr(int num, char str[]){
	char temp;

	return str;
}
*/
