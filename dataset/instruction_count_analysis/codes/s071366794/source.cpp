#include <iostream>

#include <string>

using namespace std; //头文件和命名空间

int main(){

    ios::sync_with_stdio(false); //输入输出加速

    string sInput; //输入的字符串

    int i; //循环计数器

    cin >> sInput; //读入

    for (i = 0; i < sInput.length(); i+=2){ //枚举奇数位置，注意由于string中第一个字符的索引号为0，因此题目的奇数位事实上是字符串中索引号为偶数的位置

        cout << sInput[i]; //输出对应位置的字符，注意string中第一个字符的索引号为0

    }

    cout << endl; //换行

    return 0; //结束

}