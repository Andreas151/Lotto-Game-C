/* 
made by Andreas Natvik
03/07/2020

Program to make a Lotto game. the program asks the user for input in form of the users lotto number, 
check the lotto numbers enetered with the winning numbers. sort the users lotto numbers in increasing order. 
have an array for counting amount of times the user has entered the same number. and after every option always display the main menu.
*/

//#include<stdio.h>
#define LOTTOSIZE 6
//function signatures 
int my_lotto_number(int[]);
void my_lotto_displayed(int[]);
void insertion_sort(int[], int );
void compare_lottos(int[],int[]);
void lotto_frequency(int[], int[]);

int main()
{
    int menu =0;
    int lotto_numbers[LOTTOSIZE];
    int winning_lotto[LOTTOSIZE] = {1,3,5,7,9,11};
    int nr_picked =0;
    int my_nrbs;
    int num;
    int lotto_nr[LOTTOSIZE];
    char *validation ="must do option 1 first";
    
    do //do while loop to make sure the menu is displayed atleast once.  The menu is the option the user has in their game
  
    {//start do
        printf("\n1. Play game enter your lotto numbers\n");
        printf("2. display your lotto numbers\n");
        printf("3. display lotto numbers in an increasing order\n");
        printf("4. check if you won\n");
        printf("5. check how many times you've enetered the same number\n");
        printf("6. exit program\n");
        scanf("%d",&menu);
        
        //using a switch statement to record the players input and implementing the choosen option. the switch corresponds to the menu.
        switch(menu)
        
        {//start switch
            case 1:
            {//start case 1
            
            //callling function that lets the user enter his/her desiered numbers into the array.  
            nr_picked = my_lotto_number(lotto_numbers);
            
            break;
            }//end case 1
            
            
            //case 2 is option two display lotto numbers this is where if choosen the function for displaying the players lotto numbers.
            case 2: 
            {//start case 2
                
            /*if statement to make sure the player has done option one first wich has to be done for there to be any array to display.  
                    nr_picked represents the amount of elements inputed. for the user to successfully continue they must eneter 6 elements*/
            if(nr_picked == 0) 
            {
                puts(validation);
            }
            
            //the else is if they have correctly done step 1 the array will be displayed.
            else
            {
                my_lotto_displayed(lotto_numbers);
            }
            break;
            }//end case 2
            
            
            case 3:
            { // start case 3 
            
            if (nr_picked == 0)
            {//start if 
                puts(validation);
            }//end if 
                
            //this will sort the elements of the array and then display it back to the user in increasing order.
            else 
            {//else  
                insertion_sort(lotto_numbers, num);
                my_lotto_displayed(lotto_numbers);
            } // end else 
            break;
            }//end case 3
            
            
            case 4:
            {//start case 4
             
            if(nr_picked == 0)
            {//start if 
                    puts(validation);
            }//end if 
            //call function to compare the winning numbers to the player numbers to check if they win or not. 
            
            else 
            {//start else 
                compare_lottos(lotto_numbers,winning_lotto);
            }//end else 
            break;    
            }//end case 4
            
            case 5:
            {//start case 5
            
           if (nr_picked == 0)
            {//start if 
                puts(validation);
            }//end if 
            else 
            {//start else 
                lotto_frequency(winning_lotto, lotto_numbers);
            }//end else 
            break;
            }//end case 5
            
            default: 
            {//start default
                printf("\n Error the input is not allowed try numbers between 1 and 6\n");
            }//end default
        }//end switch
        
 
        
        
    }//end do
    while(menu !=6);
    
    
    getchar();
    return 0;    
}//end main 

