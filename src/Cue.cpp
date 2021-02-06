#include "Cue.h"

Cue::Cue(const Cue& cue)
	:_name{ cue.getName() },
	_sourcePath{ cue.getSourcePath() },
	_length{ cue.getLength() }
{
}

Cue::Cue(const QString& name, const QString& sourcePath, const QString& length)
	: _name{ name },
	_sourcePath{ sourcePath },
	_length{ length }
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

Cue::Status Cue::status() const
{
	return Cue::Status::PLAYING;
}

const QString& Cue::getLength() const
{
	return _length;
}

void Cue::setName(const QString& name)
{
	_name = name;
}

void Cue::setSourcePath(const QString& sourcePath)
{
	_sourcePath = sourcePath;
}

void Cue::setLength(const QString& length)
{
	_length = length;
}