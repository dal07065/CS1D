// Lina Kang
// CS1D MW 2:30 - 5:00 PM
// Assignment 7 - Hashing
// This program exercises the hashing algorithms using a map

/* OUTPUT
Lina Kang
CS1D MW 2:30-5:00PM
Assignment 7 - Hashing
This program exercises the hashing algorithms using a map
Data Structure Used: map
--------------------------
Part One:
--------------------------
0 ---> ( 29, Dana Point )
1 ---> ( 88, El Segundo )
2 ---> ( 31, Los Angeles )
3 ---> ( 32, San Diego )
4 ---> ( 62, Laguna Hills )
5
6 ---> ( 35, Tustin )
7 ---> ( 60, Santa Ana )
8
9
10
11 ---> ( 11, La Jolla )
12 ---> ( 99, San Juan )
13 ---> ( 42, Vista )
14
15 ---> ( 44, Irvine )
16 ---> ( 103, Oceanside )
17 ---> ( 17, Orange )
18 ---> ( 18, Del Mar )
19 ---> ( 19, Brea )
20 ---> ( 49, San Diego )
21
22 ---> ( 22, Aliso Viejo )
23 ---> ( 41, San Clemente )
24
25
26
27
28
--------------------------
Part Two:
--------------------------
0 ---> ( 31, Los Angeles )
1 ---> ( 32, San Diego )
2
3
4 ---> ( 35, Tustin )
5
6 ---> ( 99, San Juan )
7
8
9 ---> ( 62, Laguna Hills )
10 ---> ( 103, Oceanside )
11 ---> ( 42, Vista )
12 ---> ( 11, La Jolla )
13 ---> ( 44, Irvine )
14 ---> ( 41, San Clemente )
15
16
17 ---> ( 17, Orange )
18 ---> ( 18, Del Mar )
19 ---> ( 49, San Diego )
20 ---> ( 19, Brea )
21
22 ---> ( 22, Aliso Viejo )
23
24
25
26 ---> ( 88, El Segundo )
27
28
29 ---> ( 60, Santa Ana )
30 ---> ( 29, Dana Point )

 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "hashTable.h"

using namespace std;

int main()
{
	cout << "Lina Kang\n"
			"CS1D MW 2:30-5:00PM\n"
			"Assignment 7 - Hashing\n"
			"This program exercises the hashing algorithms using a map\n";
	cout << "Data Structure Used: map  \n"
			"--------------------------\n"
			"Part One: \n"
			"--------------------------\n";

	hashmap citiesDouble(29);

	citiesDouble.hashingDouble();

	cout << "--------------------------\n"
			"Part Two: \n"
			"--------------------------\n";

	hashmap citiesQuadratic(31);

	citiesQuadratic.hashingQuadratic();

}

/* input.txt

18 Laguna Niguel
41 Mission Viejo
22 San Clemente
44 Irvine
Delete key 41
58 Lake Forest
32 San Diego
49 Anaheim
Delete key 58
31 Los Angeles
17 Orange
72 Palms Springs
41 Riverside
Delete key 72
19 Brea
60 Santa Ana
35 Tustin
103 Oceanside
11 La Jolla
18 Del Mar
22 Aliso Viejo
49 Laguna Beach
Delete key 41
42 Vista
49 San Diego
99 San Juan
29 Dana Point
88 El Segundo
41 San Clemente
62 Laguna Hills

 */

