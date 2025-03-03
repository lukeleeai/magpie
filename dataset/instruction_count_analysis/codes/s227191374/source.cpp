#include<iostream>

#include<vector>

#include<math.h>

#include<complex>

double PI=acos(-1);



template<typename T>

class FFT{

  private:

    using Complex = std::complex<long double>;

    std::vector<Complex> C;

    void DFT(std::vector<Complex> &F,int n,int sig=1){

        if(n==1) return;

        std::vector<Complex> f0(n/2),f1(n/2);

        for(int i=0;i<n/2;++i){

            f0[i]=F[2*i];

            f1[i]=F[2*i+1];

        }

        DFT(f0,n/2,sig);

        DFT(f1,n/2,sig);

        Complex z(cos(2.0*PI/n),sin(2.0*PI/n)*sig),zi=1;

        for(int i=0;i<n;++i){

            if(i<n/2) F[i]=f0[i]+zi*f1[i];

            else F[i]=f0[i-n/2]+zi*f1[i-n/2];

            zi*=z;

        }

        return;

    }

    void invDFT(std::vector<Complex> &f,int n){

        DFT(f,n,-1);

        for(int i=0;i<n;++i){

            f[i]/=n;

        }

        return;

    }

  public:

    FFT(const std::vector<T> &A,const std::vector<T> &B){

        int n=1;

        while(n<=A.size()+B.size()){

            n*=2;

        }

        std::vector<Complex> h(n,Complex(0)),g(n,Complex(0));

        for(int i=0;i<n;++i){

            if(i<A.size()) h[i]=Complex(A[i]);

            if(i<B.size()) g[i]=Complex(B[i]);

        }

        DFT(h,n);

        DFT(g,n);

        C.resize(n);

        for(int i=0;i<n;++i) C[i]=h[i]*g[i];

        invDFT(C,n);

        for(int i=0;i<n;++i) if(T(C[i].real())!=C[i].real()){

            C[i]=Complex(C[i].real()+0.5);

        }

    }

    T operator[](int k)const{return C[k].real();}

};



int main(){

    int N;

    long long M;

    std::cin>>N>>M;

    std::vector<int> A(N);

    int MAX_A=0;

    for(int i=0;i<N;++i){

        std::cin>>A[i];

        MAX_A=std::max(MAX_A,A[i]);

    }

    std::vector<long long> cnt(MAX_A+1);

    for(int i=0;i<N;++i){

        cnt[A[i]]++;

    }

    FFT<long long> C(cnt,cnt);

    long long ans=0;

    for(int i=2*MAX_A;i>=0;--i){

        if(M>=C[i]){

            ans+=i*C[i];

            M-=C[i];

        }else{

            ans+=i*M;

            break;

        }

    }

    std::cout<<ans<<std::endl;

}