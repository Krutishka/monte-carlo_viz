#ifndef MAINWINDOW_CONTEXT_H
#define MAINWINDOW_CONTEXT_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QTimer>
#include "playbutton.h"
#include "renderarea_context.h"

#include "../monte_carlo_techs/src/contexts/readevent_context.h"
#include "../monte_carlo_techs/src/datas/area_data.h"

class MainWindowContext : public QWidget
{
    Q_OBJECT
public:
    MainWindowContext();
    ~MainWindowContext();
    
private slots:
    void doReaction();

    void playAnimation();
    void stopAnimation();

    void openFile();
    void openDirectory();
    void updateSideLength();

    void saveSnapShot();

private:
    void updateCell(CellType value, CoordType x, CoordType y);
    void updateStatusBar();


private:
    QString _snapShotsPath;//куда сохраняем картинки
    double _everySecond;//как часто сохраняем картинки
    double _secondsCounter;//счетчик секунд

    AreaData *_area;//переменная в которой хранятся данные о поверхности катализатора
    ReadEventContext *_readContext;// объект для чтения файлов событий
    RenderAreaContext *_renderArea;//рисует поверхность катализатора
    float _cellSideLength;//размер ячейки (маленького квадратика)

    QPushButton *_loadButton;
    QPushButton *_selectDirButton;
    QLabel *_selectDirLabel;
    QLabel *_sideLengthLabel;
    QTextEdit *_sideLengthText;

    QPushButton *_doButton;
    PlayButton *_playButton;
    QTimer *_animationTimer;

    double _totalTime;
    QLabel *_totalTimeTextLabel;
    QLabel *_totalTimeValueLabel;
    QLabel *_timeDimLabel;
};

#endif // MAINWINDOW_CONTEXT_H
