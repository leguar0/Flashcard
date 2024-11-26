#ifndef FLASHHANDLER_H
#define FLASHHANDLER_H

#include <fstream>
#include <vector>

#include "Flashcard.h"

class CFlashHandler
{
	CFlashHandler();
public:
	static void loadFlashcards(const std::string& filePath, std::vector<flashcard::CFlashcard>& vFlashcards);
	static void saveFlashcards(const std::string& filePath, std::vector<flashcard::CFlashcard>& vFlashcards);
};

#endif // !FLASHHANDLER_H
