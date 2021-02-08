#include "Cue.h"
#include <iostream>

Cue::Cue(const Cue& cue)
	:_name{ cue.getName() },
	_sourcePath{ cue.getSourcePath() },
	_length{ cue.getLength() },
	_status{ Cue::Status::INACTIVE }
{
}

Cue::Cue(const QString& name, const QString& sourcePath, const QString& length)
	: _name{ name },
	_sourcePath{ sourcePath },
	_length{ length },
	_status{ Cue::Status::INACTIVE }
{

}

Cue::~Cue()
{
}

const QString& Cue::getName() const
{
	return _name;
}

const QString& Cue::getSourcePath() const
{
	return _sourcePath;
}

Cue::Status Cue::getStatus() const
{
	return _status;
}

const QString& Cue::getLength() const
{
	return _length;
}

bool Cue::setName(const QString& name)
{
	_name = name;
	return true;
}

bool Cue::setSourcePath(const QString& sourcePath)
{
	_sourcePath = sourcePath;
	return true;
}

bool Cue::setLength(const QString& length)
{
	_length = length;
	return true;
}

void Cue::play()
{
	std::cout << "o fuck\n";
	_status = Cue::Status::PAUSED;
}

void Cue::stop()
{
	_status = Cue::Status::INACTIVE;
}

void Cue::pause()
{
	_status = Cue::Status::PAUSED;
}

void Cue::setNext()
{
	_status = Cue::Status::NEXT;
}