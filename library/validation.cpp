#include "validation.h"


ostream & operator<<(ostream & out, const validationBook & ex)
{
	for (const auto& msg : ex.msg)
		out << msg << " ";
	return out;
}

void BookValidation::validateBook(const book b)
{
	vector <string> errors;
	if (b.get_id() < 0) errors.push_back("The id must be greater than 0!");
	if (b.get_author().size() == 0) errors.push_back("Author is not valid!");
	if (b.get_title().size() == 0) errors.push_back("Title is not valid!");
	if (b.get_gender().size() == 0) errors.push_back("Gender is not valid!");
	if (b.get_year() < 0) errors.push_back("Year is not valid!");

	if (errors.size() > 0)
		throw validationBook(errors);
}
