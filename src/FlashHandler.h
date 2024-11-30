//
//		author: @leguar
//		date: 25/11/24
//		purpose: 
//

#ifndef FLASHHANDLER_H
#define FLASHHANDLER_H

#include <fstream>
#include <vector>

#include "User.h"
#include "Flashcard.h"
#include "StatsManager.h"

class CFlashHandler
{
	CFlashHandler();
public:
	static bool loadUserStats(const std::string& filePath);
	static void saveUserStats(const std::string& filePath);

	static bool loadFlashcards(const std::string& filePath, std::vector<flashcard::CFlashcard>& vFlashcards);
	static void saveFlashcards(const std::string& filePath, std::vector<flashcard::CFlashcard>& vFlashcards);
};

#endif // !FLASHHANDLER_H
