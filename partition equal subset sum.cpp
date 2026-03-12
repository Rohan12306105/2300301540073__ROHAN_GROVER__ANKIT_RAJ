class Solution {
public:
    bool equalPartition(vector<int>& arr) {
        int total = 0;
        for(int x : arr) total += x;

        if(total % 2) return false;

        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for(int x : arr){
            for(int s = target; s >= x; s--){
                dp[s] = dp[s] || dp[s - x];
            }
        }

        return dp[target];
    }
};