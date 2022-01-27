
#ifndef FIRM_H
#define FIRM_H

#include <string>

using namespace std;

class Firm
{
private:
	string Name;
	string Owner;
	string Phone;
	string Address;
	string Occupation;

public:
	Firm() : Firm("", "", "", "", "") {}
	Firm(const string& name, const string& owner, const string& phone, const string& address, const string& occupation) :
		Name{ name }, Owner{ owner }, Phone{ phone }, Address{ address }, Occupation{ occupation } {}
};

#endif