#include "User.h"
#include "FlashHandler.h"

flashcard::CUser::CUser()
{
	CFlashHandler::loadUserStats("../data/userstats.txt");
}

flashcard::CUser::~CUser()
{
	CFlashHandler::saveUserStats("../data/userstats.txt");
}
