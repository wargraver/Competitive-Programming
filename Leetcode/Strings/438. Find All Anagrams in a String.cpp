class Solution {
public:
    #define pb push_back
    vector<int> findAnagrams(string str, string t) {
        int s = 0;
	int e = 0;
	unordered_map<char, int >m;
	for (char ch : t) {
		m[ch]++;
	}
	int counter = m.size();
	vector<int >ans;
	while (e < str.size()) {
		char ch = str[e];
		if (m.find(ch) != m.end()) {
			m[ch]--;
			if (m[ch] == 0) {
				counter--;
			}
		}
		e++;
		while (counter == 0) {
			if ((e - s) == t.size()) {
				ans.pb(s);
			}
			char temp = str[s];
			if (m.count(temp) == 1) {
				m[temp]++;
				if (m[temp] > 0) {
					counter++;
				}
			}
			s++;
		}
	}
        return ans;
    }
};
