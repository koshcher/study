
#ifndef LIBRARY_H
#define LIBRARY_H

#include <time.h>
#include <fstream>

#include "Literature.h"

class Library
{
private:
	int Size;
	Literature** Array;

public:
	Library() : Size{ 0 }, Array{ nullptr } {}
	~Library() {
		if (Array != nullptr) {
			for (int i = 0; i < Size; i++) {
				if (Array[i] != nullptr) {
					delete Array[i];
				}
			}
			delete[] Array;
		}
	}

	void Gen() {

		if (Array != nullptr) {
			this->~Library();
			Array = nullptr;
			Size = 0;
		}

		int type = rand() % 3;
		Size = rand() % 5 + 11;
		Array = new Literature*[Size];
		for (int i = 0; i < Size; i++) {
			switch (type) {
			case 0:
				Array[i] = new Newspaper;
				break;
			case 1:
				Array[i] = new Almanac;
				break;
			case 2:
				Array[i] = new Book;
				break;
			}
			Array[i]->Gen();
			type = rand() % 3;
		}

	}

	void Print() {
		if (Array == nullptr) {
			return;
		}

		for (int i = 0; i < Size; i++) {
			cout << (i + 1) << " ";
			Array[i]->Print();
			cout << endl;
		}
	}

	void WriteBinary() {
		WriteBinary("test.bin");
	}

	void WriteBinary(const string& file_name) {
		ofstream fout(file_name, ios_base::binary | ios_base::out);

		if (!fout.is_open())
		{
			cout << "file not opened for write." << endl;
			return;
		}

		int type = 0;
		for (int i = 0; i < Size; i++) {
			type = Array[i]->TypeNum();
		}

		fout.close();
	}


	void ReadBinary() {
		ReadBinary("test.bin");
	}

	void ReadBinary(const string& file_name) {
		ifstream fin(file_name, ios_base::binary | ios_base::in);
		if (!fin.is_open())
		{
			cout << "file not opened for read." << endl;
			return;
		}

		if (Array != nullptr) {
			this->~Library();
			Array = nullptr;
			Size = 0;
		}


		fin.close();
	}
};

#endif