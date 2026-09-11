class Solution {
public:
    bool isValid(string s) {
        vector<char> pstack;
        char pstackPop = ' ';
        for (char ch : s){
            if (ch == '[' || ch == '{' || ch == '(' ){
                pstack.push_back(ch);
                continue;
            }
            else{
                // this has to be a closing. so pop other
                // check to see if there is something to pop. 
                if (pstack.size() == 0){
                    return false;
                }
                pstackPop = pstack.back();
                pstack.pop_back();
                if(!(ch == ']' && pstackPop == '[') && 
                    !(ch == '}' && pstackPop == '{') && 
                    !(ch == ')' && pstackPop == '(') )
                    return false;
            }

        }

        if (pstack.size() != 0){
            return false;
        }
        return true;
    }
};
