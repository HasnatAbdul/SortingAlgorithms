//****************************//
//                            //
//      Abdul Hasnat          //
//      Generate Module       //
//                            //
//                            //
//****************************//

#include <stdio.h>
#include <stdlib.h>



int *generate (int size){
    int *array;
    int i;
    array = (int * )malloc(sizeof(int)*(size));

    for (i = 0; i < size; i++) {
        array[i] = rand() % 1000;
    }
    return array;
}
