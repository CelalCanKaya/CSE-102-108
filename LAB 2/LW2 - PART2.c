double minimum(){
    double number, minimum_number, zero;
    int finish_loop, set_minimum_number;
    finish_loop = 0;
    zero = 0.0;
    set_minimum_number = 0;
    while(finish_loop==0){
        scanf("%lf", &number);
        if(number>zero){
            if(set_minimum_number==0){
                minimum_number = number;
                set_minimum_number = 1;}
            else if(minimum_number>number){
                minimum_number = number;
               }
            }

       else{
            finish_loop = 1;
            }

                        }
    return(minimum_number);

    }


double maximum(){
    double number, maximum_number, zero;
    int finish_loop, set_maximum_number;
    finish_loop = 0;
    zero = 0.0;
    set_maximum_number = 0;
    while(finish_loop==0){
        scanf("%lf", &number);
        if(number>zero) {
            if(set_maximum_number==0){
                maximum_number = number;
                set_maximum_number = 1;}
            else if(maximum_number<number){
                maximum_number = number;
               }
            }

       else{
            finish_loop = 1;

            }
                     }
    return(maximum_number);
    }
