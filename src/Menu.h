//
//		author: @leguar
//		date: 19/11/24
//		purpose: 
//

#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QQmlContext>

#include "Flashcard.h"
#include "Settings.h"
#include "StatsManager.h"

class CMenu : public QObject
{
	Q_OBJECT

	CSettings*					m_Settings;
	int							m_nIndexFlashcard;
	flashcard::CFlashcard*		m_ActualFlashcard;
public:
	CMenu(QObject* parent = nullptr, CSettings* settings = nullptr, int index = 0);
	~CMenu();
public slots:
	//
	// 
	// 
	// 
	//
	//void ChangeTheme();
	//void AddNewFlashcard();

	void DisplayHint();

};

#endif // !USER_H