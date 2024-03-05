//Ali Hikmet Sagaltici
//ID: 2585313


#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define STOP 10

int roll_a_dice(void);
int play_computer(void);
int play_user(void);
void scoresheet(int, int, int, int);

int main()
{
    int rounds, n=1;
    int player, computer;
    int x;
    int p_score, c_score; //scores of player and computer
    srand(time(NULL));



    printf("Welcome to the Balut game.\nLet's get started!\n");

    printf("How many rounds would you like to play?:");
    scanf("%d", &rounds);

    do //deciding for who's starting first
    {
        player=roll_a_dice();
        computer=roll_a_dice();
        if(player==computer)
        {
            printf("Dices are the same! Re-rolling...\n");
        }

    }
    while(player==computer);


    printf("I have rolled the dice and got %d!\n", computer);
    printf("I have rolled the dice for you and you got %d!\n", player);
//depending on the first dice outcome, playing order is specified in below two loops
    if(player>computer)
    {
        do
        {
            printf("\nRound %d -- Your Turn:", n);
            printf("\n=============================================\n");
            p_score = p_score+play_user();
            printf("\nRound %d -- My turn:", n);
            printf("\n=============================================\n");
            c_score= c_score+play_computer();
            scoresheet(p_score, c_score, n, rounds);
            n++;
        }
        while(n<=rounds);

    }
    else if(computer>player)
    {
        do
        {
            printf("\nRound %d -- My turn:", n);
            printf("\n=============================================\n");
            c_score= c_score+play_computer();
            printf("\nRound %d -- Your Turn:", n);
            printf("\n=============================================\n");
            p_score = p_score+play_user();
            scoresheet(p_score, c_score, n, rounds);
            n++;
        }
        while(n<=rounds);

    }



    return 0;
}


int roll_a_dice(void) //dice rolling function
{
    int a;
    a = (1 + (int) rand() % 6);

    return a;
}
//user function
int play_user(void)
{
    int d1, d2, d3, d4, d5; //dices
    int v1=0, v2=0, v3=0, v4=0, v5=0;
    int val5=0, val6=0; //for checking if it's 5s or 6s
    char keep;
    d1= roll_a_dice();
    d2= roll_a_dice();
    d3= roll_a_dice();
    d4= roll_a_dice();
    d5= roll_a_dice();
    printf("I rolled them for you and you got:\n");
    printf("[DICE 1]= %d, [DICE 2]= %d, [DICE 3]=%d, [DICE 4]=%d, [DICE 5]=%d \n", d1, d2, d3, d4, d5);
    printf("\n\nWhich ones would you like to keep?");

    fflush(stdin);
    scanf("%c", &keep);
    while(keep!=STOP)
    {
        if(keep==49)
        {
            v1=1;
        }
        if(keep==50)
        {
            v2=1;
        }
        if(keep==51)
        {
            v3=1;
        }
        if(keep==52)
        {
            v4=1;
        }
        if(keep==53)
        {
            v5=1;
        }
        scanf("%c", &keep);
    }
    if(v1==0) //depending on the v outcome, this will reroll the specified dices
        d1= roll_a_dice();
    if(v2==0)
        d2= roll_a_dice();
    if(v3==0)
        d3= roll_a_dice();
    if(v4==0)
        d4= roll_a_dice();
    if(v5==0)
        d5= roll_a_dice();

    printf("I rolled them for you and you got:\n");
    printf("[DICE 1]= %d, [DICE 2]= %d, [DICE 3]=%d, [DICE 4]=%d, [DICE 5]=%d \n", d1, d2, d3, d4, d5);
//below here is checks for the outcomes of the dices
    if(d1=5)
        val5++;
    if(d2=5)
        val5++;
    if(d3=5)
        val5++;
    if(d4=5)
        val5++;
    if(d5=5)
        val5++;

    if(d1=6)
        val6++;
    if(d2=6)
        val6++;
    if(d3=6)
        val6++;
    if(d4=6)
        val6++;
    if(d5=6)
        val6++;

    if(d5==d4 && d4==d3 && d3==d2 && d2==d1)
    {
        return (d1+d2+d3+d4+d5+20);
    }
    else if(val6>=val5 &&val6>1)
    {
        return (val6*6);
    }
    else if(val5>6)
    {
        return (val5*5);
    }

    else if(d5>d4 && d4>d3 && d3>d2 && d2>d1)
    {
        return (d1+d2+d3+d4+d5);
    }
}

