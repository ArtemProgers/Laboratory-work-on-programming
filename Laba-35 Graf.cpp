/*Laba - 35 Графические средства    Карагузов ИВТ1-22*/

#include <SFML/Graphics.hpp> //библиотека

using namespace sf; //пространоство имён 

int main() {
    ContextSettings settings; //сглаживание
    settings.antialiasingLevel = 8; //уровень сглаживания

    RenderWindow window(VideoMode(900, 900), L"Laba-35", Style::Close, settings); //создаём окно фиксированного размера 900x900 

    window.setVerticalSyncEnabled(true); //включение вертикальной синхронизации

    Texture texture; //создание текстуры
   
    if (!texture.loadFromFile("D:\\image.png")) return EXIT_FAILURE; //если ошибка открытия - закрываем прогу

    Sprite sprite(texture); //создание спрайта
    float scale = 1.0f;  //начальный размер
    float x = 400; // начальные координаты объекта
    float y = 400;
    
    sprite.setPosition(x, y); //установка начальной позиции

    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2); // начало координат объекта (центр)

    while (window.isOpen()) { //пока открыто окно
        Event event; //событие
        Color color; //цвет
        while (window.pollEvent(event)) { //обработка событий
            if (event.type == Event::Closed) window.close(); //нажатие на крестик - закрываем прогу

            if (event.type == Event::KeyPressed) { //обработка нажатий кнопок

                if (event.key.code == Keyboard::LShift) scale += 0.1f; //Shift - увеличиваем масштаб

                else if (event.key.code == Keyboard::LControl) scale -= 0.1f; //Ctrl - уменьшаем масштаб

                if (event.key.code == Keyboard::X) sprite.rotate(90.f); //X - поворот по часовой
     
                if (event.key.code == Keyboard::Z) sprite.rotate(-90.f); //Y - поворот против часовой
  
                switch (event.key.code) //выбор цвета
                {
                case Keyboard::Q:
                    color = Color::Red; // Q - красный цвет
                    break;
                case Keyboard::W:
                    color = Color::Green; // W - зелёный цвет
                    break;
                case Keyboard::E:
                    color = Color::Blue; // E - синий цвет
                    break;
                case Keyboard::R:
                    color = Color::Yellow; // R - жёлтый цвет
                    break;
                default:
                    color = Color::White; // другие кнопки - белый цвет
                    break;
                }
                sprite.setColor(color); //установка выбранного цвета
             
                if (event.key.code == Keyboard::Left) { //нажали стрелку влево
                    x -= 5; //уменьшаем координату x
                    //если дошли до левого края - возвращаем такую координату чтобы объект не уходил за рамку
                    if (x <= 0 + sprite.getGlobalBounds().width / 2) x = (sprite.getGlobalBounds().height / 2);
                }
                else if (event.key.code == Keyboard::Right) { //нажали стрелку вправо
                    x += 5; //увеличиваем координату x
                    //если дошли до правого края - возвращаем такую координату чтобы объект не уходил за рамку
                    if (x >= 900 - sprite.getGlobalBounds().width / 2) x = 900-(sprite.getGlobalBounds().height / 2);
                }
                else if (event.key.code == Keyboard::Up) { //нажали стрелку вверх
                    y -= 5; //уменьшаем координату y
                    //если дошли до верхнего края - возвращаем такую координату чтобы объект не уходил за рамку
                    if (y <= 0 + sprite.getGlobalBounds().height / 2) y = (sprite.getGlobalBounds().height / 2);
                }
                else if (event.key.code == Keyboard::Down) { //нажали стрелку вниз
                    y += 5; //увеличиваем координату y
                    //если дошли до нижнего края - возвращаем такую координату чтобы объект не уходил за рамку
                    if (y >= 900 - sprite.getGlobalBounds().height / 2) y = 900-(sprite.getGlobalBounds().height / 2);
                }
                sprite.setPosition(x, y); //установка позиции объекта
             
            }
        }
        sprite.setScale(scale, scale); //установка размера объекта

        window.clear(Color::White); //очистка окна одним цветом - белым (фон программы)
        window.draw(sprite); //вывод объекта
        window.display(); //отображение на экране того, что было визуализировано в окне до сих пор
    }
    return 0;
}