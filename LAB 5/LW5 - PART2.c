double calculateResult(int trueAns, int falseAns, int totalAns){        /* Önceki fonksiyonda yazdýðým puan hesaplama fonksiyonum */
	double qPoint, result;
	qPoint = 1.0/totalAns;
	result = (trueAns*qPoint) - (falseAns*(qPoint/4));
	return result;
}

double testResults2d(char questionNumbersArr[][5], int qNArrSize, char keysArr[], int keysArrSize){
	int counter, counter2, markedans, trueAns, falseAns,totalAns;
	double result;
	char keysArray[1000][5];
	totalAns=keysArrSize;
	trueAns = 0;
	falseAns = 0;
	/* Bu kýsýmda keysArr arrayini answerArr'daki gibi bir optik forma döktüm */
	for(counter=0; counter<qNArrSize; counter ++){
			for(counter2=0; counter2<5; counter2 ++){
			keysArray[counter][counter2]='-';
		}
			if(keysArr[counter]=='A'){
				keysArray[counter][0]='*';
			}
			if(keysArr[counter]=='B'){
				keysArray[counter][1]='*';
			}
			if(keysArr[counter]=='C'){
				keysArray[counter][2]='*';
			}
			if(keysArr[counter]=='D'){
				keysArray[counter][3]='*';
			}
			if(keysArr[counter]=='E'){
				keysArray[counter][4]='*';
			}
	}
	/* Optik forma dönüþtürme iþlemi burada bitti. Alttaki döngümle beraber iki optik formu birbirleriyle karþýlaþtýrýyorum. */
	for(counter=0; counter<qNArrSize; counter ++){
		for(counter2=0, markedans=0; counter2<5; counter2 ++){
				if(questionNumbersArr[counter][counter2]=='*')
				markedans ++;
		}
		if(markedans>1){    /* Eðer birden fazla cevap var ise yanlýþ cevap sayýsýný 1 arttýrýyo ve alt tarafta else if kullandýðým için o kýsma girmeden diðer soruyu kontrole geçiyor */
			falseAns ++;
		}
		else if(markedans==1){
			for(counter2=0; counter2<5; counter2 ++){
				if(questionNumbersArr[counter][counter2]=='*' && questionNumbersArr[counter][counter2]==keysArray[counter][counter2]){
					trueAns ++;
				}
				else if(questionNumbersArr[counter][counter2]=='*' && questionNumbersArr[counter][counter2]!=keysArray[counter][counter2]){
					falseAns ++;
				}
			}
		}

}
	result = calculateResult(trueAns, falseAns, totalAns);
	return result;
}
