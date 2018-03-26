double testResults(int questionNumbersArr[], int qNArrSize, char answersArr[], int ansArrSize, char keysArr[], int keysArrSize){
    /*12 ve 13. satýrlarda fonksiyonumda kullanacaðým tanýmlayýcýlarý  deklare ettim. */
	int counter, trueAns, falseAns, totalAns;
	double result;
	/* 14, 15 ve 16. satýrlarda kullanacaðým deðerleri initialize ettim. */
	totalAns=keysArrSize;
	trueAns=0;
	falseAns=0;
	/* Bu döngü sayesinde doðru ve yanlýþ cevap sayýlarýný hesap ettim */
	for(counter=0; counter<ansArrSize; counter ++){
		if(answersArr[counter]==keysArr[questionNumbersArr[counter]-1]){    /* Eðer cevabým, cevap anahtarýndaki cevapla uyuþuyorsa: */
			trueAns ++;                                                     /* Doðru cevabý 1 arttýr. */
		}
		else{                                                               /* Deðilse: */
			falseAns ++;                                                    /* Yanlýþ cevabý bir arttýr */
		}
	}
	result = calculateResult(trueAns, falseAns, totalAns);                  /* Doðru, yanlýþ ve toplam cevap sayýlarýný parametre olarak alýp net sayýsýný hesaplar */
	return result;                                                          /* Hesapladýðýmýz net sayýsýný return eder */
}

double calculateResult(int trueAns, int falseAns, int totalAns){
	double qPoint, result;
	qPoint = 1.0/totalAns;                                                  /* qPoint = Soru baþýna düþen puan */
	result = (trueAns*qPoint) - (falseAns*(qPoint/4));                      /* Doðru sayýsýný soru baþýna düþen puanla çarptýktan sonra yanlýþ sayýsýnýda soru baþýna düþen puanýný 4'e bölüp farklarýný aldým. */
	return result;                                                          /* Sonucu return ettim */
}
