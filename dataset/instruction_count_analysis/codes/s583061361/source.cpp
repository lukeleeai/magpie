/*

For Bantako San

By shyyhs.



Using hash to insert and search for a perticular number.

Every insert and search is O(1) ideally.

*/



#include<iostream>

#include<cstdio>

#include<cstdlib>

using namespace std;

#define ll long long

//#define Hsize 100009

#define Hsize (1<<17)

#define MAXN 201001 

ll sumZ=0; //sum from the beginning

int Ai; //This is Ai in the problem, we use it only once so array is not necessary.

int N; //N in the problem



struct T

{

    ll number,times;

    T* next;

}hashBucket[MAXN];

int top=0;

int hashIndex[Hsize];

inline ll read(){ll tmp=0; char c=getchar(),f=1; for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1; for(;'0'<=c&&c<='9';c=getchar())tmp=tmp*10+c-'0'; return tmp*f;}



//x->hash(x)

inline int hashFunc(ll x)

{

    return (x&(0x0001FFFF));

}



//add the current sumZ to the hash table

inline void addToHash(ll sumZ)

{

    int HsumZ;

    T *index, *beginP;

    HsumZ = hashFunc(sumZ);

    for (beginP=index=&hashBucket[hashIndex[HsumZ]]; (index->times>0); index=index->next)

        if (index->number==sumZ)

        {

            index->times++;

            return;

        }

    hashIndex[HsumZ]=(++top);

    index=&hashBucket[top];

    index->number = sumZ;

    index->times = 1;

    index->next = beginP;

}



void init()

{

    N = read();

    addToHash(0);

    for (int i=0; i<N; ++i)

    {

        Ai = read();

        sumZ=sumZ+Ai;

        addToHash(sumZ);

    }

}



void work()

{

    ll answer=0;

    for (int i=1; i<=top; ++i)

    if (hashBucket[i].times>1)

        answer=answer+(((hashBucket[i].times)*(hashBucket[i].times-1))>>1) ;

    cout<<answer<<endl;

}

    

int main()

{

    init();

    work();

    return 0;

}
