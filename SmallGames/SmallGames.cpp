// SmallGames.cpp : Definiert die exportierten Funktionen für die DLL-Anwendung.
// @author Florian Dahlitz

#include "stdafx.h"

#include "SmallGames.h"

void ISmallGames::HangingMan::setupGame()
{
	wordlist = getWordlist();

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

	for (int i = 0; i < userWord.length(); i++)
		std::cout << userWord[i] << " ";

	std::cout << std::endl; // clean buffer

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

std::string ISmallGames::HangingMan::getRandomWord()
{
	std::string randomWord;
	auto iter = wordlist.begin();

	srand(time(NULL));
	std::advance(iter, rand() % wordlist.size());
	randomWord = iter->second;

	wordlist.erase(iter);
	
	return randomWord;
}

void ISmallGames::HangingMan::playGame()
{
	usedChars.clear();
	m_efforts = 0;
	word = getRandomWord();
	boost::to_upper(word);
	userWord = "_";

	for (unsigned int i = 0; i < word.size() - 1; ++i)
		userWord += "_";

	do {
		buildWindow();

		char userChar = getUserChar();
		addToUserWord(userChar);

	} while (userWord.compare(word) && (m_efforts != 6));

	// reload to add last char to display
	buildWindow();

	// ask for another word from wordlist
	if (!wordlist.empty())
	{
		char userInput;
		std::cout << "Wonna get another word from list? (J/N): ";
		std::cin >> userInput;
		userInput = toupper(userInput);

		if (userInput == 'J')
			playGame();
	}

	return;
}

char ISmallGames::HangingMan::getUserChar()
{
	std::string userInput;
	char userChar;

	do {
		std::cout << "Type in a character: ";
		std::cin >> userInput;
		userChar = userInput[0];
		userChar = toupper(userChar);
	} while ((usedChars.count(userChar) == 1) || (allowedChars.count(userChar) != 1));

	usedChars[userChar] = userChar;

	return userChar;
}

void ISmallGames::HangingMan::addToUserWord(char userChar)
{
	size_t found = word.find(userChar);
	
	if (found == std::string::npos)
		m_efforts++;

	while (found != std::string::npos)
	{
		userWord[found] = userChar;
		found = word.find(userChar, found+1);
	}

	return;
}
