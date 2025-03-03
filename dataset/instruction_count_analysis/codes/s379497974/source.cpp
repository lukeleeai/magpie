/// Zhupengfei 2018

/// Hereby declare: this program is in public domain.



/// Solution for problem: abc103D



#include "stdc++.h"



#ifdef LOCAL

#pragma GCC poison printf // To avoid fastio problems

#pragma GCC poison scanf

#endif



#define left left1erlerqwer

#define right right1rw0e9r



using namespace std;



pair<int, int> rq[100001]={};

vector<int> rsons[100001]={};

vector<int> lsons[100001]={};

int right[100001], left[100001]={};



int main(){

	ios::sync_with_stdio(false);

	cin.tie(NULL);

    int N, M;

    cin>>N>>M;

    int a, b;

    fill(right+1, right+N+1, 1e9);

    for(int i=1;i<=M;i++) {

        cin>>a>>b;

        right[a]=min(right[a], b);

    }

    int R=-1e9;

    int count=0;

    for(int i=1;i<=N;i++) {

        if(right[i]!=1e9) {

            if(i>=R) {

                count++;

                R=right[i];

            } else {

                R=min(R, right[i]);

            }

        }

    }

    cout<<count<<endl;

	return 0;

}


