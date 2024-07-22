//   Check for prime

// https://bit.ly/3ZdiWOO



#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
	int count=0;
    for (int i = 1;  i <= n; i++) {
        if (n%i==0)count++;
    }
    if(count==2)return true;
	else return false;
}

int main() {
    int n;
    cin >> n;
    if (isPrime(n)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}



// T.C. = O(n)



#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
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

int main() {
    int n;
    cin >> n;
    if (isPrime(n)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}


// T.C. = O(squrt(n))
