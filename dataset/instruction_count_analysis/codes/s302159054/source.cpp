#include "stdc++.h"



using namespace std;



int main() {

    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);



    int n;

    cin >> n;



    vector<int> score(n);

    vector<string> name(n);

    for (int i = 0 ;i < n ;i++)

        cin >> name[i] >> score[i];





    vector<int> order(n);

    iota(order.begin() , order.end() , 0);



    sort(order.begin() , order.end() , [&](int i , int j){

        if (name[i] != name[j])

            return name[i] < name[j];

        return score[i] > score[j];

    });



    for (int x : order)

        cout << x + 1 << '\n';

}
