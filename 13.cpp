Question
Prime Factorization of Multiple Queries

You are given multiple queries, each containing a single integer. For each query, you need to find all the prime factors of the given integer. Implement a function that uses the Sieve of Eratosthenes to precompute the smallest prime factors for numbers up to 100,000. For each query, use the precomputed smallest prime factors to determine the prime factors of the given integer.

Write a program that reads an integer 
𝑄
Q representing the number of queries. For each query, read a single integer and output its prime factors.

Example:
Input: 
10
2
4
8
16
32
64
128
256
512
1024
Output:
2 
2 2 
2 2 2 
2 2 2 2 
2 2 2 2 2 
2 2 2 2 2 2 
2 2 2 2 2 2 2 
2 2 2 2 2 2 2 2 
2 2 2 2 2 2 2 2 2 
2 2 2 2 2 2 2 2 2 2 




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




#include <bits/stdc++.h>
using namespace std;

vector<int> AllPrimeFactors(int n) {
    vector<int> primeFactors;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                primeFactors.push_back(i);
                n = n / i;
            }
        }
    }
    if (n != 1) primeFactors.push_back(n);
    return primeFactors;
}

vector<vector<int>> Factorisation(vector<vector<int>>& queries) {
    vector<vector<int>> result;
    for (int i = 0; i < queries.size(); i++) {
        int j = queries[i][0];
        vector<int> ans = AllPrimeFactors(j);
        result.push_back(ans);
    }
    return result;
}

int main() {
    int Q;
    cin >> Q;
    vector<vector<int>> queries(Q, vector<int>(1));

    for (int i = 0; i < Q; ++i) {
        cin >> queries[i][0];
    }

    cout << "No. of Queries: " << queries.size() << endl;
    cout << "Queries: ";
    for (const auto& query : queries) {
        cout << "(" << query[0] << ")  ";
    }
    cout << endl;

    vector<vector<int>> result = Factorisation(queries);

    cout << "Prime Factors for each query: " << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << "Query " << i + 1 << " (" << queries[i][0] << "): ";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}







T.C.= O(sqrt(n)*log(N)*Q)















#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> primeFactors(vector<int>& queries) {
    int n = 100000;
    vector<int>spf(n+1);
    // Initialize smallest prime factors for each number
    for(int i=1;i<=n;i++) spf[i] = i;
    // Sieve of Eratosthenes to fill smallest prime factors
    for(int i=2;i*i<=n;i++) {
        if(spf[i]==i) {
            for(int j=i*i;j<=n;j+=i){
              //previously not marked
                if(spf[j]==j)
                // smallestPrimeFactor
                spf[j]=i;
            }
        }
    }
    vector<vector<int>> result;
    // Process each query
    for (int n : queries) {
        vector<int> factors;
        while (n != 1) {
            factors.push_back(spf[n]);
             n= n/spf[n];
        }
        result.push_back(factors);
    }
    return result;
}

int main() {
    int Q;
    cin >> Q;
    vector<int> queries(Q);

    for (int i = 0; i < Q; ++i) {
        cin >> queries[i];
    }

    cout << "No. of Queries: " << queries.size() << endl;
    cout << "Queries: ";
    for (const auto& query : queries) {
        cout << "(" << query << ")  ";
    }
    cout << endl;

    vector<vector<int>> result = primeFactors(queries);

    cout << "Prime Factors for each query: " << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << "Query " << i + 1 << " (" << queries[i] << "): ";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}








T.C.= O(N*log(log(N))+ log(N)*Q )
