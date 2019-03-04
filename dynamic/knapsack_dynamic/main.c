#include <stdio.h>
#include <math.h>

void main(int argc, char **argv){
    int i,j,n,capacity,profits[11],weights[11],total_weight,total_profit,max_profit,max_weight,best_combination;
    FILE *f = fopen(argv[1], "r");
    max_profit = 0;
    max_weight = 0;

    //Reading CSV
    fscanf(f,"%d",&n);
    fscanf(f,"%d",&capacity);

    //int benefits[n+1][capacity+1];
    int benefits[100][100][2];


    //Reading Profilts
    for(i=1;i<n;i++)
        fscanf(f,"%d,",&profits[i]);
    fscanf(f,"%d",&profits[i]);

    //Reading Weights
    for(i=1;i<n;i++)
        fscanf(f,"%d,",&weights[i]);
    fscanf(f,"%d",&weights[i]);

    // Initialize first row to zero
    for(i=0;i<capacity+1;i++)
        benefits[0][i][0] = 0;

    for(i=1;i<n+1;i++){
        benefits[i][0][0] = 0; //Initialize first column as zero
        for(j=1;j<capacity+1;j++){
            if((weights[i] <= j) && (benefits[i-1][j][0] < (benefits[i-1][j-weights[i]][0] + profits[i]))){
                benefits[i][j][0] = benefits[i-1][j-weights[i]][0] + profits[i];
                benefits[i][j][1] = 1;
                max_weight = j;
            }else{
                benefits[i][j][0] = benefits[i-1][j][0];
                benefits[i][j][1] = 0;
            }
        }
    }

    printf("Total Profit:\t%d\n",benefits[n][capacity][0]);
    printf("Total Weight:\t%d\n",max_weight);
    printf("Selected Items\n");

    i = n;
    j = capacity;
    while(benefits[i][j][0] != 0){
        if(benefits[i][j][1] == 1){
            printf("%d\t",weights[i]);
            j = j-weights[i];
            i = i-1;
        }else{
            i = i-1;
        }
    }
}
