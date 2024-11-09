// Reverse Integer
// https://leetcode.com/problems/reverse-integer/description/


// Code using 64-bit integer

class Solution {
public:
    int reverse(int x) {
        long rev_num = 0;
        long n = x;

        while (n) {
            int last_digit = n % 10;
            rev_num = rev_num * 10 + last_digit;
            n /= 10;
        }
        if (rev_num < INT_MIN || rev_num > INT_MAX)
        return 0;
        return  int(rev_num);
    }
};





// Code using 32-bit integer


class Solution {
public:
    int reverse(int x) {
        int rev_num = 0;
        int n = x;

        while (n) {
            int last_digit = n % 10;
            if( (rev_num < INT_MIN/10) || (rev_num > INT_MAX/10)) return 0;
            rev_num = rev_num * 10 + last_digit;
            n /= 10;
        }
        return rev_num;
    }
};
