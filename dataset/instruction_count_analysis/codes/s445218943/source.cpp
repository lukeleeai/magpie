#include<stdio.h>

#include<algorithm>



#define ll long long



class FIO

{

public:

    template<typename T>FIO& operator >>(T& x){ _R(x);return *this; }

    template<typename T>FIO& operator <<(T x){ _W(x);return *this; }

private:

    char f,c,a[25],i;

    template<typename T>inline void _R(T& x)

    {

        for(f=0;(c=getchar())<48;c==45&&(f=1));

        for(x=c^48;(c=getchar())>47;x=(x<<3)+(x<<1)+(c^48));

        if(f)x=-x;

    }

    template<typename T>inline void _W(T x)

    {

        if(sizeof(x)==1){ putchar(x);return; }

        if(x<0)putchar(45),x=-x;

        if(x>99) {

            for(i=0;x;x/=10)a[i++]=x%10;

            while(i--)putchar(a[i]+48);

        } else if(x>9) putchar(x/10+48),putchar(x%10+48);

        else putchar(x+48);

    }

}io;





ll a[200005];



int main()

{

    ll n,k;

    io>>n>>k;

    for(int i=0;i<n;++i)io>>a[i];

    std::sort(a,a+n);

    ll ans=0;

    for(int i=0,_i=n-k;i<_i;++i)

        ans+=a[i];

    io<<ans;

    return 0;

}