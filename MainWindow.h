#ifndef TURINGMACHINE_MAINWINDOW_H
#define TURINGMACHINE_MAINWINDOW_H

#include <QWidget>
#include <QBoxLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QTableWidget>
#include <QPushButton>
#include <QShortcut>
#include <QThread>
#include <QLabel>
#include <QHeaderView>
#include <QMessageBox>

#include "TuringMachine.h"
#include "ValidatorAlphabet.h"
#include "TapeLetterDialog.h"
#include "AlphabetStateLineDialog.h"

//Класс главного окна
class MainWindow : public QWidget
{
	Q_OBJECT
private:
	//Объявляем разметку
	QVBoxLayout* qVBoxLayoutMain = nullptr;
	QHBoxLayout* qHBoxLayoutAlphabetStateLine = new QHBoxLayout;
	QHBoxLayout* qHBoxLayoutButtonWork = new QHBoxLayout;
	QHBoxLayout* qHBoxLayoutButtonState = new QHBoxLayout;
	//Объявляем виджеты
	QLineEdit* qLineEditAlphabet = new QLineEdit("01");
	QSpinBox* qSpinBoxState = new QSpinBox;
	QTableWidget* qTableWidgetTape = new QTableWidget(1, SIZE_TAPE);
	QTableWidget* qTableWidgetAlphabetState = new QTableWidget;
	QPushButton* qPushButtonAddState = new QPushButton("Добавить состояние");
	QPushButton* qPushButtonDeleteState = new QPushButton("Удалить состояние");
	QPushButton* qPushButtonStart = new QPushButton("Начать");
	QPushButton* qPushButtonStep = new QPushButton("Шаг");
	QPushButton* qPushButtonStop = new QPushButton("Стоп");
	//Объявляем горячие клавиши
	QShortcut* keyF1 = nullptr;
	QShortcut* keyA = nullptr;
	QShortcut* keyD = nullptr;
	QShortcut* keyS = nullptr;
	QShortcut* keySpace = nullptr;
	QShortcut* keyF = nullptr;
	QShortcut* esc = nullptr;
	//Объявляем объект машины Тьюринга
	TuringMachine* turingMachine = nullptr;
	//Объявляем поток машины Тьюринга
	QThread* turingMachineThread = nullptr;

	void initTape();
	void initAlphabetState();
	void initSpinBox();

	void startThreadTuringMachine();
	void stopThreadTuringMachine();

public:
	explicit MainWindow(QWidget* parent = nullptr);

private slots:
	void changeTapeItemSlot(const QChar& letter);
	void changeAlphabetStateCountSlot();
	void changeAlphabetStateItemSlot(const AlphabetStateLine& alphabetStateLine);
	void changeCurrentIndexTapeSlot(const int& index);
	void changeCurrentStateSlot(const int& newState);
	void changeGUIModelingSlot(const bool& isStart);

	void clickButtonStartSlot();
	void clickButtonStepSlot();
	void clickButtonStopSlot();
	void clickButtonChangeCountStateSlot(const bool& isAdd);

	void doubleClickTapeSlot();
	void doubleClickAlphabetStateSlot();

	void endTapeSlot();
	void endWorkSlot();

	void helpSlot();

	static void exitSlot();
};

#endif //TURINGMACHINE_MAINWINDOW_H
