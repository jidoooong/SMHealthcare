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
    for (i=0; i<health_data->exercise_count; i++) {
	    fprintf(file, "%s (%d kcal/min)\n", health_data->exercises[i].exercise_name, health_data->exercises[i].calories_burned_per_minute);
    }

    
    
    // ToCode: to save the chosen diet and total calories intake 
    fprintf(file, "\n[Diets] \n");
    for (i = 0; i < health_data->exercise_count; i++) {
        fprintf(file, "%s (%d kcal/min)\n", health_data->exercises[i].exercise_name, health_data->exercises[i].calories_burned_per_minute);
    }



    // ToCode: to save the total remaining calrories
    fprintf(file, "\n[Total] \n");
    
    fprintf(file, "Basal Metabolic Rate: %d kcal\n", BASAL_METABOLIC_RATE);
    fprintf(file, "Total Calories Burned: %d kcal\n", health_data->total_calories_burned);
    fprintf(file, "Total Calories Intake: %d kcal\n", health_data->total_calories_intake);
    int remaining_calories = health_data->total_calories_intake-BASAL_METABOLIC_RATE-health_data->total_calories_burned;
	fprintf(file, "Remaining Calories: %d kcal\n", remaining_calories);

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
	
	// ToCode: to print out the saved history of exercises
	 for (i = 0; i < health_data->exercise_count; i++) {
        int total_calories_burned = health_data->exercises[i].calories_burned_per_minute; // �Ҹ�� �� Į�θ�
        printf("Exercise: %s, Calories burned: %d kcal\n",
               health_data->exercises[i].exercise_name,
               total_calories_burned);
    }
  
  
    printf("=======================================================================\n");

    // ToCode: to print out the saved history of diets
    printf("============================= History of Diet =========================\n");


    printf("=======================================================================\n");


	// ToCode: to print out the saved history of calories including basal metabolic rate, 
	// total calories burned, total calories intake, and the remaining calories
	printf("============================== Total Calories =========================\n");
 
 
    printf("=======================================================================\n \n");
    
	
	// ToCode: to print out the recommendtaion depending on the current total calories burned and intake    
    
    
	 printf("=======================================================================\n");
}
