# AI Usage Log

**Platform:** ChatGPT  
**Model:** GPT-5.6 Sol

---

## Interaction 1

### User

<<ImageDisplayed>><<ImageDisplayed>>can you explain logic of how to go through each possible case please

### Assistant Summary

Explained the logic of checking every possible football scoring combination using five nested loops for 8-point touchdowns, 7-point touchdowns, 6-point touchdowns, field goals, and safeties. Described how the innermost loop changes fastest, why each loop can stop at `score / point_value`, and how an `if` statement prints only combinations whose point total equals the requested score.

---

## Interaction 2

### User

\#include \<stdio.h>

\#include \<ctype.h>

int **main**(){

    double og_temp;

    **printf**("Enter the temperature value: ");

    **scanf**("%d", &og_temp);

    char og_scale;

    **printf**("Enter the original scale (C, F, or K): ");

    **scanf**(" %c", &og_scale);

    char new_scale;

    **printf**("Enter the scale to convert to (C, F, or K): ");

    **scanf**(" %c", &new_scale);

    *//convert all to celcius*

    if(**toupper**(og_scale)=="F"){

        og_temp = (og_temp-32)/1.8;

    }

    else if(**toupper**(og_scale)=="K"){

        og_temp = og_temp-272.15;

    }

    *//convert to new scale*

    double new_temp;

    if(**toupper**(new_scale)=="F"){

        new_temp = ((og_temp)\*1.8) + 32;

    }

    else if(**toupper**(new_scale)=="K"){

        new_temp = og_temp + 272.15;

    }

    else if(**toupper**(new_scale)=="C"){

        new_temp = og_temp;

    }

    **printf**("Converted temperature: %d %s", new_temp, **toupper**(new_scale));

    *//print category*

    if(og_temp<0){

        **printf**("Temperature category: Freezing");

        **printf**("Weather advisory: Wear a hat and gloves!");

    }

    else if(og_temp<10){

        **printf**("Temperature category: Cold");

        **printf**("Weather advisory: Dont forget a jacket!");

    }

     else if(og_temp<25){

        **printf**("Temperature category: Comfortable");

        **printf**("Weather advisory: Go on a walk!");

    }

     else if(og_temp<35){

        **printf**("Temperature category: Hot");

        **printf**("Weather advisory: Drink lots of water!");

    }

     else{

        **printf**("Temperature category: Extreme heat");

        **printf**("Weather advisory: Stay inside!");

    }

} ---> why i get error?

### Assistant Summary

Identified several C type and format mismatches: character comparisons needed single quotes instead of string quotes, `%lf` was needed to scan a `double`, `%.2f` and `%c` were needed when printing the converted temperature and scale, and Kelvin conversions should use 273.15. Provided a corrected version of the program while keeping the same overall conversion-through-Celsius approach.

---

## Interaction 3

### User

why is it stopping after taking in my input?

### Assistant Summary

Explained that the program was likely crashing at the final `printf` because `%d` was being used for a `double` and `%s` was being used for the single character returned by `toupper`. Recommended using `%.2f` and `%c`, and also reiterated the `%lf` input format and single-quoted character comparisons.

---

## Interaction 4

### User

my conversion, specifically F to C isnt working

### Assistant Summary

Explained that the Fahrenheit-to-Celsius formula itself was valid and suggested checking the surrounding input and character-comparison code. Showed the expected result for 68°F to 20°C and suggested a temporary debug print after converting the original temperature to Celsius.

---

## Interaction 5

### User

50F is converting to like -17.78C

### Assistant Summary

Used the -17.78°C result to infer that the stored Fahrenheit value was effectively behaving like 0°F, and pointed to the temperature input format as the likely cause. Recommended scanning the `double` with `%lf` and noted that 50°F should convert to 10°C.

---

## Interaction 6

### User

\#include \<stdio.h>

\#include \<ctype.h>

