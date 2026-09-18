class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int ans = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < nums.size() - 2; i++) {

            int L = i + 1;
            int R = nums.size() - 1;

            while(L < R) {

                int sum = nums[i] + nums[L] + nums[R];

                if(abs(target - sum) < abs(target - ans))
                    ans = sum;

                if(sum < target)
                    L++;
                else if(sum > target)
                    R--;
                else
                    return sum;
            }
        }

        return ans;
    }
};