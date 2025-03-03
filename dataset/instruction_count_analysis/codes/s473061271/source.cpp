//                               //

    // author : samars_diary //

    // 21-09-2020 │ 11:42:49 //

//                               //



#include <iostream>

using namespace std;



void solve(){

    long long int a, b, c, k, sum(0); 

    cin>> a >> b >> c >> k;

    while (k>0){

        if (k-a<=0 && a>0){

            sum=k ; break ;

        }else if (k-a>0 && a>0){

            sum += a ; k-=a ; a=-1 ;

        }else if (k-b<=0 && b>0){

            b=-1 ; break ;

        }else if (k-b>0 && b>0){

            k-=b ; b=-1 ;

        }else if (k-c<=0 && c>0){

            sum -= k ; break ;

        }else if (k-c>=0 && c>0){

            sum -= c ; break ;

        }else{

            break;

        }

    }

    cout<< sum <<'\n';

}



int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0), cout.tie(0);



    //#ifndef ONLINE_JUDGE

        //freopen("input.txt", "r", stdin);

        // freopen("output.txt", "w", stdout);

    //#endif



    int t = 1;

    while(t--){

        solve();

    }



    return 0;

}