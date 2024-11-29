#include "FlashHandler.h"

bool CFlashHandler::loadUserStats(const std::string& filePath, flashcard::StatsInterface& stats)
{
	std::ifstream file(filePath);

	if (file)
	{

	}
	else
	{
		return false;
	}
	file.close();
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CFlashHandler::saveUserStats(const std::string& filePath, flashcard::StatsInterface& stats)
{
	std::ofstream file(filePath);

	if (file)
	{

	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CFlashHandler::loadFlashcards(const std::string& filePath, std::vector<flashcard::CFlashcard>& vFlashcards)
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
		return false;
	}

	file.close();
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CFlashHandler::saveFlashcards(const std::string& filePath, std::vector<flashcard::CFlashcard>& vFlashcards)
{
	std::ofstream file(filePath);

	if (file)
	{
		file.clear();

		for (auto flashcard : vFlashcards)
			file << static_cast<int>(flashcard.GetOriginalLang()) << " "
			<< static_cast<int>(flashcard.GetTranslatedLang()) << " "
			<< flashcard.GetOriginalText() << " "
			<< flashcard.GetTranslatedText() << "\n";
	}

	file.close();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

