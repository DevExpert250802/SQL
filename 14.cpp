 //Pow(x, n)
//Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
class Solution {
 public:
  double myPow(double x, long n) {
    if (n == 0)
      return 1;
    if (n < 0)
      return 1 / myPow(x, -n);
    if (n % 2 == 1)
      return x * myPow(x, n - 1);
    return myPow(x * x, n / 2);
  }
};




class Solution {
public:
    double myPow(double x, int n) {
        int pow = abs(n);
        double ans =1.0;
        while(pow>0){
            if(pow%2==1){
                ans=ans*x;
                pow=pow-1;
            }
            else{
                pow=pow/2;
                x=x*x;
            }
        }
        if(n<0) ans= 1/ans;
        return ans;
    }
};







class Solution {
public:
    double myPow(double x, int n) {
        int m=n;
        if(n<0) n= n*-1;
        double ans =1.0;
        while(n>0){
            if(n%2==1){
                ans=ans*x;
                n=n-1;
            }
            else{
                n=n/2;
                x=x*x;
            }
        }
        if(<0) ans= 1.0/ans;
        return ans;
    }
};




