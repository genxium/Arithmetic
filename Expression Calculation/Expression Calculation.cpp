#include <iostream>
#include <string.h>
#include <stdio.h>
#define MX 1024
using namespace std;

int expression(char str[], int& pos);
int op1(char str[], int& pos);
int element(char str[], int& pos);

int expression(char str[], int& pos){
    int ret=0, size=strlen(str);
    while(pos<size){
        ret+=op1(str,pos);
        if(str[pos]=='+')   {pos++;}
        else    {break;}
    }
    return ret;
}

int op1(char str[], int& pos){
    int ret=1, size=strlen(str);
    while(pos<size){
        ret*=element(str,pos);
        if(str[pos]=='*')   {pos++;}
        else    {break;}
    }
    return ret;
}

int element(char str[], int& pos){
    int ret=0, size=strlen(str);
    if( isdigit(str[pos]) ){
        while(isdigit(str[pos])&&pos<size){
            ret=( 10*ret+ (int)(str[pos]-'0') );
            pos++;
        }
    }
    else if( str[pos]=='(' ){
        pos++;
        ret=expression(str, pos);
        pos++;
    }
    else;

    return ret;
}

int main()
{
    char str[MX];
    int pos;
    while(scanf("%s",str)!=EOF){
        pos=0;
        int ans=expression(str,pos);
        printf("%s=%d\n", str,ans);
    }
    return 0;
}
