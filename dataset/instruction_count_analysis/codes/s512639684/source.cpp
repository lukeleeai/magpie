//

//  main.cpp

//  test130

//

//  Created by  on 2019/06/16.

//  Copyright © 2 All rights reserved.

//

//

//  main.cpp

//  new

//

//  Created on 2019/06/09.

//  Copyright  All rights reserved.

//



// C++ includes used for precompiling -*- C++ -*-



// Copyright (C) 2003-2013 Free Software Foundation, Inc.

//

// This file is part of the GNU ISO C++ Library.  This library is free

// software; you can redistribute it and/or modify it under the

// terms of the GNU General Public License as published by the

// Free Software Foundation; either version 3, or (at your option)

// any later version.



// This library is distributed in the hope that it will be useful,

// but WITHOUT ANY WARRANTY; without even the implied warranty of

// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the

// GNU General Public License for more details.



// Under Section 7 of GPL version 3, you are granted additional

// permissions described in the GCC Runtime Library Exception, version

// 3.1, as published by the Free Software Foundation.



// You should have received a copy of the GNU General Public License and

// a copy of the GCC Runtime Library Exception along with this program;

// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see

// <http://www.gnu.org/licenses/>.



/** @file stdc++.h

 *  This is an implementation file for a precompiled header.

 */



// 17.4.1.2 Headers



// C

#ifndef _GLIBCXX_NO_ASSERT

#include <cassert>

#endif

#include <cctype>

#include <cerrno>

#include <cfloat>

#include <ciso646>

#include <climits>

#include <clocale>

#include <cmath>

#include <csetjmp>

#include <csignal>

#include <cstdarg>

#include <cstddef>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <ctime>



#if __cplusplus >= 201103L

#include <ccomplex>

#include <cfenv>

#include <cinttypes>

#include <cstdbool>

#include <cstdint>

#include <ctgmath>

#include <cwchar>

#include <cwctype>

#endif



// C++

#include <algorithm>

#include <bitset>

#include <complex>

#include <deque>

#include <exception>

#include <fstream>

#include <functional>

#include <iomanip>

#include <ios>

#include <iosfwd>

#include <iostream>

#include <istream>

#include <iterator>

#include <limits>

#include <list>

#include <locale>

#include <map>

#include <memory>

#include <new>

#include <numeric>

#include <ostream>

#include <queue>

#include <set>

#include <sstream>

#include <stack>

#include <stdexcept>

#include <streambuf>

#include <string>

#include <typeinfo>

#include <utility>

#include <valarray>

#include <vector>



#if __cplusplus >= 201103L

#include <array>

#include <atomic>

#include <chrono>

#include <condition_variable>

#include <forward_list>

#include <future>

#include <initializer_list>

#include <mutex>

#include <random>

#include <ratio>

#include <regex>

#include <scoped_allocator>

#include <system_error>

#include <thread>

#include <tuple>

#include <typeindex>

#include <type_traits>

#include <unordered_map>

#include <unordered_set>

#endif





#define f(i,n) for(int i=0;i<(n);i++)





#define inf (int)(3e18)

#define int long long

#define mod (int)(1000000007)



using namespace std;



//Library

//モッドパウ

int modpow(int x, int y, int m = mod) {

    int res = 1;

    while (y) {

        if (y % 2) {

            res *= x;

            res %= m;

        }

        x = x * x % mod;

        y /= 2;

    }

    return res;

}



int mypow(int x, int y) {

    int res = 1;

    while (y) {

        if (y % 2) {

            res *= x;

        }

        x = x * x ;

        y /= 2;

    }

    return res;

}

//is the number (x) a prime number?

bool prime(int x){

    for (int i=2; i<=sqrt(x); i++) {

        if (!(x%i)) {

            return false;

        }

    }

    return true;

}



double kyori(pair<int, int> f, pair<int, int> s){

    double ans=0;

    double t = fabs(f.first-s.first);

    double y = fabs(f.second-s.second);

    ans=sqrt(t*t+y*y);

    return ans;

}



