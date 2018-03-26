/* BU KODDA SAYILARI ROMEN SAYILARINA ÇEVÝREN FONKSÝYON YOK. SADECE ÝKÝ STRING'I BÝRBÝRÝNE EKLEYEN APPEND FONKSÝYONU VAR */

int strnlen(char str[]){
	int counter, lencounter;
	char element;
	lencounter=0;
	for(counter=0, element=' '; element!='\0'; counter ++){
		element=str[counter];
		lencounter ++;
	}
	return lencounter;
}

char* append(char str1[], char str2[]){
	int str1len, str2len, counter, x;
	str1len = strnlen(str1);
	str2len = strnlen(str2);
	for(counter=0, x=0; counter<str2len; counter ++, x ++){
		str1[str1len-1+x]=str2[counter];
	}
	return str1;
}

