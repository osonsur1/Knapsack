#include <stdio.h>
#include <math.h>

void main(int argc, char **argv){
    int i,j,n,capacity,profits[10],weights[10],total_weight,total_profit,max_profit,max_weight,best_combination;
    FILE *f = fopen(argv[1], "r");
    max_profit = 0;
    max_weight = 0;

    //Reading CSV
    fscanf(f,"%d",&n);
    fscanf(f,"%d",&capacity);

    //Reading Profilts
    for(i=0;i<n-1;i++)
        fscanf(f,"%d,",&profits[i]);
    fscanf(f,"%d",&profits[i]);
    //Reading Weights
    for(i=0;i<n-1;i++)
        fscanf(f,"%d,",&weights[i]);
    fscanf(f,"%d",&weights[i]);

    int total_combinations = (int)pow(2,n);
    for(i=1;i<total_combinations;i++){
        total_weight = 0;
        total_profit = 0;
        for(j=0;j<n;j++){
            if((i & 1<<j) != 0){
                total_weight += weights[j];
                total_profit += profits[j];
            }
        }

        if(total_weight <= capacity){
            if(max_profit < total_profit){
                best_combination = i;
                max_profit = total_profit;
                max_weight = total_weight;
            }
        }
    }

    printf("Total Profit:\t%d\n",max_profit);
    printf("Total Weight:\t%d\n",max_weight);
    printf("Selected Items\n");
    for(j=0;j<n;j++){
        if((best_combination & 1<<j) != 0){
            printf("%d\t",weights[j]);
        }
    }
}


