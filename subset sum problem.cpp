class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<bool> dp(sum + 1, false);
        dp[0] = true;

        for(int x : arr){
            for(int s = sum; s >= x; s--){
                dp[s] = dp[s] || dp[s - x];
            }
        }

        return dp[sum];
    }
};