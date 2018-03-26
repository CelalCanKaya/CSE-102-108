/* BU KOD BAZI TESTLERDEN GEÇMÝYO DÝYE HATIRLIYORUM */

int getMaxExp(){
	int number, number_2, counter, max_number, real_number;
	scanf("%d", &number);
	if(number<0){
	    max_number = -1;
	}
    while(number>0){
		scanf("%d", &number_2);
		if(number_2>0){
			real_number = number;
		for(counter=1; counter<number_2; counter ++){
			number = (number * real_number);
		}}
		else{
			number = number * -1;
			max_number = number;
			break;
        }
		if(number>max_number){
			max_number = number;
		}
		scanf("%d", &number);

	}
	return(max_number);


}
