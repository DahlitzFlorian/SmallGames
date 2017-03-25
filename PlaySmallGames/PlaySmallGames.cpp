// PlaySmallGames.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
// @author Florian Dahlitz

#include "stdafx.h"

#include <iostream>
#include <string>
#include "SmallGames.h"

using std::cout;
using std::endl;
using std::cin;

using std::string;

int main()
{
	std::string file;
	std::cout << "Type in wordlistname: ";
	std::cin >> file;
	file = "wordlists/" + file + ".txt";

	ISmallGames::HangingMan test(file);

    return 0;
}

