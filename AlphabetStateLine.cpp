#include "AlphabetStateLine.h"

AlphabetStateLine::AlphabetStateLine(const QChar& letter, const Direction& direction, const int& state, const bool& isChanged) :
letter(letter), direction(direction), state(state), flag(isChanged) {}

//Метод получения факта изменения строки
bool AlphabetStateLine::isChanged() const
{
	return flag;
}
//Метод получения символа строки
QChar AlphabetStateLine::getLetter() const
{
	return letter;
}
//Метод получения направления строки
Direction AlphabetStateLine::getDirection() const
{
	return direction;
}
//Метод получения знака направления строки
int AlphabetStateLine::getDirectionSign() const
{
	switch (direction)
	{
	case Direction::Left:
		return -1;
	case Direction::Right:
		return 1;
	case Direction::Constantly:
		return 0;
	default:
		throw std::invalid_argument("Direction error");
	}
}
//Метод получения состояния строки
int AlphabetStateLine::getState() const
{
	return state;
}
//Метод получения строки в строковом виде
QString AlphabetStateLine::getStateString() const
{
	QString letterQString = letter;
	QString directionQString = "\0";
	QString stateQString = "Q" + QString::number(state + 1);

	switch (direction)
	{
	case Direction::Left:
		directionQString = "<";
		break;
	case Direction::Right:
		directionQString = ">";
		break;
	case Direction::Constantly:
		directionQString = ".";
		break;
	default:
		throw std::invalid_argument("Direction error");
	}

	return letterQString + directionQString + stateQString;
}


