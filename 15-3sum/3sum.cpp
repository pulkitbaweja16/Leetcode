class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            
            // Skip duplicate values of i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int L = i + 1;
            int R = nums.size() - 1;
            
            while (L < R) {
                
                int sum = nums[i] + nums[L] + nums[R];
                
                if (sum == 0) {
                    ans.push_back({nums[i], nums[L], nums[R]});
                    L++;
                    R--;
                    
                    // Skip duplicates
                    while (L < R && nums[L] == nums[L - 1])
                        L++;
                    
                    while (L < R && nums[R] == nums[R + 1])
                        R--;
                }
                
                else if (sum < 0) {
                    L++;
                }
                
                else {
                    R--;
                }
            }
        }
        
        return ans;
    }
};