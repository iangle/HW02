/** Phone directory application that uses console I/O. */

#include "Array_Based_PD.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <limits>
using namespace std;

// Forward declaration of functions
void process_commands(Phone_Directory&);
void do_add_change_entry(Phone_Directory&);
void do_lookup_entry(Phone_Directory&);
void do_remove_entry(Phone_Directory&);
void do_save(Phone_Directory&);

int main(int argc, char* argv[])
{
	if (argc < 2) {
		cerr << "Must specify the name of the data file"
			" that contains the directory\n";
		return 1;
	}
	Phone_Directory the_directory;
	the_directory.load_data(argv[1]);
	process_commands(the_directory);
}

void process_commands(Phone_Directory& the_directory)
{
	string commands[] = {
		"Add/Change Entry",
		"Look Up Entry",
		"Remove Entry",
		"Save Directory",
		"Exit" };
	const int NUM_COMMANDS = 5;
	int choice = NUM_COMMANDS - 1;
	do {
		for (int i = 0; i < NUM_COMMANDS; i++) {
			cout << "Select: " << i << " " << commands[i] << "\n";
		}
		cin >> choice;
		cin.ignore(numeric_limits<int>::max(), '\n');
		switch (choice) {
		case 0: do_add_change_entry(the_directory); break;
		case 1: do_lookup_entry(the_directory); break;
		case 2: do_remove_entry(the_directory); break;
		case 3: do_save(the_directory); break;
		case 4: do_save(the_directory); break;
		}
	} while (choice < NUM_COMMANDS - 1);
}

void do_add_change_entry(Phone_Directory& the_directory)
{
	string name;
	string number;
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter number: ";
	getline(cin, number);
	string old_number =
		the_directory.add_or_change_entry(name, number);
	if (old_number != "") {
		cout << name << " has been changed in the directory\n";
		cout << "Old number was " << old_number << "\n";
	}
	else {
		cout << name << " has been added to the directory\n";
	}
}

void do_lookup_entry(Phone_Directory& the_directory)
{
	string name;
	cout << "Enter name: ";
	getline(cin, name);
	string number = the_directory.lookup_entry(name);
	if (number != "") {
		cout << "The number for " << name << " is " << number << "\n";
	}
	else {
		cout << name << " is not in the directory\n";
	}
}
/** Remove an entry
post: The name is no longer in the directory
@param name The name to be removed
@return That person's name or an empty string
if not in the directory
*/
//trevor:

string Phone_Directory::remove_entry(const string& name) // Exercise 1.7: please complete the remove_entry() method - Ed/Kent
{
	string number = "";
	int index = find(name);
	if (find(name))
	{
		for (int i = index; i < size - 1; i++)
		{
			the_directory[i] = the_directory[i + 1];
			return number;
		}
	}
	else
	{
		return "";
	}

	/* Redid the do_remove_entry function so that it checks to see
	if a name exists and then deletes it if it does*/
	// isaac
	void do_remove_entry(Phone_Directory& the_directory) // Exercise 1.8: please complete the function do_remove_entry - Ed/Kent
	{

		string name;
		// asking user for name
		cout << "Enter name: ";
		getline(cin, name);
		string removeName = the_directory.remove_entry(name);
		// checking to see if the name exists in the directory
		if (name == removeName) {
			cout << "Your name has been removed from the directory";
		}
		else {
			cout << "That name does not exist!";
		}

	}

void do_save(Phone_Directory& the_directory)
{
	the_directory.save();
}

