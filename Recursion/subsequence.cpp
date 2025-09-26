#include <iostream>
//#include <bits/stdc++.h>
#include <vector>

using namespace std;

void print(vector<int>& ds, int index, int arr[], int n ){
    if(index >= n){
        for(auto it : ds){
            cout << it << " ";
        }
        cout << endl;
        return;
    }

    ds.push_back(arr[index]);
    print(ds, index+1, arr, n);

    ds.pop_back();
    print(ds, index+1, arr, n);
   

}
int main(){
    int arr[] = {3, 2, 1};
    vector<int> ds;
    print(ds, 0, arr, 3);
    

}
