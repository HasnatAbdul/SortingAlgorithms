//****************************//
//                            //
//      Abdul Hasnat          //
//         Write Module       //
//                            //
//                            //
//****************************//

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "generate.h"
#include <time.h>
#include "functions.h"

void Interface () {
    int size;
    int userInput;
    int *array;


    getSize(&size);
    io();
    scanf(" %d", &userInput);


    FILE *fp = fopen("gnu.out","w");


    //---------------------Bubble---------------------//
    if (userInput == 1) {

        array = generate(size);

        clock_t beginBubble = clock();
        bubblesort(array, size); //function
        free(array);

        clock_t endBubble = clock();

        double time_spentBubble;
        time_spentBubble = (double) (endBubble - beginBubble) / CLOCKS_PER_SEC;

        printf("Bubble sort:         Seconds: %f\n", time_spentBubble);

        fprintf(fp, "0 \"Bubble sort\" %g\n", time_spentBubble);

    }
        //---------------------Quick---------------------//
    else if (userInput == 2) {

        array = generate(size);

        clock_t begin = clock();
        quicksort(array, 0, size - 1);
        clock_t end = clock();
        free(array);

        double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

        printf("Quick sort:          Seconds: %f\n", time_spent);
        fprintf(fp, "3 \"Quick sort\" %g\n", time_spent);
    }
        //-------------------Selection-------------------//
    else if (userInput == 3) {

        array = generate(size);

        clock_t beginSelection = clock();
        selectionsort(array, size);

        //printList(array,size);
        clock_t endSelection = clock();
        free(array);

        double time_spentSelection = (double) (endSelection - beginSelection) / CLOCKS_PER_SEC;

        printf("Selection sort:      Seconds: %f\n", time_spentSelection);

        fprintf(fp, "1 \"Selection sort\" %g\n", time_spentSelection);
    }
        //---------------------Merge---------------------//
    else if (userInput == 4) {

        array = generate(size);

        clock_t beginMerge = clock();
        mergeSort(array, 0, size - 1);
        clock_t endMerge = clock();
        free(array);

        double time_spentMerge = (double) (endMerge - beginMerge) / CLOCKS_PER_SEC;

        printf("Merge Sort:          Seconds: %f\n", time_spentMerge);
        fprintf(fp, "2 \"Merge sort\" %g\n", time_spentMerge);

    }

        //----------------Run All 4 METHODS----------------//
    else if (userInput == 5){ //run all


        array = generate(size);

        clock_t beginBubble = clock();
        bubblesort(array, size); //function
        free(array);

        clock_t endBubble = clock();
        double time_spentBubble;
        time_spentBubble = (double) (endBubble - beginBubble) / CLOCKS_PER_SEC;

        printf("Bubble sort:         Seconds: %f\n", time_spentBubble);

        array = generate(size);

        clock_t begin = clock();
        quicksort(array, 0, size - 1);
        clock_t end = clock();
        free(array);

        double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

        printf("Quick sort:          Seconds: %f\n", time_spent);


        array = generate(size);

        clock_t beginSelection = clock();
        selectionsort(array, size);
        clock_t endSelection = clock();
        free(array);

        double time_spentSelection = (double) (endSelection - beginSelection) / CLOCKS_PER_SEC;

        printf("Selection sort:      Seconds: %f\n", time_spentSelection);

        array = generate(size);


        clock_t beginMerge = clock();
        mergeSort(array, 0, size - 1);
        clock_t endMerge = clock();
        free(array);

        double time_spentMerge = (double) (endMerge - beginMerge) / CLOCKS_PER_SEC;

        printf("Merge Sort:          Seconds: %f\n", time_spentMerge);

        fprintf(fp, "0 \"Bubble sort\" %g\n", time_spentBubble);
        fprintf(fp, "1 \"Selection sort\" %g\n", time_spentSelection);
        fprintf(fp, "2 \"Merge sort\" %g\n", time_spentMerge);
        fprintf(fp, "3 \"Quick sort\" %g\n", time_spent);

    }
    else{
        printf("Please enter between 1 - 5\n");
    }


    fclose(fp);
}
