#include"stdc++.h"

using namespace std;

#define int long long  

#define mod 1000000007

#define am 998244353

#define INFi 2147483647

#define INFl 9223372036854775807LL

#define fi first

#define se second

#define be begin()

#define en end()

int abs(int a,int b){ 

  int c=max(a,b)-min(a,b);

  return c;

}

int gcd(int a,int b){//最大公約数

  int c=a%b;

  while(true){

    if(c==0) break;

    a=b;

    b=c;

    c=a%b;

  }

  return b;

}

bool IsPrime(int num){

  if (num < 2) return false;

  else if (num == 2) return true;

  else if (num % 2 == 0) return false;

  double sqrtNum = sqrt(num);

  for(int i=3;i<=sqrtNum;i+=2){

    if(num%i==0){

      return false;

    }

  }

}

int lcm(int a,int b){//最小公倍数

    return (a*b)/gcd(a,b);

}	    

signed main(){

// __builtin_ctz(N);      Nを２で何回割り切れるかを返す

//(n+1)*n/2;              １からNまでの総和を求める式

    cin.tie(0);

    ios::sync_with_stdio(false);

    int a,b,d,e,q=0;

    int c[1000]={};

    cin>>a>>b;

    for(int i=0;i<a;i++){

	cin>>d;

	for(int j=0;j<d;j++){

	    cin>>e;

	    c[e]++;

	}

    }

    for(int i=0;i<50;i++){

	if(c[i]==a) q++;

    }

    cout<<q<<"\n";

}
