#include<iostream>
#include<string>
using namespace std;
string match_Prefix_Postfix(string str) {
	int len = str.length();
	int k = 0, i;
	if (len == 1) {
		return "empty";
	}
	else {
		for (i = len - 1; i > 0; i--) {
			string t1, t2;
			t1 = str.substr(0, i);
			t2 = str.substr(len - i, i);
			if (t1 == t2) {
				k = 1;
				break;
			}
		}
		if (k == 1) {
			return str.substr(0, i);
		}
		else {
			return "empty";
		}
	}
 
}
int main() {
	int n;
	cin >> n;
	string str;
	while (n--) {
		cin >> str;
		string temp = match_Prefix_Postfix(str);
		cout << temp << endl;
	}
}
