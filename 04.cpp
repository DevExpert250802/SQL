// Palindrome Number
// https://leetcode.com/problems/palindrome-number/


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long rev_num = 0;
        long n = x;
		while(n){
	     int lastdigit=n%10;
         rev_num = (rev_num*10) + lastdigit;
	     n=n/10;
	    }
	  return (x==rev_num);
    }
}
