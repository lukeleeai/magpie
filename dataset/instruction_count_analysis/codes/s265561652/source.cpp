#include<cstdio>

#include<cstring>

#include<algorithm>

#include<deque>

using namespace std;

typedef long long ll;

ll n;

deque<int>x,y;

int t=2;

int main()

{

    scanf("%lld",&n);

    n++;

    int cnt=0;

    int f=0;

    while(1ll<<(f+1)<=n)

        f++;

    for(int i=f-1;i>=0;i--){

            t++;

            cnt+=2;

            x.push_front(t);

            y.push_front(t);

        if(n&1ll<<i){

            t++;

            cnt+=2;

            x.push_front(t);

            y.push_back(t);

        }

    }

    printf("%d\n",cnt);

    while(!x.empty()){

        printf("%d ",x.front());

        x.pop_front();

    }

    while(!y.empty()){

        printf("%d ",y.front());

        y.pop_front();

    }

}
