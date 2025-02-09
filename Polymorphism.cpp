#include <iostream>
#include <vector>

class IFigure { // Абстрактный класс
public:
	virtual void draw() = 0; // Чисто виртуальный метод
	virtual ~IFigure() = default; // Виртуальный стандартный деструктор для вызова деструктора производного класса
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

int main() {
	setlocale(LC_ALL, "Russian");

	std::vector<std::unique_ptr<IFigure>> figures; // Создаем вектор уникальных указателей

	figures.push_back(std::make_unique<Square>()); // Добавляем объекты в вектор
	figures.push_back(std::make_unique<Rectangle>());
	figures.push_back(std::make_unique<Line>());

	for (const auto& figure : figures) {
		figure->draw(); // вызов полиморфных методов
	}

	return 0;
}