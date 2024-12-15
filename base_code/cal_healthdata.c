//
//  cal_healthdata.c
//  Diets for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"


/*
    description : enter the exercise and diet history in "health_data.txt" 
    input parameters : health_data - data object in which the selected exercise and diet is stored
    return value : No
    
    operation : 1. save the chosen exercise and total calories burned 
    			2. save the chosen diet and total calories intake 
    			3. save the total remaining calrories
*/

void saveData(const char* HEALTHFILEPATH, const HealthData* health_data) {
	int i;
    FILE* file = fopen(HEALTHFILEPATH, "w");
    if (file==NULL) {
        printf("There is no file for health data.\n");
        return;
    }

    // ToCode: to save the chosen exercise and total calories burned 
    fprintf(file, "[Exercises] \n");
    for (i = 0; i < health_data->exercise_count; i++) {
    fprintf(file, "Exercise: %s, Calories burned : %d kcal\n", health_data->exercises[i].exercise_name, health_data->exercises[i].calories_burned_per_minute);
    }  //by.me  

    
    // ToCode: to save the chosen diet and total calories intake 
    fprintf(file, "\n[Diets] \n");
    for (i = 0; i < health_data->diet_count; i++) {
    fprintf(file, "Food: %s, Calories intake: %d kcal\n", health_data->diet[i].food_name, health_data->diet[i].calories_intake);
    }  //by.me


    // ToCode: to save the total remaining calrories
    fprintf(file, "\n[Total] \n");
    
    fprintf(file, "Basal Metabolic Rate: %d kcal\n", BASAL_METABOLIC_RATE);  //by.me
    fprintf(file, "Total calories burned: %d kcal\n", health_data->total_calories_burned);  //by.me
    fprintf(file, "Total calories intake: %d kcal\n", health_data->total_calories_intake);  //by.me
    int remaining_calories = health_data->total_calories_intake - BASAL_METABOLIC_RATE - health_data->total_calories_burned;  //by.me
    fprintf(file, "The remaining calories: %d kcal\n", remaining_calories);  //by.me
    
    fclose(file);
}

/*
    description : print the history of exercised and diets
    input parameters : health_data - data object in which the history of the exercise and diet is to be printed
    return value : No
    
    operation : 1. print out the saved history of exercises
    			2. print out the saved history of diets
    			3. print out the saved history of calories
*/

void printHealthData(const HealthData* health_data) {
	int i;
	static int exercise_durations[MAX_EXERCISES];  //
	
	// ToCode: to print out the saved history of exercises
	printf("=========================== History of Exercise =======================\n");
    for (i = 0; i < health_data->exercise_count; i++) {
    int duration = exercise_durations[i];  // ¿îµ¿ ½Ã°£
    int total_calories_burned = health_data->exercises[i].calories_burned_per_minute * duration; // ÃÑ Ä®·Î¸® °è»ê
    printf("Exercise: %s, Calories burned: %d kcal\n", health_data->exercises[i].exercise_name, total_calories_burned);
           }
    
  
    printf("=======================================================================\n");

    // ToCode: to print out the saved history of diets
    printf("============================= History of Diet =========================\n");
    for (i = 0; i < health_data->diet_count; i++)  //by.me
	{
    printf("Food: %s, Calories intake: %d kcal\n", health_data->diet[i].food_name, health_data->diet[i].calories_intake);  //by.me
    }


    printf("=======================================================================\n");


	// ToCode: to print out the saved history of calories including basal metabolic rate, 
	// total calories burned, total calories intake, and the remaining calories
	printf("============================== Total Calories =========================\n");
 
    printf("Basal Metabolic Rate: %d kcal\n", BASAL_METABOLIC_RATE);
    printf("Total calories burned: %d kcal\n", health_data->total_calories_burned);
    printf("Total calories intake: %d kcal\n", health_data->total_calories_intake);
    int remaining_calories = health_data->total_calories_intake - BASAL_METABOLIC_RATE - health_data->total_calories_burned;
    printf("The remaining calories: %d kcal\n", remaining_calories);
 
    printf("=======================================================================\n \n");
    
	
	// ToCode: to print out the recommendtaion depending on the current total calories burned and intake 
	 if (remaining_calories == 0) {
        printf("You have consumed all your calories for today!\n");
    } else if (remaining_calories < 0) {
        printf("[Warning] Too few calories!\n");
    } else {
        if (health_data->total_calories_intake >= DAILY_CALORIE_GOAL) {
            printf("Your total calorie intake for today has reached your goal!\n");
        } else {
            printf("Your total calorie intake for today has not reached your goal, remember to eat more!\n");
        }
        printf("Please exercise for your health!\n");
    }   
   
    
	 printf("=======================================================================\n");
}
