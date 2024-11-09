// Print all Divisors of a number

//  https://bit.ly/3vzQ7yr

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int* printDivisors(int n, int&size){
    int*arr = new int[n];
     int count =0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            arr[count++] = i;
        }
    }
    size = count;
    return arr;
}





#include <vector>
using namespace std;

vector<int> printDivisors(int n) {
    vector<int> divisors;
    for(int i = 1; i <= n; ++i) {
        if(n % i == 0) {
            divisors.push_back(i);
        }
    }
    return divisors;
}


// T.C.=O(N)
//S.C. = O(sqrt(N))

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Approach 2 :




int* printDivisors(int n, int&size){
    int*arr = new int[n];
    size =0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            arr[size++] = i;
            if((n/i) !=i){
                arr[size++] = n/i;
            }
        }
    }
    sort (arr,arr+size);
    return arr;
}



vector<int> printDivisors(int n) {
    vector<int> divisors;

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (n / i != i) {
                divisors.push_back(n / i);
            }
        }
    }

    sort(divisors.begin(), divisors.end());
    return divisors;
}


// T.C. = O(sqrt(N)) + nlogn
//S.C. = O(sqrt(N))


----------------------------------------------------------------------------------------------------------------------------------------------------------------






// T.C. = O(sqrt(N))
//S.C. = O(sqrt(N))
