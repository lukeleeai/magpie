

#include <cstdio>

#include <map>

using namespace std;

map<int,int> m;

int a[200001];

int main(int argc, const char * argv[]) {

   

    int n;

    

    scanf("%d\n",&n);

    

    for(int i=0;i<n;i++){

        

        int tmp;

        scanf("%d",&tmp);

        m[tmp]++;//첫글자로 자동정렬

        a[i]=tmp;

    }

    int med = n/2;

    int sum = 0;

    int num = 0;

    int next = -1;

    for(map<int,int>::iterator it = m.begin(); it!=m.end();it++){

        map<int,int>::iterator tmp=it;

        next = (++tmp)->first;

        sum += it->second;

        if(sum >=med) {

            num = it->first;

            break;

        }

        

    }

    for(int i=0;i<n;i++){

        

        int v = a[i];

        

        if(v <= num){

            if(sum-1 >= med) printf("%d\n",num);//다음위치

            else printf("%d\n",next);

        }else{

            printf("%d\n",num);

        }

        

        

    }

    

    

    return 0;

}
