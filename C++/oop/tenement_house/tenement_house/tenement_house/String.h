
#ifndef STRING_H
#define STRING_H

class String
{
private:
	int SIZE;
	char* str;

public:
	String();
	String(int size);
	String(const char* sourth);
	String(const char* sourth, int size); // ����������� �����������
	~String();

	String& SetString(const char* sourth);
	char* GetString() {
		return str;
	}

	String& Print();
};

#endif