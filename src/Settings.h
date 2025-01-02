//
//		author: @leguar
//		date: 30/11/24
//		purpose: 
//

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

enum eThemeMode
{
	THEME_MODE_LIGHT, THEME_MODE_DARK
};

class CSettings : public QObject
{
	Q_OBJECT

	eThemeMode m_ThemeMode;

public:

	eThemeMode GetThemeMode() const;

	void SetThemeMode(eThemeMode themeMode);
};


#endif // !SETTINGS_H
