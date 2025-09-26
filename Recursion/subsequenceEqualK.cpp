#include <iostream>
//#include <bits/stdc++.h>
#include <vector>

using namespace std;

void print(vector<int>& ds, int index, int arr[], int n, int k, int sum){
    if(index >= n){
        if(sum == k){
           for(auto it : ds){
            cout << it << " ";
           }
         cout << endl;
        }
        return; 
    }
   
    ds.push_back(arr[index]);
    sum += arr[index];
    print(ds, index+1, arr, n, k , sum);

    sum -= arr[index];
    ds.pop_back();
    print(ds, index+1, arr, n, k, sum);
    
   

}
int main(){
    int k = 3;
    int arr[] = {3, 2, 1};
    vector<int> ds;
    print(ds, 0, arr, 3, k, 0);
    

}
