/* This code is calculates the age of the user and  how many days left to user's birthday */

int theAge(int day,int month, int year, int today,int this_month, int this_year ){        /* I declared a function for calculating the age of the user */
    int total_days_until_birthday, total_days_until_today, the_age;                       /* I declared the identifiers for use them in the functions */
    total_days_until_birthday = day + month * 30 + year * 365;                            /* I calculated the total number of days until user's birthday */
    total_days_until_today = today + this_month * 30 + this_year * 365;                   /* I calculated the total number of days until today */
    the_age = (total_days_until_today - total_days_until_birthday) / 365;                 /* I wrote a formula which calculates the age of the user */
    printf("%d", the_age);                                                                /* This line is prints the age of the user */
    return(the_age);                                                                      /* This line is returns the age of the user */

}

int daysLeft(int day,int month, int today,int this_month){                                /* I declared a function for calculating how many days left to user's birthday */
    int total_days_until_birthday, total_days_until_today, days_left;            /* I declared the identifiers for use them in the functions */
    total_days_until_birthday  = (day + month*30) - 30;                                   /* I calculated the total number of days until user's birthday from New Year's Day */
    total_days_until_today = (today + this_month*30) - 30;                                /* I calculated the total number of days until today from New Year's Day */
    days_left = (((total_days_until_birthday - total_days_until_today) + 360 ) % 365);    /* I wrote a formula which calculates how many days left to user's birthday */
    printf("%d", days_left);                                                              /* This line is prints the how many days left to user's birthday */
    return(days_left);                                                                    /* This line is returns the how many days lefts to user's birthday */

}

