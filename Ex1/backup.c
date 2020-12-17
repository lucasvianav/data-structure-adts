/* Author: Lucas Viana Vilela */
/* noUSP: 10748409 */

#include <stdio.h>
#include <math.h>

/* Linear/sequential search algorithm */
int linearSearch(int size, int vector[size], int target){
    for(int i = 0; i < size; i++){
        if(vector[i] == target){
            return (i + 1);
        }
        /* Considering that the input vector will be ordenated in crescenting order */
        else if(vector[i] > target){
            return -1;
        }
    }

    return -1;

}

/* Iterative binary/logarithmic/half-interval search algorithm */
int iterativeBinarySearch(int size, int vector[size], int target){
    /* The index starts at the middle of the vector */
    int middle = floor(size/2); /* Index */

    if(vector[middle] == target) {
        return (middle + 1);
    }
    else if(vector[middle] > target) {
        for(int i = middle - 1; i >= 0; i--) {
            if(vector[i] == target) {
                return (i + 1);
            }
            /* Considering that the input vector will be ordenated in crescenting order */
            else if(vector[i] < target){
                return -1;
            }
        }
    }
    else {
        for(int i = middle + 1; i < size; i++) {
            if(vector[i] == target) {
                return (i + 1);
            }
            /* Considering that the input vector will be ordenated in crescenting order */
            else if(vector[i] > target){
                return -1;
            }
        }
    }

    return -1;
    
}

/* Recursive binary/logarithmic/half-interval search algorithm */
int recursiveBinarySearch(int size, int vector[size], int target, int aux){
    /* The index starts at the middle of the vector */
    int middle = floor(size/2); /* Index */

    /** AUX MEANING
    * aux < 0 - targeting first half
    * aux = 0 - targeting middle
    * aux > 0 - targeting second half
    */

    if(0 <= middle + aux && middle + aux < size) {
        if(vector[middle + aux] == target) {
            return (middle + aux + 1);
        }
        else if(aux < 0 && vector[middle + aux] < target) {
            return -1; /* Considering that the input vector will be ordenated in crescenting order */
        }
        else if(aux > 0 && vector[middle + aux] > target) {
            return -1; /* Considering that the input vector will be ordenated in crescenting order */
        }
        else if(vector[middle + aux] > target) {
            aux--;
        }
        else if(vector[middle + aux] < target) {
            aux++;
        }

        return recursiveBinarySearch(size,vector,target,aux);
    }

    return -1;
    
}

int main() {
    int vectorSize; /* Número de registros */
    int noOfSearchs; /* Número de buscas */

    scanf("%d %d",&vectorSize,&noOfSearchs);

    int vector[vectorSize]; /* Registros */
    int targets[noOfSearchs]; /* Elementos buscados */
    int searchTypes[noOfSearchs]; /* Tipos de busca */
    int output[noOfSearchs]; /* Saída */

    /* Get input vector */
    for(int i = 0; i < vectorSize; i++) {
        scanf("%d", &vector[i]);
    }

    /* Get targets and search types */
    for(int i = 0; i < noOfSearchs; i++) {
        scanf("%d %d", &searchTypes[i], &targets[i]);

        if(searchTypes[i] < 1 || searchTypes[i] > 3) {
            printf(">>> ERROR - THE SEARCH TYPE ENTERED IS INVALID <<<");
            return 1;
        }
    }

    /* Print output */
    for(int i = 0; i < noOfSearchs; i++) {
        if(searchTypes[i] == 1){
            output[i] = linearSearch(vectorSize,vector,targets[i]);
        }
        else if(searchTypes[i] == 2){
            output[i] = iterativeBinarySearch(vectorSize,vector,targets[i]);

        }
        else if(searchTypes[i] == 3){
            output[i] = recursiveBinarySearch(vectorSize,vector,targets[i],0);
        }

        printf("%d\n",output[i]);
    }

    return 0;
}