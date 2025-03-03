#include <iostream>

#include <algorithm>

using namespace std;



int main()

{

    int N;

    pair<int, int> A[100000];

    cin >> N;

    for (int i = 0; i < N; i++)

    {

        pair<int, int> temp;

        temp.second = i;

        cin >> temp.first;

        A[i] = temp;

    }

    sort(A, A + N);

    int result = 0;

    for(int i = 0; i < N; i++)

        if(abs(A[i].second - i) % 2 != 0)

            result++;

    cout << result / 2 << endl;

    return 0;

}
