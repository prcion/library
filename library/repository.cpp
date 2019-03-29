#include "repository.h"
#include <assert.h>
#include <iostream>
#include <utility> 
#include <vector>
#include <algorithm>
#include <string>
using std::cout;
using std::swap;
using std::stoi;
using std::sort;
using std::string;

void repository::store_book(book e)
{
	all.push_back(e);
}

void repository::change_book(int id, string title, string author, string gender, int year)
{
	for (auto& el : all) {
		if (el.get_id() == id)
		{
			el.set_title(title);
			el.set_author(author);
			el.set_gender(gender);
			el.set_year(year);
		}
	}
}

void repository::delete_book(int id)
{
	for (auto& el : all) {
		if (el.get_id() == id)
		{
			swap(el, all.back());
			break;
		}
	}
	all.pop_back();
}
vector<book> repository::get_all()
{
	return all;
}

book repository::back_book() const
{
	return all.back();
}

int repository::len() const
{
	return all.size();
}

vector<book> repository::find_book(string comand, string comand2)
{
	vector <book> books;
	for (auto& e : all)
	{
		if (comand == "title")
			if (e.get_title() == comand2)
				books.push_back(e);
		if (comand == "author")
			if (e.get_author() == comand2)
				books.push_back(e);
		if (comand == "gen")
			if (e.get_gender() == comand2)
				books.push_back(e);
		if (comand == "year")
		{
			int year = stoi(comand2);
			if (e.get_year() == year)
				books.push_back(e);
		}
	}
	return books;
}
struct EntityComp 
{
	string property;
	EntityComp(string property) { this->property = property; }
	bool operator()(const book& s1, const book& s2) const 
	{
		if (property == "title")
			return s1.get_title() < s2.get_title();
		else if (property == "author")
				return s1.get_author() < s2.get_author();
			else if (s1.get_year() < s2.get_year())
					return s1.get_year() < s2.get_year();
				else if (s1.get_year() == s2.get_year())
						return s1.get_gender() < s2.get_gender();
					else return 0;
	}
};
vector <book> repository::sort_book(string comand)
{
	vector <book> books;
	books = all;
	sort(books.begin(), books.end(), EntityComp(comand));

	return books;
}

repository::repository(){}
repository::~repository(){}

void test_repo()
{
	/*
	 * STORE THE BOOK IN VECTOR
	 */
	book e{ 1,"1","1","1", 1 };
	repository re;
	re.store_book(e);
	assert(re.len() == 1);
	assert(re.back_book().get_id() == 1);

	book e1{ 2,"2","2","2", 2 };
	re.store_book(e1);
	assert(re.len() == 2);

	/*
	 * STORE THE EXESTING BOOK
	 */
	re.change_book(2, "john9", "adap", "map", 1809);
	assert(re.len() == 2);
	assert(re.back_book().get_title() == "john9");
	assert(re.back_book().get_author() == "adap");
	assert(re.back_book().get_year() == 1809);

	/*
	 * DELETE THE BOOK IN VECTOR
	 */
	re.delete_book(1);
	assert(re.len() == 1);
	assert(re.back_book().get_title() == "john9");
	assert(re.back_book().get_author() == "adap");
	assert(re.back_book().get_year() == 1809);

	/*
	 * GET ALL BOOKS FROM VECTOR
	 */
	book e2{ 3, "john1", "adap1", "map1", 1809 };
	re.store_book(e2);
	vector <book> r;
	r = re.get_all();
	assert(r.size() == 2);

	/*
	 * FIND A BOOK IN THE VECTOR
	 */
	vector <book> books;
	books = re.find_book("title", "john9");
	assert(books.size() == 1);

	books = re.find_book("author", "adap1");
	assert(books.size() == 1);

	books = re.find_book("gen", "map1");
	assert(books.size() == 1);

	books = re.find_book("year", "1809");
	assert(books.size() == 2);

	/*
	 * SORT ALL BOOKS
	 */
	
	books = re.sort_book("title");
	books = re.sort_book("author");
	books = re.sort_book("year+gen");
	book e3{ 3, "john1", "adap1", "map1", 1 };
	re.store_book(e3);
	books = re.sort_book("year+gen");
}