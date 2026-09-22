class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result = 0;
        vector<int> values;
        int topValuesPtr = 0;
        for ( string t : tokens){
            if (t == "+" || t == "-" || t == "/" || t == "*"){
                // do that operation on the top 2 values
                if (topValuesPtr < 2){
                    cout << "the expression is not valid" << endl;
                    return 0;
                }
                int temp2 = values.back();
                values.pop_back();
                int temp1 = values.back();
                values.pop_back();
                if(t == "+" )
                    values.push_back(temp1 + temp2);
                else if( t == "-" )
                    values.push_back(temp1 - temp2);
                else if( t == "/" )
                    values.push_back(temp1 / temp2);
                else if( t == "*" )
                    values.push_back(temp1 * temp2);
                topValuesPtr--;
            }
            else {
                // t is a number
                values.push_back(stoi(t));
                cout << values.back() << endl;
                topValuesPtr++;
            }
        }
        return values.back();
    }
};
