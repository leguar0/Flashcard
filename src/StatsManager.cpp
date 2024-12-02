#include "StatsManager.h"
#include <fstream>

namespace flashcard {
	CStatsManager::CStatsInfo CStatsManager::m_StatsInfo;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void CStatsManager::MarkAsMemorized(eLanguage originalLang, eLanguage translatedLang, std::string word)
	{
		auto itFlashcard = std::find_if(
			m_StatsInfo.vFlashcards.begin(),
			m_StatsInfo.vFlashcards.end(),
			[=](CFlashcard* flashcard) {
				return flashcard->GetOriginalLang() == originalLang &&
					flashcard->GetTranslatedLang() == translatedLang &&
					flashcard->GetOriginalText() == word;
			});

		if (itFlashcard == m_StatsInfo.vFlashcards.end())
		{
			FlashcardNotFoundException error;
			error.what = "Flashcard not found";
			throw error;
		}

		CFlashcard* flashcard = *itFlashcard;
		flashcard->SetIsMemorized(true);
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void CStatsManager::SaveFlashcardsToDisk()
	{
		std::ofstream file("../data/flashcards.txt");

		std::vector<CFlashcard*> flashcards(m_StatsInfo.vFlashcards.begin(), m_StatsInfo.vFlashcards.end());

		for (auto flashcard : flashcards) 
		{
			file << "1 " << static_cast<int>(flashcard->GetOriginalLang()) << " "
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
			
			if (isMemorized)
			{
				m_StatsInfo.vFlashcardsMemorized.push_back(flashcard);
			}
			else
			{
				m_StatsInfo.vFlashcardsUnmemorized.push_back(flashcard);
			}
		}

		file.close();
	}
}