////////////////////////////////////////////////////////////////////////////////
//
//  File           : cmpsc311-f16-assign1.c
//  Description    : This is the main source code for for the first assignment
//                   of CMPSC311 at Penn State University.  See the related
//                   assignment page for details.
//
//   Author        : Shaunak Wagh 
//   Last Modified : 9/16/2020
//

// Include Files
#include <stdio.h>
#include <cmpsc311_util.h>
#include <math.h>
// Defines
#define NUM_CARDS 52
#define MAX_CARDS 11
#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

// Functions

////////////////////////////////////////////////////////////////////////////////
//
// Function     : print_card
// Description  : print the card from the integer value
//
// Inputs       : card - the card to print
// Outputs      : 0 always
/*This function prints a single card with the suit.*/
int print_card( int card ) {

    // CODE HERE
    char card_faces[] = "234567891JQKA";
    char *card_suits[] = { SPADE, CLUB, HEART, DIAMOND };
    int suit = card / 13, cardty = card % 13;
    if ( cardty == 8 ) {
        printf( "10%s ", card_suits[suit] );
    } else {
        printf( "%c%s ", card_faces[cardty], card_suits[suit] );
    }

    // Return zero
    return( 0 );
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : print_cards
// Description  : print a number of cards (no more than 13 on one line)
//
// Inputs       : cards - the array of cards to print
//                num_cards - the number of cards to print
// Outputs      : 0 always
/*This function recieves the array of cards and number cards and then prints 13 cards in a line
 using print_card. */
int print_cards( int cards[], int num_cards ) {
  //printf("\n In  print_cards \n");
 int count=0;
      
      for(int a =0;a<num_cards;a++)
           {
             //printf("\n cards[%d] is %d \n", a, cards[a]) ;
             int temp=cards[a];
             print_card(temp-2);
             count++;
             
             if (count == 13)
             {
              count = 0;
              
              printf(" \n");
             }
             
             
            }
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : shuffle_cards
// Description  : print a number of cards (no more than 13 on one line)
//
// Inputs       : cards - the array of cards to print
//                num_cards - the number of cards to print
// Outputs      : 0 always
/*This function recieves the array of cards and ny=umber of cards and then shuffles 
the card using random function.*/
int shuffle_cards( int cards[], int num_cards ) {
 uint32_t getRandomValue( uint32_t min, uint32_t max );
    

    int i;
 
    for (i = num_cards - 1; i > 0; i--) {
        int j = getRandomValue(0,52) % (i + 1);
       int tmp = cards[j];
        cards[j] = cards[i];
        cards[i] = tmp;
   }
}

 

////////////////////////////////////////////////////////////////////////////////
//
// Function     : hand_value
// Description  : return the value of the hand
//
// Inputs       : cards - the array of cards in the hand
//                num_cards - the number of cards in the hand
// Outputs      : 0 always
/*This function recieves the array of cards and number of cards, then 
it gives the totala value of the cards the player or dealer has.*/
int hand_value( int cards[], int num_cards ) {
int hand_value_local = 0;
int ace=0;

//printf("\n numcards is %d", num_cards);
for( int i =0;i<num_cards;i++)
{
    int tmp,value;
   

    tmp=cards[i];
    
    value=tmp % 13;
  
    if( (value >= 11 && value <= 13 ) || (value == 0) )
    {
        value = 10;
    }
    //printf("\n value is %d", value);
    

    
    if(value==1)
    {
        ace++;
        
        
    }
    else
    {
        hand_value_local+=value;
    }
//printf("\n 111 hand_value_local is %d \n", hand_value_local);

}



 for(int i = 0; i < ace ; i++)
{
    if(hand_value_local <= 10)
        {
            hand_value_local+=11;
        }
        else
            hand_value_local+=1;
}


//printf("\n 222 hand_value_local is %d \n", hand_value_local);
return hand_value_local;

}

 

////////////////////////////////////////////////////////////////////////////////
//
// Function     : sort_cards
// Description  : sort a collection of cards
//
// Inputs       : hand - the cards to sort
//                num_cards - the number of cards in the hand
// Outputs      : 0 always
/*This function recieves an array of cards and the number of cards, then sorts the cards 
according to the assigment.*/
int sort_cards( int hand[], int num_cards ) {
   int x,y;

    for (x=0; x<num_cards-1;x++)
    {
        for (y=0;y<num_cards-1;y++)
        {
            if (hand[y]>hand[y+1])
            {
             int temp = hand[y];
             hand[y] = hand[y+1];
             hand[y+1]= temp;

            }
        }

     //print_cards(hand,num_cards);
    }
    int newarray[num_cards];

    for(int i=0, j=0; i< 52; i++)
    {
        newarray[i]= hand[j];
        switch(j){
            case 39:
                j=1;
                break;
            case 40:
                j=2;
                break;
            case 41:
                j=3;
                break;
            case 42:
                j=4;
                break;
            case 43:
                j=5;
                break;
            case 44:
                j=6;
                break;
            case 45:
                j=7;
                break;
            case 46:
                j=8;
                break;
            case 47:
                j=9;
                break;
            case 48:
                j=10;
                break;
            case 49:
                j=11;
                break;
            case 50:
                j=12;
                break;
            default:
             j=j+13;
             break;

        }




    }
    for(int x=0;x<52;x++)
        {
            hand[x]=newarray[x];
        }

}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : dealer_play
// Description  : dealer decision to hit or stand (hit on anything less 
//                than 17)
//
// Inputs       : hand - cards dealer has
//                num_cards - the number of cards in player hand
// Outputs      : 0 = stand, 1 = hit
/*This function receives dealer's card and the number of the cards the dealer has, then it decides 
if the dealer wants to hit or stand by return 1 or 0.  */
int dealer_play( int hand[], int num_cards ) {
    int dealer_value_local=hand_value(hand,num_cards);
    

    if (dealer_value_local <= 16)
        return 1;
    else
        return 0;
   
 }
////////////////////////////////////////////////////////////////////////////////
//
// Function     : player_play
// Description  : player decision to hit or stand
//
// Inputs       : hand - cards player has
//                num_cards - the number of cards in player hand
//                dealer_card - the dealers face up card
// Outputs      : 0 = stand, 1 = hit
/*This function receives player's cards and the number of the cards the player has, then it decides 
if the plater wants to hit or stand by return 1 or 0.  */
int player_play( int hand[], int num_cards, int dealer_card ) {


    int player_value_local=hand_value(hand,num_cards);

    int dealer_value_array[1];
    dealer_value_array[0]=dealer_card;

    //printf("\ndealer card %d",dealer_card);

    int dealer_value_local=hand_value(dealer_value_array,1);
    /* printf("\n Test of player play");
    printf("\n player_value_local is %d ", player_value_local);
    printf("\n dealer_value_local is %d ", dealer_value_local);
*/

    if (player_value_local>=17 && player_value_local< 21)
    {
        //printf("\n im 17 or above");
        return 0;
    }
    if(player_value_local>=13 && player_value_local<=16)
    {
        //printf("\n im above 13 and below 17");
        if (dealer_value_local<=6)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    if(player_value_local==12 && dealer_value_local>6)
    {
        return 1;
    }
    if(player_value_local==12 && dealer_value_local<4)
    {
        return 1;
    }
    if(player_value_local==12)
    {
        return 0;
    }
    if(player_value_local<=11)
    {
        return 1;
    }

   

    

}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : play_hand
// Description  : play a hand of black jack
//
// Inputs       : deck - the whole deck of cards
//                num_cards - the number of cards in the deck
//                player_money - pointer to player amount of money
// Outputs      : 1 if player wins, 0 if dealer wins
/*This function plays the game of poker with the dealer */
int play_hand( int deck[], int num_cards, float *player_money ) {

    shuffle_cards(deck,52);
    
    int playerhand[10];
    int dealerhand[10];
    int cardcount=0;
    int curr_hand_value = 0;
        playerhand[0]=deck[cardcount++];
           
        dealerhand[0]=deck[cardcount++];

        playerhand[1]=deck[cardcount++];
           
        dealerhand[1]=deck[cardcount++];
     
     
   
    printf("------- New Hand --------\n\n");

    printf("Dealer Cards: ");
    print_cards(dealerhand,1);
    printf(" XX" );

    printf("\n\n");
    printf("Players Cards:");
    print_cards(playerhand,2);

    curr_hand_value = hand_value(playerhand,2);

    //printf("\nxx curr_hand_value is %d", curr_hand_value);

    if (curr_hand_value == 21)
    {
        printf("\n Player has Black Jack, wins $7.50");
        *player_money+=((float)7.50);
        return 1;
    }
    else
    {
    
        int return_value=player_play(playerhand,2,dealerhand[0]);
    //printf("\n return value from player_play %d", return_value);
      
            
        int x=2;
        while(return_value==1)
        {
           // printf("\n In While loop");


             
            playerhand[x]=deck[cardcount++];
           // printf("\n 111 ");

           printf("\nPlayer hit (%d):", hand_value(playerhand,x+1));

            print_cards(playerhand,x+1);
            
          return_value=player_play(playerhand,x+1,dealerhand[0]);
         // printf("\n return_Value is %d", return_value);
        
            curr_hand_value = hand_value(playerhand, x+1);

            if(curr_hand_value == 21)
            {
                printf("\nPlayer has Black Jack, wins $7.50");
                *player_money+=((float)7.50);
                return 1 ;
                break;
            }

            if(curr_hand_value > 21)
            {
                printf("\nPlayer BUSTS ... dealer wins!");
                *player_money-=((float)5.0);
                return 0 ;
                break;
            }
            x++;
         }
         
         int hret = 0;
         hret = hand_value(playerhand, x);
         printf("\nPlayer Stands (%d):", hret);
         print_cards(playerhand,x);

         if ( curr_hand_value < 21) 
         {
            int dealer_curr_hand_value=0;
            return_value=dealer_play(dealerhand,2);
           // printf("\n return value from dealer_play %d", return_value);
            dealer_curr_hand_value = hand_value(dealerhand, 2);
            //printf("\n 111 Dealer value is %d \n", dealer_curr_hand_value);
            //print_cards(dealerhand,2);
        
            int y=2;
            printf("\n\n");
            while(return_value==1)
            {
                //printf("\n In D E A L E R While loop");

               
             
                dealerhand[y]=deck[cardcount++]; 
                printf("\nDealer hit (%d):", hand_value(dealerhand,y+1));
                print_cards(dealerhand,y+1);

                dealer_curr_hand_value = hand_value(dealerhand,y+1);
                if(dealer_curr_hand_value > 21)
                {

                                    
                    printf("\nDealer BUSTS ... player wins!");
                    *player_money+=((float)5.0);
                    return 1 ;
                    break;
                }

                

                
                    
                return_value=dealer_play(dealerhand,y+1);
                //printf("\n xxx Dealer value is %d \n", dealer_curr_hand_value);
                

                y++;

             }
             printf("\nDealer Stands (%d):", hand_value(dealerhand, y));
             print_cards(dealerhand, y);

             if (dealer_curr_hand_value < 21 ){
                if (curr_hand_value> dealer_curr_hand_value){
                    printf("\n Player wins $5.00");
                    *player_money+=((float)5.0);
                    return 1;
                }
                else {
                    printf("\n Dealer wins !!!");
                    *player_money-=((float)5.0);
                    return 0;
                }
             }
             
        
         }
        
    }    

}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : show_player_money_histogram
// Description  : Display a histogram of the player funds by hands
//
// Inputs       : money_rounds - the list of player money by hand number
//                last_round - the hand number where the game stopped
// Outputs      : 0 always
/*This function receives money round and the number of the player plays, then prints the histogram */
int show_player_money_histogram( float money_rounds[], int last_round ) {

 
    char hgram [41][100];

    for(int j = 0; j < last_round; j++)
    {
        for(int i=0;i<41;i++)
        {
            hgram[i][j]='.';
            int money =0;
            money=((int)money_rounds[j]/5);
            //printf("\n %d",money);
            if(i<=money)
            {
                 hgram[i][j]='x';
            }
            
        }
    }

    printf("\n                                       Player Cash by Round \n");
    printf("    ----------------------------------------------------------------------------------------------------\n");
    for( int x=40;x>=0;x--)
    {

        printf("%3d|",((x)*5));
        for(int y=0; y<last_round;y++)
        {
            printf("%c", hgram[x][y]);
        }
          printf("|\n");
    }

     printf("    ----------------------------------------------------------------------------------------------------\n");
     printf("    ");
    for(int z = 1; z< 11; z++)
    {
        printf("         %d", z);
    }
    printf("\n");
    printf("    ");
    for(int a =0 ; a<10; a++)
    {
        if (a==0)
        {
            for(int z = 1; z< 10; z++)
            {
                printf("%d", z);
            }
        }
        else
        {
        for(int z = 0; z< 10; z++)
        {
            printf("%d", z);
        }
    }

    }
     printf("0");
    printf("\n");

    return 0;
    
}


////////////////////////////////////////////////////////////////////////////////
//
// Function     : main
// Description  : The main function for the CMPSC311 assignment #1
//
// Inputs       : argc - the number of command line parameters
//                argv - the parameters
// Outputs      : 0 if successful test, -1 if failure
/* this is the main function and is the backbone of whole code*/
int main( int argc, char **argv ) {

    /* Local variables */
    /* Local variables */
    int cmp311_deck[52]; 
    float player_money=100;
    float money_array[100];

    /* Preamble information */
   printf( "CMPSC311 - Assignment #1 - Fall 2020\n\n" );
    srand(time(NULL)) ;

    /* Step #1 - create the deck of cards */
    int y =2;
    for (int a=0; a<52; a++)
    {
        

        cmp311_deck[a]=y;
        y++;


    }
    /* Step #2 - print the deck of cards */
    printf("Deck of cards is\n");
    print_cards(cmp311_deck,52);
    printf("\n");
     /* Step #4 - shuffle the deck */
    printf("Deck of shuffled cards is\n");
    shuffle_cards(cmp311_deck,52);
    /* Step #5 - print the shuffled deck of cards */
     print_cards(cmp311_deck,52);
      printf("\n");

    /* Step #6 - sort the cards */
      printf("Sorting deck of cards is\n");
    sort_cards(cmp311_deck,52);

    /* Step #7 - print the sorted deck of cards */
    printf("Deck of sorted cards is\n");
     print_cards(cmp311_deck,52);

    int ret = 0 , playerwon = 0;
    int i=0;
    for(i=0; i < 100; i++){
        /* Step #9 - deal the hands */
       // float player_money[100];
     ret = play_hand(cmp311_deck,52,&player_money);
     printf("\nAfter hand %d player has %0.2f$ left.\n", (i+1), player_money);
     if ( ret == 1 )
     {
        playerwon++;
     }
     

     money_array[i] = player_money;
     if (player_money<5)
     {
        printf("\n-------------");
        printf("Blackjack done - Player ended up with %d \n",player_money );
        break;

     }

    }
    
    printf("Blackjack done - player won %d out of  %d hands (%d.00). \n", playerwon, i, playerwon);
    /* Step 10 show historgrapm */
    show_player_money_histogram(money_array,i);
    /* Exit the program successfully */
    printf( "\n\nCMPSC311 - Assignment #1 - Spring 2020 Complete.\n" );
    return( 0 );
}
