// Print all Divisors of a number

//  https://bit.ly/3vzQ7yr



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


// T.C.=O(N)


int* printDivisors(int n, int&size){
    int*arr = new int[n];
     size =0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            arr[size++] = i;
        }
    }
    return arr;
}




// T.C.=O(N)

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



// T.C. = O(sqrt(N))
