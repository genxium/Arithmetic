void kmppreprocess(int n, string s, int *border){
	border[0]=0;
	for(int i=1;i<n;i++){
		int L=border[i-1];
		while(L>0){
			if(s[L]==s[i])	{border[i]=L+1; break;}
			else	{L=border[L-1];}
		}
		if(L==0) border[i]=(s[i]==s[L])?1:0;
	}
}