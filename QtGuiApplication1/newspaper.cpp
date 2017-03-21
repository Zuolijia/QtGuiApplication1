#include "newspaper.h"
Newspaper::Newspaper(const QString & name) :m_name(name)
{

}

void Newspaper::send()
{
	emit newPaper(m_name);
}