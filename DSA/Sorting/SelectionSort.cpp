#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>  v{2,5,3,4,1};
    // Selection sort
    for(int i = 0; i<v.size() - 1; ++i){
        int smallIndex= i;
        for(int j=i + 1; j < v.size(); ++j){
            if (v[j] <v[smallIndex]){
                smallIndex= j;
            }
        }
        if (smallIndex != i){
            swap(v[i],v[smallIndex]);
        }
    }
    for(auto i: v){
        cout << i << endl;
    }
}