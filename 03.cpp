// Reverse Integer
// https://leetcode.com/problems/reverse-integer/description/


class Solution {
public:
    int reverse(int x) {
        long rev_num=0;
        long n = x;
        if(x>=INT_MAX || x<=INT_MIN) return 0;
        else{
        while(n){
             int lastdigit =n%10;
             rev_num = (rev_num*10) + lastdigit;
             n=n/10;
            }
        }
        if(rev_num >= INT_MIN && rev_num <= INT_MAX)
        return rev_num;
        else return 0;
    }
};
