class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i < s.size(); i++) {
            if ((s[i] == '(') || (s[i] == '{') || (s[i] == '[')) {st.push(s[i]);}
            else {
                if (st.empty()) {return false;}
                if((s[i] == ')') && (st.top() != '(')) {return false;}
                if((s[i] == '}') && (st.top() != '{')) {return false;}
                if((s[i] == ']') && (st.top() != '[')) {return false;}
                st.pop();
            }
        }
        return st.empty();
    }
};



/* SIMPLE JAVA CODE:

public boolean isValid(String s) {
	Stack<Character> stack = new Stack<Character>();
	for (char c : s.toCharArray()) {
		if (c == '(')
			stack.push(')');
		else if (c == '{')
			stack.push('}');
		else if (c == '[')
			stack.push(']');
		else if (stack.isEmpty() || stack.pop() != c)
			return false;
	}
	return stack.isEmpty();
}

*/
