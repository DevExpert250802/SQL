// Print all Prime Factors of the given number



class Solution{
	public:
	bool checkPrime(int n) {
	int count=0;
    for (int i=1;i*i<=n;i++) {
        if(n%i==0){
		   count++;
			if(n/i != i){
			   count++;
			}
          }
        }
    if(count==2)return true;
	else return false;
}
    vector<int> AllPrimeFactors(int n) {
        vector<int> primeFactors;
        for (int i = 1; i <= n; i++) {
            if(n % i == 0) {
                if(checkPrime(i)){
                   primeFactors.push_back(i);
                }
            }
        }
        return primeFactors;
    }
};


T.C. = O(n * sqrt(n))







class Solution{
	public:
	bool checkPrime(int n) {
	int count=0;
    for (int i=1;i*i<=n;i++) {
        if(n%i==0){
		   count++;
			if(n/i != i){
			   count++;
			}
          }
        }
    if(count==2)return true;
	else return false;
}
    vector<int> AllPrimeFactors(int n) {
        vector<int> primeFactors;
        for (int i = 1; i<= sqrt(n); i++) {
            if(n % i == 0) {
                if(checkPrime(i)){
                   primeFactors.push_back(i);
                }
                if(n/i != i){
                    if(checkPrime(n/i)){
                        primeFactors.push_back(n/i);
                    }
                }
            }
        }
        return primeFactors;
    }
};


T.C. = O(sqrt(n)* 2sqrt(n))







class Solution{
	public:
    vector<int> AllPrimeFactors(int n) {
        vector<int> primeFactors;
        for (int i = 2; i<= n; i++) {
            if(n % i == 0) {
              primeFactors.push_back(i);
             while(n % i == 0) n=n/i;
            }
        }
        return primeFactors;
    }
}; 


T.C. =O(n*log (n))




class Solution{
	public:
    vector<int> AllPrimeFactors(int n) {
        vector<int> primeFactors;
        for (int i = 2; i<=sqrt(n); i++) {
            if(n % i == 0) {
                primeFactors.push_back(i); 
            while(n % i == 0) n=n/i;
            }
        }
        if(n!=1) primeFactors.push_back(n); 
        return primeFactors;
    }
};

T.C. =O(sqrt(n)*log (n))
