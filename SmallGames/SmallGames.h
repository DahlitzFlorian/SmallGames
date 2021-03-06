// SmallGames.h
// includes several smaller games to play
// @author Florian Dahlitz

#ifdef SMALLGAMES_EXPORT
#define SMALLGAMES_API __declspec(dllexport)
#else
#define SMALLGAMES_API __declspec(dllimport)
#endif

#include <map>		// using std::map<type, type>
#include <string>	// std::string
#include <cstdlib>	// system()
#include <iostream>	// std::cout and std::endl
#include <fstream>	// std::ifstream
#include <iterator>	// iterator in wordlist
#include <ctime>	// time() in srand()
#include <locale>	// toupper()
#include <boost/algorithm/string.hpp>	// to_upper()

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::time;
using std::toupper;
using boost::to_upper;

namespace ISmallGames
{
	class HangingMan
	{
		unsigned int m_efforts;
		const int m_hangingMan = 11;
		const std::string full_path = "C:\\Users\\Florian\\Documents\\Workspace\\C++\\PlaySmallGames\\Debug\\wordlists\\";

		//-------------------------------------------

	public:
		HangingMan()
		{
			setupGame();
			playGame();
		};

		//-------------------------------------------

	private:
		const int manHeight[7] = { 0,4,9,9,9,11,11 };
		std::map<unsigned int, std::string> wordlist;
		std::string word;
		std::string userWord;
		std::map<char, char> usedChars;

	//-------------------------------------------

		const std::map<char, char> allowedChars 
		{
			{ 'A', 'A' },
			{ 'B', 'B' },
			{ 'C', 'C' },
			{ 'D', 'D' },
			{ 'E', 'E' },
			{ 'F', 'F' },
			{ 'G', 'G' },
			{ 'H', 'H' },
			{ 'I', 'I' },
			{ 'J', 'J' },
			{ 'K', 'K' },
			{ 'L', 'L' },
			{ 'M', 'M' },
			{ 'N', 'N' },
			{ 'O', 'O' },
			{ 'P', 'P' },
			{ 'Q', 'Q' },
			{ 'R', 'R' },
			{ 'S', 'S' },
			{ 'T', 'T' },
			{ 'U', 'U' },
			{ 'V', 'V' },
			{ 'W', 'W' },
			{ 'X', 'X' },
			{ 'Y', 'Y' },
			{ 'Z', 'Z' }
		};

	//-------------------------------------------

		const std::map<unsigned int, std::string> hangingManParts
		{
			{ 1,"  _\n / \\\n |  |\n \\_/" },
			{ 2,"  _\n / \\\n |  |\n \\_/\n  |\n  |\n  |\n  |\n  |" },
			{ 3,"  _\n / \\\n |  |\n \\_/\n  |\n\\ |\n \\|\n  |\n  |" },
			{ 4,"  _\n / \\\n |  |\n \\_/\n  |\n\\ | /\n \\|/\n  |\n  |" },
			{ 5,"  _\n / \\\n |  |\n \\_/\n  |\n\\ | /\n \\|/\n  |\n  |\n /\n/" },
			{ 6,"  _\n / \\\n |  |\n \\_/\n  |\n\\ | /\n \\|/\n  |\n  |\n / \\\n/   \\" }
		};
	//-------------------------------------------

		std::map<unsigned int, std::string>::const_iterator it;

	//-------------------------------------------

		SMALLGAMES_API void setupGame();

	//-------------------------------------------

		SMALLGAMES_API void playGame();

	//-------------------------------------------

		void buildWindow();

	//-------------------------------------------

		std::map<unsigned int, std::string> getWordlist(std::string file_path);

	//-------------------------------------------

		std::string getRandomWord();

	//-------------------------------------------

		char getUserChar();

	//-------------------------------------------

		void addToUserWord(char userChar);

	//-------------------------------------------
	};

//-----------------------------------------------
}
