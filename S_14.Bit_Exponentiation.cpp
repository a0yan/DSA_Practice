class Solution {
public:
    double bit_expo(double x,long long int n){
        long  double ans=1.0;
        
        if(x==0){
            return 0.0;
        }
        if(n==0){
            return 1.0;
        }
        bool pos=n>0?true:false;
        if(pos==false){
            n=abs(n);
        }
        while(n!=0){
            if(n&1){
                ans=ans*x;
            }
            x=x*x;
            n=n>>1;
        }
        if(pos==false){
            return 1/ans;
        }
        return ans;
    }
    double myPow(double x, int n) {
        return bit_expo(x,n);
    }
};
