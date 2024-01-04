class Solution {
private:
    void findCombinations(int k, int ind , int n,vector<vector<int>>&ans,
    vector<int>&ds){
            if(n<0 || ds.size() > k)
                return;

            if(n == 0 && ds.size() == k){
                ans.push_back(ds);
                return;
            }

            for(int i=ind; i<=9; i++){
                ds.push_back(i);
                findCombinations(k,i+1,n-i,ans,ds);
                ds.pop_back();
            }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n){
        vector<int>ds;
        vector<vector<int>>ans;
        findCombinations(k,1,n,ans,ds);
        return ans;
    }
};

