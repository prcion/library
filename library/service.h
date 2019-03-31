#pragma once
#include "book.h"
#include <vector>
#include "repository.h"
#include "validation.h"
class service
{
private:
	BookValidation val;
	repository repo;
public:
	/*
	 * Add a book

	 * Parameters:
					int: id -> int
						title -> string
						author -> string
						gender -> string
						year -> int
					out: send the parameters in repository
			pre: -
			post:
	 */
	void add(int id, string title, string author, string gender, int year);

	/*
	 * Change a book

	 * Parameters:
					int: id -> int
						title -> string
						author -> string
						gender -> string
						year -> int
					out: send the parameters in repository
			pre: -
			post: -
	 */
	void change(int id, string title, string author, string gender, int year);

	/*
	 * Filter books

	 * Parameters:
					int: cmd -> string
						 cmd2 -> string
					out: send the parameters in repository
			pre: both parameters don't should NILL
			post: return a vector of type <book>
	 */
	vector <book> filter(string cmd, string cmd2);

	/*
	 * return vector of book and find a book with a parameter definite

	 * Paramters:
					in: comand -> string
						comand2 -> string
					out: vector of type <book>
			pre: both parameters don't should NILL
			post: return a vector of type <book>
	 */
	vector <book> find(string comand, string comand2);

	/*
	 * return vector of book and sort all book after a parameter definite

	 * Paramters:
					in: comand -> string

					out: vector of type <book>
			pre: the parameter don't should NILL
			post: return a vector of type <book> sorted after parameter
	 */
	vector <book> sort_books(string comand);
	
	/*
	 * return the back of the book (last element from vector book)
	 */
	book back_b() const;

	/*
	 * Delete a book in the vector <book> after id
	 */
	void dell(int id);

	/*
	 * Get a copy by a vector of type <book>
	 */
	vector <book> get();

	/*
	 * return len of the vector <book>
	 */
	int lenn();

	service();
	~service();
};

void test_service();
