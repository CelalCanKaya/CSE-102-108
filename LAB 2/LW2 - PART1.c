double mean (){
    double number,total_number,final_result;
    int counter, finish_loop;
    counter = 0;
    total_number = 0;
    finish_loop = 0;
    while(finish_loop==0) {

        scanf("%lf", &number);

        if(number>0) {
            counter = counter + 1 ;
            total_number = total_number + number;
        }

	else {
	       if(counter==0){
            counter = counter + 1;
            }
            final_result = total_number / counter;
            finish_loop = 1;

        }
        }

            return(final_result);

}
