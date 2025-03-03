#include<stdio.h>

#include<string.h>

#include<algorithm>

#include<stdlib.h>

using namespace std;

const int Max = 3;

int a[4][2]= {0,-1,1,0,0,1,-1,0};

int last[9][2]= {{2,2},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1}}; // 目标状态的数字所在位置

int k[Max][Max],k2[Max*Max],flag=0,limit,Mi;   // k用来保存八数码状态，k2用来计算曼巴顿距离

int add(int k[Max][Max])       // 曼哈顿距离为 所有的数字要走到目标状态，最少要和0换的次数；

{

    int i,j;

    int sum = 0;

    for(i=0; i<3; i++)

        for(j=0; j<3; j++)

        {

            if(k[i][j]!=0)     //判断曼哈顿距离不能判断0；

                sum += abs(i-last[k[i][j]][0])+abs(j - last[k[i][j]][1]);  //求曼哈顿距离

        }

    return sum;

}

void dfs(int y,int x,int len,int f)     // x,y当前0的坐标 len 为已经走了几步了，f为当上一次的搜索方向

{

    int s = add(k);                     // 求当前状态的曼哈顿距离

    if(flag) return;                    // 如果找到符合的结果，不在搜索

    if(len<=limit)

    {

        if(s==0)                        //曼哈顿距离为零，为目标状态

        {

            flag=1;

            Mi=len;

            return ;

        }

        if(len==limit) return;          //递归到了本轮终点，结束

    }

    for(int i=0; i<4; i++)

    {

        int tx = x + a[i][0];

        int ty = y + a[i][1];

        if(tx>=0&&ty>=0&&ty<3&&tx<3&&((f==-1)||i!=(f+2)%4))

        {

            swap(k[y][x],k[ty][tx]);    // 让下一个数与 0 交换位置

            if(len+add(k)<=limit)       // IDA* 值减少，当前走的步数 加上 当前状态到达标状态的最小步数，

            {

                // 要小于等于当前枚举到的最小的 从起始状态到达目标状态的步数，不能超过；

                dfs(ty,tx,len+1,i);

                if(flag) return ;

            }

            swap(k[y][x],k[ty][tx]);    //还原

        }

    }

}

int main()

{

    int i,j;

    while(~scanf("%d",&k2[0]))

    {

        int y,x;

        k[0][0] = k2[0];

        if(k2[0]==0)    //记录 0 所在的位置

        {

            y = 0;

            x = 0;

        }

        for(i=1; i<Max*Max; i++)

        {

            scanf("%d",&k2[i]);

            k[i/3][i%3] = k2[i];//把输入的数存到二维数组

            if(k2[i]==0)        //记录 0 所在的位置

            {

                y = i/3;

                x = i%3;

            }

        }

        flag = 0;

        limit = add(k);        // 当前要达到目标状态的最小步数；

        while(!flag&&limit<=36)

        {

            dfs(y,x,0,-1);

            if(!flag)          //如果本轮没有满足的条件，扩大搜索范围

                limit ++;      // 深搜底线 +1

        }

        if(flag)

            printf("%d\n",Mi);

    }

    return 0;

}


