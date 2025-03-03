#include"stdc++.h"



#define pb push_back

#define eb emplace_back



using namespace std;



using vi = vector<int>;

using ll = long long;



int main(){

    ios :: sync_with_stdio(false);

    cout.precision(12);

    double n, k;

    cin >> n >> k;





//    // cerr << x << endl;



//     long double r = pow(2, n) - 1.0;

//     long double b = pow(2, x);

//     long double result = r/n;

//     result/=b;



    long double result=0;

    double p = 1.0/n;

    for(int i=1; i<=n; ++i){

        double x = k/i;

        int l = ceil(log2(x));

       // cerr << "L = " << l << endl;

        if(l>0)

            result+= p * (1/pow(2, l));

        else

            result+=p;

    }

    //result/=n;

    cout << result << endl;



    return 0;

}
