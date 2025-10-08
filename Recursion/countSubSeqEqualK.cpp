#include <iostream>
//#include <bits/stdc++.h>
#include <vector>

using namespace std;

int print(vector<int>& ds, int index, int arr[], int n, int k, int sum){
    if(index >= n){
        if(sum == k){
          return 1; 
        }
        else return 0;    
    }
   
    //ds.push_back(arr[index]);
    sum += arr[index];
    int left = print(ds, index+1, arr, n, k , sum);

    sum -= arr[index];
    //ds.pop_back();
    int right = print(ds, index+1, arr, n, k , sum);
      
    return left + right;
}
int main(){
    int k = 3;
    int arr[] = {3, 2, 1};
    vector<int> ds;
    int ans =  print(ds, 0, arr, 3, k, 0);
    cout << ans << " " << endl;    

}
