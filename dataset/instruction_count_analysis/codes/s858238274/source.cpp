#include<iostream>

#include <vector>

#include <algorithm>

#include <string>

using namespace std;



int main(){

    int N; cin >> N;

    vector<int> v;

    int cnt4=0, cnt2=0;

    for(int i=0; i<N; ++i){

        int a; cin >> a;

        v.push_back(a);

    }

    sort(v.rbegin(), v.rend());

    long long ans=0;

    int cnt=0;

    for(int i=0; i<N-1; ++i){

        if(v[i]==v[i+1]){

            if(ans==0) ans =1;

            ans *= v[i];

            cnt++;

            i+=1;

        }

        if(cnt==2) break;

    }

    cout << ans << endl;

    

    return 0;

}