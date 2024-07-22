#include "CalendarList.h"

CalendarList::CalendarList(QObject *parent)
    : QObject(parent)
    , m_list{nullptr}
{
}

CalendarList::CalendarList(QListDatePtr list, QObject *parent)
    : QObject(parent)
    , m_list{list}
{
}

QListDatePtr CalendarList::items() const
{
	return m_list;
}

bool CalendarList::setDateItemAt(int index, std::shared_ptr<QDate> item)
{
	if (index < 0 || index >= m_list->size())
		return false;

	m_list->replace(index, item);
	return true;
}

void CalendarList::appendDateItem(std::shared_ptr<QDate> item)
{
	emit preDateItemAppended();
	m_list->append(item);
	emit postDateItemAppended();
}
