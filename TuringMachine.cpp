#include "TuringMachine.h"

TuringMachine::TuringMachine(QObject* parent) : QObject(parent)
{
	//Заполняем ленту начальными значениями
	for (auto& letter : tape)
		letter = ' ';
	//Заполняем алфавит начальными значениями
	QSet<QChar> alphabet = { '0', '1', ' ' };
	//Заполняем матрицу алфавит-состояние начальными значениями
	for (auto& letter : alphabet)
	{
		QList<AlphabetStateLine> row(START_COUNT_STATE);
		alphabetState[letter] = row;
	}
}
//Метод проверки индекса на выход за пределы ленты
bool TuringMachine::checkIndex(AlphabetStateLine stateString)
{
	if (currentIndex == SIZE_TAPE - 1 && stateString.getDirection() == Direction::Right ||
		currentIndex == 0 && stateString.getDirection() == Direction::Left)
	{
		emit endTapeSignal();

		return false;
	}
	return true;
}
//Метод воспроизведения шага эмуляции
bool TuringMachine::stepTuring()
{
	AlphabetStateLine stateString = alphabetState[tape[currentIndex]][currentState];

	if (stateString.isChanged() &&
		(tape[currentIndex] != stateString.getLetter() ||
		 stateString.getDirection() != Direction::Constantly ||
		 stateString.getState() != currentState))
	{
		setLetterTape(currentIndex, stateString.getLetter());
		if (!checkIndex(stateString))
			return false;
		currentIndex += stateString.getDirectionSign();

		emit currentIndexChangedSignal(currentIndex);

		currentState = stateString.getState();

		emit currentStateChangedSignal(currentState);

		return true;
	}
	else
		return false;

}
//Метод воспроизведения автоматического процесса эмуляции
void TuringMachine::emulationTuring()
{
	while (!QThread::currentThread()->isInterruptionRequested() && stepTuring())
		QThread::msleep(500);

	emit endWorkSignal();
}
//Метод получения количества состояний
int TuringMachine::getStateCount() const
{
	return currentStateCount;
}
//Метод получения алфавита
QList<QChar> TuringMachine::getAlphabet() const
{
	return alphabetState.keys();
}
//Метод изменения значения в матрице алфавит-состояние
void TuringMachine::changeAlphabetStateItem(const QChar& letter, const int& stateNum, const AlphabetStateLine& stateString)
{
	alphabetState[letter][stateNum] = stateString;

	emit matrixStringChangedSignal(stateString);
}
//Метод изменения алфавита
void TuringMachine::changeAlphabet(const QSet<QChar>& input)
{
	const QList<QChar> alphabetQList = alphabetState.keys();
	QSet<QChar> alphabet(alphabetQList.begin(), alphabetQList.end());
	QSet<QChar> deleteLetters = alphabet - input;
	QSet<QChar> addLetters = input - alphabet;

	for (auto& letter : deleteLetters)
		alphabetState.remove(letter);

	for (auto& letter : addLetters)
	{
		QList<AlphabetStateLine> row(currentStateCount);
		alphabetState[letter] = row;
	}

	emit alphabetStateChangedSignal();
}
//Метод установки значения количества состояний
void TuringMachine::setCurrentStateCount(const int& count)
{
	currentStateCount = count;

	for (auto& row : alphabetState)
		row.resize(currentStateCount);

	emit alphabetStateChangedSignal();
}
//Метод установки символа в ленте
void TuringMachine::setLetterTape(const int& index, const QChar& letter)
{
	tape[index] = letter;

	emit tapeChangedSignal(letter);
}
//Слот изменения активной ячейки в ленте
void TuringMachine::changeCurrentIndexTapeSlot(const int& row, const int& column)
{
	currentIndex = column;
}
//Слот изменения активного состояния
void TuringMachine::changeCurrentStateSlot(const int& newState)
{
	currentState = newState - 1;
}
