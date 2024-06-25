#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of elements \n");
    scanf("%d",&n);
    int arr[n],sum;
    for(int i=0;i<n;i++)
    {
        printf("\n Enter Array Element %d  :",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n Enter the sum you want to find in subset   :");
    scanf("%d",&sum);
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
                dp[i][j]=0;
            if(j==0)
                dp[i][j]=1;
            if(arr[i-1]<=j)
            {
                dp[i][j]=dp[i][j-arr[i-1]] || dp[i-1][j];
            }
            else 
             dp[i][j]=dp[i-1][j];
        }

    }
            if(dp[n][sum]==1)
        {
            printf("\n True");
        }
        else 
            printf("\n Flase");

    return 0;
}
