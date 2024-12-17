//
//  cal_exercise.c
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_EXERCISES 100           // Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50   // Maximum length of the name of exercise


// To declare the structure of the exercises
static Exercise exercise_list[MAX_EXERCISES];
int exercise_list_size = 0;


/*
    description : read the information in "excercises.txt"
*/

void loadExercises(const char* EXERCISEFILEPATH) {
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
    while(fscanf(file, "%s %d", exercise_list[exercise_list_size].exercise_name, &exercise_list[exercise_list_size].calories_burned_per_minute)==2)
	//by.me  two file scan, (==2) : return to read two fscanf  
	{
        exercise_list_size++;  //by.me data save to list
        if (exercise_list_size >= MAX_EXERCISES){
           break;
      }
    }

    fclose(file);
}


/*
    description : to enter the selected exercise and the total calories burned in the health data
    input parameters : health_data - data object to which the selected exercise and its calories are added 
    return value : No
    
    operation : 1. provide the options for the exercises to be selected
             2. enter the duration of the exercise
             3. enter the selected exercise and the total calories burned in the health data
*/

void inputExercise(HealthData* health_data) {
    int choice, duration, i;
    
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
    
	for(i=0; i<exercise_list_size; i++)  //by.me available exercise list
	{ 
    	printf("%d, %s (%d kcal/min)\n", i+1, exercise_list[i].exercise_name, exercise_list[i].calories_burned_per_minute); //by.me exercise list print 
	}


    // ToCode: to enter the exercise to be chosen with exit option
    printf("Choice exercise: "); //by.me choice exercise 
    scanf("%d", &choice); // by.me choice exercise scanf
 
    // To enter the duration of the exercise
    printf("Enter the duration of the exercise (minutes): ");  //by.me duration exercise
    scanf("%d", &duration);  //by.me duration exercise scanf

    // ToCode: to enter the selected exercise and total calcories burned in the health data
    int calories_burned = duration * exercise_list[choice - 1].calories_burned_per_minute; //by.me calories_burn caculation

    health_data->exercises[health_data->exercise_count] = exercise_list[choice - 1];  //by.me add selected exercise to health data
    health_data->exercise_count++;  // by.me exercise +1
    health_data->exercises[health_data->exercise_count - 1].calories_burned_per_minute = calories_burned;  //by.me update calories burned
    health_data->total_calories_burned += calories_burned;  //by.me renew total calories burned

    printf("Exercise: %s, Calories burned : %d kcal\n", exercise_list[choice - 1].exercise_name, calories_burned); //by.me exercise print

}
