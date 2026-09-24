// EECS 348 Lab 4
// Purpose: C program that takes in temperature from user with scale and converts to another given scale. Prints temperature category and weather advisory.
// Author: Sydney Moroney
// Inputs: takes in temperature, original scale, and converted scale.
// Outputs: prints converted temperature, temperature category, and weather advisory
// Collaborators: Madelyn Armitage and Mikayla Pelletier helped conceptual and with edge case handling
// Sources: Error trapping assisted by chatgpt
// Creation Date: 9/23/26
// Last Revision Date: 9/24/26


#include <stdio.h>
#include <ctype.h>

int main(){

    //takes in double for temperature. keeps asking until valid input
    double og_temp;
    printf("Enter the temperature value: ");

    while(scanf("%lf", &og_temp) != 1){ //if block will run if og_temp is not double or int
        printf("Invalid temperature!\n");
        printf("Enter the temperature value: ");
        while (getchar() != '\n')
        {
          // discard invalid input
        }
    };

    //------------------------------------------------------------------------------

    //takes in character for original scale. keeps asking until valid input
    char og_scale;
    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &og_scale);

    while(toupper(og_scale)!='F' && toupper(og_scale)!='K' && toupper(og_scale)!='C'){
        printf("Invalid scale!\n");
    
        while (getchar() != '\n')
        {
          // discard invalid input
        }

        printf("Enter the original scale (C, F, or K): ");
        scanf(" %c", &og_scale);
    }

    //------------------------------------------------------------------------------

    //takes in character for new scale. keeps asking until valid input
    char new_scale;
    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &new_scale);

    while(toupper(new_scale)!='F' && toupper(new_scale)!='K' && toupper(new_scale)!='C'){
        printf("Invalid scale!\n");
        
        while (getchar() != '\n')
        {
           // discard invalid input
        }

        printf("Enter the scale to convert to (C, F, or K): ");
        scanf(" %c", &new_scale);
    }

    //------------------------------------------------------------------------------

    //convert all to celcius
    
    //FROM FAHRENHEIT
    if(toupper(og_scale)=='F'){
        og_temp = (og_temp-32)/1.8;
    }
    //FROM KELVIN
    else if(toupper(og_scale)=='K'){
        og_temp = og_temp-272.15;
    }

    //------------------------------------------------------------------------------

    //convert to new scale
    double new_temp;

    //TO FAHRENHEIT
    if(toupper(new_scale)=='F'){
        new_temp = ((og_temp)*1.8) + 32;
    }
    //TO KELVIN
    else if(toupper(new_scale)=='K'){
        new_temp = og_temp + 272.15;
    }
    //TO CELCIUS
    else if(toupper(new_scale)=='C'){
        new_temp = og_temp;
    }

    printf("Converted temperature: %.2f %c\n", new_temp, toupper(new_scale));

    //------------------------------------------------------------------------------
    
    //print category and weather advisory

    //FREEZING
    if(og_temp<0){
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear a hat and gloves!\n");
    }
    //COLD
    else if(og_temp<10){
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Dont forget a jacket!\n");
    }
    //COMFORTABLE
    else if(og_temp<25){
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: Go on a walk!\n");
    }
    //HOT
    else if(og_temp<35){
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    }
    //EXTREME HEAT
    else{
        printf("Temperature category: Extreme heat\n");
        printf("Weather advisory: Stay inside!\n");
    }

}

