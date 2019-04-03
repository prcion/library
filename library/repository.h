#pragma once
#include "book.h"
#include <vector>
using std::vector;

class repository
{
private:
	vector <book> all; // all -> a vector of type book
public:

	// Create the class of type repository
	repository() noexcept;
	
	/*
	 * Store the book in vector

	 * Parameters:
					in: e - book
					pre: e should be a entety's book
					out: -
					post: In final entety's book store in vector of type int
	 */
	void store_book(book e);

	/*
	 * return the back of the book (last element from vector book)
	 */
	book back_book() const;

	/*
	 * return len of the vector <book>
	 */
	int len() const noexcept;

	/*
	 * return vector of book and find a book with a parameter definite

	 * Paramters:
					in: comand -> string
						comand2 -> string
					out: vector of type <book>
			pre: both parameters don't should NILL
			post: return a vector of type <book>
	 */
	vector <book> find_book(string comand, string comand2);

	/*
	 * return vector of book and sort all book after a parameter definite

	 * Paramters:
					in: comand -> string

					out: vector of type <book>
			pre: the parameter don't should NILL
			post: return a vector of type <book> sorted after parameter
	 */
	vector <book> sort_book(string comand);

	/*
	 * Change a book in the vector <book>

	 * Parameters: 
					int: id -> int
						title -> string
						author -> string
						gender -> string
						year -> int
					out: -
			pre: the id should be in a book from vector
			post: change the book in the vector
	 */
	void change_book(int id, string title, string author, string gender, int year);

	/*
	 * Delete a book in the vector <book> after id
	 */
	void delete_book(int id);

	/* 
	 * Get a copy by a vector of type <book>
	 */
	vector <book>& get_all() noexcept;
	
};

void test_repo();
