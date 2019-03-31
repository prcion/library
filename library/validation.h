#pragma once
#include "book.h"
#include <vector>
using namespace std;
class validationBook
{
	vector <string> msg;
public:
	validationBook(const vector <string>& errors):msg{errors}{}
	friend ostream& operator<<(ostream& out, const validationBook& ex);
};

ostream& operator<<(ostream& out, const validationBook& ex);

class BookValidation
{
public:
	void validateBook(const book b);
};
