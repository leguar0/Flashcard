//
//		author: @leguar
//		date: 21/11/24
//		purpose: flashcard class
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
		eLanguage		m_nOriginalLang; //the original language of the word
		eLanguage		m_nTranslatedLang; //the translated language of the word
		std::string		m_stOriginalText; //the original text of the word
		std::string		m_stTranslatedText; //the translated text of the word
		bool			m_bIsMemorized; //whether it is know
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
} // namespace FLASHCARD

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, flashcard::CFlashcard& flashcard);

#endif // !FLASHCARD_H
