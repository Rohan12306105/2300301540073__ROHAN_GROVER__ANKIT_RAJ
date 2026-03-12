class Solution {
public:
    int countPartitions(vector<int>& arr, int diff) {
        int sum = 0;
        for(int x : arr) sum += x;

        if((sum + diff) % 2) return 0;

        int target = (sum + diff) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for(int x : arr){
            for(int s = target; s >= x; s--){
                dp[s] += dp[s - x];
            }
        }

        return dp[target];
    }
};