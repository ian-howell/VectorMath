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

// add 2 vectors together, giving the option to save the new vector
void scalarMath(map<string, Vector>& vectors, string op);

// find the dot product of 2 vectors. Return the answer
double dotMath(map<string, Vector>& vectors);

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
			scalarMath(VList, "add");
		}
		else if (op == "sub")
		{
			scalarMath(VList, "sub");
		}
		else if (op == "dot")
		{
			dotMath(VList);
		}
		else if (op == "cro")
		{
			scalarMath(VList, "cross");
		}
		else if (op == "mag")
		{
			cout << "magnitude\n";
		}
		else if (op == "ang")
		{
			cout << "angle\n";
		}
		else if (op == "pri")
		{
			printList(VList);
		}
		else if (op == "del")
		{
			cout << "delete\n";
		}
		else if (op == "exi")
		{
			cout << "exit\n";
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

	cout << "Enter a name for this string\n";
	prompt();
	cin >> name;
	cout << "Enter the i, j, and k components seperated by spaces\n";
	prompt();
	cin >> i >> j >> k;

	vectors[name] = Vector(i, j, k);
}

void scalarMath(map<string, Vector>& vectors, string op)
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

double dotMath(map<string, Vector>& vectors)
{
	if (vectors.size() < 2 )
	{
		cout << "ERROR: You must have at least 2 vectors saved for this function\n";
		return -1;
	}

	cout << "Enter the names of the two vectors you would like to dot together\n";
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

	double answer = dot(vectors[v1], vectors[v2]);

	cout << v1 << " dot " << v2 << " = " << answer << endl;

	return answer;


}

void printList(map<string, Vector>& vectors)
{
	map<string, Vector>::iterator p;
	for (p = vectors.begin(); p != vectors.end(); p++)
	{
		cout << p->first << " => " << p->second << endl;
	}
}
