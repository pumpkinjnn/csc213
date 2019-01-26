#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
// Set up your own includes here!

#define INPUT_SIZE 100

int main(int argc, char** argv) {
  char input_chunk[INPUT_SIZE]; /* input char array    */
  char *p_input_chunk;          /* pointer to input    */
  char delimiters[] = " \n\t";  /* array of delimiters */
  int word_count = 0;           
  bool last_char = false;       /* if the last input is a char */ 
  char *word;                   /* pointer to next of token */
  
  //read stdin until EOF
  while(fgets(input_chunk, INPUT_SIZE, stdin) != NULL) {

     //check if fgets splits one word to prevent overcounting
     if(last_char == true && isalpha(input_chunk[0])){
	word_count--;
     }

     //pointer to input
     p_input_chunk = input_chunk;
    
     //If last input char is possible middle char of a string 
     last_char = isalpha(input_chunk[sizeof(input_chunk)-2])?
	         true:false;
     
     //Count number of words within the current input chunk
     while((word = strtok(p_input_chunk, delimiters)) != NULL) {
       word_count++;
       p_input_chunk = NULL;
     }
  }

  printf("%d\n", word_count);
 
  return 0;
}

