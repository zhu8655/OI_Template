inline int exGcd(int m,int n,int &x,int &y){
    int x0=1,y0=0,x1=0,y1=1,r=m%n,q=(m-r)/n;x=0;y=1;
    while(r){x=x0-q*x1;y=y0-q*y1;x0=x1;y0=y1;x1=x;y1=y;m=n;n=r;r=m%n;q=(m-r)/n;} return n;
}