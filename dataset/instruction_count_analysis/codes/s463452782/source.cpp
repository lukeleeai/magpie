#include <iostream>

#include <iomanip>

#include <vector>

#include <algorithm>



using namespace std;



vector<int> buffer;



int dfs(int m, int sum, int rem){

        if(rem == 0){

                ++(buffer[sum]);

                return 1;

        }

        int retval = 0;

        for(int i = 1; i <= m; ++i){ retval += dfs(m, sum + i, rem - 1); }

        return retval;

}



int main(){

        cout << setprecision(10);

        while(true){

                int n, m, k;

                cin >> n >> m >> k;

                if(n == 0 && m == 0 && k == 0){ break; }

                buffer.resize(n * m + 1);

                fill(buffer.begin(), buffer.end(), 0);

                int num = dfs(m, 0, n);

                double answer = 0.0;

                for(int i = 0; i < buffer.size(); ++i){

                        if(i <= k){

                                answer += 1.0 * buffer[i] / num;

                        }else{

                                answer += (double)(i - k) * buffer[i] / num;

                        }

                }

                cout << answer << endl;

        }

        return 0;

}