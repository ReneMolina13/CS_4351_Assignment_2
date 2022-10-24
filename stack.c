/* Vunlerable program: stack.c */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* You should choose last 2-digits of your 800-number as BUF_SIZE
 * Suggested value: between 0 and 400  
   Value used: 14 */
#ifndef BUF_SIZE
#define BUF_SIZE 24
#endif

int bof(char *str)
{
    char buffer[BUF_SIZE];

    /* The following statement has a buffer overflow problem */
    strcpy(buffer, str);       

    return 1;
}

int main(int argc, char **argv)
{
    char str[517];
    FILE *badfile;

     /* When ran without BADFILE existing, it uses dummy array instead
	    Used for determining memory allocations */
    char dummy[BUF_SIZE];  memset(dummy, 0, BUF_SIZE);

	badfile = fopen("badfile", "r");
    if (badfile != NULL) {
		fread(str, sizeof(char), 517, badfile);
		bof(str);
	}
	else
		bof(dummy);
	
    printf("Returned Properly\n");
    return 1;
}
