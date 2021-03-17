#include <stdio.h>

int main(void)
{
   int i = 1;
   char *p = (char *) &i;
   if ( p[0] == 1 )
   printf("Little Endian\n");
   else
   printf("Big Endian\n");
   return 0;
}
