class Solution {
private:
    bool checkHigh(vector<int>&accessTimes){
        int n = accessTimes.size();

        for(int i=2; i<n; i++){
            int currTime = accessTimes[i];
            int prevPrev = accessTimes[i-2];

            if(prevPrev + 99 >= currTime){
                return true;
            }
        }
        return false;
    }
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {

        map<string,vector<int>>empMap;
        vector<string>ans;

        for(auto &it : access_times){
            string name = it[0];
            string accessTime = it[1];

            int time = stoi(accessTime);
            empMap[name].push_back(time);

        }

        for(auto entry : empMap){
            string empname = entry.first;
            vector<int> accessTimes = entry.second;

            sort(accessTimes.begin() , accessTimes.end());

            if(checkHigh(accessTimes) == true){
                ans.push_back(empname);
            }
        }

        return ans;
    }
};
