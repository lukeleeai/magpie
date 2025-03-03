#include"stdc++.h"

using namespace std;

long double X[200100];

int N;

long long Count(long double len)

{

  long long Ans=0;

  for(int i=0;i<N;i++)

  {

    //Ans+=(long long)(X[i]/len);//解答引っ張ってきた人の条件。なぜか通る

    Ans+= ceil(X[i]/len)-1;//多少遅くなるがこっちが正解

  }

  return Ans;

}



int main()

	{

	  long long K;

	  cin>>N>>K;

	  for(int i=0;i<N;i++)

	{

		cin>>X[i];

		//X[i]-=0.1;

	}



  long double l=1,r=1e9;

  //while(l<r-0.1)//解答を引っ張ってきた人の条件。なぜかOKだったが、lとｒの整数部が異なる状態でループを出ると問題になるはず

	for(int i=0;i<300;i++)//OK log2(10^9)=30.二分探索だとこのやり方安定する。ただし、浮動小数のせいか34以上でないと通らず。

  //while(!((ceil(r)-ceil(l)) == 0))//NG:左端が初期値0のままだと、右端のceilは0にならず、無限ループ

	//while(!((floor(r)-floor(l)) == 0))//OK:右端がぴったり整数にならなければ成立.(あまりよくない)

  {

    long double mid=(l+r)/2;

    if(Count(mid)<=K) r=mid;

    else	l=mid;

  }

  cout<<(long long)(l+0.999)<<endl;

  return 0;

}