double testResults(int questionNumbersArr[], int qNArrSize, char answersArr[], int ansArrSize, char keysArr[], int keysArrSize){
    /*12 ve 13. sat�rlarda fonksiyonumda kullanaca��m tan�mlay�c�lar�  deklare ettim. */
	int counter, trueAns, falseAns, totalAns;
	double result;
	/* 14, 15 ve 16. sat�rlarda kullanaca��m de�erleri initialize ettim. */
	totalAns=keysArrSize;
	trueAns=0;
	falseAns=0;
	/* Bu d�ng� sayesinde do�ru ve yanl�� cevap say�lar�n� hesap ettim */
	for(counter=0; counter<ansArrSize; counter ++){
		if(answersArr[counter]==keysArr[questionNumbersArr[counter]-1]){    /* E�er cevab�m, cevap anahtar�ndaki cevapla uyu�uyorsa: */
			trueAns ++;                                                     /* Do�ru cevab� 1 artt�r. */
		}
		else{                                                               /* De�ilse: */
			falseAns ++;                                                    /* Yanl�� cevab� bir artt�r */
		}
	}
	result = calculateResult(trueAns, falseAns, totalAns);                  /* Do�ru, yanl�� ve toplam cevap say�lar�n� parametre olarak al�p net say�s�n� hesaplar */
	return result;                                                          /* Hesaplad���m�z net say�s�n� return eder */
}

double calculateResult(int trueAns, int falseAns, int totalAns){
	double qPoint, result;
	qPoint = 1.0/totalAns;                                                  /* qPoint = Soru ba��na d��en puan */
	result = (trueAns*qPoint) - (falseAns*(qPoint/4));                      /* Do�ru say�s�n� soru ba��na d��en puanla �arpt�ktan sonra yanl�� say�s�n�da soru ba��na d��en puan�n� 4'e b�l�p farklar�n� ald�m. */
	return result;                                                          /* Sonucu return ettim */
}
