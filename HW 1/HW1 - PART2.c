/* This code is calculates the diameter of the tree and age of the tree */

#define PI 3.14                                                     /* I defined the pi because it is a fixed value */

float diameter(float circumference){                                /* I declared a function for calculating the circumference of the tree */
float radius, diameter_of_the_tree;                                 /* I declared the identifiers for use them in this function */
radius = (circumference / (2 * PI));                                /* I wrote a formula which calculates the radius of the tree */
diameter_of_the_tree = (radius * 2);                                /* I wrote a formula which calculates the diameter of the tree */
return(diameter_of_the_tree);                                       /* This line returns the diameter of the tree */
}

float ageOfTree(float diameter , float growth_factor){              /* I declared a function for calculating the age of the tree */
float age_of_tree;                                                  /* I declared the identifier for use it in this function */
age_of_tree = diameter * growth_factor;                             /* I wrote a formula which calculates the age of the tree */
return(age_of_tree);                                                /* This line returns the age of the tree */
}

