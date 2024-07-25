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
        long long pow = abs(n);
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
        long long m = n;
        if(m<0) m= m*-1;
        double ans =1.0;
        while(m>0){
            if(m%2==1){
                ans=ans*x;
                m=m-1;
            }
            else{
                m=m/2;
                x=x*x;
            }
        }
        if(n<0) ans= 1.0/ans;
        return ans;
    }
};


T.C. = O(log2(n))




