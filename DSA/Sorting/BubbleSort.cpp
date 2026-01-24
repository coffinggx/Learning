#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> v {2,3,1,5,4};
    for(int i= 0 ; i<v.size(); ++i){
        for(int j=0; j<v.size() -1 ; j++){
            if(v[j]> v[j+1]){
                swap(v[j], v[j+1]);
            }
        }
    }
    for(auto i: v){
        cout << i <<endl;
    }
}