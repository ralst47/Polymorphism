#include <iostream>

class IFigere {
public:
	std::string tetromino = "Заготовка";
	virtual void draw() { std::cout << "Фигура: " << tetromino << std::endl; } /*= 0;*/
	IFigere() { std::cout << "__IFigere__" << std::endl; }
	virtual ~IFigere() { std::cout << "__~IFigere__" << std::endl; } /*= default;*/
};

struct Square :IFigere {
	std::string tetromino = "Квадрат";
	void draw()override { std::cout << "Фигура0: " << tetromino << std::endl; }
	Square() { std::cout << "__Square__" << std::endl; }
	~Square()override { std::cout << "__~Square__" << std::endl; }
};

struct Rectangle :IFigere {
	std::string tetromino = "Прямоугольник";
	void draw()override { std::cout << "Фигура1: " << tetromino << std::endl; }
	Rectangle() { std::cout << "__Rectangle__" << std::endl; }
	~Rectangle()override { std::cout << "__~Rectangle__" << std::endl; }
};

struct Line :IFigere {
	std::string tetromino = "Палка";
	void draw()override { std::cout << "Фигура2: " << tetromino << std::endl; }
	Line() { std::cout << "__Line__" << std::endl; }
	~Line()override { std::cout << "__~Line__" << std::endl; }
};

int main() {
	setlocale(LC_ALL, "Russian");

	constexpr size_t FIGURE_SIZE = 3u;

	IFigere* figures[FIGURE_SIZE] = { new(Square),new(Rectangle),new(Line) };

	for (auto figure : figures) {
		figure->draw();
	}

	for (auto figure : figures) {
		delete figure; // Вызвов деструктора
		figure = nullptr;
	}

	return 0;
}