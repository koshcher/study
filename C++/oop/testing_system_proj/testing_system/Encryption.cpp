#include "Encryption.h"

string encryption::Encrypt(const string& sourth) {
	string res;

	for (auto c : sourth) {
		res += (c * a + b) % 100;
		res += (c * a + b) / 100;
	}

	return res;
}

string encryption::Decrypt(const string& sourth) {
	string res;

	for (int i = 0; i < sourth.size(); i += 2) {
		res += round((sourth[i] - b + 100 * sourth[i + 1]) * 1.0 / a);
	}

	return res;
}