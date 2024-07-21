#pragma once

#include <QObject>
#include <QList>
#include <QDate>

class CalendarList : public QObject
{
	Q_OBJECT
public:
	explicit CalendarList(QObject *parent = nullptr);
	explicit CalendarList(QList<QDate*> *list, QObject *parent = nullptr);

	QList<QDate*>* items() const;

	bool setDateItemAt(int index, QDate *item);

signals:
	void preDateItemAppended();
	void postDateItemAppended();

	void preDateItemRemoved(int index);
	void postDateItemRemoved();

public slots:
	void appendDateItem(QDate *item);

private:
	QList<QDate*> *m_list;
};