//saidai-kouyakusuu

int gcd(int x,int y){

    if (y==0) {

        return x;

    }

    return gcd(y,x%y);

}



//Union-Find Tree



int par[300004];

int rankmy[300004];



int find(int x){

    if (par[x]==x) {

        return x;

    }

    return par[x]=find(par[x]);

}



void unite(int x,int y){

    x=find(x);

    y=find(y);

    if (x==y) {

        return;

    }

    if (rankmy[x]<rankmy[y]) {

        par[x]=y;

    }else{

        par[y]=x;

        if (rankmy[x]==rankmy[y]) {

            rankmy[x]++;

        }

    }

}



bool same(int x,int y){

    return find(x)==find(y);

}

void init(int n){

    for (int i=0; i<=n; i++) {

        par[i]=i;

    }

}

//Union-Find-End



//SegTree

template <class T>

class SegTree {

    int n;                       // 葉の数

    vector<T> data;              // データを格納するvector

    T def;                       // 初期値かつ単位元

    function<T(T, T)> operation; // 区間クエリで使う処理

    function<T(T, T)> update;    // 点更新で使う処理

 

    // 区間[a,b)の総和。ノードk=[l,r)に着目している。

    T _query(int a, int b, int k, int l, int r) {

        if (r <= a || b <= l) return def; // 交差しない

        if (a <= l && r <= b)

            return data[k]; // a,l,r,bの順で完全に含まれる

        else {

            T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子

            T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子

            return operation(c1, c2);

        }

    }

 

  public:

    // _n:必要サイズ, _def:初期値かつ単位元, _operation:クエリ関数,

    // _update:更新関数

    SegTree(size_t _n, T _def, function<T(T, T)> _operation,

            function<T(T, T)> _update)

        : def(_def), operation(_operation), update(_update) {

        n = 1;

        while (n < _n) {

            n *= 2;

        }

        data = vector<T>(2 * n - 1, def);

    }

 

    // 場所i(0-indexed)の値をxで更新

    void change(int i, T x) {

        i += n - 1;

        data[i] = update(data[i], x);

        while (i > 0) {

            i = (i - 1) / 2;

            data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);

        }

    }

 

    // [a, b)の区間クエリを実行

    T query(int a, int b) {

        return _query(a, b, 0, 0, n);

    }

 

    // 添字でアクセス

    T operator[](int i) {

        return data[i + n - 1];

    }

};

#define R_MIN ([](long long a, long long b) { return min(a, b); })

#define R_MAX ([](long long a, long long b) { return max(a, b); })

#define R_SUM ([](long long a, long long b) { return a + b; })

#define NORMAL_UPDATE ([](long long a, long long b) { return b; })



//same as "R_SUM"

#define ADD_UPDATE ([](long long a, long long b) { return a + b; })



//dfs

vector<int> v[100004];

bool went[100004];

void dfs(int x){

    went[x]=true;

    for (int i=0; i<v[x].size(); i++) {

        if (!went[v[x][i]]) {

            dfs(v[x][i]);

            

        }

    }

}

//Library-End

int n,m,q[14],ans;

vector<int> vec[14];

signed main(){

    cin>>n>>m;

    for (int i=0; i<m; i++) {

        int k;

        cin>>k;

        for (int j=0; j<k; j++) {

            int p;

            cin>>p;

            p--;

            vec[i].push_back(p);

        }

    }

    for (int i=0; i<m; i++) {

        cin>>q[i];

    }

    for (int i=0; i<mypow(2, n); i++) {

        bitset<30> bits(i);

        bool ok=true;

        for (int j=0; j<m; j++) {

            int g=0;

            for(int k=0;k<vec[j].size();k++){

                if (bits[vec[j][k]]) {

                    g++;

                }

                

            }

            if ((g&1)!=q[j]) {

                ok=false;

                break;

            }

        }

        if (ok) {

            ans++;

        }

        

    }

    cout<<ans<<endl;

}
