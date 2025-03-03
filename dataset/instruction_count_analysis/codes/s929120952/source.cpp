#include "stdc++.h"

using namespace std;



int n,t,a,h[1010];





int main()

{

    cin>>n>>t>>a;



    for (int i = 0; i < n; i++)

    {

        cin>>h[i];

    }



    

    int ans = 0;

    double min_diff = 1<<30;



    for (int i = 0; i < n; i++)

    {

        double temp = t - h[i] * 0.006;

        double difftemp = abs(a-temp);



        if(min_diff > difftemp){

            min_diff = difftemp;

            ans = i+1;

        }

    }

    

    cout << ans << endl;

    

    return 0;

}
