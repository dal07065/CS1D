#include <iostream>
#include <fstream>

using namespace std;

bool recursion(string);
string clearSpaceAndLowercase(string str);

int main()
{
    ifstream input;

    input.open("input.txt");

    string inputString;

    while(input)
    {
        getline(input,inputString);

        cout << "word : " << inputString << endl;

        inputString = clearSpaceAndLowercase(inputString);

        cout << "     : " << inputString << endl << endl;

        bool result = recursion(inputString);

        if(result)
            cout << "True  - Palindrome" << endl;
        else
            cout << "False - Not Palindrome" << endl;
        cout << endl;

    }

    input.close();
}
string clearSpaceAndLowercase(string str)
{
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] != ' ')
			str[i] = tolower(str[i]);
		else
		{
			str.erase(i,1);
			i--;
		}
	}
	return str;
}
bool recursion(string str)
{
    if(str[0] == str[str.size()-1])
        return true;
    else
        return false;

    string newStr;
    for(int i = 1; i < str.size()-1; i++)
    {
        newStr.append(to_string(str[i]));
    }
    recursion(newStr);
}
