#include <stdio.h>
#include <ctype.h>

int main(){
    double og_temp;
    printf("Enter the temperature value: ");
    scanf("%lf", &og_temp);

    char og_scale;
    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &og_scale);

    char new_scale;
    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &new_scale);

    //convert all to celcius
    if(toupper(og_scale)=='F'){
        og_temp = (og_temp-32)/1.8;
    }
    else if(toupper(og_scale)=='K'){
        og_temp = og_temp-272.15;
    }
    
    //convert to new scale
    double new_temp;

    if(toupper(new_scale)=='F'){
        new_temp = ((og_temp)*1.8) + 32;
    }
    else if(toupper(new_scale)=='K'){
        new_temp = og_temp + 272.15;
    }
    else if(toupper(new_scale)=='C'){
        new_temp = og_temp;
    }

    printf("Converted temperature: %.2f %c\n", new_temp, toupper(new_scale));
    
    //print category
    if(og_temp<0){
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear a hat and gloves!\n");
    }
    else if(og_temp<10){
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Dont forget a jacket!\n");
    }
    else if(og_temp<25){
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: Go on a walk!\n");
    }
    else if(og_temp<35){
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    }
    else{
        printf("Temperature category: Extreme heat\n");
        printf("Weather advisory: Stay inside!\n");
    }

}

