/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are+,-,*,/. Each operand may be an integer or another expression.
Some examples:
["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6


*/

/*
思路：逆波兰表达式，栈
*/

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
		if (tokens.size() == 0)
			return 0;
		stack<int> st;
		for (int i = 0; i < tokens.size(); ++i)
		{
			string str = tokens[i];
			if (str == "+" || str == "-" || str == "*" || str == "/")
			{
				if (st.size() < 2)
					return 0;
				int num2 = st.top();
				st.pop();
				int num1 = st.top();
				st.pop();
				int result = 0;
				if (str == "+")
					result = num1 + num2;
				else if (str == "-")
					result = num1 - num2;
				else if (str == "*")
					result = num1 * num2;
				else if (str == "/")
					result = num1 / num2;
				st.push(result);
			}
			else
				st.push(atoi(str.c_str()));
		}
		return st.top();
    }
};