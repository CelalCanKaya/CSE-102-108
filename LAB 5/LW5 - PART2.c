double calculateResult(int trueAns, int falseAns, int totalAns){        /* �nceki fonksiyonda yazd���m puan hesaplama fonksiyonum */
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
	/* Bu k�s�mda keysArr arrayini answerArr'daki gibi bir optik forma d�kt�m */
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
	/* Optik forma d�n��t�rme i�lemi burada bitti. Alttaki d�ng�mle beraber iki optik formu birbirleriyle kar��la�t�r�yorum. */
	for(counter=0; counter<qNArrSize; counter ++){
		for(counter2=0, markedans=0; counter2<5; counter2 ++){
				if(questionNumbersArr[counter][counter2]=='*')
				markedans ++;
		}
		if(markedans>1){    /* E�er birden fazla cevap var ise yanl�� cevap say�s�n� 1 artt�r�yo ve alt tarafta else if kulland���m i�in o k�sma girmeden di�er soruyu kontrole ge�iyor */
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
