#ifndef SAVE_H
#define SAVE_H

#include <QtWidgets>

class Save : public QDialog
{
	Q_OBJECT
	friend class GLWidget;
public:
	explicit Save(QWidget *parent = 0);
	~Save();

signals:
	void startRender(void);

protected:
	void hideEvent(QHideEvent *e);
	void closeEvent(QCloseEvent *e);

private slots:
	void reset();
	void updateRes();
	void render();
	void save();
	void done();
	void failed(const QString str);

private:
	QSize finalRes();

	enum Dim {X = 0, Y = 1};
	QTime tStart;
	QImage *img;
	QSpinBox *spBlockSize[2], *spBlockCount[2];
	QLabel *lFinalRes, *lOutput;
	QListWidget *lwProgess;
	//QVector<QVector<QLabel *> > lOutputArray;
	//QVector<QVector<QImage> > lOutputArray;
};

#endif // SAVE_H
