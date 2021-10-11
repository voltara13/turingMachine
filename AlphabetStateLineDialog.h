#ifndef TURINGMACHINE_ALPHABETSTATELINEDIALOG_H
#define TURINGMACHINE_ALPHABETSTATELINEDIALOG_H

#include <QDialog>
#include <QBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>

#include "TuringMachine.h"

//Класс диалогового окна создания строки в таблице алфавит-значение
class AlphabetStateLineDialog : public QDialog
{
	Q_OBJECT
private:
	//Объявляем разметку
	QVBoxLayout* qVBoxLayoutMain = nullptr;
	QHBoxLayout* qHBoxLayoutComboBoxLetter = new QHBoxLayout;
	QHBoxLayout* qHBoxLayoutComboBoxDirection = new QHBoxLayout;
	QHBoxLayout* qHBoxLayoutComboBoxState = new QHBoxLayout;
	QHBoxLayout* qHBoxLayoutButton = new QHBoxLayout;
	//Объявляем выпадающие списки
	QComboBox* qComboBoxLetter = new QComboBox;
	QComboBox* qComboBoxDirection = new QComboBox;
	QComboBox* qComboBoxState = new QComboBox;
	//Объявляем кнопки результата диалогового окна
	QPushButton* qPushButtonOK = new QPushButton("ОК");
	QPushButton* qPushButtonCancel = new QPushButton("Отмена");

public:
	explicit AlphabetStateLineDialog(TuringMachine* turingMachinePtr, QWidget* parent = nullptr);

	[[nodiscard]] AlphabetStateLine getAlphabetStateLine() const;
};


#endif //TURINGMACHINE_ALPHABETSTATELINEDIALOG_H
