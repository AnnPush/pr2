#include <stdio.h>
#include <stdlib.h>

int main(void)
{ 
   char c;             
   char sentence[ 80 ]; 
   int i = 0;           
   FILE *in = stdin, *out = stdout;
   char input[15], output[15];

   fputs( "enter your choice: ", out );
   scanf("%d%*c", &i);

   if(i == 1) {
      fputs( "Input file: ", out );
      scanf("%s", input);

      if( (in = fopen(input, "r")) == NULL) {
	 printf("cannot open the file\n");
	
      }

      fputs( "Output file: ", out );
      scanf("%s", output);

      if( (out = fopen(output, "w")) == NULL) {
	 printf("cannot open the file\n");
	
      }
   }
   else 
      
      puts( "Enter a line of text:" ); 

   i = 0;

   
   while( ( c = fgetc(in) ) != '\n') {
      sentence[ i++ ] = c; 
   } 

   sentence[ i++ ] = '\n'; 
   sentence[ i ] = '\0'; 
   
   
   fputs( "\nThe line entered was:\n", out ); 
   fputs( sentence, out );

   

} 

