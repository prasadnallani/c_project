/* Writing wrapper c funcions */
#include<stdio.h>


void mallocWrapper(int **intArray, int length)
{
    *intArray = malloc(length * sizeof(int));

}

int main()
{

    int *array    = NULL;    //Whenever you declare a pointer assign it to NULL
    int arraySize = 10;

    mallocWrapper(&array, arraySize);

    array[0] = 0;
   array[1]=10;
    printf("array[1]=%d\n",array[1]);
    return 0;
}
