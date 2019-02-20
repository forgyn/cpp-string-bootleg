#pragma once
#include <iostream>
#include <math.h>
#include "DynamicArray.h"
using namespace std;
class String {
#define ERROR(text) std::cout << text << std::endl;
#define LOOP(n) for(int i = 0;i<n;i++)
#define RLOOP(n) for(int i = n-1;i>=0;i--)
#define INPUT int input = _getwch() 
#define DEBUG
public:
	///enums
	enum remove_enum_delete_order { ALL, FIRST, LAST };
	enum remove_use_remove_wtsp { REMOVE,USE };
	enum find_way {LEFT,RIGHT};
	///konstruktory
	String() {};
	String(const char* text);
	String(const String &text2);
	String(char *);
	///destruktor
	~String() {
		clear();
	}
	//uvoln� data
	void clear() {
		if (_text != nullptr && velikost !=0) {
			delete[] _text;
			_text = nullptr;
			velikost = 0;
		}
	}

	///operatorov� funkce
	//p�i�azen� hodnoty
	void operator=(const char *);
	void operator=(char *);
	void operator=(String &);
	void operator=(const char &);
	//slou�en� dvou �et�zc�/znak�
	String& operator+(String &);
	String& operator+(const char*);
	//String& operator[](unsigned);
	char operator[](unsigned)const;
	bool operator==(const char*)const;
	bool operator==(const String&)const;
	///ovl�dac� funkce
	void del(unsigned);
	void delEdgWts();
	void add(const char &);
	///pomocn� funkce
	//vra� text
	char* get() const {
		if (_text != nullptr)
			return _text;
	}
	char* getPart(unsigned start,unsigned end)const;
	//vyp�e obsah na obrazovku
	void see() {
		LOOP(velikost-1)cout << _text[i];
		cout << endl;
	}
	//vr�t� velikost
	unsigned size() const { return velikost; }
	//odstran� znak dle parametr� Prvn�/Posledn�/V�echny a Odstranit mezery/nechat mezery
	bool remove(const char &, remove_enum_delete_order DELETE = FIRST, remove_use_remove_wtsp WTSP = REMOVE);
	//najde prvn� znak zleva a vr�t� jeho index
	unsigned find(const char&, find_way WAY = RIGHT);
	//spocita vybrane prvky
	unsigned count(const char&)const;
	bool checkNumber();
	//vypi� text
	friend ostream& operator<<(ostream &str, const String &text);
	void operator=(const String &);
	//converzni funkce
	double convToDouble();
	char* convertToChar();
	//zkombinuje n-po�et Stringu
	void combine(DynamicArray<String> &);
	//��d�c� hodnoty
	bool _temp = false;
private:
	char *_text = nullptr;
	size_t velikost = 0;
	int16_t _selectedNumber = -1;
};