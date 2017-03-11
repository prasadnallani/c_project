/********Simple Bubble Sorting *******/
#include <stdio.h>
int main()
{
	int arr[]={11,99,77,66,55,22};
	 int i,j;
	 int tmp;
	 int number=6;
	 for(j=0;j<number;j++)
	 {

	 for(i=0;i<number-1;i++)
	 {
	 
	 if (arr[i] > arr[i+1])
	 {
	 	tmp=arr[i+1];
	 	arr[i+1]=arr[i];
	 	arr[i]=tmp;
     }
   }
   
    }

   for(i=0;i<number;i++)
   {
   	 printf("Array number =%d\n",arr[i]);
   }
}
