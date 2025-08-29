#include<iostream>
#include<vector>

using namespace std;

    vector<int> relativeSortArray(vector<int> & arr1,vector<int> &arr2){
        int n = arr1.size();
        int m = arr2.size();

        vector<int> freqCount(1001,0);
        vector<int> relativeArray;

        for(int i : arr2){
            while(freqCount[i]){
                relativeArray.push_back(i);
                freqCount[i]--;
            }
        }
        for(int i = 0 ; i < 1001;i++){
            while(freqCount[i]){
                relativeArray.push_back(i);
                freqCount[i]--;
            }
        }
        return relativeArray;
    }

int main(){
    int n;
    int m;
    cout<<"Enter the Size of arr 1: ";
    cin>>n;
    vector<int> arr1(n);
    cout<<"Enter the Size of arr 2: ";
    cin>> m;
    vector<int> arr2(m);

    cout<<"Enter the values of arr1 : ";
    for(int i = 0 ; i < n ; i++)
        cin>>arr1[i];
    cout<<"Enter the Values of arr2 : ";
    for(int i = 0 ; i < m ;i++)
        cin>>arr2[i];
    
    vector<int> result = relativeSortArray(arr1,arr2);

    for(int i : result)
        cout<<i << " ";

    return 0;
}