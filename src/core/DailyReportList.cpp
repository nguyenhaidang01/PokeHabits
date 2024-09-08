#include "DailyReportList.h"
#include "Pokemon.h"

DailyReportList::DailyReportList(QObject *parent)
	: QObject(parent)
	, m_Items{ std::make_shared<QList<DailyReportPtr>>() }
{
}

DailyReportList::DailyReportList(QVectorDailyReportPtr list, QObject *parent)
	: QObject(parent)
	, m_Items{ list }
{
}

QVectorDailyReportPtr DailyReportList::items() const
{
	return m_Items;
}

bool DailyReportList::setItemAt(int index, DailyReportPtr item)
{
	if (!m_Items) {
		return false;
	}

	if (index < 0 || index >= m_Items->size())
		return false;

	m_Items->replace(index, item);
	return true;
}

void DailyReportList::appendItem(DailyReportPtr item)
{
	if (!m_Items) {
		return;
	}

	emit preItemAppended();
	m_Items->append(item);
	emit postItemAppended();
}
