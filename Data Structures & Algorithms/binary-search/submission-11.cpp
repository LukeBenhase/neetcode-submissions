class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start, end, output;
        start = 0;
        end = nums.size()-1;
        
        while (start != end){
            // find the middle value
            int middle = ((end-start)/2)+start; // rounds down
            cout << "end, start, middle: "<< end <<  ", " << start << ", " << middle << endl;
            // check middle value
            //if (nums[middle] == target){
                // done return output.
            //    return middle;
            //}
            //else 
            if (nums[middle] < target){
                // throw out bottom half
                start = middle+1;
            }
            else {
                // throw out top half you can't subtract if it rounds down.
                end = middle;
            }
        }
        // check the value the start and end converge on
        if (nums[start] == target){
            return start;
        }
        return -1;
    }
};
