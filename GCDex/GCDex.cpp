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
