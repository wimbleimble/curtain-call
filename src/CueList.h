#include <QAbstractTableModel>
#include "Cue.h"
#include <vector>

class CueList : public QAbstractTableModel
{
	Q_OBJECT

	private:
		std::vector<Cue> list{};
		//constexpr static char HEADERS [static_cast<int>(Cue::Col::NUM_COL)] [8]
			//{"", "Name", "Source", "Length"};

		const std::vector<QString> HEADERS{ "", "Name", "Source", "Length" };

	public:
		CueList();
		~CueList();
	
		int rowCount(const QModelIndex& parent = QModelIndex()) const;
		int columnCount(const QModelIndex& parent = QModelIndex()) const;
		QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
		QVariant headerData(int col, Qt::Orientation orientation, int role) const;

		Qt::ItemFlags flags(const QModelIndex& index) const;
		bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);

		bool addCue(const Cue& Cue);
};