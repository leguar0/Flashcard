//
//		author: @leguar
//		date: 19/11/24
//		purpose: A place to storage information about the user's progress
//

#ifndef STATSINFO_H
#define STATSINFO_H

#include <vector>
#include <algorithm>
#include <cstdint>

#include "Flashcard.h"

namespace flashcard
{
	struct FlashcardNotFoundException final
	{
		const char*		what;
	};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	class CStatsManager
	{
		struct CStatsInfo
		{
			uint32_t					m_uiPoints = 0;
			uint32_t					m_uiPointsToday = 0;
			int16_t						m_iFlashcardsToday = 0;

			std::vector<CFlashcard*>	m_vecFlashcards;
		} m_StatsInfo;

		CStatsManager();
	public:
		void AddPoints(int iPoints) 
		{
			m_StatsInfo.m_uiPoints += iPoints;
		}

		size_t GetCountFlashcards()
		{
			return m_StatsInfo.m_vecFlashcards.size();
		}

		void AddNewFlashcard(CFlashcard* flashcard)
		{
			m_StatsInfo.m_vecFlashcards.push_back(flashcard);
		}

		CFlashcard* GetFlashcard(int index)
		{
			return m_StatsInfo.m_vecFlashcards[index];
		}

		void MarkAsMemorized(eLanguage originalLang, eLanguage translatedLang, std::string word);

		void SaveFlashcardsToDisk();

		void LoadFlashcardsFromDisk();
	};
} // namespace FLASHCARD

#endif // !STATSINFO_H
