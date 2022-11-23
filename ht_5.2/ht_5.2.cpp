#include <iostream>
#include <Windows.h>
#include <string>

    class Figure {
    protected:
        std::string name;
        int points;

    public:

        Figure() {
            name = "Фигура";
            points = 0;
        }

        virtual void print_info() {
            std::cout << name << ":\n";
            std::cout << "Стороны: " << points << "\n";
        }
    };

    class Triangle : public Figure {
    protected:
        int a = 0;
        int b = 0;
        int c = 0;
        int A = 0;
        int B = 0;
        int C = 0;

    public:
        Triangle() {
            name = "Треугольник";
            points = 3;
        }

        Triangle(int a, int b, int c, int A, int B, int C) : Triangle() {
            this->a = a;
            this->b = b;
            this->c = c;
            this->A = A;
            this->B = B;
            this->C = C;
        }
    };

    class RightTriangle : public Triangle {
    public:
        RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) { name = "Прямоугольный треугольник"; }

        void print_info() override {
            std::cout << name << ":\n";
            std::cout << "Стороны: " << a << ' ' << b << ' ' << c << '\n';
            std::cout << "Углы: " << A << ' ' << B << ' ' << C << '\n';
        }
    };

    class IsoscelesTriangle : public Triangle {
    public:
        IsoscelesTriangle(int a, int c, int A, int C) : Triangle(a, a, c, A, A, C) { name = "Равнобедренный треугольник"; }

        void print_info() override {
            std::cout << name << ":\n";
            std::cout << "Стороны: " << a << ' ' << b << ' ' << c << '\n';
            std::cout << "Углы: " << A << ' ' << B << ' ' << C << '\n';
        }
    };



    class EquilateralTriangle : public Triangle {
    public:
        EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) { name = "Равносторонний треугольник"; }

        void print_info() override {
            std::cout << name << ":\n";
            std::cout << "Стороны: " << a << ' ' << b << ' ' << c << '\n';
            std::cout << "Углы: " << A << ' ' << B << ' ' << C << '\n';
        }
    };




    class Quadrangle : public Figure {
    protected:

        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        int A = 0;
        int B = 0;
        int C = 0;
        int D = 0;

    public:
        Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle() {
            this->a = a;
            this->b = b;
            this->c = c;
            this->d = d;
            this->A = A;
            this->B = B;
            this->C = C;
            this->D = D;
        }
        Quadrangle() {
            name = "Четырехугольник";
            points = 4;
        }
    };



    class Parallelogram : public Quadrangle {
    public:

        Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) { name = "Параллелограмм"; }

        void print_info() override {
            std::cout << name << ":\n";
            std::cout << "Стороны: " << a << " " << b << " " << c << " " << d << "\n";
            std::cout << "Углы: " << A << " " << B << " " << C << " " << D << "\n";
        }
    };



    class Rect : public Parallelogram {
    public:
        Rect(int a, int b) : Parallelogram(a, b, 90, 90) { name = "Прямоугольник"; };
    };



    class Rhombus : public Parallelogram {
    public:
        Rhombus(int a, int A, int B) : Parallelogram(a, a, A, B) { name = "Ромб"; };
    };


    class Square : public Rhombus {
    public:
        Square(int a) : Rhombus(a, 90, 90) { name = "Квадрат"; };
    };

    int main()
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);


        RightTriangle rt = RightTriangle(1, 1, 1, 2, 2);
        Figure* fig = &rt;
        fig->print_info();
        std::cout << std::endl;

        IsoscelesTriangle it = IsoscelesTriangle(10, 20, 100, 100);
        fig = &it;
        fig->print_info();
        std::cout << std::endl;

        EquilateralTriangle et = EquilateralTriangle(200);
        fig = &et;
        fig->print_info();
        std::cout << std::endl;

        Parallelogram p = Parallelogram(10, 20, 30, 60);
        fig = &p;
        fig->print_info();
        std::cout << std::endl;

        Rect rect = Rect(10, 20);
        fig = &rect;
        fig->print_info();
        std::cout << std::endl;

        Rhombus rhomb = Rhombus(10, 45, 45);
        fig = &rhomb;
        fig->print_info();
        std::cout << std::endl;

        Square square = Square(30);
        fig = &square;
        fig->print_info();

}