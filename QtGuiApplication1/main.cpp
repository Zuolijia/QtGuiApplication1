#include <QApplication>
#include <QDebug>
#include <QCoreApplication>

#include "newspaper.h"
#include "reader.h"

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	/*QtGuiApplication1 w;
	w.show();*/

	/*QPushButton button("Quit");
	QObject::connect(&button, &QPushButton::clicked, [](bool) {
		qDebug() << "You clicked me!"; 
		QApplication::quit(); });
	button.show();*/

	Newspaper newspaper("Newspaper A");
	Reader reader;
	QObject::connect(&newspaper, &Newspaper::newPaper, &reader, &Reader::receiveNewspaper);
	newspaper.send();
	
	return app.exec();
}
