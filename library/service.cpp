#include "service.h"
#include <string>
#include "book.h"
#include <assert.h>
#include <vector>

using std::string;
using std::stoi;
using std::vector;

void service::add(int id, string title, string author, string gender, int year)
{
	book b{ id, title, author, gender, year };
	val.validateBook(b);
	repo.store_book(b);
}

void service::change(int id, string title, string author, string gender, int year)
{
	repo.change_book(id, title, author, gender, year);
}

vector<book> service::filter(string cmd, string cmd2)
{
	vector <book> new_books;
	vector <book> books = repo.get_all();
	for (auto& e : books)
	{
		if (cmd == "title")
		{
			if (e.get_title() == cmd2)
				new_books.push_back(e);
		}
		else
		{
			int year = 0;
			year = stoi(cmd2);
			if (e.get_year() == year)
				new_books.push_back(e);
		}
	}
	return new_books;
}

vector<book> service::find(string comand, string comand2)
{
	vector <book> books;
	books = repo.find_book(comand, comand2);
	return books;
}

vector<book> service::sort_books(string comand)
{
	vector<book> books;
	books = repo.sort_book(comand);
	return books;
}

int service::lenn() noexcept
{
	return repo.len();
}
void service::dell(int id)
{
	repo.delete_book(id);
}
vector <book>& service::get() noexcept
{
	return repo.get_all();
}

book service::back_b() const
{
	return repo.back_book();
}


service::service() noexcept
{ 
}



void test_service()
{
	service v;

	/*
	 * TEST FOR ADD
	 */

	v.add(2, "john", "adap", "map", 1809);
	v.add(1, "john1", "adap1", "map1", 1009);
	v.add(3, "john2", "john", "map2", 1109);
	assert(v.lenn() == 3);
	assert(v.back_b().get_author() == "john");

	/*
	 * TEST FOR CHANGE
	 */

	v.change(3, "opa", "hopa", "mar", 1111);
	assert(v.lenn() == 3);
	assert(v.back_b().get_title() == "opa");
	assert(v.back_b().get_year() == 1111);

	/*
	 * TEST FOR FILTERS
	 */

	vector <book> books;
	//title
	books = v.filter("title", "john");
	assert(books.size() == 1);
	//year
	books = v.filter("year", "1009");
	assert(books.size() == 1);

	/*
	 * TEST FOR DELETE
	 */

	v.dell(3);
	assert(v.lenn() == 2);
	assert(v.back_b().get_title() == "john1");
	assert(v.back_b().get_year() == 1009);

	/*
	 * TEST FOR GET ALL BOOKS IN A VECTOR
	 */

	vector  <book> b;
	b = v.get();
	assert(b.size() == 2);


	/*
	 * FIND THE BOOKS WITH CERTAIN ELEMENT
	 */

	b = v.find("title", "john1");
	assert(b.size() == 1);

	/*
	 * SORT
	 */
	b = v.sort_books("title");

}