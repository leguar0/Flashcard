#include "Settings.h"

eThemeMode CSettings::GetThemeMode() const
{
	return m_ThemeMode;
}

void CSettings::SetThemeMode(eThemeMode themeMode)
{
	m_ThemeMode = themeMode;
}
