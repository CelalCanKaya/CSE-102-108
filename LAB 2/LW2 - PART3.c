/* YANLIŞ HATIRLAMIYOSAM BU KOD TÜM TESTLERDEN GEÇMİYODU */

double maxSumOfIncSeq(){
    double number, prev_number, total_number, zero;
    int maximum_seq_counter, counter, set_first_number, finish_loop;
    maximum_seq_counter = 0;
    finish_loop = 0;
    zero = 0.0;
    counter = 0;
    set_first_number = 0;
    total_number = 0;
    while (finish_loop==0){
        scanf("%lf", &number);
        if(number>zero){
            if(set_first_number==0){
                prev_number = number;
                set_first_number = 1;}
            if(prev_number<number){
                counter += counter;
                total_number = prev_number + number;
        }
            else{
                if(maximum_seq_counter<counter){
                    maximum_seq_counter = counter;}
            counter = 0;
                }}

        else{
            finish_loop = 1;
        }}

        return(total_number);
}
