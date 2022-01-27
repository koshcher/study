// Файл для работы с шифрованием

#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include "Include.h"
using namespace std;

namespace encryption
{
	static const char a = 'k';
	static const char b = 'r';

	string Encrypt(const string& sourth);
	string Decrypt(const string& sourth);
}

#endif