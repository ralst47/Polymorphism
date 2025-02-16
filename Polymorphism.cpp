#include <iostream>
#include <vector>

struct IFigure { // Абстрактный класс (интерфейс)
	virtual void draw() = 0; // Чисто виртуальный метод
	virtual ~IFigure() = default; // Виртуальный деструктор по умолчанию, для вызова деструктора производного класса
};

struct Square :IFigure {
	std::string tetromino = "Квадрат";
	void draw()override { std::cout << "Фигура0: " << tetromino << std::endl; }
};

struct Rectangle :IFigure {
	std::string tetromino = "Прямоугольник";
	void draw()override { std::cout << "Фигура1: " << tetromino << std::endl; }
};

struct Line :IFigure {
	std::string tetromino = "Палка";
	void draw()override { std::cout << "Фигура2: " << tetromino << std::endl; }
};


struct Cursor {
	void control(IFigure& figure) {
		std::cout << std::endl << "Управляю курсором: ";// << std::endl;
		figure.draw();
	}
};


int main() {
	setlocale(LC_ALL, "Russian");

	std::vector<std::unique_ptr<IFigure>> figures; // Создаем вектор уникальных указателей

	figures.push_back(std::make_unique<Square>()); // Добавляем объекты в вектор
	figures.push_back(std::make_unique<Rectangle>());
	figures.push_back(std::make_unique<Line>());

	for (const auto& figure : figures) {
		figure->draw(); // вызов полиморфных методов
	}

	Cursor cursor;
	//Square figure;// Square или Rectangle или Line
	//cursor.control(figure);
	// Или то же самое
	std::unique_ptr<IFigure> pfigure = std::make_unique<Square>();// <Square> или <Rectangle> или <Line>
	cursor.control(*pfigure);

	return 0;
}