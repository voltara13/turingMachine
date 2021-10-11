#include "ValidatorAlphabet.h"

ValidatorAlphabet::ValidatorAlphabet(TuringMachine* turingMachinePtr, QValidator* parent) :
turingMachinePtr(turingMachinePtr), QValidator(parent) {}
//Метод валидации новой строки алфавита
QValidator::State ValidatorAlphabet::validate(QString& input, int& pos) const
{
	if (input.count() == MAX_COUNT_LETTER - 1 || input.contains(" ") || !checkAlphabet(input))
		return QValidator::Invalid;
	return QValidator::Acceptable;
}
//Метод проверки строки алфавита на повторяющиеся символы и пробелы
bool ValidatorAlphabet::checkAlphabet(const QString& input) const
{
	QSet<QChar> setInput;
	for (auto& letter : input)
		setInput.insert(letter);

	if (setInput.size() != input.size())
		return false;

	setInput.insert(' ');
	turingMachinePtr->changeAlphabet(setInput);

	return true;
}




