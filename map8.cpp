#include <iostream>
#include <string>
#include <map>

using namespace std;

template <typename key, typename value>
void mapLab8_1() {

	int mapSize;
	key mapKey;
	map<key, value> map;
	cout << "Input mapSize: ";
	cin >> mapSize;

	for (size_t i = 0; i < mapSize; i++) {
		cout << "Write key: ";
		cin >> mapKey;
		cout << "Write value for key: ";
		cin >> map[mapKey];
	}

	bool found = false;
	value valueToFind;

	cout << "Input the key we are looking for: ";
	cin >> valueToFind;
	for (auto pair : map) {
		if (valueToFind == pair.first) {
			cout << "Founded value: " << pair.second;
			found = true;
			break;
		}
	}
	if (!found) cout << "We can't found value by key\n";

}

void mapLab8_2() {
	map<string, int> map;
	string sentence, buffer;
	cout << "\n\nLab 8.2\n\n Input string: ";
	cin.ignore();
	getline(cin, sentence);

	for (size_t i = 0; i <= sentence.length(); i++) {
		if (sentence[i] != ' ' && sentence[i] && ((char)sentence[i] > 96 && (char)sentence[i] < 123 || (char)sentence[i] > 64 && (char)sentence[i] < 91)) {
			buffer += sentence[i];
		}
		if (sentence[i] == ' ' || sentence[i] == '\0') {
			map[buffer]++;
			buffer = "";
		}
	}
	cout << "\n";
	for (auto pair : map) {
		cout << "Word " << pair.first << " was found in the sentence: " << pair.second << " times\n\n";
	}

}

int main()
{
	mapLab8_1<string, string>();
	mapLab8_2();

	return 0;
}

//int n;
//cout << "Input n: ";
//cin >> n;
//string* word = new string[n];
//string* def = new string[n];
//for (size_t i = 0; i < n; i++) cin >> word[i] >> def[i];
//
//string s;
//cout << "input s\n";
//while (cin >> s) {
//	bool found = false;
//	for (size_t i = 0; !found && i < n; ++i) {
//		if (word[i] == s) {
//			found = true;
//			cout << def[i] << "\n";
//		}
//	}
//	if (!found) cout << "not found!\n";
//}
//
//delete word;
//delete def;
