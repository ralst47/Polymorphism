#include <iostream>

class IFigere { // Абстрактный класс
public:
	virtual void draw() = 0; // Чисто виртуальный метод
	virtual ~IFigere() = default; // Виртуальный стандартный деструктор
};

struct Square :IFigere {
	std::string tetromino = "Квадрат";
	void draw()override { std::cout << "Фигура0: " << tetromino << std::endl; }
};

struct Rectangle :IFigere {
	std::string tetromino = "Прямоугольник";
	void draw()override { std::cout << "Фигура1: " << tetromino << std::endl; }
};

struct Line :IFigere {
	std::string tetromino = "Палка";
	void draw()override { std::cout << "Фигура2: " << tetromino << std::endl; }
};

int main() {
	setlocale(LC_ALL, "Russian");

	IFigere* figures[] = { new(Square),new(Rectangle),new(Line) };

	for (auto figure : figures) {
		figure->draw(); // вызов полиморфных методов
	}

	for (auto figure : figures) {
		delete figure; // Вызвов деструктора
		figure = nullptr;
	}

	return 0;
}