/*** Implent all string functions without using standard ones **** 
Function	Work of Function
strlen()	Calculates the length of string
strcpy()	Copies a string to another string
strcat()	Concatenates(joins) two strings
strcmp()	Compares two string
strlwr()	Converts string to lowercase
strupr()	Converts string to uppercase
***/

#include<stdio.h>

/***Strlen function Implementaion ****/
int mystrlen(char *cptr)
{
	int len=0;
	puts(cptr);
	while(*cptr != '\0')
	{
		len++;
		cptr++;
	}
	return len;	
}

/****Str ***
char * strcpy ( char * destination, const char * source );
***/
char * mystrcpy( char *dest,const char *source)
{
	while(*source != '\0')
	{
		*dest=*source;
		 dest++;
		 source++;
	}
}

/***
char *strcat(char *dest, const char *src)
***/
char  *mystrcat(char *dest, const char *src)
{
	int len=0;
	len= mystrlen(dest);
	  dest=dest+len;
	  while(*src != '\0')
    {
		*dest=*src;
		dest++;
		src++;
	}	
}

/***
int strcmp(const char *str1, const char *str2)

if Return value < 0 then it indicates str1 is less than str2.

if Return value > 0 then it indicates str2 is less than str1.

if Return value = 0 then it indicates str1 is equal to str2.
***/
int mystrcmp(const char *str1, const char *str2)
{
	while(*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

/******/
int mystrlwr()
{
	
}


int mystrupr()
{
	
}

int main()
{
	char *str1="prasad"; //String Pointer
	char str2[] = "nallani"; //String array
	 char *str3=NULL; //Use char str3[10]
	 char *str4 = "prasa1"; 
	 str3=malloc(10); 
	int length=0;
	int size;
	int ret;
	
	length=mystrlen(str1); //Calling mystrlen Function 
	 
	printf("String length =%d\n",length);
	printf("size of str2 =%d\n",sizeof(str2)); //Sizeof operator include null charcater for measuring size
	
	mystrcpy(str3,str1); //Calling mystrcpy function 
	puts(str3);
	
	mystrcat(str2,str1); //calling strcat function
	puts(str2);
	
	ret = mystrcmp(str1,str4); //calling strcmp function
	
	printf("return value =%d\n",ret); //ret =0 means its both are sasme 
}
