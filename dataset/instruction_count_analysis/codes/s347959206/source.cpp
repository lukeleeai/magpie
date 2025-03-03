#import<cstdio>

int main(){int K,n,i=-1,j,k;scanf("%d",&K);printf("%d",n=(K+3)/4*2);while(++i<n){puts("");j=-1;while(++j<n)printf("%d ",((k=i%2*n+(i+j)%n)>=K?k-n:k)%K+1);}}