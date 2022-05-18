#include <SFML/Graphics.hpp>
#include <iostream>

sf::RectangleShape rect[100];

void Bubblesort(int size, int *arr)
{
    int swapint;
    sf::RectangleShape swap;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swapint = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = swapint;
                swap = rect[j + 1];
                rect[j + 1] = rect[j];
                rect[j + 1] = rect[j];
            }
            rect[j + 1].setFillColor(sf::Color(0, 255, 0));
            rect[j].setFillColor(sf::Color(255, 255, 255));
            sf::sleep(sf::milliseconds(1));
        }
    }
    rect[0].setFillColor(sf::Color(0, 255, 0));
}
void Algortihms(int size)
{
    int *arr = NULL;
    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = std::rand() % 100;
    }
    sf::RenderWindow window(sf::VideoMode(600, 600), "Sorting Algorithm");
    window.setPosition(sf::Vector2i(10, 10));
    sf::Thread thread(std::bind(mergeSort, arr, 0, size - 1));
    thread.launch();
    int posx = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        for (int i = 0; i < size; i++)
        {
            rect[i].setSize(sf::Vector2f(5, arr[i] * -6));
            rect[i].setPosition(posx, 600);
            posx += 7;
            window.draw(rect[i]);
        }
        posx = 0;
        window.display();
    }
    delete[] arr;
}