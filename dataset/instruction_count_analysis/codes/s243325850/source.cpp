#include "stdc++.h"

using namespace std;

long long x,y,ans,sum;

int main(){   

    cin>>x>>y;

    ans=(y/x);

    while(ans)ans/=2,sum++;

    cout<<sum;

    return 0;

}