//implementing function my_lotto_number(int[])
int my_lotto_number(int lotto_nr[])
{//start fxn

    //register int to asigne the index variables to the cpu cach  increase execution speed 
    register int i = 0;
    int numbers_picked = 0;
    
   
    do
    {
        printf("enter any 6 numbers between 1-42\n");
        //loop around the amount og times it takes to fill in the array with numbers of the users choise. 
        for(i=0; i<LOTTOSIZE; i++)
        {//start for
            scanf("%d",&lotto_nr[i]); 
            if ((*lotto_nr +i) < 43 && (*lotto_nr +i) > 0)
            {//start if 
                numbers_picked ++;    
            }//end if
            else 
            {//start else
                printf("invalid input\n");    
            }//end else
        }//end for 
    }//end do
    while(numbers_picked != LOTTOSIZE);
    {
    //return this value to use it a validator for the user input.
    return numbers_picked;
    }
}//end fxn

/*implement function int my_lotto_displayed(int[])
This function is to display the content of the users array to standard output 
*/

void my_lotto_displayed(int my_nrbs[])
{//start fxn 
    for( int i=0; i<LOTTOSIZE;i++)
    {
        printf("%d ",*(my_nrbs+i));
    }
}//end fxn 

//implement function for selction sort algorythm. this will sort the content of the elements to be in scaling order. smalest to highest 

void insertion_sort(int sort_lotto_nr[], int n)
{
    //register index var for speed.
    
    
    register int i,j;
    int my_arr;
    n = LOTTOSIZE;
    for (i =1; i<LOTTOSIZE;i++)
        {
        
            my_arr = sort_lotto_nr[i];
            j = i -1;
            while (j>=0 && sort_lotto_nr[j] > my_arr)
            {
                sort_lotto_nr[j+1] = sort_lotto_nr[j];
                j= j-1;
            } //end while 
                sort_lotto_nr[j+1] = my_arr;
        } //end for 
    }//end fxn 
    
    
//implement function to check if the player has won any prices! 
    
  void compare_lottos(int users_lottonr[],int lottery_nrs[])
{//start fxn 
    register int i,j;
    int temp =0;
    char *no_prize = "\nSorry no Prices\n";
    char *worst_prize ="\nYou won Cinema Pass\n";
    char *middle_prize = "You won a Weekend away\n";
    char *good_prize ="You won a New car\n";
    char *jackpot = "Jackpot!\n";
    
    for (i=0; i<LOTTOSIZE;i++)
    {
        for (j=0; j<LOTTOSIZE; j++)
        {
            if ( *(users_lottonr +i) == *(lottery_nrs+j))
            {
            temp = temp +1;    
            }//end if 
        }//end nested for 
        
    }//end outer for
    printf("temp is %d",temp);
    if (temp < 3)
    {
        puts(no_prize);    
    }
    
    else if (temp == 3)
    {
        puts(worst_prize);
    }
    
    else if (temp == 4) 
    {
    puts(middle_prize);    
    }
    
    else if (temp == 5)
    {
    puts(good_prize);    
    }
    
    else if (temp == 6) 
    {
    puts(jackpot);    
    }
}//end fxn

//implement function 5 wich is a function to display the frequensy of the numbers entered by the user.
/*
function below made from looking at youtube and useing google. 
I dont fully understand it and I could'nt get it to keep the frequency for more then once of use. even thoe i tried with "static"
I can not take cradit for this part i just modified it to match my program and just wanted to have it there instead of leaving function 5 blank. 
*/
void lotto_frequency(int winning_lotto[], int lotto_numbers[])
{
    int register i,j;
    int static count_freq;
    for(i=0; i<LOTTOSIZE; i++)
    {
       
        count_freq = 1;
        for(j=i+1; j<LOTTOSIZE; j++)
        {
            //check if the duplicated element is found
            if(lotto_numbers[i]==lotto_numbers[j])
            {
                count_freq++;

                //make sure to not count the same element twice
                winning_lotto[j] = 0;
            }
            
        }

        //if frequency of current element is not counted 
        if(winning_lotto[i] != 0)
        {
            winning_lotto[i] = count_freq;
        }
    }

    
     // Print frequency of each element
     
    printf("\nFrequency of all elements of array : \n");
    
    for(i=0; i<LOTTOSIZE; i++)
    {
        if(winning_lotto[i] != 0)
        {
            printf("%d occurs %d times\n",lotto_numbers[i] , count_freq);
        }
    }
}




