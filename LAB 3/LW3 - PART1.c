int getMinAndMax(int *min, int *max){
	int number, minimum, maximum, status;
	status = 0;
	minimum = 0;
	maximum = 0;
	scanf("%d", &number);
	if(number>0){
	maximum = number;
	minimum = number;
	while(number>0){
		scanf("%d", &number);
		if(number<0){
			break;
		}
		if(number>maximum){
			maximum = number;

		}
		if(number<minimum){
			minimum = number;
		}
	}
	}
	else if(number<0){
		status = -1;
	}
    *min = minimum;
	*max = maximum;

	return(status);


}
