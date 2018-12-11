//Author: TANEJS4

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
enum Status { CONTINUE, WON , LOST}; // enumeration constants represent game status
int rollDice(void); //prototype function
int crap(void); //prototype function
     
int main(){
  int bankBalance = 1000; //start with bankBalance
  int wage; //intializing variable  wage
  printf("Your Bank Balance is: %d\n",bankBalance );
  do{ //i used do while loop to get the value of the wage then evaluating
  while (wage > 0){ //to check the wage input is within the required limits
      printf("\nEnter your wage (less than %d) or -1 to end: ", bankBalance);
      scanf("%d", &wage); //gettting the value of wage
      if (wage <= bankBalance){ //checking with the given requirements
        break;    }
      if( wage == (-1)){ //EOF
        exit(1);}
      else{ //invalid input so we promt and run the code again
        printf("enter correct wager\n");
        continue;  }

    }
  if (crap() == WON){ //checking the value fo die roll result
    bankBalance += wage; //adding wage to bankBalance
    printf("\nYou WON!\n"); //promting user
    printf("\nYour Bank Balance is: %d", bankBalance); //promting user with new Balance
     }
  else{
    if (bankBalance <= 0){
      printf("\nYou lost\n"); //user lost the game as bankBalance is not positive anymore
      printf("\nYour Bank Balance is: %d", bankBalance ); //user lost the game
      printf("\nSorry. You got busted!\n"); } //promting
    else{
      bankBalance -= wage; //subtracting wage to bankBalance
      printf("\nYou lost\n");//promting user
      printf("\nYour Bank Balance is: %d", bankBalance); //promting user with new balance

    }

  }
  int yahoo = rand() % 3; //random number for randomizing promts
  switch(yahoo){ //using switch because as yahoo gets a new random rumber after every lost or win
    case 0:
      printf("\nYou can do better!!!\n");
      break; //ending the switch statement
    case 1:
      printf("\nBE A DAREDEVIL! WAGE MORE!\n");
      break;//ending the switch statement
    case 2:
      printf("\nsuch a klutz! haha\n");
      break;//ending the switch statement
}
}while( bankBalance >0 ); //condition for do..while loop

}


int crap(void){
  srand(time(NULL));// randomize random number generator using current time
  int myPoint; // player must make this point to win
  enum Status gameStatus;// can contain CONTINUE, WON, or LOST

  int sum = rollDice();// first roll of the dice
  // determine game status based on sum of dice
  switch(sum) {
// win on first roll
    case 7:// 7 is a winner
    case 11:// 11 is a winner
      gameStatus = WON;
      break;
      // lose on first roll
    case 2:// 2 is a loser
    case 3:// 3 is a loser
    case 12:// 12 is a loser
      gameStatus = LOST;
      break; // remember point
    default:
      gameStatus = CONTINUE;// player should keep roll
      myPoint = sum;// remember the point
      printf("Point is %d\n", myPoint);
      break;// optional
    }
    // while game not complete
  while (CONTINUE == gameStatus) {// player should keep rolling
      sum = rollDice();
  if (sum == myPoint) {// win by making point
    gameStatus = WON;    }
  else {
  if (7 == sum) {// lose by rolling 7 after first roll
    gameStatus = LOST;   }
        }
                                }
// display won or lost message

  if (WON == gameStatus) {// did player win?
    return gameStatus; //returning value for status of the roll
                        }
  else {
    return gameStatus;//returning value for status of the roll
  }
}


int rollDice(void){ //defining the prototype function
  int die1 = 1 + (rand() % 6); //random number out of 6
  int die2 = 1 + (rand() % 6); //random number out of 6
  printf("player rolled %d + %d = %d\n", die1, die2, die1 + die2);
  return die1 + die2; //returning sum of the two dies rolled
}
