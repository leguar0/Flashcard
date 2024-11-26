#include "Flashcard.h"

namespace flashcard
{
	CFlashcard::CFlashcard(eLanguage originalLang, eLanguage translatedLang,
		std::string originalText, std::string translatedText)
		: m_nOriginalLang(originalLang), m_nTranslatedLang(translatedLang),
		m_sOriginalText(originalText), m_sTranslatedText(translatedText)
	{
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	bool CFlashcard::operator==(std::string word)
	{
		if (word == m_sTranslatedText)
			return true;

		return false;
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	eLanguage CFlashcard::GetOriginalLang() const
	{
		return m_nOriginalLang;
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	eLanguage CFlashcard::GetTranslatedLang() const
	{
		return m_nTranslatedLang;
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	std::string CFlashcard::GetOriginalText() const
	{
		return m_sOriginalText;
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	std::string CFlashcard::GetTranslatedText() const
	{
		return m_sTranslatedText;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, flashcard::CFlashcard& flashcard)
{
	os << "OriginalLang " << static_cast<int>(flashcard.GetOriginalLang())
		<< " TranslatedLang " << static_cast<int>(flashcard.GetTranslatedLang())
		<< " OriginalText " << flashcard.GetOriginalText()
		<< " TranslatedText " << flashcard.GetTranslatedText() << std::endl;
	return os;
}
