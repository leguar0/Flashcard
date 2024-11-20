#include <iostream>
#include "StatsInfo.h"

int main()
{
#ifdef _DEBUG
	flashcard::StatsInterface::AddNewFlashcard(
		new flashcard::CFlashcard(
			flashcard::eLanguage::LANGUAGE_ENGLISH,
			flashcard::eLanguage::LANGUAGE_POLISH,
			"dog",
			"pies"
		));

	flashcard::StatsInterface::MarkAsMemorized(
		flashcard::eLanguage::LANGUAGE_ENGLISH,
		flashcard::eLanguage::LANGUAGE_POLISH,
		"dog"
	);

	try
	{
		flashcard::StatsInterface::MarkAsMemorized(
			flashcard::eLanguage::LANGUAGE_ENGLISH,
			flashcard::eLanguage::LANGUAGE_POLISH,
			"cat"
		);
	} 
	catch (flashcard::FlashcardNotFoundException)
	{
		std::cout << "Exception: flashcard not found" << std::endl;
	}

	std::cout <<
		flashcard::StatsInterface::GetCountFlashcardsUnmemorized()
		<< std::endl;

	std::cout <<
		flashcard::StatsInterface::GetCountFlashcards()
		<< std::endl;
#endif // _DEBUG
	return 0;
}