class Solution {
public:
    string removeKdigits(string num, int k) {
        // Edge case
        if(num.size() == k) return "0";

        stack<char> st;
        for(int i = 0; i < num.size(); i++) {
            if(st.empty()) {st.push(num[i]); continue;}
            
            while(!st.empty() && k > 0 && st.top() > num[i]) {st.pop(); k--;}

            st.push(num[i]);
        }

        while(!st.empty() && k > 0) {st.pop(); k--;}

        string s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }

        while(s.size() > 0 && s.back() == '0') s.pop_back();
        reverse(s.begin(), s.end());

        // Edge case
        if(s.empty()) return "0";

        return s;
    }
};