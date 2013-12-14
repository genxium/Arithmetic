int C(int n, int k, int MOD){
		long long ret=1;
		for(int i=0;i<k;i++){
           	ret*=(long long)(n-i); ret%=(long long)MOD;
           	int x,y;
           	gcdex(MOD,(i+1),x,y);
        	while(y<0){
        		y+=MOD;
        		x-=(i+1);
        	} // (i+1)^(-1)=y (% MOD)
        	ret*=(long long)y; ret%=(long long)MOD;
		}
		ret%=(long long)MOD;
		return (int)ret;
	}

	void gcdex(int a, int b, int&x, int& y){ // a>b
		x=1, y=0;//r[0]=a
		int lastx=0, lasty=1;// r[1]=b
		while(b>0){
			int q=a/b;
			int tmpx=x-lastx*q;
			int tmpy=y-lasty*q;
			x=lastx; y=lasty;
			lastx=tmpx; lasty=tmpy;
			int c=a; a=b; b=c%b;
		}
	}