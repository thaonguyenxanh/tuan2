#include<iostream>
#include<stack>
#include<string>
#include<fstream>

using namespace std;
bool areParanthesisBalanced(string expr)
{
	stack<char> s;
	char x;

	for (int i = 0; i<expr.length(); i++)
	{
		if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
		{
			s.push(expr[i]);
			continue;
		}


		if (s.empty())
			return false;

		switch (expr[i])
		{
		case ')':

			x = s.top();
			s.pop();
			if (x == '{' || x == '[')
				return false;
			break;

		case '}':

			x = s.top();
			s.pop();
			if (x == '(' || x == '[')
				return false;
			break;

		case ']':

			x = s.top();
			s.pop();
			if (x == '(' || x == '{')
				return false;
			break;
		}
	}

	return (s.empty());
}
int main() {
	int c;
	stack <char> stack1;
	stack<int> location1;
	stack<char> stack2;
	stack<int> location2;
	string path;
	string whole_file;
	//char *char_array = new char[sizeof(char)];
nhaplai:
	cout << "Enter path of file:" << endl;
	cin >> path;
	fstream file(path);
	if (!file.is_open()) {
		cout << "file can not be openned!" << endl;
		goto nhaplai;
	}
	else {
		file.seekg(0, ios::end);
		whole_file.reserve(file.tellg());
		file.seekg(0, ios::beg);
		whole_file.assign(istreambuf_iterator<char>(file), istreambuf_iterator<char>());
		file.close();

	}
	cout << whole_file << endl;
	if (areParanthesisBalanced(whole_file)) {
		cout << "ok\n";
		
	}
	else
	{
		for (int i = 0; i < whole_file.length(); i++)
		{
			if ((whole_file[i] == '(') || (whole_file[i] == '[') || (whole_file[i] == '{')) {
				stack1.push(whole_file[i]);
				location1.push(i);
			}///
			else
			if ((whole_file[i]==')'&& stack1.top()=='(')|| (whole_file[i] == ']'&& stack1.top() == '[')|| (whole_file[i] == '}'&& stack1.top() == '{')) {
					stack1.pop();
					location1.pop();
			}
			else {
					stack2.push(whole_file[i]);
					location2.push(i);
			}
			}
		}
	int wrong = stack1.size() + stack2.size();
	cout << wrong<<endl;
	ofstream file2("D:\BRACKET.txt");
	file2 << wrong << endl;

	while ((!stack1.empty()) && (!location1.empty())) {
		if (stack1.top() == '(') {
			//cout << ")\n" << location1.top() + 1 << endl;
			file2 << ") " << location1.top() + 1 << " " << endl;
			stack1.pop();
			location1.pop();
		}
		else 		
			if (stack1.top() == '[') {
			//cout << ")\n" << location1.top() + 1 << endl;
				file2 << "] " << location1.top() + 1 << " " << endl;
				stack1.pop();
				location1.pop();
			}
			else 		
				if (stack1.top() == '{') {
				//cout << ")\n" << location1.top() + 1 << endl;
					file2 << "} " << location1.top() + 1 << " " << endl;
					stack1.pop();
					location1.pop();
			}
	}			

	while ((!stack2.empty()) && (!location2.empty())) {
		if (stack2.top() == ')') {
			//cout << ")\n" << location1.top() + 1 << endl;
			file2 << "( " << location2.top() - 1<<" "<<endl;
			stack2.pop();
			location2.pop();
		}
		else
			if (stack2.top() == ']') {
				//cout << ")\n" << location1.top() + 1 << endl;
				file2 << "[ " << location2.top() - 1 << " " << endl;
				stack2.pop();
				location2.pop();
			}
			else
				if (stack2.top() == '}') {
					file2 << "{ " << location2.top() - 1 << " " << endl;
					stack2.pop();
					location2.pop();
				}
	}
	file2.close();
	system("PAUSE");

}