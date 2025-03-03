/******************************************************************************



Welcome to GDB Online.

GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,

C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.

Code, Compile, Run and Debug online from anywhere in world.



*******************************************************************************/

#include "stdc++.h"

using namespace std;



const int MAXN = 2E5+2;



struct FenwickTree{

    vector<int> F;

    void init(int n){

      F.assign(n+1, 0);

        

    }

    void update(int p, int val){

        for(int i=p; i< F.size(); i+= i&(-i)) F[i]+= val;

    }

    int get(int p){

        if(p==0) return 0;

        return F[p]+ get(p-(p&(-p)));

    }

};





int n;

string S;

vector<int> pos[26];

vector<pair<int,int> >P;

int spec = -1;

FenwickTree fen;

long long ret = 0;



bool check(){

    int cnt = 0;

    for(int i=0; i< 26; ++i) cnt+= (int)(pos[i].size()%2);

    return (cnt <= 1);

}



void pairing(){

		

    for(int i=0; i< 26; ++i){

			//	cerr << i << " " << pos[i].size() << "\n";

        int half = (int)(pos[i].size()+1)/2;

        for(int j=0; j< half; ++j){

					int o =(int)pos[i].size()-j-1;

		 			if(o==j) spec = pos[i][j];

        	else P.push_back({pos[i][j], pos[i][o]});

				}

            

    }

		sort(P.begin(), P.end());

		if(spec != -1) for(pair<int, int> v : P){

			ret += (v.second < spec || v.first > spec);

		}

    /*int cur = 1;

    for(int i=0; i< P.size(); ++i){

			id[cur] = P[i].first;

			id[n+1-cur] = P[i].second;

			++cur;

		}*/

}



signed main()

{

		//freopen("input.txt", "r", stdin);

	//	freopen("output1.txt", "w", stdout);

    cin >>  S;

    n = S.length();

    for(int i=0; i< n; ++i){

        pos[S[i]-'a'].push_back(i+1);

    }

    if(!check()){

        cout << -1;

        return 0;

    }



    pairing();

    fen.init(n);

    vector<int> X(n+1, -1);

    for(int i=0; i< P.size(); ++i){

    	X[P[i].first] = fen.get(P[i].first);

    	X[P[i].second] = fen.get(P[i].second);

			ret += 1LL*(X[P[i].first] + X[P[i].second]);

			fen.update(P[i].second, 1);

		}

	//cout << i << " " << X[i] << "\n";

		//cout << ret;

    //according to the first element

    /*fen.init(n);

    for(int i=n; i>= 1; --i){

			ret += 1LL*fen.get(id[i]);

			fen.update(id[i], 1);

		}*/

		cout << ret;

}