#include "CueList.h"
#include <iostream>

CueList::CueList()
	: _cursor{ -1 }
{
}

CueList::~CueList()
{
}

int CueList::rowCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);
	return parent.isValid() ? 0 : _list.size();
}


int CueList::columnCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);
	return parent.isValid() ? 0 : static_cast<int>(Cue::Col::NUM_COL);
}

QVariant CueList::data(const QModelIndex& index, int role) const
{
	if (!index.isValid() || role != Qt::DisplayRole)
		return QVariant();

	const Cue::Col row{ static_cast<Cue::Col>(index.column()) };
	const Cue& cue{ _list[index.row()] };

	switch (row)
	{
	case Cue::Col::STATUS:
	{
		if (cue.next())
			return ">";
		const Cue::Status status{ cue.getStatus() };
		switch (status)
		{
		case Cue::Status::INACTIVE:
			return "";
		case Cue::Status::PLAYING:
			return "💚";
		case Cue::Status::PAUSED:
			return "❤️";
		default:
			return "you dumb little shit";
		}
	}
	case Cue::Col::NAME:
		return cue.getName();
	case Cue::Col::SOURCE:
		return cue.getSourcePath();
	case Cue::Col::LENGTH:
		return cue.getLength();
	default:
		return "wuh oh error";
	}
}

QVariant CueList::headerData(int col, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
		return HEADERS[col];

	return QVariant();
}


Qt::ItemFlags CueList::flags(const QModelIndex& index) const
{
	Qt::ItemFlags ret{ Qt::ItemIsEnabled | Qt::ItemIsSelectable };
	if (index.column() != 0)
		ret = ret | Qt::ItemIsEditable;
	return ret;
}

bool CueList::setData(const QModelIndex& index, const QVariant& value, int role)
{
	Cue& cue{ _list[index.row()] };
	Cue::Col col{ static_cast<Cue::Col>(index.column()) };
	switch (col)
	{
	case Cue::Col::NAME:
		return cue.setName(value.toString());
	case Cue::Col::SOURCE:
		return cue.setSourcePath(value.toString());
	case Cue::Col::LENGTH:
		return cue.setLength(value.toString());
	default:
		return false;
	}
	dataChanged(index, index, QVector<int>{ role });
}


bool CueList::insertRows(int row, int count, const QModelIndex& parent)
{
	if (row > rowCount() || row < 0)
		return false;
	
	std::vector<Cue>::iterator it{ _list.begin() + row};
	beginInsertRows(parent, row, row + count - 1);
	_list.insert(it, count, Cue{});
	endInsertRows();

	if (_cursor == -1)
		setCursor(0);

	return true;
}

bool CueList::removeRows(int row, int count, const QModelIndex& parent)
{
	if (row > rowCount() || row < 0)
		return false;

	std::vector<Cue>::iterator it{ _list.begin() + row };

	beginRemoveRows(parent, row, row + count - 1);
	_list.erase(it, it + count);
	endRemoveRows();

	return true;
}

void CueList::go()
{
	if (_cursor == -1)
		return;
	_list[_cursor].play();
	if (_cursor == rowCount() - 1)
		setCursor(0);
	else
		setCursor(_cursor + 1);

}

void CueList::panic()
{
	for (Cue& cue : _list)
		cue.stop();
	refreshStatus();
}

void CueList::setCursor(int cursor)
{
	if(_cursor != -1)
		_list[_cursor].unsetNext();
	_list[cursor].setNext();
	_cursor = cursor;
	std::cout << "New Cursor: " << _list[cursor].getName().toStdString() << '\n';
	refreshStatus();
}

void CueList::refreshStatus()
{
	dataChanged(createIndex(0, 0),
		createIndex(0, rowCount() - 1),
		QVector<int>(Qt::DisplayRole));
}