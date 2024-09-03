#include "DailyReportList.h"
#include "Pokemon.h"

DailyReportList::DailyReportList(QObject *parent)
	: QObject(parent)
    , m_list{std::make_shared<QList<std::shared_ptr<PokeHabit>>>()}
{
}

DailyReportList::DailyReportList(ListDailyReportPtr list, QObject *parent)
	: QObject(parent)
	, m_list{list}
{
}

ListDailyReportPtr DailyReportList::items() const
{
	return m_list;
}

bool DailyReportList::setDailyReporItemAt(int index, std::shared_ptr<PokeHabit> item)
{
	if (!m_list) {
		return false;
	}

	if (index < 0 || index >= m_list->size())
		return false;

	m_list->replace(index, item);
	return true;
}

void DailyReportList::appendDailyReportItem(std::shared_ptr<PokeHabit> item)
{
	if (!m_list) {
		return;
	}
	
    emit preDailyReportItemAppended();
	m_list->append(item);
    emit postDailyReportItemAppended();
}
