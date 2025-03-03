#include "stdc++.h"

using namespace std;

#define ll long long int

#define endl "\n"

#define pb push_back

#define fo for(int i=0;i<n;i++)

#define clear cin.clear();cin.ignore(numeric_limits<streamsize>::max(), '\n');

#define loopSolve int t; cin>>t; while(t--){solve();}

//INT_MAX         2,147,483,647                       <10^10

//U_INT_MAX       4,294,967,295                       <10^10

//LONG_LONG_MAX   9,223,372,036,854,775,807           <10^18

//U_LONG_LONG_MAX 18,446,744,073,709,551,615          <10^18



/*ll power(int a, int b){

    return (ll)(pow(a,b)+0.5);

}*/



vector<int> gV(int n){

    vector<int> v;

    int input;

    fo { cin>>input; v.pb(input); }

    return v;

}



int* gA(int n){

    int* arr = new int[n];

    fo cin>>arr[i];

    return arr;

}





void solve(){

    int H,W,K;

    cin>>H>>W>>K;

    char** arr= new char*[H];

    for(int i=0;i<H;i++){

        arr[i]=new char[W];

    }



    for(int i=0;i<H;i++){

        for(int j=0;j<W;j++){

            cin>>arr[i][j];

        }

    }

    int range = (1<<H+W)- 1;

    ll ans=0;

    for(int i=0;i<=range;i++){

        int t=i,count=0;

        map<int,bool> row;

        map<int,bool>col;

//        char s[100];

        while(t>0){



            if(t&1==1){

//                s[count]='1';

                if(count<W){

                    col[count]=true;

                }else{

                    row[count-W]=true;

                }

            }

//            }else{

//                s[count]='0';

//            }

            t=t>>1;

            count++;

        }

//        s[count]='\n';

//        cout<<"\n-------------------------------"<<endl;

//        for(int i=0;i<5-count;i++)

//            cout<<0;

//        for(int i=count-1;i>=0;i--){

//            cout<<s[i];

//        }

//        cout<<endl;



        ll temp=0;

        for(int p=0;p<H;p++){

            if(row[p]){

//                cout<<"\tAlready Painted Row "<<p<<endl;

                continue;

            }

            for(int q=0;q<W;q++){

                if(col[q]){

//                    cout<<"\tAlready Painted Col "<<q<<endl;

                    continue;

                }

                if(arr[p][q]=='#'){

                    temp++;

//                    cout<<"\t\tFound # for "<<"("<<p<<","<<q<<")"<<endl;

                }

            }

        }

//        cout<<"\ttemp was "<<temp;

        if(temp==K){

            ans++;

        }



    }



    cout<<ans<<endl;









//    for(int i=0;i<H;i++){

//        for(int j=0;j<W;j++){

//            cout<<arr[i][j];

//        }

//        cout<<endl;

//    }



}









int main() {

	ios_base::sync_with_stdio(false);

    std::cin.tie(NULL);

    std::cout.tie(NULL);



    solve();

    //loopSolve;



	return 0;

}
