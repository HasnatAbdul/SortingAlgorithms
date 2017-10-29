//****************************//
//                            //
//      Abdul Hasnat          //
//         Sort Module        //
//                            //
//                            //
//****************************//

#include "sort.h"


void bubblesort(int array[], int n) {

    int x, y, z;

    for (x = 0 ; x < ( n - 1 ); x++)
    {
        for (y = 0 ; y < n - x - 1; y++)
        {
            if (array[y] > array[y+1])
            {
                // Swapping

                z         = array[y];
                array[y]   = array[y+1];
                array[y+1] = z;
            }
        }
    }
//printf("Bubble sort:\n");
    // printList(array,n);

}



void quicksort(int array[],int first,int last){
    int pivot,j,temp,i;

    if(first<last){
        pivot=first;
        i=first; // i is first number
        j=last; //j is last number

        while(i<j){ // 2 pivots with in while loop
            while(array[i]<=array[pivot]&&i<last) //pivot from end
                i++;
            while(array[j]>array[pivot]) //pivot from beginning
                j--;
            if(i<j) { // flips two sides (end and beginnings)
                //swapping
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;

            }
        }

        temp=array[pivot];
        array[pivot]=array[j];
        array[j]=temp;
        quicksort(array,first,j-1);
        quicksort(array,j+1,last);

    }
}

void insertionsort (int array[], int length) {
    int j, temp, i;


    for (i = 0; i < length; i++){
        j = i;

        while (j > 0 && array[j] < array[j-1]){
            //swapping
            temp = array[j];
            array[j] = array[j-1];
            array[j-1] = temp;
            j--;
        }
    }
    //  printf("Insertion sort:\n");
    //  printList(array,length);
}


void selectionsort(int array[],int n) {
    int i,j,temp;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (array[i] > array[j]) {
                //swapping
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    // printf("Selection sort:\n");
    //printList(array,n);

}



void merge(int array[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the sub-array of arr to be sorted
void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = left+(right-left)/2;

        // Sort first and second halves
        mergeSort(array, left, m);
        mergeSort(array, m+1, right);

        merge(array, left, m, right);
    }
}
