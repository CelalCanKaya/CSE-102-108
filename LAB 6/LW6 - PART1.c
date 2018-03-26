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


char* interleave(char str1[], char str2[], char res[]){
	int str1len, str2len, counter, x;
	str1len = strnlen(str1);
	str2len = strnlen(str2);
	if(str1len>=str2len){
		for(counter=0; counter<str2len; counter ++){
			res[counter*2]=str1[counter];
			res[counter*2 + 1]=str2[counter];
		}
		for(counter=0, x=0; counter<str1len-str2len+1; counter ++, x ++){
			res[((str2len-1)*2)+x] = str1[str2len-1+x];
		}
	}
	if(str2len>str1len){
		for(counter=0; counter<str1len; counter ++){
			res[counter*2]=str1[counter];
			res[counter*2 + 1]=str2[counter];
		}
		for(counter=0, x=0; counter<str2len-str1len+1; counter ++, x ++){
			res[((str1len-1)*2)+x] = str2[str1len-1+x];
		}
	}
	return res;
}
