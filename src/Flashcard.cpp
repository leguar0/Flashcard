#include "Flashcard.h"

namespace flashcard
{
	CFlashcard::CFlashcard(eLanguage originalLang, eLanguage translatedLang,
		std::string originalText, std::string translatedText, bool isMemorized)
		: m_nOriginalLang(originalLang),
		  m_nTranslatedLang(translatedLang),
		  m_stOriginalText(originalText),
		  m_stTranslatedText(translatedText),
		  m_bIsMemorized(isMemorized)
	{
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	bool CFlashcard::operator==(std::string word)
	{
		if (word == m_stTranslatedText)
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
		return m_stOriginalText;
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	std::string CFlashcard::GetTranslatedText() const
	{
		return m_stTranslatedText;
	}
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	bool CFlashcard::GetIsMemorized() const
	{
		return m_bIsMemorized;
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void CFlashcard::SetIsMemorized(bool isMemorized)
	{
		m_bIsMemorized = isMemorized;
	}
} // namespace FLASHCARD

std::ostream& operator<<(std::ostream& os, flashcard::CFlashcard& flashcard)
{
	os << "OriginalLang " << static_cast<int>(flashcard.GetOriginalLang())
		<< " TranslatedLang " << static_cast<int>(flashcard.GetTranslatedLang())
		<< " OriginalText " << flashcard.GetOriginalText()
		<< " TranslatedText " << flashcard.GetTranslatedText() << std::endl;
	return os;
}
