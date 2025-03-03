#include<cstdio>



char str[100005];



int main(){

    bool flag = true;

    int r = 0;

    scanf("%s",str);

    for(int i=0;str[i];i++){

        if(str[i]=='d'){

            if(r)r=0;

            if(str[i+1]=='r'&&str[i+2]=='e'&&str[i+3]=='a'&&str[i+4]=='m'){

                r = 1;

                if(str[i+5]=='e'){

                    if(str[i+6]=='r'){

                        i+=4;

                    }else {

                        flag = false;break;

                    }

                }else {

                    i+=4;

                }

            }else {

                flag = false;

                break;

            }

        }else if(str[i]=='e'){

            if(str[i+1]=='r'){

                if(str[i+2]=='a'&&str[i+3]=='s'&&str[i+4]=='e'){

                    if(str[i+5]=='r'){

                        i += 5;

                    }else {

                        i += 4;

                    }

                }else if(r){

                    i += 1;

                }else {

                    flag = false;

                    break;

                }

            }else {

                flag = false;

                break;

            }

            r = 0;

        }else {

            flag = false;

            break;

        }

    }

    if(flag)

        puts("YES");

    else

        puts("NO");

    return 0;

}
