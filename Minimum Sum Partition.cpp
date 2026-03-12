class Solution {
public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int x : arr) sum += x;

        vector<bool> dp(sum + 1, false);
        dp[0] = true;

        for(int x : arr){
            for(int s = sum; s >= x; s--){
                dp[s] = dp[s] || dp[s - x];
            }
        }

        int ans = sum;
        for(int s = 0; s <= sum/2; s++){
            if(dp[s]){
                ans = min(ans, sum - 2*s);
            }
        }

        return ans;
    }
};