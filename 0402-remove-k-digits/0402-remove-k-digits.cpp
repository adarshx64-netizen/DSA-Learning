class Solution {
public:
    string removeKdigits(string num, int k) {
        
        return solve(num, k);
    }

    // TC -> O(N), SC -> O(N)
    string solve(string num, int k) {

        stack<char> st;
        for(char c : num) {

            // if k greater than 0 and our stack is not empty and 
            // the upcoming digit is less than the current top than 
            // we will pop the stack top
            while(!st.empty() && k > 0 && st.top() > c) {st.pop(); k--;}

            st.push(c);

            // popping preceding zeroes
            if(st.size() == 1 && c == '0') st.pop();
        }

        // cases like "456" where every num[i] > num.top()
        while(!st.empty() && k > 0) {st.pop(); k--;}

        string res = "";
        while(!st.empty()) {

            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        if(res.size() == 0) return "0";

        return res;
    }
};