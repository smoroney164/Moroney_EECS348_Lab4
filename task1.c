

#include <stdio.h>

int main(){
    int score;

    //takes in the goal score from user
    printf("Enter the NFL score (Enter 1 to stop): ");
    scanf("%d", &score);

    //while score is negative, keeps asking for valid input
    while (score<0){
        printf("Score invalid! Please try again!: ");
        scanf("%d", &score);
    }

    //block runs as long as score is not 1, program will stop otherwise
    while (score != 1){

        printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);

        //goes through possible number of td2, td1, td, fg, and safetys to each reach the goal score
        for(int td2=0; td2 <= score/8; td2++){
            for(int td1=0; td1 <= score/7; td1++){
                for(int td=0; td <= score/6; td++){
                    for(int fg=0; fg <= score/3; fg++){
                        for(int safety=0; safety <= score/2; safety++){
                            int total_score = (td2*8)+(td1*7)+(td*6)+(fg*3)+(safety*2); //calcuates the total score per each combination

                            //will only print combination if it equals the goal score
                            if(total_score == score){
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, td1, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }

        //Asks again so that if the user enter 1, it will not run again.
        printf("Enter the NFL score (Enter 1 to stop): ");
        scanf("%d", &score);

    }
}
