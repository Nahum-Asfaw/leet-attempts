class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int>old = nums; // O(n)

        sort(nums.begin(), nums.end()); // O(nlogn)

        int new_target = 0;
        vector<int>ans = {0, 0}; // blank


        for (int i = nums.size() - 1; i >= 0; i--){
            // Binary Sort
            int hold = nums[i];
            new_target = target - hold;
            cout << "new_target:" << new_target << endl;
            cout << "nums[i]:" << nums[i] << endl;

            if (binary_search(nums.begin(), nums.end(), new_target)){ // found the correct ans
                cout << "HERE" << endl;
                ans[0] = new_target;
                ans[1] = hold;
                //cout << "ans:" << ans << endl;
                nums.pop_back(); // remove last element in O(1)
                break;
            }

            nums.pop_back(); // remove last element in O(1)

        }

        
        // recover sol'n for new_target
        for(int i = 0; i < old.size(); i++){ // O(n)
            if (old[i] == ans[0]){
                ans[0] = i;
                // replace?
                old[i] = -100000000;
                break;
            }
        }

        // recover for hold
        for(int i = 0; i < old.size(); i++){ // O(n)
            if (old[i] == ans[1]){
                ans[1] = i;
                break;
            }
        }
        
        return ans;
    }
};