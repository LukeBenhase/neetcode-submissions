class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m, n, l, r, mid;
        if (matrix.size() == 0){
            return false;
        }

        m = matrix.size();
        n = matrix[0].size();
        l = 0;
        r = m * n - 1;

        while (l != r){
            // find middle
            mid = ((r-l)/2)+l;
            // calculate vector location
            int mloc = mid / n; // rounds down 
            int nloc = mid % n; 

            if (matrix[mloc][nloc] < target){
                // throw out bottom half
                l = mid+1;
            }
            else if (matrix[mloc][nloc] > target){
                r = mid;
            }
            else {
                return true;
            }

        }
        // calculate vector location
        int mloc = l / n; // rounds down 
        int nloc = l % n; 
        if (matrix[mloc][nloc] == target )
            return true;
        return false;

    
    }
};
