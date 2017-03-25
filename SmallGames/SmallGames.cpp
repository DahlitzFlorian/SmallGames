// SmallGames.cpp : Definiert die exportierten Funktionen f�r die DLL-Anwendung.
// @author Florian Dahlitz

#include "stdafx.h"

#include "SmallGames.h"

void ISmallGames::HangingMan::setupGame()
{
	wordlist = getWordlist();
	word = getRandomKey(wordlist);
	userWord = "_";

	for (unsigned int i = 0; i < word.size() - 1; ++i)
		userWord += " _";
	
	buildWindow();

	return;
}

void ISmallGames::HangingMan::buildWindow()
{
	system("cls");

	std::cout << "THE HANGING MAN" << std::endl;

	for (it = hangingManParts.begin(); it != hangingManParts.end(); ++it)
		if (it->first == m_efforts)
			std::cout << it->second << std::endl << std::endl;

	for (int i = 0; i < (m_hangingMan - manHeight[m_efforts]); ++i)
		std::cout << "\n";

	std::cout << "" << std::endl << std::endl;	// clean buffer + better overview

	std::cout << userWord << std::endl;

	return;
}

std::map<unsigned int, std::string> ISmallGames::HangingMan::getWordlist()
{
	unsigned int i = 0;
	std::string strWord;
	std::map<unsigned int, std::string> wordlist;
	std::ifstream worldlistFile(m_path);
	if (worldlistFile.fail())
		std::cout << m_path << std::endl;
	// TODO: change reading file w/ vectors -> read something about
	while (std::getline(worldlistFile, strWord))
	{
		wordlist[i] = strWord;
		std::cout << ++i << " - " << strWord << std::endl;
	}

	return wordlist;
}

std::string ISmallGames::HangingMan::getRandomKey(std::map<unsigned int, std::string> wordlist)
{
	auto iter = wordlist.begin();
	srand(time(NULL));
	std::advance(iter, rand() % wordlist.size());
	
	return iter->second;
}

void ISmallGames::HangingMan::playGame()
{
	char userChar = getUserChar();

	return;
}

char ISmallGames::HangingMan::getUserChar()
{
	char userChar;
	std::cout << "Type in a character: ";
	std::cin >> userChar;
	// TODO: check if char was already taken
	return userChar;
}
