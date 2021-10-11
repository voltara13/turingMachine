#ifndef TURINGMACHINE_VALIDATORALPHABET_H
#define TURINGMACHINE_VALIDATORALPHABET_H

#include <QValidator>

#include "TuringMachine.h"

//Валидатор строки алфавита
class ValidatorAlphabet : public QValidator
{
private:
	TuringMachine* turingMachinePtr = nullptr;

	[[nodiscard]] bool checkAlphabet(const QString& input) const;

public:
	explicit ValidatorAlphabet(TuringMachine* turingMachinePtr, QValidator* parent = nullptr);
	QValidator::State validate(QString &input, int &pos) const override;
};


#endif //TURINGMACHINE_VALIDATORALPHABET_H
