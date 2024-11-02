#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

// Función para dibujar líneas horizontales usando puntos
void DrawHorizontalLine(Canvas &can, int y, int x_start, int x_end) {
    for (int x = x_start; x <= x_end; ++x) {
        can.DrawPoint(x, y, true);
    }
}

// Función para dibujar líneas verticales usando puntos
void DrawVerticalLine(Canvas &can, int x, int y_start, int y_end) {
    for (int y = y_start; y <= y_end; ++y) {
        can.DrawPoint(x, y, true);
    }
}

// Función para dibujar números en el Canvas usando líneas de puntos
void DrawNumber(Canvas &can, int number) {
    int offset_x = 30;  // Posición X inicial para centrar
    int offset_y = 30;  // Posición Y inicial para centrar

    switch (number) {
        case 5:
            DrawHorizontalLine(can, offset_y, offset_x, offset_x + 20);          // Línea superior
            DrawVerticalLine(can, offset_x, offset_y, offset_y + 10);            // Línea izquierda superior
            DrawHorizontalLine(can, offset_y + 10, offset_x, offset_x + 20);     // Línea media
            DrawVerticalLine(can, offset_x + 20, offset_y + 10, offset_y + 20);  // Línea derecha inferior
            DrawHorizontalLine(can, offset_y + 20, offset_x, offset_x + 20);     // Línea inferior
            break;
        case 4:
            DrawVerticalLine(can, offset_x, offset_y, offset_y + 10);            // Línea izquierda superior
            DrawHorizontalLine(can, offset_y + 10, offset_x, offset_x + 20);     // Línea media
            DrawVerticalLine(can, offset_x + 20, offset_y, offset_y + 20);       // Línea derecha completa
            break;
        case 3:
            DrawHorizontalLine(can, offset_y, offset_x, offset_x + 20);          // Línea superior
            DrawVerticalLine(can, offset_x + 20, offset_y, offset_y + 20);       // Línea derecha completa
            DrawHorizontalLine(can, offset_y + 10, offset_x, offset_x + 20);     // Línea media
            DrawHorizontalLine(can, offset_y + 20, offset_x, offset_x + 20);     // Línea inferior
            break;
        case 2:
            DrawHorizontalLine(can, offset_y, offset_x, offset_x + 20);          // Línea superior
            DrawVerticalLine(can, offset_x + 20, offset_y, offset_y + 10);       // Línea derecha superior
            DrawHorizontalLine(can, offset_y + 10, offset_x, offset_x + 20);     // Línea media
            DrawVerticalLine(can, offset_x, offset_y + 10, offset_y + 20);       // Línea izquierda inferior
            DrawHorizontalLine(can, offset_y + 20, offset_x, offset_x + 20);     // Línea inferior
            break;
        case 1:
            DrawVerticalLine(can, offset_x + 10, offset_y, offset_y + 20);       // Línea central
            break;
        case 0:
            DrawHorizontalLine(can, offset_y, offset_x, offset_x + 20);          // Línea superior
            DrawVerticalLine(can, offset_x, offset_y, offset_y + 20);            // Línea izquierda
            DrawVerticalLine(can, offset_x + 20, offset_y, offset_y + 20);       // Línea derecha
            DrawHorizontalLine(can, offset_y + 20, offset_x, offset_x + 20);     // Línea inferior
            break;
        default:
            break;
    }
}

int main(int argc, char const *argv[])
{
    int seconds = 5; // Tiempo de cuenta regresiva en segundos

    for (int i = seconds; i >= 0; --i) {
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        auto can = Canvas(100, 100);
        
        DrawNumber(can, i); // Dibujar el número actual en el Canvas

        Element lienzo = bgcolor(Color::Black, border(canvas(&can)));
        Render(pantalla, lienzo);
        pantalla.Print();

        this_thread::sleep_for(1s);
    }

    std::cout << "\n¡La cuenta regresiva ha terminado!\n";

    return 0;
}
