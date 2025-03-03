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



void secondThreadApproach(){

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



    int range = (1<<(H+W))- 1;                //2^(H+W)-1

    int ans=0;                              //int as ans can be at max 2^(H+W) and H,W<=6



    for(int mask=0;mask<=range;mask++){

        int count=0;

        for(int i=0;i<H;i++){

            for(int j=0;j<W;j++){

                if(arr[i][j]!='#') continue;

                //if ((mask&(1<<(H-i-1+W)|(1<<(W-j-1))))!=0) continue;              //For mask 10010 => R0,R1,C0,C1,C2. 1=>Painted, 0=>Not Painted

                if((mask&((1<<W+i)|(1<<j)))!=0) continue;                      //For mask 10010 => R1,R0,C2,C1,C2. 1=>Painted, 0=>Not Painted

                count++;

            }

        }

        if(count==K)

            ans++;

    }



    cout<<ans<<endl;

}



//https://atcoder.jp/contests/abc173/tasks/abc173_c

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



    int range = (1<<H+W)- 1;                //2^(H+W)-1

    ll ans=0;

    for(int i=0;i<=range;i++){

        int t=i,count=0;

        map<int,bool> row;

        map<int,bool>col;

        while(t>0){

            if(t&1==1){

                if(count<W) col[count]=true;

                else row[count-W]=true;

            }

            t=t>>1;

            count++;

        }



        ll temp=0;

        for(int p=0;p<H;p++){

            if(row[p]) continue;

            for(int q=0;q<W;q++){

                if(col[q]) continue;

                if(arr[p][q]=='#') temp++;

            }

        }

        if(temp==K) ans++;



    }



    cout<<ans<<endl;









}









int main() {

	ios_base::sync_with_stdio(false);

    std::cin.tie(NULL);

    std::cout.tie(NULL);



    secondThreadApproach();

    //solve();

    //loopSolve;



	return 0;

}
