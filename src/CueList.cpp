#include "CueList.h"
#include <iostream>

CueList::CueList()
{
}

CueList::~CueList()
{
}

int CueList::rowCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);
	return list.size();
}


int CueList::columnCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);
	return static_cast<int>(Cue::Col::NUM_COL);
}

QVariant CueList::data(const QModelIndex& index, int role) const
{
	if (!index.isValid() || role != Qt::DisplayRole)
		return QVariant();

	const Cue::Col row{ static_cast<Cue::Col>(index.column()) };
	const Cue& cue{ list[index.row()] };

	switch (row)
	{
	case Cue::Col::STATUS:
	{
		const Cue::Status status{ cue.status() };
		switch (status)
		{
		case Cue::Status::INACTIVE:
			return "";
		case Cue::Status::PLAYING:
			return "💚";
		case Cue::Status::STOPPED:
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
	if (index.column() != 0)
		return Qt::ItemIsEditable | Qt::ItemIsSelectable | Qt::ItemIsEnabled;
	else
		return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

bool CueList::setData(const QModelIndex& index, const QVariant& value, int role)
{
	Cue& cue{ list[index.row()] };
	Cue::Col col{ static_cast<Cue::Col>(index.column()) };
	switch (col)
	{
	case Cue::Col::NAME:
		cue.setName(value.toString());
		return true;
	case Cue::Col::SOURCE:
		cue.setSourcePath(value.toString());
		return true;
	case Cue::Col::LENGTH:
		cue.setLength(value.toString());
		return true;
	default:
		return false;
	}
}

bool CueList::addCue(const Cue& cue)
{
	list.push_back(cue);
	return true;
}