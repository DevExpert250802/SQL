// Sieve of Eratosthenes 


#include <iostream>
#include <vector> // Include this for using the vector
using namespace std;

bool isPrime(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (n / i != i) {
                count++;
            }
        }
    }
    if (count == 2) return true;
    else return false;
}

void PrintPrimes(int n) {
    for (int i = 2; i <=n; i++) {
        if (isPrime(i))
            cout << i <<" ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    PrintPrimes(n);
    return 0;
}




Time Complexity: O(N*sqrt(N))





#include <iostream>
#include <vector> 
using namespace std;

void PrintPrime(int n) {
    vector<int>prime(n+1,1);
    prime[0] = prime[1] = 0;
    for (int i=2;i<=n;i++) {
        if (prime[i]==1) {
        for (int j=2*i;j<=n;j+=i) {
            prime[j]=0;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (prime[i] == 1)
            cout << i << endl;
    }
}

int main() {
    int n;
    cin >> n;
    PrintPrime(n);
    return 0;
}



T.C. = O(N*log(log N)) + O(2N)

//|||||||||||||||||||||||||||||||||||||||||||||||||||||||| OPTIMIZED |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||





#include <bits/stdc++.h>
using namespace std;

void PrintPrime(int n) {
    vector<int>prime(n+1,1);
    prime[0] = prime[1] = 0;
    for (int i=2;i<=sqrt(n);i++) {
        if (prime[i]==1) {
        for (int j=i*i;j<=n;j+=i) {
            prime[j]=0;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (prime[i] == 1)
            cout << i << endl;
    }
}

int main() {
    int n;
    cin >> n;
    PrintPrime(n);
    return 0;
}





T.C. = O(N*log(log N)) + O(2N)






#include <bits/stdc++.h>
using namespace std;

void PrintPrime(int n) {
    vector<int>prime(n+1,1);
    prime[0] = prime[1] = 0;
    for (int i=2;i*i<=n;i++) {
        if (prime[i]==1) {
        for (int j=i*i;j<=n;j+=i) {
            prime[j]=0;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (prime[i] == 1)
            cout << i << endl;
    }
}

int main() {
    int n;
    cin >> n;
    PrintPrime(n);
    return 0;
}


T.C. = O(N*log(log N)) + O(2N)
