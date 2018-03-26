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

char readChar()
{
    char charValue;
    scanf("%c", &charValue);
    return(charValue);
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

void printPersonalInfo(int id, char name, int height, double weight){
    double BMI;
    BMI = calculateBMI(height, weight);
    printf("Id:%d\n", id);
    printf("Name:%c\n", name);
    printf("Height:%dcm\n", height);
    printf("Weight:%.2fkg\n", weight);
    printf("BMI:%.2f\n", BMI);

}

void getAndPrintPersonalInfo(){
    int id;
    char name;
    int height;
    double weight;
    double BMI;
    id = readInt();
    name = readChar();
    height = readInt();
    weight = readDouble();
    BMI = calculateBMI(height, weight);
    printf("Id:%d", id);
    printf("Name:%c", name);
    printf("Height:%d", height);
    printf("Weight:%f", weight);
    printf("BMI:%f", BMI);
    printPersonalInfo(id,name,height,weight);


}
