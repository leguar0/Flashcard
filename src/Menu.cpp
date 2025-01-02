#include "Menu.h"

CMenu::CMenu(QObject* parent, CSettings* settings, int index)
	: QObject(parent), m_Settings(settings), m_ActualFlashcard(nullptr), m_nIndexFlashcard(index)
{
	flashcard::CStatsManager::LoadFlashcardsFromDisk();

	m_ActualFlashcard = flashcard::CStatsManager::GetFlashcard(m_nIndexFlashcard);
}

CMenu::~CMenu()
{
	if (m_Settings) delete m_Settings;
	if (m_ActualFlashcard) delete m_ActualFlashcard;

	flashcard::CStatsManager::SaveFlashcardsToDisk();
}

void CMenu::ChangeTheme()
{
	if (m_Settings->GetThemeMode() == eThemeMode::THEME_MODE_DARK)
	{
		m_Settings->SetThemeMode(eThemeMode::THEME_MODE_LIGHT);
	}
	else
	{
		m_Settings->SetThemeMode(eThemeMode::THEME_MODE_DARK);
	}
}

void CMenu::AddNewFlashcard()
{
	std::cout << "TEST" << std::endl;
}


void CMenu::DisplayHint()
{
	std::cout << "TEST" << std::endl;
}
