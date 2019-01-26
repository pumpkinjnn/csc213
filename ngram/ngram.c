#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
  // Make sure the program is run with an N parameter
  if(argc != 2) {
    fprintf(stderr, "Usage: %s N (N must be >= 1)\n", argv[0]);
    exit(1);
  }
  
  // Convert the N parameter to an integer
  int N = atoi(argv[1]);
  
  // Make sure N is >= 1
  if(N < 1) {
    fprintf(stderr, "Invalid N value %d\n", N);
    exit(1);
  }
 
  char input_chunk1[N+1]; /* first input_chunk of N chars*/
  char input_chunk2[N+1]; /* second input_chunk of N chars */

  //Get the first reading of N chars
  fgets(input_chunk1, N+1, stdin);

  //Check if input length >= Ni
  if(strlen(input_chunk1) < N) return -1; 

  
  int print_num;  /* numer of substrings printed */

  //Keep reading until no input
  while(fgets(input_chunk2, N+1, stdin) != NULL) {
     print_num = sizeof(input_chunk2)-1;

     //Print print_num substrings for each pair of input
     for(int i = 0; i < print_num; i++) {  
        printf("%s%.*s\n",
	       input_chunk1+i,
	       i,
	       input_chunk2);
    }

     //Assign chunk2 to chunk1, read new to chunk2
     strcpy(input_chunk1, input_chunk2);
  }

  //if input_chunk2 contain exact N chars, print
  if((sizeof(input_chunk1)-1) == N) printf("%s\n", input_chunk1);
  
  return 0;
}
