#include "stdc++.h"

using namespace std;



int N;

int p[8],q[8];

vector<int> dic(40325);

int idx=0;



int kaijo(int n){

  int ans=1;

  for(int i=1;i<=n;i++) ans*=i;

  return ans;

}



bool is_d_in_x(int d, int x){

  while(x>0){

    int res= x%10;

    if(res==d) return false;

    x/=10;

  }



  return true;

}



int digits(int x){

  int d=0;

  while(x>0){

    x/=10;

    d++;

  }

  return d;

}



void dfs(int d){

  if(digits(d)==N) {

    dic[idx]=d;

    idx++;



    return;

  }

  for(int i=1;i<=N;i++){



    if(is_d_in_x(i,d)){

      dfs(d*10+i);

    }

  }

}

int main() {



  cin>>N;



  for(int i=0;i<N;i++) cin>>p[i];

  for(int i=0;i<N;i++) cin>>q[i];

  int P=0,Q=0;

  for(int i=0;i<N;i++){

    P+=p[N-1-i]*long(pow(10,i));

  }

  for(int i=0;i<N;i++){

    Q+=q[N-1-i]*long(pow(10,i));

  }



  int l,r;



  dfs(0);

  sort(dic.begin(),dic.begin()+kaijo(N));



  int a,b;

  for(int i=0;i<kaijo(N);i++){

    if(dic[i]==P) a=i;

    if(dic[i]==Q) b=i;

  }

  cout<<abs(a-b)<<endl;









}
