#include <stdio.h>
int Sumcheck(int arr[],int n, int sum)
{
    int dp[n+1][sum+1];
   /* for(int i=0 ;i<n;i++)
    {
        printf("\t %d",arr[i]);
    }
    printf("\n sum %d = \n",sum);
    */
    for(int i=0;i<sum+1;i++)
    {
        dp[0][i]=0;
        if(i<n+1)
        {
            dp[i][0]=1;
        }
    }

    for(int i=1; i<n+1 ;i++)
    {   
        for( int j=1 ;j<sum+1;j++)
        {
          /*  if(i==0)
                dp[i][j]=0;
            if(j==0)
                dp[i][j]=1;*/
        if(arr[i-1]<=j)
            dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
        else 
        dp[i][j]=dp[i-1][j];
        }
    }
      /*  for(int i=0;i<sum+1;i++)
    printf("\t %d",i);
    printf("\n");
    for(int i=0 ;i<n+1 ;i++)
    {   printf("%d",i);
        for(int j=0 ;j<sum+1;j++)
        {
            printf( "\t %d" ,dp[i][j]);
        }
        printf("\n");
    }*/
    if(dp[n][sum]==1)
     return 1;
    else
        return 0;
}


int main()
{
   int n;
   printf("Enter the number of array elements    ");
   scanf("%d",&n);
   int arr[n],sum=0;
    for(int i=0 ;i<n ;i++)
    {
        printf("\n Enter the %d element  :",i+1);
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    if(sum%2!=0)
    {
        printf("\n False \n");
    }
    else
    {
        int check = Sumcheck(arr,n,sum/2);
        printf(" \n Check = %d",check);
        if(check==1)
        
            printf("\n True \n");
        
        else 
            printf("\n  False \n");
    }
    return 0;
}



