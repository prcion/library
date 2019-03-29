#pragma once
#include <string>
using std::string;

class book
{
private:
	int id;
	string author, title, gender;
	int year;
public:
	/*
	 * return the id of the entity's current
	 */
	int get_id() const;

	/*
	 * return the author of the entity's current
	 */
	string get_author() const;
	
	/*
	 * return the title of the entity's current
	 */
	string get_title() const;
	
	/*
	 * return the gender of the entity's current
	 */
	string get_gender() const;
	
	/*
	 * return the year of the entity's current
	 */
	int get_year() const;
	

	/*
	 * set the author of the entity's current with other author
	 */
	void set_author(string s_author);

	/*
	 * set the title of the entity's current with other title
	 */
	void set_title(string s_title);

	/*
	 * set the gender of the entity's current with other gender
	 */
	void set_gender(string s_gender1);

	/*
	 * set the year of the entity's current with other year
	 */
	void set_year(int s_year);


	/*
	 * Create a entity's book

	 * Parameters:
	 				in: id - int
						title - string
						author - string
						gender - string
						year  - int
					out: -
					post: A final create a entity's book
	 */
	book(int id, string title, string author, string gender, int year);

	/*
	 * Destroy the class book
	 */
	~book();
};
void test_book();

