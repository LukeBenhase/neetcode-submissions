class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int middle;
        //cout << "test" << endl;
        while (l != r){
            // find middle 
            middle = (l + r) / 2; // should always round down
            //cout << "numbers are: " << l << " : " << r << " : " << middle << endl;
            // if smaller than target set l to middle else set r
            if (nums[middle] < target){
                
                    l = middle+1;
                
            }
            else {
                r = middle;
            }
        }

        if (nums[l] == target)
            return l;
        return -1;
    }
};
