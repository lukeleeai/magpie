/*

 * Author: liuchang

 * Created Time:  2012/7/17 15:18:57

 * File Name: C.cpp

 */

#include <iostream>

#include <cstdio>

#include <cstring>

#include <cmath>

#include <cstdlib>

#include <algorithm>

#include <vector>

using namespace std;

#define out(v) cerr << #v << ": " << (v) << endl

#define SZ(v) ((int)(v).size())

const int maxint = -1u>>1;

template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}

template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

struct die{

    int num[6]; // top front left right back btm

die(){}

die(int top,int fr)

{

    memset(num,0,sizeof num);

    

    num[0] = top;

    num[1] = fr;

    num[5] = 7 - top;

    num[4] = 7 - fr;

     //for(int i = 0;i < 6;i ++) cout<<num[i]<<' ';cout<<endl;

    if( top == 1){

        switch( fr ){

        case 3: num[2] = 2;num[3] = 5;break;

        case 5: num[2] = 3;num[3] = 4;break;

        case 4: num[2] = 5;num[3] = 2;break;

        case 2: num[2] = 4;num[3] = 3;break;

        }

    }

    else if(top == 6){

        switch( fr ){

        case 3: num[2] = 2;num[3] = 5;break;

        case 5: num[2] = 3;num[3] = 4;break;

        case 4: num[2] = 5;num[3] = 2;break;

        case 2: num[2] = 4;num[3] = 3;break;

        }

        int tmp = num[2];num[2] = num[3];num[3] = tmp;

    }    

    else if(top == 3){

        switch(fr){

        case 6: num[2] = 2;num[3] = 5;break;

        case 5: num[2] = 6;num[3] = 1;break;

        case 1: num[2] = 5;num[3] = 2;break;

        case 2: num[2] = 1;num[3] = 6;break;

        }

    }

    else if(top == 4){

    switch(fr)

    {

        case 6: num[2] = 2;num[3] = 5;break;

        case 5: num[2] = 6;num[3] = 1;break;

        case 1: num[2] = 5;num[3] = 2;break;

        case 2: num[2] = 1;num[3] = 6;break;

    }

        int tmp = num[2];num[2] = num[3];num[3] = tmp;

    }

    else if(top == 2){

    switch(fr){

        case 1: num[2] = 3;num[3] = 4;break;

        case 4: num[2] = 1;num[3] = 6;break;

        case 6: num[2] = 4;num[3] = 3;break;

        case 3: num[2] = 6;num[3] = 1;break;

    }

    }

    else {

    switch(fr){

        case 1: num[2] = 3;num[3] = 4;break;

        case 4: num[2] = 1;num[3] = 6;break;

        case 6: num[2] = 4;num[3] = 3;break;

        case 3: num[2] = 6;num[3] = 1;break;

    }

    int tmp = num[2];num[2] = num[3];num[3] = tmp;

    }

    //for(int i = 0;i < 6;i ++) cout<<num[i]<<' ';cout<<endl;

}

        

    void rot_left()

    {

        int tmp;

        tmp = num[0];

        num[0] = num[3];

        num[3] = num[5];

        num[5] = num[2];

        num[2] = tmp;

    }

    void rot_right()

    {

        int tmp;

        tmp = num[0];

        num[0] = num[2];

        num[2] = num[5];

        num[5] = num[3];

        num[3] = tmp;

    }

    

    void rot_front()

    {

        int tmp;

        tmp = num[0];

        num[0] = num[4];

        num[4] = num[5];

        num[5] = num[1];

        num[1] = tmp;

    }

    void rot_back()

    {

        int tmp;

        tmp = num[0];

        num[0] = num[1];

        num[1] = num[5];

        num[5] = num[4];

        num[4] = tmp;

    }

    int gettop()

{

   return num[0];

} 

int get_front()

    {

        return num[1];

    }

    int get_left()

{

    return num[2];

}

int get_right(){

    return num[3];

}

int get_back(){

    return num[4];

}

void rot(int x)

{

    switch(x){

        case 0: rot_front();break;

        case 1: rot_back();break;

        case 2: rot_left();break;

        case 3: rot_right();break;

    }

}

int get(int x)

{

    switch(x){

        case 0: return get_front();break;

        case 1: return get_back();break;

        case 2: return get_left();break;

        case 3: return get_right();break;

    }

}

} dics;

int n;

int high[1000][1000],val[1000][1000];

int dx[] = {-1,+1,0,0};

int dy[] = {0,0,-1,+1};

int main() {

    while(cin>>n && n!=0)

    {

        int x,y,z,a,b;

        memset(high,0,sizeof high);

        memset(val,0,sizeof val);

        for(int i = 0;i < n;i ++)

        {

            cin>>a>>b;

            die nxt = die(a,b);

            y = x = 500;

            z = high[x][y];

            do{

            int mx = 3,dir = -1;

            for(int i = 0;i < 4;i ++)

            { 

               if( nxt.get(i) > mx &&

                   high[x+dx[i]][y+dy[i]] < z){

                   mx = nxt.get(i);

                   dir = i;

               }

            } 

            //cout<<"rot "<<dir<<endl;

            if(dir == -1){

                //cout<<nxt.gettop()<<endl;

                //cout<<"x y z "<<x<<' '<<y<<' '<<z<<endl; 

                high[x][y] ++;

                val[x][y] = nxt.gettop();

                break;

            }

            else {

                nxt.rot(dir);

                x += dx[dir];

                y += dy[dir];

                z  = high[x][y];

            }

            }while(1);

        }

        int ans[7];

        memset(ans,0,sizeof ans);

        for(int i = 0;i < 505;i ++)

            for(int j = 0;j < 505;j ++)

                ans[val[i][j]] ++;

        for(int i = 1;i <= 5;i ++)

           cout<<ans[i]<<' ';

       cout<<ans[6]<<endl;

    } 

            

            

            

        

    return 0;

}