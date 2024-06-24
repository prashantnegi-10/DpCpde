#include <stdio.h>
    int Max (int a, int b)
    {
        return (a>b?a:b);
    }
    int main()
    {
        int n , w;
        printf("Enter number of elements for 0/1 knapsack and aslo provide weight of napsack \n");
        scanf("%d%d",&n,&w);
        int wt[n],val[n];
        for(int i=0 ; i<n;i++)
        {
            printf("\n Enter weight for %d item :",i+1);
            scanf("%d",&wt[i]);
            printf("\n Enter Value for %d item  :",i+1);
            scanf("%d",&val[i]);
            printf("\n");
        }
        int dp[n+1][w+1];
            for(int i =0 ; i<n+1;i++)
        {
            for(int j=0; j<w+1;j++)
            {
                dp[i][j]=0;
            }
        }
       // memset(dp,0,sizeof(dp));
        for(int i =0 ; i<n+1;i++)
        {
            for(int j=0; j<w+1;j++)
            {
                
                if(i==0 || j==0)
                    dp[i][j]=0;
                else 
                  if(wt[i-1]<=j)
                  dp[i][j]=Max(val[i-1]+dp[i-1][j-wt[i-1]] , dp[i-1][j]);
                  else
                  dp[i][j]=dp[i-1][j];
            }
            
        }
        
        printf("\n Solution is :%d" , dp[n][w]);
        
        return 0;
    }
