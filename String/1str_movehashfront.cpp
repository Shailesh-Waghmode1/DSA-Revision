#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getAns(string s, int n){
    int idx = n;
    for(int i=n; i>=0; i--){
        if(s[i] != '#'){
           s[idx--] = s[i];
        }
    }

    while(idx >= 0){
        s[idx--] = '#';
    }

    return s;
}


int main(){
    string s = "shai#lesh#";
    int n = s.size()- 1;
    cout<< n <<endl;
    string get_hash_Front = getAns(s, n);

    cout<<get_hash_Front<<endl;

}
