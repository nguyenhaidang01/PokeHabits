#include "DailyReportList.h"
#include "Pokemon.h"

DailyReportList::DailyReportList(QObject *parent)
	: QObject(parent)
	, m_Items{ std::make_shared<QVector<DailyReportPtr>>() }
{
}

DailyReportList::DailyReportList(QVector<PokeHabit> items, QObject *parent)
	: QObject(parent)
	, m_Items{ std::make_shared<QVector<DailyReportPtr>>() }
{
	for (auto item : items) {
		m_Items->push_back(std::make_shared<PokeHabit>(item));
	}
}

DailyReportList::DailyReportList(QVectorDailyReportPtr items, QObject *parent)
	: QObject(parent)
	, m_Items{ items }
{
}

QVectorDailyReportPtr DailyReportList::items() const
{
	return m_Items;
}

QVector<PokeHabit> DailyReportList::itemsClone()
{
	QVector<PokeHabit> itemsClone;
	for (auto &item : *m_Items) {
		itemsClone.push_back(*item);
	}

	return itemsClone;
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

void DailyReportList::setUndoneAllItems()
{
	for (auto &item : *m_Items) {
		if (item->done) {
			item->done = false;
		}
	}
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
