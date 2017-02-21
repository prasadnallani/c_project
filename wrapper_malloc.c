/* Writing wrapper c funcions */
#include<stdio.h>
/***** Pn_printf function ******/
pn_printf(char *str)
{
	puts(str);
}
/**********end*****************/
void* pn_malloc100()
{
	return malloc(100);

	
}

int main()
{
	pn_printf("calling printf wrapper function");
	int i;
	int *ptr=NULL;
	ptr = pn_malloc100();
	*ptr=11;
	*(ptr+1)=22;
	//ptr=malloc(100);
	if(ptr == NULL)
	printf("Malloc failed\n");	
	
	printf("value of *ptr = %d\n",*ptr);
    printf("value of *ptr+1 = %d\n",*(ptr+1));	
}


