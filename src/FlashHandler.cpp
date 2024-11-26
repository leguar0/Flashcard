#include "FlashHandler.h"

void CFlashHandler::loadFlashcards(const std::string& filePath, std::vector<flashcard::CFlashcard>& vFlashcards)
{
	std::ifstream file(filePath);

	if (file)
	{
		int originalLang;
		int translatedLang;
		std::string originalText;
		std::string translatedText;

		while (file >> originalLang >> translatedLang >> originalText >> translatedText)
		{

			flashcard::CFlashcard flashcard(static_cast<flashcard::eLanguage>(originalLang),
				static_cast<flashcard::eLanguage>(translatedLang), originalText, translatedText);
			vFlashcards.push_back(flashcard);
		}
	}
	else
	{
		std::cout << "ERROR Z PLIKIEM!!!" << std::endl;
	}

	file.close();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

