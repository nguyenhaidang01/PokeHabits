#pragma once

#include <QObject>
#include <QList>
#include <QDate>

using QListDatePtr = std::shared_ptr<QList<std::shared_ptr<QDate>>>;

class CalendarList : public QObject
{
	Q_OBJECT
public:
	explicit CalendarList(QObject *parent = nullptr);
	explicit CalendarList(QListDatePtr list, QObject *parent = nullptr);

	QListDatePtr items() const;

	bool setDateItemAt(int index, std::shared_ptr<QDate> item);

signals:
	void preDateItemAppended();
	void postDateItemAppended();

	void preDateItemRemoved(int index);
	void postDateItemRemoved();

public slots:
	void appendDateItem(std::shared_ptr<QDate> item);

private:
	QListDatePtr m_list;
};
