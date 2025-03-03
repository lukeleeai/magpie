/*Lucky_Glass*/

#include<vector>

#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

using namespace std;



const int N=250;

#define fir first

#define sec second



int n,mod;



struct MNUM{

    int num;

    MNUM(){}

    MNUM(int x):num(x){}

    MNUM operator +(const MNUM &B)const&{return (1ll*num+B.num)%mod;}

    MNUM operator -(const MNUM &B)const&{return ((1ll*num-B.num)%mod+mod)%mod;}

    MNUM operator *(const MNUM &B)const&{return (1ll*num*B.num)%mod;}

    MNUM operator +=(const MNUM &B){return *this=(*this)+B;}

    MNUM operator -=(const MNUM &B){return *this=(*this)-B;}

    MNUM operator *=(const MNUM &B){return *this=(*this)*B;}

}dp[N*2+3][N+3],ans;



vector< pair<int,int> > per;



int main(){

    scanf("%d%d",&n,&mod);

    /*

    f(i) (0<=i<n) > g(i)

    f(i) (0<=i<n) > f(i) (n<=i<2n)

    */

    for(int i=0,Nf=2*n-1,Ng=2*n-1;i<2*n;i++){

		while(i*i+Nf*Nf>4*n*n && Nf>=0) Nf--;

		while(i*i+Ng*Ng>=n*n && Ng>=0) Ng--;

		if(i<n){

            int Vf=Nf,Vg=Ng;

            per.push_back(make_pair(Vg+1,Vf+1));

        }

        else{

            int Vf=Nf;

            per.push_back(make_pair(Vf+1,0));

        }

    }

    sort(per.begin(),per.end());

    // for(auto it : per) printf("%d %d\n",it.fir,it.sec);

    for(int k=0;k<=n;k++){

        memset(dp,0,sizeof dp);

        dp[0][0]=1;

        int cnt_2f=0; //前面有多少个 f(i) n<=i<2n

        int cnt_fg=0; //前面有多少个 f(i)/g(i) 0<=i<n

        for(int i=0;i<(int)per.size();i++){

            for(int j=0;j<=k;j++)

                if(per[i].sec==0)

                    //1.比它小的 cnt_2f 个f(i)；2.比它小的 j 个g(i)

                    dp[i+1][j]+=dp[i][j]*(per[i].fir-j-cnt_2f);

                else{

                    //前面比它小的有：1.选择的j个g(i)；2.出现的cnt_2f个f(i) i>=n

                    if(j<k) dp[i+1][j+1]+=dp[i][j]*(per[i].fir-j-cnt_2f);

                    //1.所有n个f(i) i>=n；2.前面出现的cnt_fg-j个f(i)；3.所有k个g(i)

                    dp[i+1][j]+=dp[i][j]*(per[i].sec-n-k-(cnt_fg-j));

                }

            if(per[i].sec==0) cnt_2f++;

            else cnt_fg++;

        }

        if(k%2) ans-=dp[per.size()][k];

        else ans+=dp[per.size()][k];

    }

    printf("%d\n",ans);

    return 0;

}
