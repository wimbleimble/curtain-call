#include "Cue.h"
#include <iostream>

Cue::Cue(const Cue& cue)
	:_name{ cue.getName() },
	_sourcePath{ cue.getSourcePath() },
	_length{ cue.getLength() },
	_status{ Cue::Status::INACTIVE },
	_next{}
{
}

Cue::Cue(const QString& name, const QString& sourcePath, const QString& length)
	: _name{ name },
	_sourcePath{ sourcePath },
	_length{ length },
	_status{ Cue::Status::INACTIVE },
	_next{}
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

bool Cue::next() const
{
	return _next;
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
	_status = Cue::Status::PLAYING;
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
	_next = true;
}
void Cue::unsetNext()
{
	_next = false;
}