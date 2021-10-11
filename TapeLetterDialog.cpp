#include "TapeLetterDialog.h"

TapeLetterDialog::TapeLetterDialog(TuringMachine* turingMachinePtr, QWidget* parent) :
QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
	setWindowTitle("Установка символа в ленте");
	//Добавляем главную разметку
	qVBoxLayoutMain = new QVBoxLayout(this);
	//Добавляем выпадающий список добавляемых символов
	qHBoxLayoutComboBox->addWidget(new QLabel("Буква алфавита:"));
	qHBoxLayoutComboBox->addWidget(qComboBox);
	qVBoxLayoutMain->addLayout(qHBoxLayoutComboBox);
	//Добавляем кнопки результата диалогового окна
	qHBoxLayoutButton->addWidget(qPushButtonOK);
	qHBoxLayoutButton->addWidget(qPushButtonCancel);
	qVBoxLayoutMain->addLayout(qHBoxLayoutButton);
	//Добавляем значения в выпдающий список добавляемых символов
	for (auto& letter : turingMachinePtr->getAlphabet())
		qComboBox->addItem(letter);
	//Соединяем сигналы кнопок со слотами результата диалогового окна
	connect(qPushButtonOK, &QPushButton::clicked, this, &QDialog::accept);
	connect(qPushButtonCancel, &QPushButton::clicked, this, &QDialog::reject);
	//Меняем параметры окна
	resize(225, 100);
	setWindowTitle("Установка символа в ленте");
}
//Метод получения выбранного символа
QChar TapeLetterDialog::getTapeLetter() const
{
	return qComboBox->currentText().at(0);
}


