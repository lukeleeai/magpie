#import<ios>

long n,k,a;main(){for(scanf("%d%d",&n,&k);k<n+2;)a+=1-(k+~n)*k++;printf("%d",a%=n=1e9+7);}