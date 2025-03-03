#include"stdc++.h"

using namespace std;

#define int long long

int a[3*114514];

int b[3*114514];

int c[3*114514];

signed main(){

  int n;

  cin>>n;

  for(int i=0;i<n*3;i++) cin>>a[i];

  priority_queue<int,vector<int>,greater<int> > q1;

  priority_queue<int> q2;

  memset(b,0,sizeof(b));

  memset(c,0,sizeof(c));

  int tmp1=0,tmp2=0;

  for(int i=0;i<n;i++){

    q1.push(a[i]);

    tmp1+=a[i];

    b[i]=tmp1;

    q2.push(a[3*n-1-i]);

    tmp2+=a[3*n-1-i];

    c[3*n-1-i]=tmp2;

  }

  for(int i=n;i<n*3;i++){

    q1.push(a[i]);

    tmp1+=a[i];

    int k=q1.top();q1.pop();

    tmp1-=k;

    b[i]=tmp1;

    q2.push(a[3*n-1-i]);

    tmp2+=a[3*n-1-i];

    k=q2.top();q2.pop();

    tmp2-=k;

    c[3*n-1-i]=tmp2;

  }

  int ans=-(1LL<<55LL);

  for(int i=n-1;i<2*n;i++){

    ans=max(ans,b[i]-c[i+1]);

  }

  cout<<ans<<endl;

  return 0;

}
