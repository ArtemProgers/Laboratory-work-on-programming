/*Laba - 35 ����������� ��������    ��������� ���1-22*/

#include <SFML/Graphics.hpp> //����������

using namespace sf; //������������� ��� 

int main() {
    ContextSettings settings; //�����������
    settings.antialiasingLevel = 8; //������� �����������

    RenderWindow window(VideoMode(900, 900), L"Laba-35", Style::Close, settings); //������ ���� �������������� ������� 900x900 

    window.setVerticalSyncEnabled(true); //��������� ������������ �������������

    Texture texture; //�������� ��������
   
    if (!texture.loadFromFile("D:\\image.png")) return EXIT_FAILURE; //���� ������ �������� - ��������� �����

    Sprite sprite(texture); //�������� �������
    float scale = 1.0f;  //��������� ������
    float x = 400; // ��������� ���������� �������
    float y = 400;
    
    sprite.setPosition(x, y); //��������� ��������� �������

    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2); // ������ ��������� ������� (�����)

    while (window.isOpen()) { //���� ������� ����
        Event event; //�������
        Color color; //����
        while (window.pollEvent(event)) { //��������� �������
            if (event.type == Event::Closed) window.close(); //������� �� ������� - ��������� �����

            if (event.type == Event::KeyPressed) { //��������� ������� ������

                if (event.key.code == Keyboard::LShift) scale += 0.1f; //Shift - ����������� �������

                else if (event.key.code == Keyboard::LControl) scale -= 0.1f; //Ctrl - ��������� �������

                if (event.key.code == Keyboard::X) sprite.rotate(90.f); //X - ������� �� �������
     
                if (event.key.code == Keyboard::Z) sprite.rotate(-90.f); //Y - ������� ������ �������
  
                switch (event.key.code) //����� �����
                {
                case Keyboard::Q:
                    color = Color::Red; // Q - ������� ����
                    break;
                case Keyboard::W:
                    color = Color::Green; // W - ������ ����
                    break;
                case Keyboard::E:
                    color = Color::Blue; // E - ����� ����
                    break;
                case Keyboard::R:
                    color = Color::Yellow; // R - ����� ����
                    break;
                default:
                    color = Color::White; // ������ ������ - ����� ����
                    break;
                }
                sprite.setColor(color); //��������� ���������� �����
             
                if (event.key.code == Keyboard::Left) { //������ ������� �����
                    x -= 5; //��������� ���������� x
                    //���� ����� �� ������ ���� - ���������� ����� ���������� ����� ������ �� ������ �� �����
                    if (x <= 0 + sprite.getGlobalBounds().width / 2) x = (sprite.getGlobalBounds().height / 2);
                }
                else if (event.key.code == Keyboard::Right) { //������ ������� ������
                    x += 5; //����������� ���������� x
                    //���� ����� �� ������� ���� - ���������� ����� ���������� ����� ������ �� ������ �� �����
                    if (x >= 900 - sprite.getGlobalBounds().width / 2) x = 900-(sprite.getGlobalBounds().height / 2);
                }
                else if (event.key.code == Keyboard::Up) { //������ ������� �����
                    y -= 5; //��������� ���������� y
                    //���� ����� �� �������� ���� - ���������� ����� ���������� ����� ������ �� ������ �� �����
                    if (y <= 0 + sprite.getGlobalBounds().height / 2) y = (sprite.getGlobalBounds().height / 2);
                }
                else if (event.key.code == Keyboard::Down) { //������ ������� ����
                    y += 5; //����������� ���������� y
                    //���� ����� �� ������� ���� - ���������� ����� ���������� ����� ������ �� ������ �� �����
                    if (y >= 900 - sprite.getGlobalBounds().height / 2) y = 900-(sprite.getGlobalBounds().height / 2);
                }
                sprite.setPosition(x, y); //��������� ������� �������
             
            }
        }
        sprite.setScale(scale, scale); //��������� ������� �������

        window.clear(Color::White); //������� ���� ����� ������ - ����� (��� ���������)
        window.draw(sprite); //����� �������
        window.display(); //����������� �� ������ ����, ��� ���� ��������������� � ���� �� ��� ���
    }
    return 0;
}