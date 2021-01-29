// Lina Kang
// CS1D MW 2:30 - 5:00 PM
// Assignment 8 - Skip List
// This program exercises the skip list method through insertions,
// deletions, searches, and other standard functions of skip list

/*
Lina Kang
CS1D MW 2:30 - 5:00 PM
Assignment 8 - Skip List
This program exercises the skip list method through insertions,
deletions, searches, and standard functions of skip list

Print all levels and items:
----------------------------
Level: 0
Laguna Niguel 18

Level: 1
Laguna Niguel 18

Level: 2
Laguna Niguel 18

Level: 3
Laguna Niguel 18 -> Aliso Viejo 22 -> Tustin 35 -> San Juan 99

Level: 4
Laguna Niguel 18 -> Aliso Viejo 22 -> Dana Point 29 -> San Diego 32 -> Tustin 35 -> San Juan 99

Level: 5
Laguna Niguel 18 -> Aliso Viejo 22 -> Dana Point 29 -> San Diego 32 -> Tustin 35 -> Irvine 44 -> Anaheim 49 -> Laguna Beach 49 -> San Diego 49 -> San Juan 99

Level: 6
La Jolla 11 -> Orange 17 -> Laguna Niguel 18 -> Del Mar 18 -> Brea 19 -> San Clemente 22 -> Aliso Viejo 22 -> Dana Point 29 -> Los Angeles 31 -> San Diego 32 -> Tustin 35 -> San Clemente 41 -> Vista 42 -> Irvine 44 -> Anaheim 49 -> Laguna Beach 49 -> San Diego 49 -> Santa Ana 60 -> Laguna Hills 62 -> El Segundo 88 -> San Juan 99 -> Oceanside 103

Print values and keys:
----------------------------

La Jolla 11
Orange 17
Laguna Niguel 18
Del Mar 18
Brea 19
San Clemente 22
Aliso Viejo 22
Dana Point 29
Los Angeles 31
San Diego 32
Tustin 35
San Clemente 41
Vista 42
Irvine 44
Anaheim 49
Laguna Beach 49
San Diego 49
Santa Ana 60
Laguna Hills 62
El Segundo 88
San Juan 99
Oceanside 103


Find values and keys:
----------------------------
Found: 49 Anaheim

Found: 32 San Diego

Not found: -1


Test empty function:
----------------------------
Testing this skip list: The list is NOT empty
Testing a completely NEW skip list: The list is empty
Testing NEW skip list with 1 item added & removed immediately: The list is empty


Test size function:
----------------------------
Size of "skip": 22
Size of "skipEmpty": 0
Size of "skipEmpty2": 0
*/

#include "header.h"

int main()
{
	skipList skip;

	skip.generateRandom();

	// ---------------- Test "put" and "erase" function ------------------//

	skip.put(18, "Laguna Niguel"); //
	skip.put(41, "Mission Viejo");
	skip.put(22, "San Clemente"); //
	skip.put(44, "Irvine"); //
	skip.erase(41);
	skip.put(58, "Lake Forest");
	skip.put(32, "San Diego"); //
	skip.put(49, "Anaheim"); //
	skip.erase(58);
	skip.put(31, "Los Angeles"); //
	skip.put(17, "Orange"); //
	skip.put(72, "Palms Springs");
	skip.put(41, "Riverside");
	skip.erase(72);
	skip.put(19, "Brea"); //
	skip.put(60, "Santa Ana"); //
	skip.put(35, "Tustin"); //
	skip.put(103, "Oceanside"); //
	skip.put(11, "La Jolla"); //
	skip.put(18, "Del Mar"); //
	skip.put(22, "Aliso Viejo"); //
	skip.put(49, "Laguna Beach"); //
	skip.erase(41);
	skip.put(42, "Vista"); //
	skip.put(49, "San Diego"); //
	skip.put(99, "San Juan"); //
	skip.put(29, "Dana Point"); //
	skip.put(88, "El Segundo"); //
	skip.put(41, "San Clemente"); //
	skip.put(62, "Laguna Hills"); //

	cout << "Lina Kang\n"
			"CS1D MW 2:30 - 5:00 PM\n"
			"Assignment 8 - Skip List\n"
			"This program exercises the skip list method through insertions,\n"
			"deletions, searches, and standard functions of skip list\n\n";

	// ---------------- Output each level of the skip list ------------------//

	cout << "Print all levels and items: \n"
			"----------------------------\n";

	skip.printLevels();

	// -------------- Output the dictionary keys and values -----------------//

	cout << "\n\nPrint values and keys: \n"
			"----------------------------\n\n";

	skip.printDictionary();

	// --------------------- Test "find" function -------------------------//

	cout << "\n\nFind values and keys: \n"
			"----------------------------";

	int key = 49;
	Node * found = skip.find(key);

	if(found != NULL)
		cout << "\nFound: " << found->key << " " << found->name << endl;
	else
		cout << "\nNot found: "<< key;

	key = 32;
	found = skip.find(key);

	if(found != NULL)
		cout << "\nFound: " << found->key << " " << found->name << endl;
	else
		cout << "\nNot found: " << key;

	key = -1;
	found = skip.find(key);

	if(found != NULL)
		cout << "\nFound: " << found->key << " " << found->name << endl;
	else
		cout << "\nNot found: " << key;

	// --------------------- Test "empty" function -------------------------//

	cout << "\n\n\nTest empty function: \n"
			"----------------------------\n";


	cout << "Testing this skip list: ";
	if(skip.empty())
		cout << "The list is empty" << endl;
	else
		cout << "The list is NOT empty" << endl;


	skipList skipEmpty;

	cout << "Testing a completely NEW skip list: ";
	if(skipEmpty.empty())
		cout << "The list is empty" << endl;
	else
		cout << "The list is NOT empty" << endl;


	skipList skipEmpty2;
	skipEmpty2.put(100, "Testing");
	skipEmpty2.erase(100);

	cout << "Testing NEW skip list with 1 item added & removed immediately: ";
	if(skipEmpty2.empty())
		cout << "The list is empty" << endl;
	else
		cout << "The list is NOT empty" << endl;

	// --------------------- Test "size" function ---------------------------//

	cout << "\n\nTest size function: \n"
			"----------------------------";

	cout << "\nSize of \"skip\": " << skip.getSize();
	cout << "\nSize of \"skipEmpty\": " << skipEmpty.getSize();
	cout << "\nSize of \"skipEmpty2\": " << skipEmpty2.getSize();

}

