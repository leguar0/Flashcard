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
	struct FlashcardNotFoundException
	{
	};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	class StatsInterface
	{
		struct CStatsInfo
		{
			uint32_t				m_uiPoints = 0;
			uint32_t				m_uiPointsToday = 0;
			int16_t					m_iFlashcardsToday = 0;

			std::vector<CFlashcard>	vFlashcardsMemorized;
			std::vector<CFlashcard>	vFlashcardsUnmemorized;
		};

		static CStatsInfo		m_StatsInfo;
	public:
		static void AddPoints(int iPoints) 
		{
			m_StatsInfo.m_uiPoints += iPoints;
		}

		static size_t GetCountFlashcardsMemorized()
		{
			return m_StatsInfo.vFlashcardsMemorized.size();
		}

		static size_t GetCountFlashcardsUnmemorized()
		{
			return m_StatsInfo.vFlashcardsUnmemorized.size();
		}

		static size_t GetCountFlashcards()
		{
			return GetCountFlashcardsMemorized() + GetCountFlashcardsUnmemorized();
		}

		static void AddNewFlashcard(const CFlashcard* flashcard)
		{
			m_StatsInfo.vFlashcardsUnmemorized.push_back(*flashcard);
		}

		static void MarkAsMemorized(eLanguage originalLang, eLanguage translatedLang, std::string word);
	};
}

#endif // !STATSINFO_H
