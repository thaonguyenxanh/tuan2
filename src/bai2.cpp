#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<vector>
using namespace std;

/*vector<string> */ void replaced(vector<string> string_vector, string str_found, string replaced_str) {

	vector<string>::size_type sz = string_vector.size();
	bool substring_was_found = false;
	for (unsigned i = 0; i < sz; i++)
	{
		size_t found = string_vector[i].find(str_found);
		for (size_t pos = 0; pos < string_vector[i].length(); ++pos)
		{
			if (string_vector[i].find(str_found, pos) == pos) {
				if (!substring_was_found) {
					substring_was_found = true;
				}
				string_vector[i].replace(string_vector[i].find(str_found), str_found.length(), replaced_str);
			}
		}
		cout << string_vector[i] << endl;
	}
	//return string_vector;

}
void find_substring(vector<string> string_vector, string found_str) {
	vector<string>::size_type sz = string_vector.size();
	int count = 0;
	bool substring_was_found = false;
	for (unsigned i = 0; i < sz; i++)
	{
		size_t found = string_vector[i].find(found_str);
		for (size_t pos = 0; pos < string_vector[i].length(); ++pos)
		{
			if (string_vector[i].find(found_str, pos) == pos) {
				if (!substring_was_found) {
					cout << found_str << " was found at: "<<endl;
					substring_was_found = true;
					count++;
				}
				cout <<"column: "<< pos << ' ' << " line: " << i << endl;
			}
		}
		cout << string_vector[i] << endl;
	}
}

int main() {
	int c;
	string path;
	vector<string> vector_lines;
	
	int line = 1;
	char *char_array = new char[sizeof(char)];
	char **matrix2 = new char*;
nhaplai:
	cout << "Enter path of file:" << endl;
	cin >> path;
	fstream file(path);
	if (!file.is_open()) {
		cout << "file can not be openned!" << endl;
		goto nhaplai;
	}
	else {
		for (string str; getline(file, str);) {
			vector_lines.push_back(str);
		}
		//file.seekg(0, ios::end);
		//whole_file.reserve(file.tellg());
		//file.seekg(0, ios::beg);
		//whole_file.assign(istreambuf_iterator<char>(file), istreambuf_iterator<char>());
		//cout << whole_file << endl;// read whole file as string

		//for (list<string>::iterator it = list_lines.begin(); it != list_lines.end();it++)
		//{
		//	cout << *it << endl;
		//}
	
		file.close();
		//list<string>::iterator it = list_lines.begin();
		//advance(it, 0);
		//cout << *it << endl;



		while (1)
		{
			cout << "1: Search\n2: Replace\n3: Exit" << endl;
			cout << "choose one of three modes: " << endl;
			cin >> c;
			switch (c)
			{

			case 1:
			{
				string found_string;
				cout << "enter string to find: " << endl;
				cin >> found_string;
				find_substring(vector_lines, found_string);
				//getchar();
				//return 3;
				break;
			}


			case 2:
			{
				string str_found;
				string replaced_str;
				cout << "enter string to search: " << endl;
				cin >> str_found;
				cout << "enter string to replace:" << endl;
				cin >> replaced_str;
				replaced(vector_lines, str_found, replaced_str);
				
				//vector<string>::size_type sz = vector_lines.size();
				//file.open(path, ostream::out | ofstream::trunc);

				//ofstream file2(path);
				//for (unsigned i = 0; i < sz; i++)
				//{
				//	file2 << vector_lines[i]<<"\n";
				//}

			}
			break;
			case 3:
				return 0;
				break;
			break;

			}

		}

	}
	for (unsigned i = 0; i < vector_lines.size(); i++)
	{
		cout << vector_lines[i] << endl;
	}
	delete[] char_array;

	return 0;
	system("PAUSE");
}