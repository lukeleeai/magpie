#include <iostream>

#include <vector>



using namespace std;



int main(void) {

    int N;

    cin >> N;



    vector<int> a(N);

    int i, j;

    for (i=0; i<N; i++) {

        cin >> a[i];

    }



    int min_cost=1<<28LL;

    for (i=-100; i<=100; i++) {        

        int cost=0;

        for (j=0; j<N; j++) {

            cost += (a[j]-i)*(a[j]-i);

        }

        if (cost < min_cost) min_cost = cost;

    }

    cout << min_cost << endl;

    return 0;

}
