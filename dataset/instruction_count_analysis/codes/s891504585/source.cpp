

#include<stdio.h> 



long long max(long long a, long long b) { return (a > b)? a : b; } 



long long  knapSack(long long W, long long wt[], long long val[], long long n) 

{  

      

long long i, w; 

long long K[n+1][W+1]; 

  

   for (i = 0; i <= n; i++) 

   { 

       for (w = 0; w <= W; w++) 

       { 

           if (i==0 || w==0) 

               K[i][w] = 0; 

           else if (wt[i-1] <= w) 

                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 

           else

                 K[i][w] = K[i-1][w]; 

       } 

   } 

  

   return K[n][W]; 

} 





int main() 

{ 

	

	long long n,W;

	scanf("%lld %lld",&n,&W);

	long long val[n] ; 

	long long wt[n]; 

	for(int i=0;i<n;i++){

		scanf("%lld %lld",&wt[i],&val[i]);

	}

	printf("%lld", knapSack(W, wt, val, n)); 

	return 0; 

} 
