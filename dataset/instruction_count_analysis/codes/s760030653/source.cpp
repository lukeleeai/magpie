#pragma GCC optimize("Ofast")

#pragma GCC target ("avx")

#pragma GCC optimize("unroll-loops")



#include <stdio.h>

#include <utility>



// 入力

constexpr unsigned int MAX_INPUT_SIZE = 3'000'000; //'

char Input[MAX_INPUT_SIZE];

char* input = Input;



inline unsigned int get(void){

    unsigned int res = 0; char c;

    while((c = *(input++) - '0') >= 0) res = 10 * res + c;

    return res;

}

// 出力

constexpr unsigned int MAX_OUTPUT_SIZE = 3'000'000; //'

char Output[MAX_INPUT_SIZE];

char* output = Output;



constexpr unsigned int digit_len = 1;

constexpr unsigned int MAX_D_SIZE = 10;

struct NoName{

    char S[MAX_D_SIZE][digit_len + 1];

    char T[MAX_D_SIZE][digit_len + 1];

    constexpr NoName(void):S(), T(){

        for(unsigned int i = 0; i < MAX_D_SIZE; ++i){

            unsigned int t = i;

            char* ptr = S[i];

            while(t){ *(ptr++) = '0' ^ (t % 10); t /= 10; }

            for(unsigned int j = 0; j < digit_len; ++j){

                T[i][j] = S[i][j] ? S[i][j] : '0';

            }

        }

    }

};

constexpr NoName Da;



inline void writeBuffer(unsigned long long int n){

    if(!n) *(output++) = '0';

    else{

        char* ptr = output;

        while(n){

            if(n < MAX_D_SIZE){

                const char* ttt = Da.S[n]; n = 0;

                while(*ttt) *(ptr++) = *(ttt++);

            }

            else{

                const char* ttt = Da.T[n % MAX_D_SIZE]; n /= MAX_D_SIZE; 

                while(*ttt) *(ptr++) = *(ttt++);

            }

        }

        char* ptr2 = output; output = (ptr--);

        while(ptr2 < ptr) std::swap(*(ptr2++), *(ptr--));

    }

    *(output++) = '\n';

}



inline void out(void){

    fwrite_unlocked(Output, sizeof(char), output - Output, stdout);

}



// 制約

constexpr unsigned int MAX_N = 200'000; //'

constexpr unsigned int mod = 1'000'000'007; //'



// 階乗計算

template <const unsigned int M> struct shuumai {

public:

    unsigned long long int P[M + 1];

    unsigned long long int Inv[M + 1];

    unsigned long long int inv[M + 1];

    constexpr shuumai(void):P(), Inv(), inv(){

        P[0] = 1; P[1] = 1;

        for(unsigned int x = 1, y = 2; x < M; ++x, ++y) P[y] = (P[x] * y) % mod;

        Inv[M] = inverse(P[M]);

        for(unsigned int x = M, y = M - 1; x ; --x, --y){

            Inv[y] = (Inv[x] * x) % mod;

            inv[x] = (P[y] * Inv[x]) % mod;

        }

        inv[0] = 1;

    }

    constexpr unsigned int inverse(unsigned int a) const noexcept {

        unsigned int b = mod;

                 int u = 1, v = 0;

        while (b) {

            unsigned int t = a / b; 

            a -= t * b; { const unsigned int tmp = a; a = b; b = tmp; }

            u -= t * v; { const unsigned int tmp = u; u = v; v = tmp; }

        }

        if(u < 0) u += mod;

        return u;

    }

};

constexpr shuumai<MAX_N> karashi;



// リスト

struct Node{

    unsigned int vertex;

    unsigned int next;

};

Node node[2 * MAX_N];

unsigned int begin[MAX_N];

unsigned int end = 1;

inline void append(const unsigned int u, const unsigned v){

    node[end] = {v, begin[u]}; begin[u] = end++;

    node[end] = {u, begin[v]}; begin[v] = end++;

}



// 擬似stack

unsigned int Stack[MAX_N];

unsigned int index_stack = 0;



inline void push(const unsigned int value){ Stack[index_stack++] = value; }

inline unsigned int top(void){ return Stack[--index_stack];}

inline bool exist(void){ return index_stack; }



// 

bool visited[MAX_N];

unsigned int parent[MAX_N];

unsigned int order[MAX_N];

unsigned int index_order = 0;



unsigned int subTree[MAX_N];

unsigned long long int dp[MAX_N];



int main(void){

    fread_unlocked(Input, sizeof(char), MAX_INPUT_SIZE, stdin);

    const unsigned int n = get();

    for(unsigned int _ = 1; _ < n; ++_) append(get() - 1, get() - 1);



    // DFSの順序決め

    push(0); visited[0] = true; order[index_order++] = 0;

    while(exist()){

        const unsigned int v = top();

        for(unsigned int idx = begin[v]; idx ; idx = node[idx].next){

            const unsigned int nv = node[idx].vertex;

            if(not visited[nv]){ 

                visited[nv] = true; parent[nv] = v; 

                order[index_order++] = nv; push(nv);  

            }

        }

    }



    for(unsigned int i = 0; i < n; ++i) dp[i] = 1;

    // 根からボトムアップにdp値を計算

    for(unsigned int i = n - 1; i ; --i){

        const unsigned int v = order[i];

        const unsigned int nv = parent[v];

        dp[v] = dp[v] * karashi.P[subTree[v]++] % mod;

        dp[nv] = dp[nv] * (dp[v] * karashi.Inv[subTree[v]] % mod) % mod;

        subTree[nv] += subTree[v];

    }



    {

        dp[0] = dp[0] * karashi.P[subTree[0]++] % mod;

    }





    for(unsigned int i = 1; i < n; ++i){

        const unsigned int v = order[i];

        const unsigned int nv = parent[v];

        dp[v] = dp[nv] * (subTree[v] * karashi.inv[n - subTree[v]] % mod) % mod;

    }



    // 出力

    for(unsigned int i = 0; i < n; ++i) writeBuffer(dp[i]);

    out();

    return 0;

}