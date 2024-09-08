#include "CalendarList.h"

CalendarList::CalendarList(QObject *parent)
	: QObject(parent)
	, m_Items{ std::make_shared<QList<QDate>>() }
{
}

CalendarList::CalendarList(QVectorDatePtr list, QObject *parent)
	: QObject(parent)
	, m_Items{ list }
{
}

QVectorDatePtr CalendarList::items() const
{
	return m_Items;
}

bool CalendarList::setItemAt(int index, QDate &item)
{
	if (!m_Items) {
		return false;
	}

	if (index < 0 || index >= m_Items->size())
		return false;

	m_Items->replace(index, item);
	return true;
}

void CalendarList::appendItem(QDate &item)
{
	if (!m_Items) {
		return;
	}

	emit preItemAppended();
	m_Items->append(item);
	emit postItemAppended();
}
