class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result;
        vector<pair<int, int>> tempStack; // value, index

        for (int i = 0; i < temperatures.size(); i ++){    
            result.push_back(0);
            // check if current temp is larger than top of stack
            
            while ( tempStack.size() > 0 && temperatures[i] > tempStack.back().first){ 
                // pop off value and give length
                pair<int, int> oldTemp = tempStack.back();
                tempStack.pop_back();
                result[oldTemp.second] = i-oldTemp.second;       
            }
            
            // push that temp on the stack
            tempStack.push_back({temperatures[i], i});
        }

        return result;
    }
};
