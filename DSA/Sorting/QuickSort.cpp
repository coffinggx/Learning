#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (true)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if(i>=j) break;
        swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[low]);
    return j;
}
void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex -1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int main(){
    vector<int> arr{2, 4, 1, 5, 3};
    quickSort(arr,0,arr.size()-1);
    for(int i: arr){
        cout << i;
    }
}