/* Author: Lucas Viana Vilela */
/* noUSP: 10748409 */

#include <stdio.h>

/* Linear/sequential search algorithm */
int linearSearch(int size, int vector[], int target){
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
int iterativeBinarySearch(int size, int vector[], int target){
    int middle; /* Vector's middlepoint */
    int start = 0; /* Vector's beginning */

    while(start <= size){
        middle = (start + size)/2; 
    
        if(vector[middle] == target) {
            return (middle + 1);
        }
        else if(vector[middle] > target) {
            size = middle - 1;
        }
        else {
            start = middle + 1;
        }
    }

    return -1;
}

/* Recursive binary/logarithmic/half-interval search algorithm */
int recursiveBinarySearch(int size, int vector[], int target, int start){
    int middle; /* Vector's middlepoint */

    middle = (start + size)/2; 

    if(vector[middle] == target) {
        return (middle + 1);
    }
    else if(vector[middle] > target) {
        size = middle - 1;
    }
    else {
        start = middle + 1;
    }

    if(start <= size){
        return recursiveBinarySearch(size,vector,target,start);
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
            printf("\n\n::::ERROR - THE SEARCH TYPE ENTERED IS INVALID\n\n");
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