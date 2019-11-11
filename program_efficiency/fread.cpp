#include <stdio.h>
int main ()
{
  FILE * pFile;
  char mystring [100];
  pFile = fopen ("myfile.txt","rw");
//   if (pFile!=NULL)
//   {
//     fputs ("fopen example",pFile);
//     fclose (pFile);
//   }

  if ( fgets (mystring , 100 , pFile) != NULL )
       puts (mystring);
     fclose (pFile);
  return 0;
}