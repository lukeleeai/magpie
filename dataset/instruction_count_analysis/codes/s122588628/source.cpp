#include "stdc++.h"

#define mp make_pair

#define ff first

#define ss second

using namespace std;

typedef long long LL;

typedef pair<LL, LL> PLL;

typedef pair<int, int> PII;

 

const PLL M = mp(1e9+7, 1e9+9);        ///Should be large primes

const LL base = 875329;               ///Should be a prime larger than highest value

const int N = 1e5+7;                 ///Highest length of string

 

ostream& operator<<(ostream& os, PLL hash) {

    return os<<"("<<hash.ff<<", "<<hash.ss<<")";

}

 

PLL operator+ (PLL a, LL x)     {return mp(a.ff + x, a.ss + x);}

PLL operator- (PLL a, LL x)     {return mp(a.ff - x, a.ss - x);}

PLL operator* (PLL a, LL x)     {return mp(a.ff * x, a.ss * x);}

PLL operator+ (PLL a, PLL x)    {return mp(a.ff + x.ff, a.ss + x.ss);}

PLL operator- (PLL a, PLL x)    {return mp(a.ff - x.ff, a.ss - x.ss);}

PLL operator* (PLL a, PLL x)    {return mp(a.ff * x.ff, a.ss * x.ss);}

PLL operator% (PLL a, PLL m)    {return mp(a.ff % m.ff, a.ss % m.ss);}

 

PLL pb[N];      ///powers of base mod M

///Call pre before everything

void pre() {

    pb[0] = mp(1,1);

    for (int i=1; i<N; i++)

        pb[i] = (pb[i-1] * base)%M;

}

 

///Calculates hashes of all prefixes of s including empty prefix

vector<PLL> hashList(string &s) {

    int n = s.size();

    vector<PLL> ans(n+1);

    ans[0] = mp(0,0);

 

    for (int i=1; i<=n; i++)

        ans[i] = (ans[i-1] * base + s[i-1])%M;

    return ans;

}

 

///Calculates hash of substring s[l..r] (1 indexed)

PLL Hash(vector<PLL> &hashlist, int l, int r) {

    int len = (r-l+1);

    return ((hashlist[r] - hashlist[l-1]*pb[len])%M+M)%M;

}

vector<PLL>hashVec;

int n; 

bool ok(int len) {



    for(int i =1 ; i+len-1 <= n ; i++ ) {

        

        PLL val1 = Hash(hashVec , i , i+len-1);

        

        for(int j = i+len ; j+len-1 <=n ; j++ ) {

            

            PLL val2 = Hash(hashVec , j , j+len-1);

            if(val1 == val2) return true;

        }

    }

    return false;

}





int main() {

    

    ios::sync_with_stdio(false);

    cin.tie(0);

    pre();

    

    

    string str;

    

    cin>>n>>str;

    

    hashVec = hashList(str);

    

    int lo = 0 , hi = n;

    int ans = 0;

    

    while(lo <= hi) {

        

        int mid = (lo+hi)/2;

        

        if(ok(mid)) {

            ans = mid;

            lo = mid+1;

        }

        else hi = mid-1;

    }

    cout<<ans<<'\n';

    return 0;

    



}