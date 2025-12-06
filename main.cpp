#include <iostream>
#include <string>
#include <limits>
#include "Graph.h"
#include <windows.h>

#ifdef _WIN32
#define CLEAR_CMD "cls"
#else
#define CLEAR_CMD "clear"
#endif

void wait_for_enter() {
    std::cout << "\nНажмите Enter, чтобы продолжить...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void print_menu() {
    std::cout << "================ Граф =================\n";
    std::cout << "1 - Добавить вершину\n";
    std::cout << "2 - Удалить вершину (по индексу)\n";
    std::cout << "3 - Соединить две вершины (по индексам)\n";
    std::cout << "4 - Разорвать связь между вершинами\n";
    std::cout << "5 - Показать граф\n";
    std::cout << "6 - Сохранить граф в файл\n";
    std::cout << "7 - Загрузить граф из файла\n";
    std::cout << "8 - Очистить граф\n";
    std::cout << "0 - Выход\n";
    std::cout << "=======================================\n";
    std::cout << "Выберите пункт меню: ";
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    Graph g;

    while (true) {
        system(CLEAR_CMD);
        print_menu();

        int choice = -1;
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 0:
                std::cout << "Завершение работы.\n";
                return 0;

            case 1: {
                int value;
                std::cout << "Введите значение вершины: ";
                std::cin >> value;

                g.add_vertex(value);
                std::cout << "Вершина добавлена.\n";
                wait_for_enter();
                break;
            }

            case 2: {
                int index;
                std::cout << "Введите индекс вершины для удаления: ";
                std::cin >> index;

                g.remove_vertex(index);
                std::cout << "Если индекс был корректен — вершина удалена.\n";
                wait_for_enter();
                break;
            }

            case 3: {
                int v1, v2;
                std::cout << "Введите индекс первой вершины: ";
                std::cin >> v1;
                std::cout << "Введите индекс второй вершины: ";
                std::cin >> v2;

                g.connect_vertex(v1, v2);
                std::cout << "Связь установлена.\n";
                wait_for_enter();
                break;
            }

            case 4: {
                int v1, v2;
                std::cout << "Введите индекс первой вершины: ";
                std::cin >> v1;
                std::cout << "Введите индекс второй вершины: ";
                std::cin >> v2;

                g.disconnect_vertex(v1, v2);
                std::cout << "Связь удалена.\n";
                wait_for_enter();
                break;
            }

            case 5: {
                std::cout << g;
                wait_for_enter();
                break;
            }

            case 6: {
                std::string filename;
                std::cout << "Введите имя файла: ";
                std::cin >> filename;

                g.save_to_file(filename);
                std::cout << "Граф сохранён.\n";
                wait_for_enter();
                break;
            }

            case 7: {
                std::string filename;
                std::cout << "Введите имя файла: ";
                std::cin >> filename;

                g.clear();
                g.load_from_file(filename);
                std::cout << "Граф загружен.\n";
                wait_for_enter();
                break;
            }

            case 8: {
                g.clear();
                std::cout << "Граф очищен.\n";
                wait_for_enter();
                break;
            }

            default:
                std::cout << "Неизвестная команда.\n";
                wait_for_enter();
                break;
        }
    }

    return 0;
}
