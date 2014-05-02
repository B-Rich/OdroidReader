#include "datapoint.h"
#include <QtEndian>

DatapointBase::DatapointBase(QByteArray ba)
{
	min_item = new QTableWidgetItem("undef");
	min_item->setBackgroundColor(Qt::yellow);
	last_item = new QTableWidgetItem(*min_item);
	max_item = new QTableWidgetItem(*min_item);
	avg_item = new QTableWidgetItem(*min_item);

	//Initialize from bytearray
	uint8_t name_len = static_cast<quint8>(ba.left(1).constData()[0]);
	ba.remove(0,1);
	_type = static_cast<FIELD_TYPE>(ba.left(1).constData()[0]);
	ba.remove(0,1);
	_factor = qFromBigEndian<quint32>(reinterpret_cast<const uchar*>(ba.left(4).constData()));
	ba.remove(0,4);
	_name = QString(ba.left(name_len).constData());
	ba.remove(0,name_len);
	_unit = QString(ba.constData());
	initialized = false;

	unit_item = new QTableWidgetItem(_unit);
	unit_item->setBackgroundColor(Qt::yellow);
	name_item = new QTableWidgetItem(_name);
	name_item->setBackgroundColor(Qt::yellow);
}

DatapointBase::DatapointBase(const DatapointBase &src) {
	_type = src._type;
	_factor = src._factor;
	_name = src._name;
	_unit = src._unit;
	unit_item = new QTableWidgetItem(*src.unit_item);
	name_item = new QTableWidgetItem(*src.name_item);
}

DatapointBase::~DatapointBase() {
	delete name_item;
	delete unit_item;
	delete min_item;
	delete max_item;
	delete avg_item;
	delete last_item;
}