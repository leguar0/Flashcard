//
//		author: @leguar
//		date: 21/11/24
//		purpose: 
//

#ifndef FLASHCARD_H
#define FLASHCARD_H

#include <string>
#include <iostream>

namespace flashcard
{
	enum class eLanguage { LANGUAGE_POLISH, LANGUAGE_ENGLISH, LANGUAGE_GERMAN, LANGUAGE_SPANISH };

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	class CFlashcard
	{
		eLanguage		m_nOriginalLang;
		eLanguage		m_nTranslatedLang;
		std::string		m_sOriginalText;
		std::string		m_sTranslatedText; 
		bool			m_bIsMemorized;
	public:
		CFlashcard(eLanguage originalLang, eLanguage translatedLang,
			std::string originalText, std::string translatedText, bool isMemorized = false);

		bool operator==(std::string word);

		eLanguage		GetOriginalLang() const;
		eLanguage		GetTranslatedLang() const;
		std::string		GetOriginalText() const;
		std::string		GetTranslatedText() const;
		bool			GetIsMemorized() const;

		void			SetIsMemorized(bool isMemorized);
	};
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, flashcard::CFlashcard& flashcard);

#endif // !FLASHCARD_H
