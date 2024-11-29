#include <iostream>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "StatsInfo.h"
#include "FlashHandler.h"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);
	
	QQmlApplicationEngine engine;
	const QUrl url(QStringLiteral("qrc:/qml/main.qml"));

	QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
		&app, [url](QObject* obj, const QUrl& objUrl) {
			if (!obj && url == objUrl)
				QCoreApplication::exit(-1);
		}, Qt::QueuedConnection);

	engine.load(url);

	return app.exec();


/*
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

	std::vector<flashcard::CFlashcard> vFlashcards;
	bool isLoad = CFlashHandler::loadFlashcards("../data/flashcards.txt", vFlashcards);

	if (isLoad)
	{
		for (auto flashcard : vFlashcards)
		{
			std::cout << flashcard << std::endl;
		}

		CFlashHandler::saveFlashcards("../data/flashcards.txt", vFlashcards);
	}

#endif // _DEBUG
*/
}