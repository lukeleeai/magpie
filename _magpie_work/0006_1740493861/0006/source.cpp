#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, cnt;

    while(cin >> n){
        vector<bool> prime(n + 1, false);
        prime[1] = true; // 1 is not a prime number

        // Sieve of Eratosthenes
        for(int j = 2; j*j <= n; j++){
            if(prime[j] == false){
                for(int k = j*j; k <= n; k += j){
                    prime[k] = true;
                }
            }
        }

        cnt = 0;
        for(int i = 2; i <= n; i++){
            if(prime[i] == false) cnt++;
        }

        cout << cnt << endl;
    }
}
