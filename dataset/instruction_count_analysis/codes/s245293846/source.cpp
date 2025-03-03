#include<cstdio>

inline void scan(int &num){

int c=getchar();

num=0;

while(c<'0'||c>'9')c=getchar();

while(c>='0'&&c<='9'){num=num*10+c-'0';c=getchar();}

}

int main(){

int x,y;

long long  i=2;

long long result;

long long max=1000000000000000000;

long long imax;

scan(x);

scan(y);

imax=max/x;

if(x%y==0){printf("-1\n");return 0;}

for(i=1;i<y&&(y+i)<imax;i++){

result=x*(y-i);

if((result%y)){printf("%lld\n",result);return 0;}

result=x*(y+i);

if((result%y)){printf("%lld\n",result);return 0;}

}

for (i=y;i<imax;i++){

result=i*x;

if((result%y)){printf("%lld\n",result);return 0;}

}

printf("-1");

return 0;

}
