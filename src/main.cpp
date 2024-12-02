#include <iostream>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Menu.h"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);
	
	QQmlApplicationEngine engine;

	CSettings settings;
	CMenu menu(nullptr, &settings);

	engine.rootContext()->setContextProperty("menuObject", &menu);

	engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();

#ifdef _DEBUG
	//flashcard::CFlashcard flashc(
	//	flashcard::eLanguage::LANGUAGE_ENGLISH,
	//	flashcard::eLanguage::LANGUAGE_POLISH,
	//	"dog",
	//	"pies");

	//flashcard::StatsInterface::AddNewFlashcard(flashc);

	//flashcard::StatsInterface::MarkAsMemorized(
	//	flashcard::eLanguage::LANGUAGE_ENGLISH,
	//	flashcard::eLanguage::LANGUAGE_POLISH,
	//	"dog"
	//);

	//try
	//{
	//	flashcard::StatsInterface::MarkAsMemorized(
	//		flashcard::eLanguage::LANGUAGE_ENGLISH,
	//		flashcard::eLanguage::LANGUAGE_POLISH,
	//		"cat"
	//	);
	//} 
	//catch (flashcard::FlashcardNotFoundException flashcardNotFoundEx)
	//{
	//	std::cout << "Exception: " << flashcardNotFoundEx.what << std::endl;
	//}

	//std::cout <<
	//	flashcard::StatsInterface::GetCountFlashcardsUnmemorized()
	//	<< std::endl;

	//std::cout <<
	//	flashcard::StatsInterface::GetCountFlashcards()
	//	<< std::endl;
#endif // _DEBUG
}