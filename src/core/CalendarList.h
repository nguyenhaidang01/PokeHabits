#pragma once

#include <QObject>
#include <QList>
#include <QDate>

using QVectorDatePtr = std::shared_ptr<QVector<QDate>>;

class CalendarList : public QObject
{
	Q_OBJECT
public:
	explicit CalendarList(QObject *parent = nullptr);
	explicit CalendarList(QVectorDatePtr list, QObject *parent = nullptr);

	QVectorDatePtr items() const;

	bool setItemAt(int index, QDate &item);

signals:
	void preItemAppended();
	void postItemAppended();

	void preItemRemoved(int index);
	void postItemRemoved();

public slots:
	void appendItem(QDate &item);

private:
	QVectorDatePtr m_Items;
};
