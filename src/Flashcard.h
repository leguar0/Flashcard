#ifndef FLASHCARD_H
#define FLASHCARD_H

#include <string>

namespace flashcard
{
	enum class eLanguage { LANGUAGE_POLISH, LANGUAGE_ENGLISH, LANGUAGE_GERMAN, LANGUAGE_SPANISH };

	class CFlashcard
	{
		eLanguage m_nOriginalLang;
		eLanguage m_nTranslatedLang;
		std::string m_sOriginalText;
		std::string m_sTranslatedText;
	public:
		CFlashcard(eLanguage originalLang, eLanguage translatedLang,
			std::string originalText, std::string translatedText);

		bool operator==(std::string word);

		eLanguage GetOriginalLang() const;
		eLanguage GetTranslatedLang() const;
		std::string GetOriginalText() const;
		std::string GetTranslatedText() const;
	};
}


#endif // !FLASHCARD_H
