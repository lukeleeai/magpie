#import <ios>

long b,a;char S[200005];main(){scanf("%s",S);for(char c:S)c%2?a+=b:b++;printf("%ld",a);}