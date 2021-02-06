#include "Cue.h"

Cue::Cue(const QString& name)
	: name{ name },
	sourcePath{"fuck if i kno"},
	length{"huh?"}
{	
}

Cue::Cue()
{
}

Cue::~Cue()
{
}

const QString& Cue::getName() const
{
	return name;
}

const QString& Cue::getSourcePath() const
{
	return sourcePath;
}

Cue::Status Cue::status() const
{
	return Cue::Status::PLAYING;
}

const QString& Cue::getLength() const
{
	return length;
}