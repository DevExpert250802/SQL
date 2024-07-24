// Count Prime in a range L-R 
// Problem Statement: Given a range L to R, calculate the number of prime numbers in it.
// Note: Q <= 10^5, 1 <= L <=R <= 10^6

Input:
Q = 3
L = 3  R = 10
L = 8  R = 20
L = 1  R = 5

Output:
3
4
3





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  Approach:1

  
                                
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
    int cnt = 0; 
    for(int i = 1; i * i <= n; i++) { 
        if(n % i == 0) {
            cnt++; 
            if((n / i) != i) {
                cnt++; 
            }
        }
    }
    if(cnt == 2) { 
        return true; 
    }
    return false; 
}
vector<int> countPrimes(vector<vector<int>>& queries) {
  vector<int> ans;
    for(int i=0;i<queries.size();i++){
        int l = queries[i][0];
        int r = queries[i][1];
        int cnt = 0;
        for(int j = l; j <=r; j++) {
            if(isPrime(j)) {
                cnt++;
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}


int main() {
    int Q;
    cin >> Q;
    vector<vector<int>> queries(Q, vector<int>(2));

    for (int i = 0; i < Q; ++i) {
        cin >> queries[i][0] >> queries[i][1];
    }

    cout << "No. of Queries: " << queries.size() << endl;
    cout << "Queries: ";
    for (const auto& query : queries) {
        cout << "(" << query[0] << ", " << query[1] << ")  ";
    }
    cout << endl;

    vector<int> result = countPrimes(queries);

    cout << "Number of primes between the ranges: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

                                

T.C.= O (Q*(R-L+1)*sqrt(n))




Approach:2




  

                      
#include <bits/stdc++.h>
using namespace std;
vector<int>getSieve(int n) {
    vector<int>prime(n+1,1);
    prime[0] = prime[1] = 0;
    for (int i=2;i*i<=n;i++) {
        if (prime[i]==1) {
        for (int j=i*i;j<=n;j+=i) {
            prime[j]=0;
            }
        }
    }
    return prime;
}
vector<int> countPrimes(vector<vector<int>>& queries){
    vector<int> prime=getSieve(1000000);
     vector<int> ans;
    for(int i=0;i<queries.size();i++){
        int l = queries[i][0];
        int r = queries[i][1];
        int cnt = 0;
        for(int j = l; j <=r; j++) {
            if(prime[j]==1) {
                cnt++;
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}


int main() {
    int Q;
    cin >> Q;
    vector<vector<int>> queries(Q, vector<int>(2));

    for (int i = 0; i < Q; ++i) {
        cin >> queries[i][0] >> queries[i][1];
    }

    cout << "No. of Queries: " << queries.size() << endl;
    cout << "Queries: ";
    for (const auto& query : queries) {
        cout << "(" << query[0] << ", " << query[1] << ")  ";
    }
    cout << endl;

    vector<int> result = countPrimes(queries);

    cout << "Number of primes between the ranges: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

                                
 T.C.= O( (Q*(R-L+1)) + N*log(log(N)) )              





Approach:3




   

   
#include <bits/stdc++.h>
using namespace std;
vector<int>getSieve(int n) {
    vector<int>prime(n+1,1);
    prime[0] = prime[1] = 0;
    for (int i=2;i*i<=n;i++) {
        if (prime[i]==1) {
        for (int j=i*i;j<=n;j+=i) {
            prime[j]=0;
            }
        }
    }
    return prime;
}
vector<int> countPrimes(vector<vector<int>>& queries){
    vector<int> ans;
    vector<int> prime=getSieve(1000000);
    int cnt=0;
    for(int i=2;i<=1000000;i++){
        cnt=cnt+prime[i];
        prime[i]=cnt;
    }
    for(int i=0;i<queries.size();i++){
        int l = queries[i][0];
        int r = queries[i][1];
        ans.push_back(prime[r]-prime[l-1]);
        }
    return ans;
}

int main() {
    int Q;
    cin >> Q;
    vector<vector<int>> queries(Q, vector<int>(2));

    for (int i = 0; i < Q; ++i) {
        cin >> queries[i][0] >> queries[i][1];
    }

    cout << "No. of Queries: " << queries.size() << endl;
    cout << "Queries: ";
    for (const auto& query : queries) {
        cout << "(" << query[0] << ", " << query[1] << ")  ";
    }
    cout << endl;

    vector<int> result = countPrimes(queries);

    cout << "Number of primes between the ranges: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

                                
T.C.= O( (Q + 10^6 + N*log(log(N)) )                                       
