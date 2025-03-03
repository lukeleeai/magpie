#include <iostream>

#include <algorithm>

#include <vector>

#include <cmath>

#include <string>

#include <set>

#include <map>

#include <unordered_map>

#include <iomanip>

#include <stack>

#include <queue>

#include <deque>

using namespace std;

 

long long mod = 1000000007;

const long long N=2e5+10;



int a[N],b[2*N];

int main() {

    

    long long n, k;

    

    cin>>n>>k;

    

    for(int i=1;i<=n;i++){

        cin>>a[i];

    }

    k=min(k, 1ll + 50);

    

    while(k--){

        for(int i=1;i<=n;i++){

            b[i]=0;

        }

        

        for(int i=1;i<=n;i++){

            int l = max(1,i-a[i]);

            int r = i + a[i];

            

            b[l]++;

            b[r+1]--;

        }

        

        for(int i=1;i<=n;i++){

            

            b[i]=b[i]+b[i-1];

        

        }

        

        for(int i=1;i<=n;i++){

            a[i]=b[i];

        }

    }

    

    for(int i=1;i<=n;i++){

        cout<<a[i]<<' ';

    }

    return 0;

}
