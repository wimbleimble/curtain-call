#ifndef CUE_H
#define CUE_H
#include <QString>

class Cue
{
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
			PAUSED,
			NUM_STATUSES
		};

	private:
		QString _name;
		QString _sourcePath;
		QString _length;
		Status _status;
		bool _next;
	
	public:

		Cue(const Cue& cue);
		Cue(const QString& name = "Untitled", const QString& sourcePath = "", const QString& length = "0:00");
		~Cue();
		
		const QString& getName() const;
		Status getStatus() const;
		const QString& getSourcePath() const;
		const QString& getLength() const;
		bool next() const;

		bool setName(const QString& name);
		bool setSourcePath(const QString& sourcePath);
		bool setLength(const QString& length);

		void play();
		void stop();
		void pause();
		void setNext();
		void unsetNext();

};

#endif