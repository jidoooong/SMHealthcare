//
//  main.c
//  Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define EXERCISEFILEPATH "exercises.txt"
#define DIETFILEPATH "diets.txt"
#define HEALTHFILEPATH "health_data.txt"

static int choice;

int main() {
	// To initialize the health data object
    HealthData health_data = {0};
    
    // Tocode: to read the list of the exercises and diets
    loadExercises(EXERCISEFILEPATH); // by.me loadexercise
    loadDiets(DIETFILEPATH); // by.me loaddiet

    // ToCode: to run the "Healthcare Management Systems" until all calories are used up or the user wants to exit the system
    do {
    	int the_remaining_calories = health_data.total_calories_intake - BASAL_METABOLIC_RATE - health_data.total_calories_burned; //by me.remainingcalories declare
    	if (the_remaining_calories==0){ //by.me remaining calories=0
            printf("You have consumed all your calories for today! \n");
		} 
		else{
			printf("\n=======================================================================\n");
        	printf("[Healthcare Management Systems] \n");
        	printf("1. Exercise \n");
        	printf("2. Diet \n");
        	printf("3. Show logged information \n");
        	printf("4. Exit \n");
        	printf("Select the desired number: ");
        	scanf("%d", &choice);
        	printf("=======================================================================\n");
        }
        
		// ToCode: to run the sysmtem based on the user's choice
        switch (choice) {
            case 1:
            	inputExercise(&health_data); //by.me exercise data input precess
                break;
                
            case 2:
            	inputDiet(&health_data); //by.me diet data input precess
                break;
                
            case 3:
            	printHealthData(&health_data); //by.me saved exercise, diet print
                break;
                
            case 4:
            	saveData(HEALTHFILEPATH, &health_data); //by.me save present health data to datafile
    			printf("Exit the system.\n");
    			printf("=======================================================================\n");
                break;
                
            default:
                printf("[Error] Invalid option. \n");
                printf("Please try again! \n");
        }
    } while(choice!=4);

    return 0;
}

