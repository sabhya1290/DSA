#include<iostream>
#include<vector>

using namespace std;


void recur(int idx,vector<int>&nums,vector<int>&ans,vector<vector<int>>&res){
    
    if(idx==nums.size()){
        res.push_back(ans);
        return ;
    }

    ans.push_back(nums[idx]);

    recur(idx+1,nums,ans,res);

    ans.pop_back();

    recur(idx+1,nums,ans,res);
}

vector<vector<int>> subsets(vector<int>& nums) {
    
    vector<int>ans;
    vector<vector<int>>res;
    
    recur(0,nums,ans,res);
    
    return res;
}

int main(){

    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = subsets(nums);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl; 

        string a; 
        
    }
    
}