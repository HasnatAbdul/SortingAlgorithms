//****************************//
//                            //
//      Abdul Hasnat          //
//     Functions Module       //
//                            //
//                            //
//****************************//
#include <stdio.h>
#include <ctype.h>
#include "functions.h"
#include "sort.h"

//----Print the list into order----//
void printList(int array[], int size)
{

    int i;
    printf("---- UnSorted Array (Test) ----\n");
    for (i = 0; i < size; i++)
        printf("%d\n", array[i]);
    printf("\n");
}

void io()
{
    //----Interface for selection----//

    printf("Enter number based on which sorting method you want to use\n");
    printf("Bubblesort = '1'\n");
    printf("Quick      = '2'\n");
    printf("Selection  = '3'\n");
    printf("Merge      = '4'\n");
    printf("All        = '5'\n");
}

//--- Get the size of the array and store in size ---//
void getSize(int* size)
{
    printf("Enter how many numbers you want to sort : ");
    //scanf("%d", size);
    int* array; //set the array size to user input

    if((scanf("%d", size) == 0 )){
        printf("ERROR: Please enter a number\n");
        exit(0);
    }

}
