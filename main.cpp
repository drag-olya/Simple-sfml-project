#include <SFML/Graphics.hpp>


bool check_direct(float x, float w, float d, bool flag) {
    if ((w - d - x) < 0.1) {
        return false;
    }
    else if (x < 0.1) {
        return true;
    }
    return flag;   
}


float change_pos(float x, bool flag, float step) {

    if (flag) {
        x += step;
    }
    else {
        x -= step;
    }
    return x;
}


int main()
{
    float w = 800;
    float h = 800;

    sf::RenderWindow window(sf::VideoMode(w, h), "SFML works!");
    
    float r1 = w / 6;
    float d1 = r1 * 2;

    sf::CircleShape ball1(r1);
    ball1.setFillColor(sf::Color::Green);

    float r2 = 70, d2 = r2 * 2;

    float x = 8, y = 8;

    bool right = true, down = true;

    float step_x = 0.32, step_y = 0.76;

    sf::CircleShape ball2(r2);
    ball2.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();


        // draw green circles on full window
        for (int i = 0; i < w; i += d1)
        {
            for (int j = 0; j < h; j += d1)
            {
                ball1.setPosition(i, j);
                window.draw(ball1);
            }
        }

        
        // red animated cirlcle
        ball2.setPosition(x, y);
        window.draw(ball2);
        
        x = change_pos(x, right, step_x);
        right = check_direct(x, w, d2, right);
       
        y = change_pos(y, down, step_y);
        down = check_direct(y, h, d2, down);

        window.display();
    }

    return 0;
}