int play_computer(void)
{
    int d1, d2, d3, d4, d5;
    int rerolling=0; //rerolling condition for computer
    int val5, val6;
    d1= roll_a_dice();
    d2= roll_a_dice();
    d3= roll_a_dice();
    d4= roll_a_dice();
    d5= roll_a_dice();
    printf("\nI rolled the dice and got:");
    printf("[DICE 1]= %d, [DICE 2]= %d, [DICE 3]=%d, [DICE 4]=%d, [DICE 5]=%d \n", d1, d2, d3, d4, d5);

//rerolling condition checks
    if(d1!=1 && d2==2 && d3==3 && d4==4 && d5==5)
    {
        d1= roll_a_dice();
        printf("\nRerolling dice 1...");
        rerolling=1;
    }
    else if(d1==1 && d2!=2 && d3==3 && d4==4 && d5==5)
    {
        d2=roll_a_dice();
        printf("\nRerolling dice 2...");
        rerolling=1;
    }
    else if(d1==1 && d2==2 && d3!=3 && d4==4 && d5==5)
    {
        d3=roll_a_dice();
        printf("\nRerolling dice 3...");
        rerolling=1;
    }
    else if(d1==1 && d2==2 && d3==3 && d4!=4 && d5==5)
    {
        d4=roll_a_dice();
        printf("\nRerolling dice 4...");
        rerolling=1;
    }
    else if(d1==1 && d2==2 && d3==3 && d4==4 && d5!=5)
    {
        d5=roll_a_dice();
        printf("\nRerolling dice 5...");
        rerolling=1;
    }
    else if(d1!=2 && d2==3 && d3==4 && d4==5 && d5==6)
    {
        d1=roll_a_dice();
        printf("\nRerolling dice 1...");
        rerolling=1;
    }
    else if(d1==2 && d2!=3 && d3==4 && d4==5 && d5==6)
    {
        d2=roll_a_dice();
        printf("\nRerolling dice 2...");
        rerolling=1;
    }
    else if(d1==2 && d2==3 && d3!=4 && d4==5 && d5==6)
    {
        d3=roll_a_dice();
        printf("\nRerolling dice 3...");
        rerolling=1;
    }
    else if(d1==2 && d2==3 && d3==4 && d4!=5 && d5==6)
    {
        d4=roll_a_dice();
        printf("\nRerolling dice 4...");
        rerolling=1;
    }
    else if(d1==2 && d2==3 && d3==4 && d4==5 && d5!=6)
    {
        d5=roll_a_dice();
        printf("\nRerolling dice 5...");
        rerolling=1;
    }
    if(rerolling==1)
    {
        printf("\nI got [DICE 1]= %d, [DICE 2]= %d, [DICE 3]=%d, [DICE 4]=%d, [DICE 5]=%d \n", d1, d2, d3, d4, d5);
    }


//below here is scoring conditions and checks
    if(d1=5)
        val5++;
    if(d2=5)
        val5++;
    if(d3=5)
        val5++;
    if(d4=5)
        val5++;
    if(d5=5)
        val5++;

    if(d1=6)
        val6++;
    if(d2=6)
        val6++;
    if(d3=6)
        val6++;
    if(d4=6)
        val6++;
    if(d5=6)
        val6++;

    if(d5==d4 && d4==d3 && d3==d2 && d2==d1)
    {
        return (d1+d2+d3+d4+d5+20);
    }
    else if(val6>=val5 && val6>1)
    {
        return (val6*6);
    }
    else if(val5>6)
    {
        return (val5*5);
    }

    else if(d5>d4 && d4>d3 && d3>d2 && d2>d1)
    {
        printf("\nLucky me!");
        return (d1+d2+d3+d4+d5);
    }

}
void scoresheet(int p_score, int c_score, int n, int rounds)
{
    printf("\n\nOur scores after round %d", n);
    printf("\n===============================\n");
    printf("\nYOUR SCORE             MY SCORE\n");
    printf(" %d                       %d\n", p_score, c_score);
    if(rounds==n)
    {
        if(p_score>c_score)
        {
            printf("\nYOU ARE THE WINNER!");
        }
        else if(c_score>p_score)
        {
            printf("\nI AM THE WINNER!");
        }
        else
        {
            printf("\n TIE!");
        }
    }

}
