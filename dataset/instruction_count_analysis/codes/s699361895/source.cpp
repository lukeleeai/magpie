/*

For Bantako San

By shyyhs.



Using hash to insert and search for a perticular number.

Every insert and search is O(1) ideally.

*/



#include<iostream>

#include<cstdio>

#include<cstdlib>

#include<cmath>

#include<cstring>

#include<string>

using namespace std;

#define ll long long

#define Hsize 100009

#define MAXN 210001 

ll sumZ=0; //sum from the beginning

int Ai; //This is Ai in the problem, we use it only once so array is not necessary.

int N; //N in the problem



struct T

{

    ll number,times;

    int next;

}hashBucket[MAXN];

int top=0;

int hashIndex[Hsize];





//x->hash(x)

inline int hashFunc(ll x)

{

    if (x<0) x=-x;

    return (x%100007);

}



//add the current sumZ to the hash table

void addToHash(ll sumZ)

{

    int index, HsumZ, beginP;

    HsumZ = hashFunc(sumZ);

    for (beginP=index=hashIndex[HsumZ]; index>0; index=hashBucket[index].next)

        if (hashBucket[index].number == sumZ) // there is already that number in the hashbucket

        {

            hashBucket[index].times+=1;

            return;

        } 

    hashIndex[HsumZ]=(++top);

    hashBucket[top].number = sumZ;

    hashBucket[top].times = 1;

    hashBucket[top].next = beginP;

}



void init()

{

    memset(hashBucket,-1,sizeof(hashBucket));

    scanf("%d",&N);

    addToHash(0);

    for (int i=0; i<N; ++i)

    {

        scanf("%d",&Ai);

        sumZ=sumZ+Ai;

        addToHash(sumZ);

    }

}



void work()

{

    ll answer=0;

    for (int i=1; i<=top; ++i)

        answer=answer+(((hashBucket[i].times)*(hashBucket[i].times-1))>>1) ;

    cout<<answer<<endl;

}

    

int main()

{

    init();

    work();

    return 0;

}
