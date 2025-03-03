#include<iostream>



using namespace std;



int bisc[2];



long long perm(int a){

    int pangkat = 1;

    if (a == 1) return 1;

    for(int i=1; i<a; i++){

        pangkat*=2;

    }

    return perm(a-1) + pangkat;

}



int main(){

    int N, P;

    cin >> N >> P;

    for(int i=1; i<=N; i++){

        int biscuits;

        cin >> biscuits;

        bisc[biscuits % 2]++;

    }

    long long ans = 1;

    for(int i=1; i<=bisc[0] ; i++) ans*=2;

    ans--;

    if(bisc[1] > 1){

        ans +=  ans*(perm(bisc[1] - 1)) + perm(bisc[1] - 1) ;

    }

    ans++;

    if (P == 0){

        cout << ans << endl;

    } else{

        long long pangkat = 1;

        for(int i=1; i<=N; i++){

            pangkat*=2;

        }

        cout << pangkat - ans << endl;

    }

}