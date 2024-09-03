#pragma once

#include <QAbstractListModel>

Q_MOC_INCLUDE("DailyReportList.h")

class DailyReportList;

class DailyReportModel : public QAbstractListModel
{
	Q_OBJECT
	Q_PROPERTY(int count READ count NOTIFY countChanged FINAL)

public:
	explicit DailyReportModel(QObject *parent = nullptr);
	explicit DailyReportModel(std::shared_ptr<DailyReportList> dailyReportList, QObject *parent = nullptr);

	enum {
		HabitNameRole = Qt::UserRole,
		ImageRole,
		ExpRole,
		DoneRole
	};

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
	Qt::ItemFlags flags(const QModelIndex& index) const override;

	virtual QHash<int, QByteArray> roleNames() const override;

	std::shared_ptr<DailyReportList> dailyReportList() const;
	void setDailyReportList(std::shared_ptr<DailyReportList> list);

	int count();

signals:
	void countChanged();

private:
	std::shared_ptr<DailyReportList> m_dailyReportList;
};
