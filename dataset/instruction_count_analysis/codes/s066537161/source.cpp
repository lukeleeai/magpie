#include"stdc++.h"

using namespace std;



#define SIZE 100100

#define POS 1

#define NEG 0



int n;

long long arr[SIZE];



long long solve(long long sum, int index, int should){

    if(index == n){

        return 0;

    }



    long long ans = 0LL;



    sum += arr[index];

    if(sum <= 0 && should == POS){

        ans += (abs(sum) + 1);

        ans += solve(1, index + 1, NEG);

    }else if(sum >= 0 && should == NEG){

        ans += (abs(sum) + 1);

        ans += solve(-1, index + 1, POS);

    }else{

        ans += solve(sum, index + 1, 1 - should);

    }



    return ans;

}



int main(){

    #ifdef magUNbos

    freopen("a.in.c","r",stdin);

    #endif // magUNbos



    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);



    cin >> n ;

    for(int i = 0; i < n ; i++){

        cin >> arr[i];

    }



    long long a1 = solve(0LL, 0, POS);

    long long a2 = solve(0LL, 0, NEG);



    cout << min(a1, a2) << endl;

}
