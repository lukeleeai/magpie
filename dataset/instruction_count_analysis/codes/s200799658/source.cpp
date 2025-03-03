#include "stdc++.h"

using namespace std;



#define rep(i,x,y) for(int i=(x);i<(y);++i)

#define debug(x) #x << "=" << (x)



#ifdef DEBUG

#define _GLIBCXX_DEBUG

#define dump(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl

#else

#define dump(x)

#endif



typedef long long int ll;

typedef pair<int,int> pii;

//template<typename T> using vec=std::vector<T>;



const int inf=1<<30;

const long long int infll=1LL<<58;

const double eps=1e-9;

const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};



template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){

	os << "[";

	for (const auto &v : vec) {

		os << v << ",";

	}

	os << "]";

	return os;

}



int p,q,a,n;



int gcd(int x,int y){

    if(y==0) return x;

    return gcd(y,x%y);

}



int dfs(int denom,int numer,int prev,int product,int num){

    int res=0;

    if((double)p/q-eps<=(double)numer/denom  and (double)numer/denom<=(double)p/q+eps) ++res;

    if(num==0) return res;



    {

        int tmp1=denom*prev,tmp2=numer*prev+denom*num;

        if((double)tmp2/tmp1<(double)p/q) return 0;

    }



    if((double)numer/denom>(double)p/q) return 0;



    int x=prev;

    while(true){

        if(product*x>a) break;

        res+=dfs(denom*x,numer*x+denom,x,product*x,num-1);

        ++x;

    }

    return res;

}



void solve(){

    while(cin >> p >> q >> a >> n){

        if(p==0 and q==0 and a==0 and n==0) break;

        cout << dfs(1,0,1,1,n) << endl;

    }

}



int main(){

	std::ios::sync_with_stdio(false);

	std::cin.tie(0);

	solve();

	return 0;

}