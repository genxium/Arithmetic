#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
int* mk;
vector<char> toprint;

void printstr(char* str, int pos, int size, int mk[]){ // abcde
    mk[pos]=1;
    toprint.push_back(str[pos]);
    //printf("str[%d]=%c(cnt=%d)\n",pos,str[pos], cnt);
    if(toprint.size()==size){
        for(int i=0;i<toprint.size();i++) {printf("%c", toprint[i]);} puts("");
        mk[pos]=0;
        toprint.pop_back();
        return;
    }
    else{
        for(int i=0;i<size;i++){
                if(!mk[i]){
                    printstr(str, i, size, mk);
                }
        }
    }
    toprint.pop_back();
    mk[pos]=0;
}

char str[1024];

int main(){

    while(scanf("%s",str)!=EOF){
        for(int i=0;i<strlen(str);i++){
            int cnt=0;
            mk=new int[strlen(str)];
            memset(mk,0,strlen(str)*sizeof(int));
            printstr(str,i,strlen(str),mk);
        }
    }
    return 0;
}
