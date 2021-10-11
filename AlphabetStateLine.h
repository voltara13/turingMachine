#ifndef TURINGMACHINE_ALPHABETSTATELINE_H
#define TURINGMACHINE_ALPHABETSTATELINE_H

#include <QChar>
#include <QString>

//Перечисление направления
enum class Direction
{
	Null = -1,
	Left,
	Right,
	Constantly,
};
//Класс строки алфавит-значение
class AlphabetStateLine
{
private:
	//Объявляем переменные строки и фалг изменения
	QChar letter;
	Direction direction;
	int state;
	bool flag;

public:
	explicit AlphabetStateLine(const QChar& letter = '\0', const Direction& direction = Direction::Null, const int& state = -1, const bool& flag = false);
	[[nodiscard]] bool isChanged() const;

	[[nodiscard]] QChar getLetter() const;
	[[nodiscard]] Direction getDirection() const;
	[[nodiscard]] int getDirectionSign() const;
	[[nodiscard]] int getState() const;
	[[nodiscard]] QString getStateString() const;
};


#endif //TURINGMACHINE_ALPHABETSTATELINE_H
