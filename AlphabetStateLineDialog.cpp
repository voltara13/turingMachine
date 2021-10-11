#include "AlphabetStateLineDialog.h"

AlphabetStateLineDialog::AlphabetStateLineDialog(TuringMachine* turingMachinePtr, QWidget* parent) :
QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
	//Добавляем главную разметку
	qVBoxLayoutMain = new QVBoxLayout(this);
	//Добавляем выпадающий список заменяющих символов
	qHBoxLayoutComboBoxLetter->addWidget(new QLabel("Заменить на:"));
	qHBoxLayoutComboBoxLetter->addWidget(qComboBoxLetter);
	qVBoxLayoutMain->addLayout(qHBoxLayoutComboBoxLetter);
	//Добавляем выпадающий список направления головки
	qHBoxLayoutComboBoxDirection->addWidget(new QLabel("Головка:"));
	qHBoxLayoutComboBoxDirection->addWidget(qComboBoxDirection);
	qVBoxLayoutMain->addLayout(qHBoxLayoutComboBoxDirection);
	//Добавляем выпадающий список заменяющего состояния
	qHBoxLayoutComboBoxState->addWidget(new QLabel("К состоянию:"));
	qHBoxLayoutComboBoxState->addWidget(qComboBoxState);
	qVBoxLayoutMain->addLayout(qHBoxLayoutComboBoxState);
	//Добавляем кнопки результата диалогового окна
	qHBoxLayoutButton->addWidget(qPushButtonOK);
	qHBoxLayoutButton->addWidget(qPushButtonCancel);
	qVBoxLayoutMain->addLayout(qHBoxLayoutButton);
	//Добавляем значения в выпдающий список заменяющих символов
	for (auto& letter : turingMachinePtr->getAlphabet())
		qComboBoxLetter->addItem(letter);
	//Добавляем значения в выпадающий список направления головки
	qComboBoxDirection->addItem("Влево");
	qComboBoxDirection->addItem("Вправо");
	qComboBoxDirection->addItem("Не изменять");
	//Добавляем значения в выпадающий список заменяющего состояния
	for (int i = 0; i < turingMachinePtr->getStateCount(); ++i)
		qComboBoxState->addItem(tr("Q%1").arg(i + 1));
	//Соединяем сигналы кнопок со слотами результата диалогового окна
	connect(qPushButtonOK, &QPushButton::clicked, this, &QDialog::accept);
	connect(qPushButtonCancel, &QPushButton::clicked, this, &QDialog::reject);
	//Меняем параметры окна
	resize(200, 100);
	setWindowTitle("Изменение строки");
}
//Метод получения объекта строки в таблице алфавит-значение
AlphabetStateLine AlphabetStateLineDialog::getAlphabetStateLine() const
{
	return AlphabetStateLine(
			qComboBoxLetter->currentText().at(0),
			static_cast<Direction>(qComboBoxDirection->currentIndex()),
			qComboBoxState->currentIndex(),
			true);
}
