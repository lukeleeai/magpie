#include "stdc++.h"



#define rep(i,n) for(int i=0;i<(n);i++)



using namespace std;

using lint=long long;



class rolling_hash{

	static const long long base=10007,mod1=1e9+7,mod2=1e9+9;

	int len;

	vector<long long> pow1,pow2,h1,h2;

public:

	using hash_type=pair<long long,long long>;

	rolling_hash(){}

	rolling_hash(const string& s):len(s.length()),pow1(len+1),pow2(len+1),h1(len+1),h2(len+1){

		pow1[0]=pow2[0]=1;

		rep(i,len){

			pow1[i+1]=pow1[i]*base%mod1;

			pow2[i+1]=pow2[i]*base%mod2;

			h1[i+1]=(h1[i]*base+s[i])%mod1;

			h2[i+1]=(h2[i]*base+s[i])%mod2;

		}

	}

	template<class T>

	rolling_hash(const vector<T>& a):len(a.size()),pow1(len+1),pow2(len+1),h1(len+1),h2(len+1){

		pow1[0]=pow2[0]=1;

		rep(i,len){

			pow1[i+1]=pow1[i]*base%mod1;

			pow2[i+1]=pow2[i]*base%mod2;

			h1[i+1]=(h1[i]*base+a[i])%mod1;

			h2[i+1]=(h2[i]*base+a[i])%mod2;

		}

	}

	hash_type get_hash(int l,int r)const{

		assert(0<=l && l<=r && r<=len);

		auto res1=(h1[r]-h1[l]*pow1[r-l])%mod1; if(res1<0) res1+=mod1;

		auto res2=(h2[r]-h2[l]*pow2[r-l])%mod2; if(res2<0) res2+=mod2;

		return {res1,res2};

	}

	static hash_type get_hash(const string& s){

		long long res1=0,res2=0;

		rep(i,s.length()){

			res1=(res1*base+s[i])%mod1;

			res2=(res2*base+s[i])%mod2;

		}

		return {res1,res2};

	}

	template<class T>

	static hash_type get_hash(const vector<T>& a){

		long long res1=0,res2=0;

		rep(i,a.size()){

			res1=(res1*base+a[i])%mod1;

			res2=(res2*base+a[i])%mod2;

		}

		return {res1,res2};

	}



	hash_type f(int l,int r,char c){

		auto res1=(h1[r]-h1[l]*pow1[r-l])%mod1; if(res1<0) res1+=mod1;

		auto res2=(h2[r]-h2[l]*pow2[r-l])%mod2; if(res2<0) res2+=mod2;

		res1=(pow1[r-l]*c+res1)%mod1;

		res2=(pow2[r-l]*c+res2)%mod2;

		return {res1,res2};

	}

};



int main(){

	int n; cin>>n;

	vector<string> s(n);

	rep(i,n) cin>>s[i];



	vector<bool> L(1e6+1);

	rep(i,n) L[s[i].length()]=true;



	vector<rolling_hash::hash_type> H;

	rep(i,n){

		int len=s[i].length();



		int freq[128]={};

		rep(j,len) freq[s[i][j]]++;



		rolling_hash R(s[i]);

		for(int j=len;j>=0;j--){

			if(L[len-j+1]){

				for(int c='a';c<='z';c++) if(freq[c]) {

					H.emplace_back(R.f(j,len,c));

				}

			}

			if(j>0) freq[s[i][j-1]]--;

		}

	}



	sort(H.begin(),H.end());



	lint ans=0;

	rep(i,n){

		auto p=equal_range(H.begin(),H.end(),rolling_hash::get_hash(s[i]));

		ans+=p.second-p.first-1;

	}

	printf("%lld\n",ans);



	return 0;

}
