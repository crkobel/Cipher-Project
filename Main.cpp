#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


string cesarDecrypt(string text, int n) {
	string result = "";

	for (int i = 0; i < text.length(); i++) {
		if (isupper(text[i]))
			result += char(int(text[i] + n - 65) % 26 + 65);
		else if (text[i] == ' ') {
			result += ' ';
		}
		else
			result += char(int(text[i] + n - 97) % 26 + 97);
	}
	return result;
}

static bool subDecrypt(string input, string oldAlphabet, string newAlphabet, string &output) {
	output = "";
	int inputLen = input.size();

	if (oldAlphabet.size() != newAlphabet.size())
		return false;

	for (int i = 0; i < inputLen; i++) {
		int oldCharIndex = oldAlphabet.find(tolower(input[i]));

		if (oldCharIndex >= 0)
			output += isupper(input[i]) ? toupper(newAlphabet[oldCharIndex]) : newAlphabet[oldCharIndex];
		else
			output += input[i];
	}
	return true;
}

static bool Encipher(string input, string cipherAlphabet, string &output) {
	string plainAlphabet = "abcdefghijklmnopqrstuvwxyz";
	return subDecrypt(input, plainAlphabet, cipherAlphabet, output);
}

static bool Decipher(string input, string cipherAlphabet, string &output) {
	string plainAlphabet = "abcdefghijklmnopqrstuvwxyz";
	return subDecrypt(input, cipherAlphabet, plainAlphabet, output);
}

int main() {
	string quote1 = "fqjcb rwjwj vnjax bnkhj whxcq nawjv nfxdu mbvnu ujbbf nnc";

	cout << "Text: " << quote1 << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	                      // abcdefghijklmnopqrstuvwxyz
	string cipherAlphabet = "sherlockabxfgijmnpqtudwvzy";
	string cipherText;
	string plainText;

	bool encipherResult = Encipher(quote1, cipherAlphabet, cipherText);
	bool decipherResult = Decipher(cipherText, cipherAlphabet, plainText);

	cout << cipherText << endl;
	cout << plainText << endl;
	for (int i = 0; i < 26; i++) {
		cout << cesarDecrypt(quote1, 26 - i) << endl << endl;
	}


	getchar();
	return 0;
}