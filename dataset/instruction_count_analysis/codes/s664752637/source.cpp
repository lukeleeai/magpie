//

//  AAAAAB.cpp

//  my_programs

//

//  Created by Jiatuo Zou on 7/22/20.

//  Copyright © 2020 Jiatuo Zou. All rights reserved.

//



#include <iostream>



int main()

{

    using namespace std;

    

    int n, m, k, f = 0, books = 0, ans = 0, f2 = 0;

    long long int ab[2][200000], prefixs_sum[2][200001] = {{0}};

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++){

        cin >> ab[0][i];

        prefixs_sum[0][i + 1] += (ab[0][i] + prefixs_sum[0][i]);

        if(prefixs_sum[0][i + 1] > k && f2 == 0){

            f = i;

            f2 = 1;

        }

    }

    if(prefixs_sum[0][n] <= k){

        f = n;

    }

    books = f;

    ans = f;

    for(int i = 0; i < m; i++){

        cin >> ab[1][i];

        prefixs_sum[1][i + 1] += (ab[1][i] + prefixs_sum[1][i]);

    }

    for(int i = f, j = 1; j <= m; ){

        if(prefixs_sum[1][j] > k){

            break;

        }

        if(k - prefixs_sum[0][i] >= prefixs_sum[1][j]){

            j++;

            books++;

        } else if(i > 0 && k - prefixs_sum[0][i] < prefixs_sum[1][j]){

            i--;

            books--;

        }

        ans = max(ans, books);

    }

    cout << ans << endl;

    return 0;

}
