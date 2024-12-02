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
		static struct CStatsInfo
		{
			uint32_t					m_uiPoints = 0;
			uint32_t					m_uiPointsToday = 0;
			int16_t						m_iFlashcardsToday = 0;

			std::vector<CFlashcard*>	vFlashcards;
		} m_StatsInfo;

		CStatsManager();
	public:
		static void AddPoints(int iPoints) 
		{
			m_StatsInfo.m_uiPoints += iPoints;
		}

		static size_t GetCountFlashcards()
		{
			return m_StatsInfo.vFlashcards.size();
		}

		static void AddNewFlashcard(CFlashcard* flashcard)
		{
			m_StatsInfo.vFlashcards.push_back(flashcard);
		}

		static CFlashcard* GetFlashcard(int index)
		{
			return m_StatsInfo.vFlashcards[index];
		}

		static void MarkAsMemorized(eLanguage originalLang, eLanguage translatedLang, std::string word);

		static void SaveFlashcardsToDisk();

		static void LoadFlashcardsFromDisk();
	};
}

#endif // !STATSINFO_H
