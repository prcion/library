#include "book.h"
#include <assert.h>
#include <string>
#include <iostream>
using namespace std;

book::book(int id, string title, string author, string gender, int year)
{
	this->id = id;
	this->title = title;
	this->author = author;
	this->gender = gender;
	this->year = year;

}

book::book(const book &p)
{
	this->id = p.id;
	this->title = p.title;
	this->author = p.author;
	this->gender = p.gender;
	this->year = p.year;
}


void book::set_author(string s_author)
{
	this->author = s_author;
}
void book::set_title(string s_title)
{
	this->title = s_title;
}
void book::set_gender(string s_gender)
{
	this->gender = s_gender;
}
void book::set_year(int s_year) noexcept
{
	this->year = s_year;
}


int book::get_id() const noexcept
{
	return id;
}
string book::get_author() const
{
	return author;
}
string book::get_title() const
{
	return title;
}
string book::get_gender() const
{
	return gender;
}
int book::get_year() const noexcept
{
	return year;
}


void test_book()
{
	book one{ 1, "Luceafarul", "Mihai Eminescu", "Poezii", 1880 };
	assert(one.get_id() == 1);
	assert(one.get_title() == "Luceafarul");
	assert(one.get_author() == "Mihai Eminescu");
	assert(one.get_gender() == "Poezii");
	assert(one.get_year() == 1880);

	one.set_title("barak");
	assert(one.get_title() == "barak");

	one.set_author("John");
	assert(one.get_author() == "John");

	one.set_gender("wtf");
	assert(one.get_gender() == "wtf");

	one.set_year(1800); 
	assert(one.get_year() == 1800);
}