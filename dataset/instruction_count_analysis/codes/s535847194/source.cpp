/// Zhupengfei 2018 / public domain / abc103D



#include "stdc++.h"



#define right right1



using namespace std;



int right[100001];



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

    int R=-1e9, count=0;

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


