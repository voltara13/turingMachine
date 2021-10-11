#ifndef TURINGMACHINE_TAPELETTERDIALOG_H
#define TURINGMACHINE_TAPELETTERDIALOG_H

#include <QDialog>
#include <QBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>

#include "TuringMachine.h"

//Класс диалогового окна добавления символа в ленту
class TapeLetterDialog : public QDialog
{
	Q_OBJECT
private:
	//Объявляем разметку
	QVBoxLayout* qVBoxLayoutMain = nullptr;
	QHBoxLayout* qHBoxLayoutComboBox = new QHBoxLayout;
	QHBoxLayout* qHBoxLayoutButton = new QHBoxLayout;
	//Объявляем выпадающий список
	QComboBox* qComboBox = new QComboBox;
	//Объявляем кнопки результата диалогового окна
	QPushButton* qPushButtonOK = new QPushButton("ОК");
	QPushButton* qPushButtonCancel = new QPushButton("Отмена");

public:
	explicit TapeLetterDialog(TuringMachine* turingMachinePtr, QWidget* parent = nullptr);

	[[nodiscard]] QChar getTapeLetter() const;
};


#endif //TURINGMACHINE_TAPELETTERDIALOG_H
