// GCD/HCF  :   https://bit.ly/3GB4Mj8 


int gcd(int a,int b){
	int n= min(a,b);
	int  gcd_value=0;
		for(int i=1;i<=n;i++){
		if(a%i==0 && b%i==0) gcd_value=i;
	}
	return gcd_value;
}


// T.C. = min(a,b)


int gcd(int a,int b){
	int n= min(a,b);
	int  gcd_value=0;
		for(int i=n;i>=1;i--){
		if(a%i==0 && b%i==0){
			gcd_value=i;
			break;
		}
	}
	return gcd_value;
}

// T.C. = min(a,b)

// Approach : Euclidean Algorithm

int gcd(int a,int b){
  while (a > 0 && b > 0) {
     if (a>b)a=a%b;
     else b=b%a;
    }
	if(a==0) return b;
	else return a;
}

// T.C. = O (log(min(a,b)))




// Approach : Built-in

#include <algorithm>
int gcd(int a, int b) {
   return __gcd(a, b);
}
