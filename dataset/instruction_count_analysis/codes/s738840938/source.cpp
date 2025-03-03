#include<cstdio>



#define LL long long

#define MAXN 100000

#define MOD 1000000007

LL fac[2*MAXN+5];

LL inv[2*MAXN+5];



LL Pow(LL x,LL p){

    LL ret=1;

    while(p){

        if(p&1)

            ret=ret*x%MOD;

        x=(x*x)%MOD;

        p>>=1;

    }

    return ret;

}



void Prep(int N){

    fac[0]=1;

    for(int i=1;i<=N;i++)

        fac[i]=fac[i-1]*i%MOD;

    //inv[fac[i]]=Pow(fac[i],MOD-2)=Pow(1,MOD-2)...Pow(i,MOD-2)

    //inv[fac[i-1]]=Pow(fac[i-1],MOD-2)=Pow(1,MOD-2)...Pow(i-1,MOD-2)=Pow(fac[i],MOD-2)/Pow(i,MOD-2)=inv[i]*i

    inv[0]=1;

    inv[N]=Pow(fac[N],MOD-2);

    for(int i=N-1;i>=1;i--)

        inv[i]=inv[i+1]*(i+1)%MOD;

}



LL C(int m,int n){

    return fac[m]*inv[n]%MOD*inv[m-n]%MOD;

}



int main(){

    int H,W,A,B;

    scanf("%d%d%d%d",&H,&W,&A,&B);

    Prep(H+W);

    LL Ans=0;

    for(int i=B+1;i<=W;i++){

        LL tmp1=C(H-A+i-2,i-1);

        //C(m+n-x-y-2,m-x-1)

        //(H-A,i) -> (H,W)

        LL tmp2=C(A+W-i-1,W-i);

        Ans=(Ans+(tmp1*tmp2)%MOD)%MOD;

    }

    printf("%lld",Ans);

}