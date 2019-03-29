#pragma once
#include "service.h"

// Class UI
class ui
{

private:

	service srv; // srv -> reference to class service

	/*
	 * Print all book in the vector

	 * Parameters:
					in: books -> vector book
					out: -
			pre: -
			post: print all book 
	 */
	void print(vector <book> books);

	/*
	 * Like function print
	 */
	void print_all();

	/*
	 * Add a book
	 */
	void add_bk();
	
	/*
	 * Change a book
	 */
	void change_bk();

	/*
	 * Delete a book
	 */
	void delete_bk();

	/*
	 * Filter books with a parameter define by user
	 */
	void filter_bk();

	/*
	 * Find a book after a parameter
	 */
	void find_bk();

	/*
	 * Sort all books after a parameter
	 */
	void sort_bk();

public:

	//Run 
	void run();

	// Create the class of type ui
	ui();

	// The destructor of the class
	~ui();
};

