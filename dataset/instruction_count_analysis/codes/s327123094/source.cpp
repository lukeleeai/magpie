#include "stdc++.h"

using namespace std;



#define rep(i,x,y) for(int i=(x);i<(y);++i)

#define debug(x) #x << "=" << (x)



#ifdef DEBUG

#define _GLIBCXX_DEBUG

#define show(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl

#else

#define show(x)

#endif



typedef long long int ll;

typedef pair<int,int> pii;

template<typename T> using vec=std::vector<T>;



const int inf=1<<30;

const long long int infll=1LL<<62;

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





//base=9973,mod=999999937LL, 1000000007LL;

struct rolling_hash{

    int mnum;

	std::string str;

    long long int base;

	std::vector<long long int> mod;

    std::vector<vector<long long int>> hash,pow;



	rolling_hash(const std::string &str,long long int base,std::vector<long long int> mod):mnum(mod.size()),str(str),base(base),mod(mod){

		int size=str.size();

		hash=std::vector<std::vector<long long int>>(mnum,std::vector<long long int>(size+1));

		pow=std::vector<std::vector<long long int>>(mnum,std::vector<long long int>(size+1));



		for(int i=0; i<mnum; ++i){

            hash[i][0]=0;

            pow[i][0]=1;

        }

        for(int i=0; i<mnum; ++i){

            long long int m=mod[i];

    		for(int j=1; j<size+1; ++j){

    			pow[i][j]=pow[i][j-1]*base%m;

    			hash[i][j]=(hash[i][j-1]*base+str[j-1])%m;

    		}

        }

	}



	long long int compute_hash(int l,int r,int i){ //[l,r)

		return (hash[i][r]-hash[i][l]*pow[i][r-l]%mod[i]+mod[i])%mod[i];

	}



    bool match(int l,int r,const std::vector<long long int> &hs){

        for(int i=0; i<mnum; ++i) if(compute_hash(l,r,mod[i])!=hs[i]) return false;

        return true;

    }

};



struct rolling_hash64{

    typedef unsigned long long int ull;

	std::string str;

    ull base;

    std::vector<ull> hash,pow;



	rolling_hash64(const std::string &str,ull base):str(str),base(base){

        int size=str.size();

        hash.resize(size+1);

        pow.resize(size+1);

        hash[0]=0;

        pow[0]=1;

        for(int i=1; i<size+1; ++i){

            pow[i]=pow[i-1]*base;

            hash[i]=hash[i-1]*base+str[i-1];

        }

	}



	ull compute_hash(int l,int r){ //[l,r)

		return hash[r]-hash[l]*pow[r-l];

	}



    bool match(int l1,int r1,int l2,int r2){

        return compute_hash(l1,r1)==compute_hash(l2,r2);

    }

};



void solve(){

    int n,m;

    string s;

    cin >> n >> m >> s;



    rolling_hash64 roriha(s,9973);

    vector<unsigned long long int> v;

    int l=0,r=1;

    rep(i,0,m){

        string q;

        cin >> q;

        if(q=="R++") ++r;

        if(q=="R--") --r;

        if(q=="L++") ++l;

        if(q=="L--") --l;

        v.push_back(roriha.compute_hash(l,r));

    }

    sort(v.begin(),v.end());

    v.erase(unique(v.begin(),v.end()),v.end());

    cout << v.size() << endl;

}



int main(){

    std::cin.tie(0);

    std::ios::sync_with_stdio(false);

    cout.setf(ios::fixed);

    cout.precision(10);

    solve();

    return 0;

}