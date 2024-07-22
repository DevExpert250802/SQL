// LCM

// Approach : Euclidean Algorithm

int gcd(int a,int b){
  while (a > 0 && b > 0) {
     if (a>b)a=a%b;
     else b=b%a;
    }
	if(a==0) return b;
	else return a;
}

int LCM(int a, int b) {
    return (a / gcd(a, b)) * b;
}
// T.C. = O (log(min(a,b)))






// Approach : Built-in

#include <bits/stdc++.h> 
int GCD(int x, int y) {
    return __gcd(x,y);
}
long long LCM(int x, int y) {
    long long product = (long long)x * (long long )y;
    int gcd = GCD(x, y);
    return product / gcd;
}

// T.C. = O (log(min(a,b)))







#include <algorithm>
int LCM(int a, int b) {
   return lcm(a, b);
}
// T.C. = O (log(min(a,b)))
