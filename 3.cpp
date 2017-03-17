#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct st {
	string val;

	bool operator<(st s) {
		int len = min(val.size(), s.val.size());
		
		for (int i = 0; i < len; i++) {
			if (val[i] < s.val[i]) return true;
			if (val[i] > s.val[i]) return false;
		}

		return false;
	}
};

int main() {
	bool done = false;

	while(!done) {
		vector<st> list;
		string line;
		string word;

		getline(cin, line);
		stringstream ss(line);

		while (ss >> word) {
			struct st s;
			s.val = word;
			list.push_back(s);
		}

		sort(list.begin(), list.end());

		for (st s : list) cout << s.val;
		cout << endl;

		if (list[0].val == "0") done = true;
	}

	return 0;
}
