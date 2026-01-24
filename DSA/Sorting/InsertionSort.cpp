#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a {2,3,1,5,4};

    // Sorting

    for(int i=1; i<a.size(); ++i){
        int key = a[i];
        int j = i - 1;
        while (j >= 0  && a[j] > key){
            a[j +1] = a[j];
            --j;
        }
        a[j+1] = key;
    }

    for (auto i: a){
        cout << i << endl;
    }
}