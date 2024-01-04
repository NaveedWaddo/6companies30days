class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = nums[0].size();

        vector<int>res;

        for(auto query : queries){
            int k = query[0];
            int x = query[1];

            priority_queue<pair<string,int>>pq; //{num : ind}
            for(int i=0; i<n; i++){
                string str = nums[i].substr(m-x);
                pq.push({str,i});

                if(pq.size() > k){
                    pq.pop();
                }
            }

            res.push_back(pq.top().second);
        }

        return res;
    }
};
