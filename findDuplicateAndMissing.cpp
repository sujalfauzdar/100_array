//find all duplicate and missing in array [1,n]
#include<iostream>
#include<vector>
#include<cmath>


using namespace std;

    pair<vector<int>,vector<int>> findDuplicateAndMissing(vector<int> & nums){
        vector<int>duplicate;
        vector<int> missing;
        for(int i : nums){
            int index = abs(i) - 1;
            if(nums[index] < 0)
                duplicate.push_back(abs(i));
            else
                nums[index] = -nums[index];
        }
        for(int i =0 ; i < nums.size();i++){
            if(nums[i] > 0 )
                missing.push_back(i+1);
        }
        return {duplicate,missing};
    }
int main(){
    vector<int> nums = {4,3,2,7,8,2,3,1};
    pair<vector<int>,vector<int>> result = findDuplicateAndMissing(nums);

    cout << "Duplicates: ";
    for (int j : result.first)
        cout << j << " ";
    cout << endl;

    cout << "Missing: ";
    for (int j : result.second)
        cout << j << " ";
    cout << endl;

    return 0;
}