#ifndef ENVIRONMENTDELEGATE_H
#define ENVIRONMENTDELEGATE_H

#include <QStyledItemDelegate>

class EnvironmentDelegate : public QStyledItemDelegate
{
	Q_OBJECT
public:
	explicit EnvironmentDelegate(QObject *parent = 0);
	virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	virtual void setEditorData(QWidget *editor, const QModelIndex &index) const;
	virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
signals:

public slots:

};

#endif // ENVIRONMENTDELEGATE_H
