/*

Next permutation of a[0, ..., n-1]

1. Find the largest index k such that a[k] < a[k+1]. If no such index exists, the permutation is the last permutation.
2. Find the largest index l such that a[k] < a[l] where l>k.
3. Swap a[k] and a[l].
4. Reverse the sequence a[k+1, ..., n-1]

*/

string next_permutation(string str){
        
        int size=str.size();
        string s=str;
        int pos1, pos2;

        bool flag=false;
        for(int i=0;i<size-1;i++){
            if(s[i]<s[i+1]) {pos1=i; flag=true;}
        }
        if(!flag) return s;
        for(int j=pos1+1;j<size;j++){
            if(s[pos1]<s[j]) {pos2=j;}
        }
        swap(s[pos1],s[pos2]);
        int mid=((pos1+size)>>1);
        for(int i=pos1+1;i<=mid;i++){
            swap(s[i],s[size+pos1-i]);
        }
        return s;
    }
	
/*
char* next_permutation(char* str){

        int size=strlen(str);
        char* s=str;
        int pos1, pos2;

        bool flag=false;
        for(int i=0;i<size-1;i++){
            if(s[i]<s[i+1]) {pos1=i; flag=true;}
        }
        if(!flag) return s;
        for(int j=pos1+1;j<size;j++){
            if(s[pos1]<s[j]) {pos2=j;}
        }
        swap(s[pos1],s[pos2]);
        int mid=((pos1+size)>>1);
        for(int i=pos1+1;i<=mid;i++){
            swap(s[i],s[size+pos1-i]);
        }
        return s;
    }
*/
