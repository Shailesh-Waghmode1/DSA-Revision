#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& vec, int low, int mid, int high){
    int st1 = low;
    int st2 = mid+1;
    vector<int> temp;
    
    while(st1<=mid && st2<=high){
        if(vec[st1] < vec[st2]){
           temp.push_back(vec[st1++]);
        }else{
            temp.push_back(vec[st2++]);
        }
    }

    while(st1<=mid)
       temp.push_back(vec[st1++]);

    while(st2<=high)
        temp.push_back(vec[st2++]);

    for(int j=low; j<=high; j++)
      vec[j] = temp[j-low];

}

void divide(vector<int>& vec, int low, int high){
    if(low >= high) return;
    int mid = low + (high - low) / 2;
    divide(vec, low, mid);
    divide(vec, mid+1, high);
    merge(vec, low, mid, high);
}

int main(){
    vector<int> vec = {45,10,25,17,65};

    divide(vec,0,4);
    for(auto it : vec){
        cout << it << " ";
    }
    cout << endl;
}

