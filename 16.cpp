#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>&arr,int n){
    for(int i=0;i<=n-2;i++){
        int mini = i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[mini]) mini=j;
        }
        swap(arr[i],arr[mini]);
    }
}
int main(){
    int n; cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    selectionSort(arr,n);
    
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}







#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&arr,int n){
    for(int i=n-1;i>=1;i--){
        int didSwap=0;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            didSwap=1;
            }
        } 
        if(didSwap==0) break;
    }
}
int main(){
    int n; cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    bubbleSort(arr,n);
    
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}









#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}
int main(){
    int n; cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    insertionSort(arr,n);
    
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}










#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr,int low,int mid,int high){
    vector<int>temp;
    int left = low, right = mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
    while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
    for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
}
void mergeSort(vector<int>&arr, int low, int high){
    if(low>=high) return;
    int mid = (low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    int n; cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];

    mergeSort(arr,0,n-1);
    
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}











#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;

    while (i < j) {
        while (i <= high-1 && arr[i] <= pivot) i++;
        while (j >= low && arr[j] > pivot) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}


















#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int>& arr) {
    int n = arr.size();
    int k = *max_element(arr.begin(), arr.end());

    vector<int> count(k + 1, 0);

    // Count the occurrences of each element
    for (int i = 0; i < n; i++) count[arr[i]]++;

    // Update count array to contain actual positions
    for (int i = 1; i <= k; i++) count[i] += count[i - 1];

    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[--count[arr[i]]] = arr[i];
    }
    
    arr = ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    countSort(arr);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}


