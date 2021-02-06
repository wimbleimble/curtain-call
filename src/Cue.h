#ifndef CUE_H
#define CUE_H
#include <QString>

class Cue
{
	private:
		QString name;
		QString sourcePath;
		QString length;
	
	public:

		enum class Col 
		{
			STATUS,
			NAME,
			SOURCE,
			LENGTH,
			NUM_COL
		};

		enum class Status
		{
			INACTIVE,
			PLAYING,
			STOPPED,
			NUM_STATUSES
		};

		Cue();
		Cue(const QString& name);
		~Cue();
		
		const QString& getName() const;
		Status status() const;
		const QString& getSourcePath() const;
		const QString& getLength() const;

};

#endif