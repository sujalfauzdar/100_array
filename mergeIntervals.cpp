#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

    vector<vector<int>> merge(vector<vector<int>>& intervals){
        vector<vector<int>> result ;
        if(intervals.empty())
            return result;
        sort(intervals.begin(),intervals.end());

        result.push_back(intervals[0]);
        int end = intervals[0][1];
        int j =0;
        for(int i = 1; i < intervals.size(); i++){
            if(end >= intervals[i][0]){
                result[j][1] = max(result[j][1],intervals[i][1]);
                end = result[j][1];
            }
            else{
                result.push_back(intervals[i]);
                end = intervals[i][1];
                j++;
            }
        }
        return result;
    }

int main() {
    vector<vector<int>> nums = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result = merge(nums);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << "," << result[i][1] << "]";
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