int **main**(){

    double og_temp;

    **printf**("Enter the temperature value: ");

    **scanf**("%1f", &og_temp);

    char og_scale;

    **printf**("Enter the original scale (C, F, or K): ");

    **scanf**(" %c", &og_scale);

    char new_scale;

    **printf**("Enter the scale to convert to (C, F, or K): ");

    **scanf**(" %c", &new_scale);

    *//convert all to celcius*

    if(**toupper**(og_scale)=='F'){

        og_temp = (og_temp-32)/1.8;

    }

    else if(**toupper**(og_scale)=='K'){

        og_temp = og_temp-272.15;

    }

    *//convert to new scale*

    double new_temp;

    if(**toupper**(new_scale)=='F'){

        new_temp = ((og_temp)\*1.8) + 32;

    }

    else if(**toupper**(new_scale)=='K'){

        new_temp = og_temp + 272.15;

    }

    else if(**toupper**(new_scale)=='C'){

        new_temp = og_temp;

    }

    **printf**("Converted temperature: %.2f %c\n", new_temp, **toupper**(new_scale));

    *//print category*

    if(og_temp<0){

        **printf**("Temperature category: Freezing\n");

        **printf**("Weather advisory: Wear a hat and gloves!\n");

    }

    else if(og_temp<10){

        **printf**("Temperature category: Cold\n");

        **printf**("Weather advisory: Dont forget a jacket!\n");

    }

    else if(og_temp<25){

        **printf**("Temperature category: Comfortable\n");

        **printf**("Weather advisory: Go on a walk!\n");

    }

    else if(og_temp<35){

        **printf**("Temperature category: Hot\n");

        **printf**("Weather advisory: Drink lots of water!\n");

    }

    else{

        **printf**("Temperature category: Extreme heat\n");

        **printf**("Weather advisory: Stay inside!\n");

    }

}

### Assistant Summary

Found that the input format contained the digit `1` in `%1f` instead of a lowercase `l` in `%lf`. Explained that this was the main reason the Fahrenheit input was being stored incorrectly. Also pointed out that Kelvin conversion should use 273.15 instead of 272.15.

---

## Interaction 7

### User

oh! thanks

### Assistant Summary

Acknowledged the thanks and noted that `%1f` versus `%lf` is an easy typo to miss in C.

---

## Interaction 8

### User

double og_temp;

    **printf**("Enter the temperature value: ");

    while(**scanf**("%lf", &og_temp) != 1){ *//if block will run if og_temp is not double or int*

        **printf**("Invalid temperature!\n");

        **scanf**("%lf", &og_temp); *//takes input again*

    };

### Assistant Summary

Explained that invalid input remains in the input buffer when `scanf` fails, which can create an infinite loop. Suggested clearing the bad input with `getchar()` until the newline and removing the extra `scanf` inside the loop because the loop condition already attempts another read.

---

## Interaction 9

### User

C:/msys64/ucrt64/bin/../lib/gcc/x86_64-w64-mingw32/15.2.0/../../../../x86_64-w64-mingw32/bin/ld.exe: cannot open output file task2.exe: Permission denied

### Assistant Summary

Explained that the linker could not overwrite or create `task2.exe`, most likely because the executable was still running and locked by Windows. Suggested stopping the process, killing the terminal or process if necessary, and recompiling.

---

## Interaction 10

### User

    char og_scale;

    **printf**("Enter the original scale (C, F, or K): ");

    **scanf**(" %c", &og_scale);

    while(**toupper**(og_scale)!='F' && **toupper**(og_scale)!='K' && **toupper**(og_scale)!='C'){

        **printf**("Invalid scale!\n");

        **printf**("Enter the original scale (C, F, or K): ");

        while (**getchar**() != '\n')

        {

        *// discard invalid input*

        }

    } ---> what is wrong with this?

### Assistant Summary

Identified that `og_scale` never changed inside the validation loop, so an invalid character would cause the loop to repeat forever. Suggested reading a new scale value with `scanf(" %c", &og_scale)` inside the loop after clearing the invalid input.

---

## Interaction 11

### User

im running it on a lineux system and when i type make it says no targetrs specified and no makefile found

### Assistant Summary

Explained that `make` could not find a Makefile in the current directory. Suggested checking the current directory with `pwd` and `ls`, compiling directly with `gcc` if no Makefile was required, or moving to the directory containing both the source file and Makefile.

---

## Interaction 12

### User

so it needs to be Makefile? not MakeFile

### Assistant Summary

Explained that Linux filenames are case-sensitive and that the standard filename is `Makefile` with a capital `M` and lowercase `f`. Also noted that lowercase `makefile` is typically recognized, while `MakeFile` is a different filename.

---

## Interaction 13

### User

now it says nor ule to make target task1.c needed by task1.o

### Assistant Summary

Explained that the Makefile was looking for a source file named `task1.c` but Linux could not find that exact filename. Suggested checking the directory contents and either renaming the source file or updating the Makefile to match the actual filename.

---

## Interaction 14

### User

i have a task1.C

### Assistant Summary

Explained that `task1.C` and `task1.c` are different filenames on Linux and that uppercase `.C` is commonly treated as C++ source by GCC. Recommended renaming the file to `task1.c` so it matches the Makefile and is compiled as C.

---

## Interaction 15

### User

can you make this for me!!! if you put name anywehre put Sydney Moroney

### Assistant Summary

Created the requested `ai_usage_log.md` file using the available conversation history and the required AI Usage Log structure.
