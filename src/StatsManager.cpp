#include "StatsManager.h"

namespace flashcard {
	CStatsManager::CStatsInfo CStatsManager::m_StatsInfo;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void CStatsManager::MarkAsMemorized(eLanguage originalLang, eLanguage translatedLang, std::string word)
	{
		auto itFlashcard = std::find_if(
			m_StatsInfo.vFlashcardsUnmemorized.begin(),
			m_StatsInfo.vFlashcardsUnmemorized.end(),
			[=](const CFlashcard& flashcard) {
				return flashcard.GetOriginalLang() == originalLang &&
					flashcard.GetTranslatedLang() == translatedLang &&
					flashcard.GetOriginalText() == word;
			});

		if (itFlashcard == m_StatsInfo.vFlashcardsUnmemorized.end())
		{
			FlashcardNotFoundException error;
			error.what = "Flashcard not found";
			throw error;
		}

		CFlashcard* flashcard = &(*itFlashcard);
		m_StatsInfo.vFlashcardsUnmemorized.erase(itFlashcard);
		m_StatsInfo.vFlashcardsMemorized.push_back(*flashcard);
	}

}