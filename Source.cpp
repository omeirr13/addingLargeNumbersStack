#include<iostream>
#include<string>
#include<stack>

using namespace std;


string addingLargeNumbers(string first, string second)
{
	stack<char> stack1;
	stack<char> stack2;
	stack<char> result;
	
	int carry = 0;

	int i = 0;
	int j = 0;
	while (first[j] != '\0' || second[i] != '\0')
	{
		if (first[j] != '\0')
			stack1.push(first[j++]);

		if (second[i] != '\0')
			stack2.push(second[i++]);
	}
	int f, s;

	while (!stack1.empty() && !stack2.empty())
	{
		f = stack1.top() - '0';
		s = stack2.top() - '0';

		int ans = f + s + carry;
		carry = ans / 10;

		result.push(ans % 10 + '0');
		stack1.pop();
		stack2.pop();
	}

	while (!stack1.empty())
	{
		result.push((stack1.top() - '0' + carry) + '0');
		carry = 0;
		stack1.pop();
	}

	while (!stack2.empty())
	{
		result.push((stack2.top() - '0' + carry) + '0');
		carry = 0;
		stack2.pop();
	}

	if (carry != 0)
		result.push(carry + '0');

	string res;
	while (!result.empty())
	{
		 res += result.top();
		 result.pop();
	}

	return res;
}
int main()
{
	cout << addingLargeNumbers("592123123123123123012312", "592123123123123123012312")<<endl;
	cout << addingLargeNumbers("592123123123123123012312", "1")<<endl;
	cout << addingLargeNumbers("1", "592123123123123123012312");
}