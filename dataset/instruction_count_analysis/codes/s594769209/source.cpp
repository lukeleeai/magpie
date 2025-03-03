#include<iostream>

#include<vector>

#include<assert.h>



using namespace std;

#define int long long

#define repeat(i, n) for(int i=0;i<(n);i++)



struct SegmentTree{



   static const int N=1<<17;

   static const int Z=0;

   vector<int> seg, lazy;

   SegmentTree(){

      seg.resize(2*N-1, 0);

      lazy.resize(2*N-1, 0);

   }



   void update(int i, int l, int r){

      if(lazy[i]){

         seg[i]+=lazy[i]*(r-l);

         if(r-l>1){

            lazy[2*i+1]+=lazy[i];

            lazy[2*i+2]+=lazy[i];

         }

         lazy[i]=0;

      }

   }



   void add(int a, int b, int x, int i=0, int l=0, int r=N){

      update(i, l, r);

      if(b<=l or r<=a){

         return;

      }else if(a<=l and r<=b){

         lazy[i]+=x;

         update(i, l, r);

      }else{

         //update(i, l, r);

         int m=(r+l)/2;

         add(a, b, x, 2*i+1, l, m);

         add(a, b, x, 2*i+2, m, r);

         seg[i]=seg[2*i+1]+seg[2*i+2];

      }

   }



   int sum(int a, int b, int i=0, int l=0, int r=N){

      update(i, l, r);

      if(b<=l or r<=a){

         return Z;

      }else if(a<=l and r<=b){

         return seg[i];

      }else{

         //update(i, l, r);

         int m=(r+l)/2;

         int vl=sum(a, b, 2*i+1, l, m);

         int vr=sum(a, b, 2*i+2, m, r);

         return vl+vr;

      }

   }



};



signed main(){



   int N, Q;

   cin>> N>> Q;

   SegmentTree st;

   while(Q--){

      int q; cin>> q;

      if(q==0){

         int s, t, x;

         cin>> s>> t>> x;

         st.add(s-1, t, x);

      }else{

         int s, t;

         cin>> s>> t;

         cout<< st.sum(s-1, t)<< endl;

      }

   }



   return 0;

}