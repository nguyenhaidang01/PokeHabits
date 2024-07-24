#include "CalendarList.h"

CalendarList::CalendarList(QObject *parent)
    : QObject(parent)
    , m_list{std::make_shared<QList<std::shared_ptr<QDate>>>()}
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
    if (!m_list) {
        return false;
    }

	if (index < 0 || index >= m_list->size())
		return false;

	m_list->replace(index, item);
	return true;
}

void CalendarList::appendDateItem(std::shared_ptr<QDate> item)
{
    if (!m_list) {
        return;
    }

	emit preDateItemAppended();
	m_list->append(item);
	emit postDateItemAppended();
}
