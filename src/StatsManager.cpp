#include "StatsManager.h"
#include <fstream>

namespace flashcard {

	// Name			:	MarkAsMemorized
	// Purpose		:	Set the flashcard as known
	// Parameters	:	originalLang - original language of the word
	//					translatedLang - translated language of the word
	//					word - word in the original language
	// Returns		:	void - none
	void CStatsManager::MarkAsMemorized(eLanguage originalLang, eLanguage translatedLang, std::string word)
	{
		auto itFlashcard = std::find_if(
			m_StatsInfo.m_vecFlashcards.begin(),
			m_StatsInfo.m_vecFlashcards.end(),
			[=](CFlashcard* flashcard) {
				return flashcard->GetOriginalLang() == originalLang &&
					flashcard->GetTranslatedLang() == translatedLang &&
					flashcard->GetOriginalText() == word;
			});

		if (itFlashcard == m_StatsInfo.m_vecFlashcards.end())
		{
			FlashcardNotFoundException error;
			error.what = "Flashcard not found";
			throw error;
		}

		CFlashcard* flashcard = *itFlashcard;
		flashcard->SetIsMemorized(true);
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Name			:	SaveFlashcardsToDisk
	// Purpose		:	Save flashcards to disk
	// Returns		:	void - none
	void CStatsManager::SaveFlashcardsToDisk()
	{
		std::ofstream file("../data/flashcards.txt");

		std::vector<CFlashcard*> flashcards(m_StatsInfo.m_vecFlashcards.begin(), m_StatsInfo.m_vecFlashcards.end());

		for (auto flashcard : flashcards) 
		{
			file << flashcard->GetIsMemorized() << " " << static_cast<int>(flashcard->GetOriginalLang()) << " "
				<< static_cast<int>(flashcard->GetTranslatedLang()) << " "
				<< flashcard->GetOriginalText() << " "
				<< flashcard->GetTranslatedText() << "\n";
			
			if (!file) 
			{
				std::cout << "Error: while writting" << std::endl;
			}
		}

		file.close();
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Name			:	LoadFlashcardsFromDisk
	// Purpose		:	Load flashcards from disk
	// Returns		:	void - none
	void CStatsManager::LoadFlashcardsFromDisk()
	{
		std::ifstream file("../data/flashcards.txt");

		if (!file)
		{
			std::cout << "Error: opening file for reading" << std::endl;
			return;
		}

		bool isMemorized;
		int originalLang, translatedLang;
		std::string originalText, translatedText;
		while (!file.fail())
		{
			file >> isMemorized >> originalLang >>
				 translatedLang >> originalText >>
				translatedText;

			CFlashcard* flashcard = new CFlashcard(static_cast<eLanguage>(originalLang),
				static_cast<eLanguage>(translatedLang), originalText, translatedText);
			
			m_StatsInfo.m_vecFlashcards.push_back(flashcard);
		}

		file.close();
	}
} // namespace FLASHCARD