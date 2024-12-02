//
//		author: @leguar
//		date: 30/11/24
//		purpose: 
//

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class CSettings : public QObject
{
	Q_OBJECT

	enum eThemeMode
	{
		THEME_MODE_LIGHT, THEME_MODE_DARK
	} m_ThemeMode;

public:

	void SetThemeMode(eThemeMode themeMode);
};


#endif // !SETTINGS_H
