int readInt()
 {
    int intValue;
    scanf("%d", &intValue);
    return(intValue);

}

double readDouble()
{
    double doubleValue;
    scanf("%lf", &doubleValue);
    return(doubleValue);
}

double calculateBMI(int height, double weight){
    double height_m = height / 100.0;
    double BMI = weight / (height_m * height_m);
    return(BMI);
}


double getInfoAndCalculateBMI(){
    int height;
    double weight;
    double BMI;
    height = readInt();
    weight = readDouble();
    BMI = calculateBMI(height, weight);
    return(BMI);
    }
