#include "stdc++.h"

using namespace std;

static const long long MOD=1000000007;

#include <boost/multiprecision/cpp_dec_float.hpp>

#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;

// 任意長整数型

using Bint = mp::cpp_int;

// 仮数部が1024ビットの浮動小数点数型(TLEしたら小さくする)

using Real = mp::number<mp::cpp_dec_float<1024>>;



int main(){

  long long N;

  cin>>N;

  Bint A[200010];

  Bint sum=0;

  for(long long i=0;i<N;i++){

    cin>>A[i];

    sum+=A[i];

  }

  Bint ans=0;

  sum-=A[0];

  for(long long i=0;i<N-1;i++){

    //cout<<ans<<" "<<sum<<endl;

    ans+=A[i]*sum;

    ans%=MOD;

    sum-=A[i+1];

  }

  

  cout<<ans<<endl;

  return 0;

}



 



 