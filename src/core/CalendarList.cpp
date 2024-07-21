#include "CalendarList.h"

CalendarList::CalendarList(QObject *parent)
    : QObject(parent)
    , m_list{nullptr}
{
}

CalendarList::CalendarList(QList<QDate*> *list, QObject *parent)
    : QObject(parent)
    , m_list{list}
{
}

QList<QDate*>* CalendarList::items() const
{
	return m_list;
}

bool CalendarList::setDateItemAt(int index, QDate* item)
{
	if (index < 0 || index >= m_list->size())
		return false;

	m_list->replace(index, item);
	return true;
}

void CalendarList::appendDateItem(QDate *item)
{
	emit preDateItemAppended();
	m_list->append(item);
	emit postDateItemAppended();
}
