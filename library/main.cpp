#include "book.h"
#include "repository.h"
#include "service.h"
#include "ui.h"
#include <iostream>
using namespace std;
void all_test()
{
	test_book();
	test_repo();
	test_service();
}

int main()
{
	ui UI;
	all_test();
	cout << '\n';
	UI.run();
	return 0;
}