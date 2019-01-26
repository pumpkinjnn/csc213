#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Here are some handy C preprocessor definitions for suits of cards
// Source: http://stackoverflow.com/questions/27133508/how-to-print-spades-hearts-diamonds-etc-in-c-and-linux
#if defined(_WIN32) || defined(__MSDOS__)
   #define SPADE   "\x06"
   #define CLUB    "\x05"
   #define HEART   "\x03"
   #define DIAMOND "\x04"
#else
   #define SPADE   "\xE2\x99\xA0"
   #define CLUB    "\xE2\x99\xA3"
   #define HEART   "\xE2\x99\xA5"
   #define DIAMOND "\xE2\x99\xA6"
#endif

#define TOTAL_CARDS 52

int main(int argc, char** argv) {
 
  //set seed fo srand
  srand(time(NULL));

  //array of cards
  int cards[TOTAL_CARDS];

  //initialize cards
  for(int i = 0; i < TOTAL_CARDS; i++) {
     cards[i] = i;
  }

  //shuffle cards array
  int temp, random_index;

  for(int i = 0; i < TOTAL_CARDS; i++){
      temp = cards[i];
      random_index= rand() % TOTAL_CARDS;

      cards[i] = cards[random_index];
      cards[random_index] = temp;
  }

  //Print deck
  int suit, num;

  for(int i = 0; i < TOTAL_CARDS; i++){
      suit = cards[i] % 4;
      num = cards[i] / 4;

      //print number
      if(num == 0){
         printf("A");
      }else if (num == 10){
         printf("J");
      }else if (num == 11){
         printf("Q");
      }else if (num == 12){
         printf("K");
      }else{
         printf("%d", num+1);
      }

      //print suit
      if(suit == 0){
         printf(SPADE);
      } else if(suit == 1){
         printf(CLUB);
      } else if(suit == 2){
         printf(HEART);
      } else {
         printf(DIAMOND);
      }

      printf("\n");
  }

  return 0;
}
