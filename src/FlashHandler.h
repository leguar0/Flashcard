#ifndef FLASHHANDLER_H
#define FLASHHANDLER_H

#include <fstream>
#include <vector>

#include "User.h"
#include "Flashcard.h"

class CFlashHandler
{
	CFlashHandler();
public:
	static bool loadUserStats(const std::string& filePath, flashcard::StatsInterface& stats);
	static void saveUserStats(const std::string& filePath, flashcard::StatsInterface& stats);

	static bool loadFlashcards(const std::string& filePath, std::vector<flashcard::CFlashcard>& vFlashcards);
	static void saveFlashcards(const std::string& filePath, std::vector<flashcard::CFlashcard>& vFlashcards);
};

#endif // !FLASHHANDLER_H
