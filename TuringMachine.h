#ifndef TURINGMACHINE_TURINGMACHINE_H
#define TURINGMACHINE_TURINGMACHINE_H

#include <QObject>
#include <QThread>
#include <QList>
#include <QSet>
#include <QMap>

#include "AlphabetStateLine.h"

//Константные переменные эмулятора
constexpr int SIZE_TAPE = 201;
constexpr int START_VALUE_STATE = 0;
constexpr int START_COUNT_STATE = 8;
constexpr int MAX_COUNT_STATE = 100;
constexpr int MIN_COUNT_STATE = 1;
constexpr int MAX_COUNT_LETTER = 100;

//Класс эмулятора машины Тьюринга
class TuringMachine : public QObject
{
	Q_OBJECT
private:
	//Объявляем переменные машины Тьюринга
	QChar tape[SIZE_TAPE];
	QMap<QChar, QList<AlphabetStateLine>> alphabetState;
	int currentStateCount = START_COUNT_STATE;
	int currentIndex = (SIZE_TAPE - 1) / 2;
	int currentState = START_VALUE_STATE;

	[[nodiscard]] bool checkIndex(AlphabetStateLine stateString);

public:
	explicit TuringMachine(QObject* parent = nullptr);

	bool stepTuring();
	void emulationTuring();

	[[nodiscard]] int getStateCount() const;
	[[nodiscard]] QList<QChar> getAlphabet() const;

	void changeAlphabetStateItem(const QChar& letter, const int& stateNum, const AlphabetStateLine& stateString);
	void changeAlphabet(const QSet<QChar>& input);

	void setCurrentStateCount(const int& count);
	void setLetterTape(const int& index, const QChar& letter);

public slots:
	void changeCurrentIndexTapeSlot(const int& row, const int& column);
	void changeCurrentStateSlot(const int& newState);


signals:
	void endTapeSignal();
	void endWorkSignal();

	void currentIndexChangedSignal(const int& index);
	void currentStateChangedSignal(const int& stateNum);

	void tapeChangedSignal(const QChar& letter);
	void alphabetStateChangedSignal();
	void matrixStringChangedSignal(const AlphabetStateLine& stateString);
};


#endif //TURINGMACHINE_TURINGMACHINE_H
