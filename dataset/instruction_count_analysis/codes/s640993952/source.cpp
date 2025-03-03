#include "stdc++.h"

using namespace std;

 

#define lli long long int

#define REP(i,s,n) for(int i=s;i<n;i++)

#define NUM 2520

#define INF (1LL<<50)

#define DEBUG 0

#define mp(a,b) make_pair(a,b)

#define SORT(V) sort(V.begin(),V.end())

#define PI (3.141592653589794)

#define TO_STRING(VariableName) # VariableName

#define LOG(x) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<endl;

#define LOG2(x,y) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<endl;

#define LOG3(x,y,z) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;

#define LOG4(w,x,y,z) if(DEBUG)cout<<TO_STRING(w)<<"="<<w<<" "<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;

 

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }

template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }



lli x[30][30];

lli d;

lli distance(lli i,lli j){



	lli ans = 0;



	REP(k,0,d){



		lli diff = x[i][k]-x[j][k];

		ans += (diff)*diff;

	}



	return ans;

}



bool judge(lli num){

	for(lli i=1;i*i<=num;i++){

		if(i*i==num){

			return true;

		}

	}

	

		return false;



}



int main(){



	lli n;



	cin>>n>>d;



	REP(i,0,n)REP(j,0,d)cin>>x[i][j];



	lli cnt=0;

	REP(i,0,n)REP(j,i+1,n){

		if(judge(distance(i,j)))cnt++;

	}

	cout<<cnt<<endl;



    return 0;

}