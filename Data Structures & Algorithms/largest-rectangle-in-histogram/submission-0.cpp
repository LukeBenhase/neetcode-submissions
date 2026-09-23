class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largest = 0;
        vector<pair<int, int>> heightStack; // height position
        for (int i = 0; i < heights.size(); i++) {
            // check left to see if it is smaller 
            int furthestBack = i;
                while (!heightStack.empty() && heights[i] < heightStack.back().first){
                    // calculate the size of that rectangle
                    int size = (i-heightStack.back().second) * heightStack.back().first;
                    if (largest < size)
                        largest = size;
                    furthestBack = heightStack.back().second;
                    heightStack.pop_back();
                } 
            // add self
            heightStack.push_back({heights[i], furthestBack});
        }

        while (!heightStack.empty() && 0 < heightStack.back().first){
            // calculate the size of that rectangle
            int size = (heights.size()-heightStack.back().second) * heightStack.back().first;
            if (largest < size)
                largest = size;
            // replace the larger with a size equal
            heightStack.pop_back();   
        }
        
        return largest;

    }
};
