#include "Vector.h"
#include <iostream>
#include <map>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

void prompt();

// print out the menu
void menu();

// add a vector to the map
void create(map<string, Vector>& vectors);

// create a new vector using vector operation 'op', then
// give the option to save the new vector
void vectorMath(map<string, Vector>& vectors, string op);

// find either the angle or dot product of 2 vectors based on 'op'
// return the answer
double scalarMath(map<string, Vector>& vectors, string op);

// get the magnitude of a vector
double findMagnitude(map<string, Vector>& vectors);

// delete a vector from the map
void deleteVector(map<string, Vector>& vectors);

// print the list of vectors
void printList(map<string, Vector>& vectors);


int main()
{
	map<string, Vector> VList;
	string op = "";

	menu();
	do
	{
		//get operation from user
		prompt();
		cin >> op;

		//shorten the option to allow for shortcuts
		op = op.substr(0, 3);

		if (op == "cre")
		{
			create(VList);
		}
		else if(op ==  "add")
		{
			vectorMath(VList, "add");
		}
		else if (op == "sub")
		{
			vectorMath(VList, "sub");
		}
		else if (op == "dot")
		{
			scalarMath(VList, "dot");
		}
		else if (op == "cro")
		{
			vectorMath(VList, "cross");
		}
		else if (op == "mag")
		{
			findMagnitude(VList);
		}
		else if (op == "ang")
		{
			scalarMath(VList, "angle");
		}
		else if (op == "pri")
		{
			printList(VList);
		}
		else if (op == "del")
		{
			deleteVector(VList);
		}
		else if (op == "exi")
		{
			// Delete vectors!
			cout << "Goodbye!\n";
		}
		else if (op == "?")
		{
			menu();
		}
		else
		{
			menu();
		}

	} while (op != "exi");



	return 0;
} 

void prompt()
{
	cout << ">>>";
}

void menu()
{
	cout << "Menu:\n";
	cout << "1. [create] new vector\n";
	cout << "2. [add]\n";
	cout << "3. [subtract]\n";
	cout << "4. [dot] product\n";
	cout << "5. [cross] product\n";
	cout << "6. [magnitude]\n";
	cout << "7. [angle] between 2 vectors\n";
	cout << "8. [print] the list of vectors\n";
	cout << "9. [delete] a vector\n";
	cout << "10. [exit]\n";
	cout << "11. help [?]\n";
}

void create(map<string, Vector>& vectors)
{
	string name = "";
	double i = 0, j = 0, k = 0;

	cout << "Enter a name for this vector\n";
	prompt();
	cin >> name;
	cout << "Enter the i, j, and k components seperated by spaces\n";
	prompt();
	cin >> i >> j >> k;

	vectors[name] = Vector(i, j, k);
}

void vectorMath(map<string, Vector>& vectors, string op)
{
	if (vectors.size() < 2 )
	{
		cout << "ERROR: You must have at least 2 vectors saved for this function\n";
		return;
	}

	cout << "Enter the names of the two vectors you would like to " << op << endl; 
	prompt();

	string v1, v2;
	cin >> v1 >> v2;

	if (vectors.find(v1) == vectors.end())
	{
		cout << v1 << " was not found in the list\n";
		return;
	}
	if (vectors.find(v2) == vectors.end())
	{
		cout << v2 << " was not found in the list\n";
		return;
	}

	Vector answer;
	if (op == "add")
	{
		answer = vectors[v1] + vectors[v2];
		cout << v1 << " + " << v2 << " = " << answer << endl;
	}
	else if (op == "sub")
	{
		answer = vectors[v1] - vectors[v2];
		cout << v1 << " - " << v2 << " = " << answer << endl;
	}
	else if (op == "cross")
	{
		answer = cross(vectors[v1], vectors[v2]);
		cout << v1 << " cross " << v2 << " = " << answer << endl;
	}

	// save the sum to the vector list?
	cout << "Would you like to save this new vector to the list? (y/n)\n";
	prompt();
	string choice;
	cin >> choice;
	if (tolower(choice[0]) == 'y')
	{
		cout << "Enter a name for the new vector\n";
		string answerName = "";
		cin >> answerName;
		vectors[answerName] = answer;
	}
}

double scalarMath(map<string, Vector>& vectors, string op)
{
	if (vectors.size() < 2 )
	{
		cout << "ERROR: You must have at least 2 vectors saved "
			 << "for this function\n";
		return -1;
	}

	cout << "Enter the names of the two vectors for the " 
		<< op << " operation\n";
	prompt();

	string v1, v2;
	cin >> v1 >> v2;

	if (vectors.find(v1) == vectors.end())
	{
		cout << v1 << " was not found in the list\n";
		return -1;
	}
	if (vectors.find(v2) == vectors.end())
	{
		cout << v2 << " was not found in the list\n";
		return -1;
	}

	double answer = 0;
	if (op == "dot")
	{
		answer = dot(vectors[v1], vectors[v2]);
		cout << v1 << " dot " << v2 << " = " << answer << endl;
	}
	else if (op == "angle")
	{
		answer = angle(vectors[v1], vectors[v2]);
		cout << "The angle between " << v1 << " and " << v2
			 << " is " << answer << endl;
	}

	return answer;
}

double findMagnitude(map<string, Vector>& vectors)
{
	string v1 = "";
	double answer = 0;
	cout << "Enter the name of the vector whose magnitude you want\n";
	prompt();
	cin >> v1;

	if (vectors.find(v1) == vectors.end())
	{
		cout << v1 << " was not found in the list\n";
		return -1;
	}

	answer = vectors[v1].getMagnitude();

	cout << "Magnitude of " << v1 << ": " << answer << endl;

	return answer;
}

void deleteVector(map<string, Vector>& vectors)
{
	string v1 = "";
	cout << "Enter the name of the vector you would like to delete\n";
	prompt();
	cin >> v1;

	map<string, Vector>::iterator p = vectors.find(v1);
	if (p == vectors.end())
	{
		cout << v1 << " was not found in the list\n";
		return;
	}

	// delete the item from the map
	vectors.erase(p);
}

void printList(map<string, Vector>& vectors)
{
	map<string, Vector>::iterator p;
	for (p = vectors.begin(); p != vectors.end(); p++)
	{
		cout << p->first << " => " << p->second << endl;
	}
}
