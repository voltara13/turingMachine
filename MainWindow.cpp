#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : QWidget(parent)
{
	//Инициализируем машину Тьюринга
	turingMachine = new TuringMachine(this);
	//Добавляем главную разметку
	qVBoxLayoutMain = new QVBoxLayout(this);
	//Добавляем кнопки работы
	qHBoxLayoutButtonWork->addWidget(qPushButtonStart);
	qHBoxLayoutButtonWork->addWidget(qPushButtonStep);
	qHBoxLayoutButtonWork->addWidget(qPushButtonStop);
	qVBoxLayoutMain->addLayout(qHBoxLayoutButtonWork);
	//Добавляем ленту
	qVBoxLayoutMain->addWidget(qTableWidgetTape);
	//Добавляем алфавит и нумерацию состояния
	qHBoxLayoutAlphabetStateLine->addWidget(new QLabel("Алфавит"));
	qHBoxLayoutAlphabetStateLine->addWidget(qLineEditAlphabet);
	qHBoxLayoutAlphabetStateLine->addWidget(new QLabel("Номер состояния"));
	qHBoxLayoutAlphabetStateLine->addWidget(qSpinBoxState);
	qVBoxLayoutMain->addLayout(qHBoxLayoutAlphabetStateLine);
	//Добавляем кнопки управления состояниями
	qHBoxLayoutButtonState->addWidget(qPushButtonAddState);
	qHBoxLayoutButtonState->addWidget(qPushButtonDeleteState);
	qVBoxLayoutMain->addLayout(qHBoxLayoutButtonState);
	//Добавляем таблицу алфавит-состояния
	qVBoxLayoutMain->addWidget(qTableWidgetAlphabetState);
	//Инициализируем ленту
	initTape();
	//Инициализируем таблицу алфавит-состояния
	initAlphabetState();
	//Инициализируем номер состояния
	initSpinBox();
	//Создаём горячие клавиши
	keyF1 = new QShortcut(this);
	keyA = new QShortcut(this);
	keyD = new QShortcut(this);
	keyS = new QShortcut(this);
	keySpace = new QShortcut(this);
	keyF = new QShortcut(this);
	esc = new QShortcut(this);
	//Связываем указатели горячих клавишей с клавишами
	keyF1->setKey(Qt::Key_F1);
	keyA->setKey(Qt::Key_A);
	keyD->setKey(Qt::Key_D);
	keyS->setKey(Qt::Key_S);
	keySpace->setKey(Qt::Key_Space);
	keyF->setKey(Qt::Key_F);
	esc->setKey(Qt::Key_Escape);
	//Связываем горячие клавиши со слотами
	QObject::connect(keyF1, &QShortcut::activated, this, &MainWindow::helpSlot);
	QObject::connect(keyA, &QShortcut::activated, this, [this] { clickButtonChangeCountStateSlot(true); });
	QObject::connect(keyD, &QShortcut::activated, this, [this] { clickButtonChangeCountStateSlot(false); });
	QObject::connect(keyS, &QShortcut::activated, this, &MainWindow::clickButtonStartSlot);
	QObject::connect(keySpace, &QShortcut::activated, this, &MainWindow::clickButtonStopSlot);
	QObject::connect(keyF, &QShortcut::activated, this, &MainWindow::clickButtonStepSlot);
	QObject::connect(esc, &QShortcut::activated, this, &MainWindow::exitSlot);
	//Соединяем сигналы машины Тьюринга со слотами пользовательского интерфейса
	connect(turingMachine, &TuringMachine::tapeChangedSignal, this, &MainWindow::changeTapeItemSlot);
	connect(turingMachine, &TuringMachine::endTapeSignal, this, &MainWindow::endTapeSlot);
	connect(turingMachine, &TuringMachine::endWorkSignal, this, &MainWindow::endWorkSlot);
	connect(turingMachine, &TuringMachine::currentIndexChangedSignal, this, &MainWindow::changeCurrentIndexTapeSlot);
	connect(turingMachine, &TuringMachine::currentStateChangedSignal, this, &MainWindow::changeCurrentStateSlot);
	connect(turingMachine, &TuringMachine::matrixStringChangedSignal, this, &MainWindow::changeAlphabetStateItemSlot);
	connect(turingMachine, &TuringMachine::alphabetStateChangedSignal, this, &MainWindow::changeAlphabetStateCountSlot);
	//Соединяем сигналы кнопок со слотами пользовательского интерфейса
	connect(qPushButtonStart, &QPushButton::clicked, this, &MainWindow::clickButtonStartSlot);
	connect(qPushButtonStep, &QPushButton::clicked, this, &MainWindow::clickButtonStepSlot);
	connect(qPushButtonStop, &QPushButton::clicked, this, &MainWindow::clickButtonStopSlot);
	connect(qPushButtonAddState, &QPushButton::clicked, this, [this] { clickButtonChangeCountStateSlot(true); });
	connect(qPushButtonDeleteState, &QPushButton::clicked, this, [this] { clickButtonChangeCountStateSlot(false); });
	//Соединяем сигналы виджетов со слотами пользовательского интерфейса и машины Тьюринга
	connect(qTableWidgetTape, &QTableWidget::doubleClicked, this, &MainWindow::doubleClickTapeSlot);
	connect(qTableWidgetAlphabetState, &QTableWidget::doubleClicked, this, &MainWindow::doubleClickAlphabetStateSlot);
	connect(qTableWidgetTape, &QTableWidget::cellClicked, turingMachine, &TuringMachine::changeCurrentIndexTapeSlot);
	connect(qSpinBoxState, &QSpinBox::valueChanged, turingMachine, &TuringMachine::changeCurrentStateSlot);
	//Применяем валидатор к вводу алфавита
	qLineEditAlphabet->setValidator(new ValidatorAlphabet(turingMachine));
	//Отключаем кнопку остановки
	qPushButtonStop->setEnabled(false);
	keySpace->setEnabled(false);
	//Меняем параметры окна
	resize(845, 400);
	setWindowTitle("Машина Тьюринга");
}
//Метод инициализации таблицы ленты
void MainWindow::initTape()
{
	for (int i = 0; i < qTableWidgetTape->columnCount(); ++i)
		qTableWidgetTape->setHorizontalHeaderItem(i, new QTableWidgetItem(tr("%1").arg(i - SIZE_TAPE / 2)));
	qTableWidgetTape->verticalHeader()->hide();

	qTableWidgetTape->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	qTableWidgetTape->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
	qTableWidgetTape->setEditTriggers(QAbstractItemView::NoEditTriggers);
	qTableWidgetTape->setSelectionMode(QAbstractItemView::SingleSelection);
	qTableWidgetTape->setCurrentCell(0, SIZE_TAPE / 2);
	qTableWidgetTape->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
}
//Метод инициализации таблицы алфавит-состояние
void MainWindow::initAlphabetState()
{
	qTableWidgetAlphabetState->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	qTableWidgetAlphabetState->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
	qTableWidgetAlphabetState->setEditTriggers(QAbstractItemView::NoEditTriggers);
	qTableWidgetAlphabetState->setSelectionMode(QAbstractItemView::SingleSelection);

	changeAlphabetStateCountSlot();
}
//Метод инициализации переключателя номера состояния
void MainWindow::initSpinBox()
{
	qSpinBoxState->setMinimum(MIN_COUNT_STATE);
	qSpinBoxState->setMaximum(turingMachine->getStateCount());
	qSpinBoxState->setValue(START_VALUE_STATE + 1);
}
//Метод создания потока эмуляции
void MainWindow::startThreadTuringMachine()
{
	turingMachineThread = QThread::create([this] { turingMachine->emulationTuring(); });
	turingMachineThread->setParent(this);
	connect(turingMachineThread, &QThread::started, this, [this] { changeGUIModelingSlot(true); });
	connect(turingMachineThread, &QThread::finished, this, [this] { changeGUIModelingSlot(false); });
	turingMachineThread->start();
}
//Метод завершения потока эмуляции
void MainWindow::stopThreadTuringMachine()
{
	turingMachineThread->requestInterruption();
}
//Слот изменения значения в ленте
void MainWindow::changeTapeItemSlot(const QChar& letter)
{
	auto item = new QTableWidgetItem(letter);
	item->setTextAlignment(Qt::AlignCenter);
	qTableWidgetTape->setItem(0, qTableWidgetTape->currentColumn(), item);
}
//Слот изменения количества ячеек в таблице алфавит-состояние
void MainWindow::changeAlphabetStateCountSlot()
{
	int columnCount = turingMachine->getStateCount();
	int rowCount = turingMachine->getAlphabet().size();

	qTableWidgetAlphabetState->setColumnCount(columnCount);
	qTableWidgetAlphabetState->setRowCount(rowCount);

	for (int i = 0; i < columnCount; ++i)
		qTableWidgetAlphabetState->setHorizontalHeaderItem(i,
				new QTableWidgetItem(tr("Q%1").arg(i + 1)));

	for (int i = 0; i < rowCount; ++i)
		qTableWidgetAlphabetState->setVerticalHeaderItem(i,
				new QTableWidgetItem(*std::next(turingMachine->getAlphabet().begin(), i)));
}
//Слот изменения значения в таблице алфавит-состояние
void MainWindow::changeAlphabetStateItemSlot(const AlphabetStateLine& alphabetStateLine)
{
	auto item = new QTableWidgetItem(alphabetStateLine.getStateString());
	item->setTextAlignment(Qt::AlignCenter);
	qTableWidgetAlphabetState->setItem(qTableWidgetAlphabetState->currentRow(), qTableWidgetAlphabetState->currentColumn(), item);
}
//Слот изменения активной ячейки в ленте
void MainWindow::changeCurrentIndexTapeSlot(const int& index)
{
	qTableWidgetTape->setCurrentCell(0, index);
}
//Слот изменения активного состояния
void MainWindow::changeCurrentStateSlot(const int& newState)
{
	qSpinBoxState->setValue(newState + 1);
}
//Слот изменения состояния кнопок управления
void MainWindow::changeGUIModelingSlot(const bool& isStart)
{
	qPushButtonStart->setEnabled(!isStart);
	qPushButtonStep->setEnabled(!isStart);
	qPushButtonStop->setEnabled(isStart);
	qPushButtonAddState->setEnabled(!isStart);
	qPushButtonDeleteState->setEnabled(!isStart);

	keyS->setEnabled(!isStart);
	keySpace->setEnabled(isStart);
	keyF->setEnabled(!isStart);
	keyA->setEnabled(!isStart);
	keyD->setEnabled(!isStart);

	qLineEditAlphabet->setEnabled(!isStart);
	qSpinBoxState->setEnabled(!isStart);
	qTableWidgetTape->setEnabled(!isStart);
	qTableWidgetAlphabetState->setEnabled(!isStart);
}
//Слот нажатия на кнопку "Старт"
void MainWindow::clickButtonStartSlot()
{
	startThreadTuringMachine();
}
//Слот нажатия на кнопку "Шаг"
void MainWindow::clickButtonStepSlot()
{
	turingMachine->stepTuring();
}
//Слот нажатия на кнопку "Стоп"
void MainWindow::clickButtonStopSlot()
{
	stopThreadTuringMachine();
}
//Слот нажатия на одну из кнопок изменения количества состояний
void MainWindow::clickButtonChangeCountStateSlot(const bool& isAdd)
{
	int stateCount = turingMachine->getStateCount();

	if (stateCount == MIN_COUNT_STATE)
		qPushButtonDeleteState->setEnabled(isAdd);
	isAdd ? stateCount++ : stateCount--;
	turingMachine->setCurrentStateCount(stateCount);
	if (stateCount == MAX_COUNT_STATE)
		qPushButtonAddState->setEnabled(!isAdd);

	qSpinBoxState->setMaximum(turingMachine->getStateCount());
}
//Слот двойного нажатия по ячейке ленты
void MainWindow::doubleClickTapeSlot()
{
	auto tapeLetterDialog = new TapeLetterDialog(turingMachine, this);
	if (tapeLetterDialog->exec() == QDialog::Accepted)
		turingMachine->setLetterTape(
				qTableWidgetTape->currentColumn(),
				tapeLetterDialog->getTapeLetter());
}
//Слот двойного нажатия по ячейке таблицы алфавит-состояние
void MainWindow::doubleClickAlphabetStateSlot()
{
	auto stateStringDialog = new AlphabetStateLineDialog(turingMachine, this);
	if (stateStringDialog->exec() == QDialog::Accepted)
		turingMachine->changeAlphabetStateItem(
				*std::next(turingMachine->getAlphabet().begin(), qTableWidgetAlphabetState->currentRow()),
				qTableWidgetAlphabetState->currentColumn(),
				stateStringDialog->getAlphabetStateLine());
}
//Слот окончания ленты
void MainWindow::endTapeSlot()
{
	QMessageBox::warning(this,
			"Предупреждение",
			"Лента закончилась");
}
//Слот окончания работы
void MainWindow::endWorkSlot()
{
	QMessageBox::information(this,
			"Предупреждение",
			"Работа завершена");
}
//Слот вызова помощи
void MainWindow::helpSlot()
{
	QMessageBox::information(this,
			"Помощь",
			"Эмулятор машины Тьюринга.\n"
			"Вводится нужный алфавит, количество состояний изменяется до нужного. "
			"Если необходимо, то на ленте (верхней таблице) можно проставить символы "
			"из алфавита двойным нажатием по нужной клетке. В таблице алфавит / состояние "
			"(нижней таблице) указывается необходимое действие по символ и состояние двойным нажатием по "
			"нужной клетке. Эмуляцию можно запустить нажатием на 'начать', либо провести "
			"один шаг нажатием на 'шаг', нажатием на кнопку 'Стоп' можно прервать запущенную "
			"симуляцию. Также имеется возможность изменять текущее состояние с помощью переключателя");
}
//Слот выхода из программы
void MainWindow::exitSlot()
{
	::exit(0);
}
