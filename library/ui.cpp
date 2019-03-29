#include "ui.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

void ui::add_bk()
{
	int id;
	cout << "ID: ";
	cin >> id;
	string title;
	cout << "TITLE: ";
	cin >> title;
	string author;
	cout << "AUTHOR: ";
	cin >> author;
	string gender;
	cout << "GEN: ";
	cin >> gender;
	int year;
	cout << "YEAR: ";
	cin >> year;

	srv.add(id, title, author, gender, year);


	srv.add(2, "john", "adap", "map", 1809);
	srv.add(1, "infinity", "zara", "cap2", 1109);
	srv.add(3, "adapa", "john", "ap2", 1109);
	cout << "The book was added! \n";
}

void ui::change_bk()
{
	int id;
	cout << "ID: ";
	cin >> id;
	string title;
	cout << "TITLE: ";
	cin >> title;
	string author;
	cout << "AUTHOR: ";
	cin >> author;
	string gender;
	cout << "GEN: ";
	cin >> gender;
	int year;
	cout << "YEAR: ";
	cin >> year;

	srv.change(id, title, author, gender, year);
	cout << "The book was changed! \n";
}

void ui::delete_bk()
{
	int id;
	cout << "ID: ";
	cin >> id;

	srv.dell(id);
	cout << "The book was deleted! \n";
}

void ui::filter_bk()
{
	vector <book> books;
	string cmd;
	cout << "title/year: ";
	cin >> cmd;
	if (cmd == "title") {
		string cmd2;
		cout << "Name of title: ";
		cin >> cmd2;
		books = srv.filter(cmd, cmd2);
	}
	else 
	{
		if (cmd == "year") 
		{

			string cmd2;
			cout << "The year: ";
			cin >> cmd2;
			books = srv.filter(cmd, cmd2);
		}
	}
	print(books);
}

void ui::find_bk()
{
	string comand, comand2;
	cout << "Find after title/author/gen/year: ";
	cin >> comand;
	cout << ">>> ";
	cin >> comand2;
	vector <book> books;
	books = srv.find(comand, comand2);
	print(books);

}

void ui::sort_bk()
{
	string comand;
	cout << "Sort after title/author/year+gen: ";
	cin >> comand;
	vector <book> books;
	books = srv.sort_books(comand);
	print(books);
}
void ui::print(vector<book> books)
{
	cout << "********************************" << '\n';
	cout << "ID" << "     " << "TITLE" << "     " << "AUTHOR" << "     " << "GEN" << "     " << "YEAR" << '\n';
	for (auto& el : books)
		cout << el.get_id() << "      " << el.get_title() << "     " << el.get_author()
		<< "     " << el.get_gender() << "     " << el.get_year() << "     " << '\n';
	cout << "********************************" << '\n';
}
void ui::print_all()
{
	vector <book> all = srv.get();
	cout << "********************************"<< '\n';
	cout << "ID" << "     " << "TITLE" << "     " << "AUTHOR" << "     " << "GEN" << "     " << "YEAR" << '\n';
	for (auto& el : all)
		cout << el.get_id() << "      " << el.get_title() << "     " << el.get_author() 
		<< "     " << el.get_gender() << "     " << el.get_year() << "     " << '\n';
	cout << "********************************" << '\n';
}

void ui::run()
{
	int rule = true;
	while (rule)
	{
		cout<<"1 Add\n2 Change\n3 Delete\n4 Filter\n5 Find\n6 Sort \n7 Print\n0 Exit\n";
		int cmd = 0;
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			add_bk();
			break;
		case 2:
			change_bk();
			break;
		case 3:
			delete_bk();
			break;
		case 4:
			filter_bk();
			break;
		case 5:
			find_bk();
			break;
		case 6:
			sort_bk();
			break;
		case 7:
			print_all();
			break;
		case 0:
			rule = 0;
			break;
		default:
			printf("Comand invalid!!!\n");
		}
	}
}

ui::ui()
{
}


ui::~ui()
{
}
