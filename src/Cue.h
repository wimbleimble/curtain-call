#ifndef CUE_H
#define CUE_H
#include <QString>

class Cue
{
	private:
		QString _name;
		QString _sourcePath;
		QString _length;
	
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

		Cue() = delete;
		Cue(const Cue& cue);
		Cue(const QString& name, const QString& sourcePath = "", const QString& length = "0:00");
		~Cue();
		
		const QString& getName() const;
		Status status() const;
		const QString& getSourcePath() const;
		const QString& getLength() const;

		void setName(const QString& name);
		void setSourcePath(const QString& sourcePath);
		void setLength(const QString& length);

};

#endif