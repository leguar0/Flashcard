#include <iostream>
#include "StatsInfo.h"
#include "FlashHandler.h"

int main()
{
#ifdef _DEBUG
	//flashcard::CFlashcard flashc(
	//	flashcard::eLanguage::LANGUAGE_ENGLISH,
	//	flashcard::eLanguage::LANGUAGE_POLISH,
	//	"dog",
	//	"pies");

	//flashcard::StatsInterface::AddNewFlashcard(flashc);

	//flashcard::StatsInterface::MarkAsMemorized(
	//	flashcard::eLanguage::LANGUAGE_ENGLISH,
	//	flashcard::eLanguage::LANGUAGE_POLISH,
	//	"dog"
	//);

	//try
	//{
	//	flashcard::StatsInterface::MarkAsMemorized(
	//		flashcard::eLanguage::LANGUAGE_ENGLISH,
	//		flashcard::eLanguage::LANGUAGE_POLISH,
	//		"cat"
	//	);
	//} 
	//catch (flashcard::FlashcardNotFoundException flashcardNotFoundEx)
	//{
	//	std::cout << "Exception: " << flashcardNotFoundEx.what << std::endl;
	//}

	//std::cout <<
	//	flashcard::StatsInterface::GetCountFlashcardsUnmemorized()
	//	<< std::endl;

	//std::cout <<
	//	flashcard::StatsInterface::GetCountFlashcards()
	//	<< std::endl;

	std::vector<flashcard::CFlashcard> vFlashcards;
	CFlashHandler::loadFlashcards("../data/flashcards.txt", vFlashcards);

	for (auto flashcard : vFlashcards )
	{
		std::cout << flashcard << std::endl;
	}

#endif // _DEBUG
	return 0;
}