
#ifndef CATALOG_H
#define CATALOG_H

#include "Firm.h"

class Catalog
{
private:
	int SIZE;
	Firm* Objects;

public:
	Catalog() : SIZE{ 0 }, Objects { nullptr } {}
	~Catalog() {
		if (Objects != nullptr) {
			delete Objects;
		}
	}

	Firm FindByName(const string& name);
	Firm FindByOwner(const string& owner);
	Firm FindByPhone(const string& phone);
	Firm FindByOccupation(const string& occupation);

	void Add(const Firm& sourth);
	void Del(const int& index);

	void Show();
	void Save();
	void Load();
};



#endif