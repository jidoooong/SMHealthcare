//
//  cal_diets.c
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

#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food


// list of diets 
static Diet diet_list[MAX_DIETS];
static int diet_list_size = 0;


/*
    description : read the information in "diets.txt"
*/

void loadDiets(const char* DIETFILEPATH) {
    FILE *file = fopen(DIETFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for diets! \n");
        return;
    }

     // ToCode: to read a list of the diets from the given file
    while (fscanf(file, "%s %d", diet_list[diet_list_size].food_name, &diet_list[diet_list_size].calories_intake) == 2)
    	//by.me  two file scan, (==2) : return to read two fscanf
		{
    	diet_list_size++;  //by.me data save to list
        if (diet_list_size >= MAX_DIETS){
        	break;
		}
    }
    fclose(file);
}

/*
    description : to enter the selected diet and the total calories intake in the health data
    input parameters : health_data - data object to which the selected diet and its calories are added 
    return value : No
    
    operation : 1. provide the options for the diets to be selected
    			2. enter the selected diet and the total calories intake in the health data
*/

void inputDiet(HealthData* health_data) {
    int choice, i;
    
    // ToCode: to provide the options for the diets to be selected
    printf("The list of diets:\n");
    for (i = 0; i < diet_list_size; i++)  //by.me available diet list
	    {
        printf("%d, %s (%d kcal)\n", i + 1, diet_list[i].food_name, diet_list[i].calories_intake);
		}  //by.me //by.me diet list print 
    
    
	// ToCode: to enter the diet to be chosen with exit option
	printf("Choice diet: ");  //by.me choice diet
    scanf("%d", &choice);  //by.me choice diet scanf
     

    // ToCode: to enter the selected diet in the health data
    Diet selected_diet = diet_list[choice-1];  //by.me save to select diet
    health_data->diet[health_data->diet_count] = selected_diet;  //by.me save to selected diet in structure(diet)
    health_data->diet_count++;  //by.me save+1

    // ToCode: to enter the total calories intake in the health data
    health_data->total_calories_intake += selected_diet.calories_intake;  //by.me add select diet's calories to total intake calories
    printf("Food: %s, Calories intake: %d kcal\n", selected_diet.food_name, selected_diet.calories_intake);  //by.me foodname, intake calories print

}

