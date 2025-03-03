#include<cstdio>

int N,a,i,r{2},A[101];main(){scanf("%d",&N);while(r--)for(i=N;i--;)scanf("%d",&a),A[i]=a+A[i+(A[i+1]>A[i])];printf("%d\n",*A);}