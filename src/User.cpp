#include "User.h"
#include "FlashHandler.h"

flashcard::CUser::CUser(StatsManager statsManager)
	: m_StatsManager(statsManager)
{
	CFlashHandler::loadUserStats("../data/userstats.txt", m_StatsManager);
}

flashcard::CUser::~CUser()
{
	CFlashHandler::saveUserStats("../data/userstats.txt", m_StatsManager);
}
