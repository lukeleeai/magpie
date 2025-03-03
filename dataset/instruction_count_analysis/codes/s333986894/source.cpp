#include"stdc++.h"

#define model l,mid,num<<1

#define moder mid+1,r,num<<1|1

#define bug(k)  cout<<"text :"<<t<<endl

#define lowbit(k) k&-k

using namespace std;

typedef long long LL;

const LL mod=1e9+7;

const int M=1e5+5;

int main()

{

    int a,b;

    while(cin>>a>>b)

    {

        if((a&1)&&(b&1))puts("Yes");

        else puts("No");

    }

}
