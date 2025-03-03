#import<cstdio>



template<typename ...> static inline int gc(void) { return getchar(); }

static inline void read(int &x){int k,m=0;x=0;for(;;){k=gc();if(48<=k&&k<=57){x=k-48;break;}}for(;;){k=gc();if(k<48||k>57)break;x=x*10+k-48;}}



int N, d[262144], p, x, i;



main(){

    read(N);

    for(; i < N; d[x] = ++i)read(x);

    x = N;

    for(; --i;)

        if(p){

            if((d[i] < d[i + 1]) ^ (d[i + 1] < d[x]) ^ (d[x] < d[i])){

                ++p;

                x = i + 1;

            }

        }else

            if(d[i] < d[i + 1])--x;

            else++p;

    printf("%d", p);

}
