#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <sstream>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include "Platform.h"
int page_number;

int main()
{

    sf::RenderWindow window(sf::VideoMode(910, 650), "SFML" , sf::Style::Close);
    Menu menu(window.getSize().x, window.getSize().y);
    sf::Texture texture;
    if (!texture.loadFromFile("Background main.jpg"));
    {
        //handle error
    }
    sf::Sprite background;
    background.setTexture(texture);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;
                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;
                case sf::Keyboard::Return:
                    switch (menu.GetPressedItem())
                    {
                    case 0:
                        page_number = 0;
                        std::cout << "Play button has been pressed" << std::endl;
                        window.close();
                          break;
                    case 1:
                        page_number = 1;
                        window.close();
                        break;
                    case 2:
                        window.close();
                        page_number = 2;
                        break;
                    }
                }
            }
        }

        window.clear();
        window.draw(background);
        menu.draw(window);
        window.display();
    }
    

    if (page_number == 0)

    {
        Platform platform1(nullptr, sf::Vector2f(400.0f, 50.0f), sf::Vector2f(500.0f, 300.0f));
        Platform platform2(nullptr, sf::Vector2f(400.0f, 50.0f), sf::Vector2f(500.0f, 300.0f)); 

        sf::Vector2i screenDimensions(910, 650);
        sf::RenderWindow window;
        window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "SFML works!");

     


        sf::Music music;
        music.openFromFile("Megaman SOUND.wav");
        music.setVolume(5.0);
        music.play();

        sf::SoundBuffer soundulti, soundJump, soundAttack;
        soundulti.loadFromFile("UltimateSound.wav");
        soundJump.loadFromFile("JumpSOUND.wav");
        soundAttack.loadFromFile("attack.ogg");
        sf::Sound sUlti, sJump, sAtk;
        sUlti.setBuffer(soundulti);
        sJump.setBuffer(soundJump);
        sAtk.setBuffer(soundAttack);
        sUlti.setVolume(15.0);
        sJump.setVolume(15.0);
        sAtk.setVolume(15.0);


        sf::Texture bTexture;
        sf::Sprite bImage;

        if (!bTexture.loadFromFile("Mappppppppppppppp1.jpg"));
        std::cout << "Could not load background image" << std::endl;
        bImage.setTexture(bTexture);
        bImage.setScale(1.0f, (float)screenDimensions.y / bTexture.getSize().y);

        sf::View view;
        view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
        view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

        sf::Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);

        sf::CircleShape life1;
        life1.setRadius(20.0f);
        sf::Texture Life1Texture;
        Life1Texture.loadFromFile("life.png");
        life1.setTexture(&Life1Texture);
        life1.setPosition(850, 10);


        sf::CircleShape life2;
        life2.setRadius(20.0f);
        sf::Texture Life2Texture;
        Life2Texture.loadFromFile("life.png");
        life2.setTexture(&Life2Texture);
        life2.setPosition(800, 10);

        sf::CircleShape life3;
        life3.setRadius(20.0f);
        sf::Texture Life3Texture;
        Life3Texture.loadFromFile("life.png");
        life3.setTexture(&Life3Texture);
        life3.setPosition(750, 10);



        int ultivalue[10] = {};
        sf::Clock clockUlti;
        sf::CircleShape ultimate[10];
        sf::Texture ultimateTexture;
        ultimateTexture.loadFromFile("ultimate.png");
        for (int k = 0; k <= 9; k++)
        {
            ultimate[k].setRadius(80.0f);
            ultimate[k].setTexture(&ultimateTexture);
            ultimate[k].setPosition(10000000.0f, 100000000000.0f);
        }
        int indexUlti = 0;


        int bulletvalue[10] = {};
        sf::Clock clockShoot;
        sf::CircleShape bullet[10];
        sf::Texture bulletTexture;
        bulletTexture.loadFromFile("bullet.png");
        for (int j = 0; j <= 9; j++)
        {
            bullet[j].setRadius(10.0f);
            bullet[j].setTexture(&bulletTexture);
            bullet[j].setPosition(10000000.0f, 100000000000.0f);
        }
        int indexBullet = 0;

        window.setFramerateLimit(60);

        sf::Texture playerTexture;
        playerTexture.loadFromFile("Megaman.png");
        Player player(sf::Vector2f(100.0f, 100.0f), &playerTexture);

        sf::Texture enemyTexture;
        sf::Clock cdEnemy;
        sf::RectangleShape enemy[100];
        enemyTexture.loadFromFile("enemy.png");
        for (int j = 0; j <= 99; j++)
        { 
            enemy[j].setSize(sf::Vector2f(80.0f, 80.0f));
            enemy[j].setTexture(&enemyTexture);
        }
       
        int posx[10];
        for (int i = 0; i < 10; i++)
        {
            posx[i] = rand() % 15000;
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = i + 1; j<10 ; j++)
            {
                if (posx[j] < posx[i] + 2000)
                {
                    posx[j] = rand() % 10000;
                }
            }
        }
        
        
            
            


        /*sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));

        player.setTexture(&playerTexture);*/



        int cdUltiValue = 1;
        sf::Clock clockCdUltiValue;
        sf::RectangleShape cdUltimate(sf::Vector2f(400.0f, 50.0f));;
        sf::Texture cdUltiTexture;
        cdUltiTexture.loadFromFile("CDULTIMATE.PNG");
        cdUltimate.setTexture(&cdUltiTexture);
        cdUltimate.setPosition(0, 600);






        int HP = 100;
        sf::Font ARLRDBD;
        ARLRDBD.loadFromFile("8-BIT WONDER.TTF");
        std::ostringstream ssHP;
        ssHP << "HP| " << HP;

        sf::Text lblHP;
        lblHP.setCharacterSize(20);
        lblHP.setPosition({ 10 ,10 });
        lblHP.setFont(ARLRDBD);
        lblHP.setString(ssHP.str());

        const int groundHeight = 460;
        const float gravitySpeed = 10;
        player.setPosition(sf::Vector2f(0, groundHeight));
        while (window.isOpen())
        {


            sf::Event evnt;
            while (window.pollEvent(evnt))
            {
                if (evnt.type == sf::Event::Closed)
                    window.close();
            }
            sf::Time cdEnemySpawn = cdEnemy.getElapsedTime();

            sf::Time cdShoot = clockShoot.getElapsedTime();
            sf::Time cdUlti = clockUlti.getElapsedTime();
            sf::Time cdCdUltiValue = clockCdUltiValue.getElapsedTime();
            const float movespeed = 8;

            //JUMP
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && player.isJump() == false)
            {
                //player.move({ 0, -30.0f });
                player.setSpeedValue();
                player.setJump(1);

                sJump.play();
            }


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q) && indexUlti < 10 && ultivalue[indexUlti] == 0 && cdUltiValue == 1)
            {

                ultimate[indexUlti].setPosition(player.getPosition().x + 40, player.getPosition().y-80 );
                ultivalue[indexUlti] = 1;
                cdUltiValue = 0;
                sUlti.play();

                indexUlti++;
                if (indexUlti >= 10)
                    indexUlti = 0;
            }
            if (cdCdUltiValue.asSeconds() >= 10.0 && cdUltiValue == 0)
            {
                clockCdUltiValue.restart();
                cdUltiValue = 1;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E) && indexBullet < 10 && bulletvalue[indexBullet] == 0 && cdShoot.asSeconds() >= 0.2)
            {
                clockShoot.restart();
                bullet[indexBullet].setPosition(player.getPosition().x + 20, player.getPosition().y );
                bulletvalue[indexBullet] = 1;
                sAtk.play();
                indexBullet++;
                if (indexBullet >= 10)
                    indexBullet = 0;

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            {
                player.move({ -8.0f, 0.0f });
            }
            /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                player.move(0.0f, -8.0f);
            }
           if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                player.move(0.0f, +8.0f);
            }
            */
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            {
                player.move({ +8.0f, 0.0f });
            }

            if (player.getPosition().y < groundHeight && player.isJump() == false )
            {
                player.move({ 0 , gravitySpeed });
            }

            if (player.isJump() == true)
            {
                player.jump();
                if (player.getPosition().y > groundHeight)
                {
                    
                    player.setPosition(sf::Vector2f(player.getPosition().x, groundHeight));
                    player.setJump(0);
                }
            }


            

            //life move
            if (player.getPosition().x + 300 > screenDimensions.x / 2)
            {
                position.x = player.getPosition().x +695;
                life1.setPosition(position.x, 10);
            }

            if (player.getPosition().x + 300 > screenDimensions.x / 2)
            {
                position.x = player.getPosition().x + 645;
                life2.setPosition(position.x, 10);
            }

            if (player.getPosition().x + 300 > screenDimensions.x / 2)
            {
                position.x = player.getPosition().x + 595;
                life3.setPosition(position.x, 10);
            }

            //Hp move
            if (player.getPosition().x + 300 > screenDimensions.x / 2)
            {
                position.x = player.getPosition().x -150;
                lblHP.setPosition(position.x, 10);
            }

            //cdUlti move
            if (player.getPosition().x + 300 > screenDimensions.x / 2)
            {
                position.x = player.getPosition().x - 150;
                cdUltimate.setPosition(position.x, 600);
            }
            
                if (player.getPosition().x + 300 > screenDimensions.x / 2)
                {
                    position.x = player.getPosition().x + 300;

                }
                else
                {
                    position.x = screenDimensions.x / 2;
                }
                if (position.x + 455 > 16208)
                {
                    position.x = 15753;
                }
            
            view.setCenter(position);

            for (int i = 0; i <= 9; i++)
            {
                bullet[i].move(20.0f, 0.0f);
                if (bulletvalue[i] == 1)
                {

                    bulletvalue[i] = 0;
                }
            }
            for (int l = 0; l <= 9; l++)
            {
                ultimate[l].move(20.0f, 0.0f);
                if (ultivalue[l] == 1)
                {

                    ultivalue[l] = 0;
                }
            }
            for (int i = 0; i < 100; i++)
            {
                enemy[i].setPosition(posx[i], groundHeight-25);
            }
            


            //Player
            std::cout << player.getPosition().x << " " << player.getPosition().y << "\n";
            if (player.getPosition().x < 40)
            {
                player.setPosition(sf::Vector2f(40, player.getPosition().y));
            }
            if (player.getPosition().x > 16104 )
            {
                player.setPosition(sf::Vector2f(16104, player.getPosition().y));
            }
            //Collision
            Collider playerCollision = player.GetCollider();

            platform2.GetCollider().CheckCollision(playerCollision, 1.0f);
            if (player.getPosition().x > 250 && player.getPosition().x < 750  &&  player.getPosition().y == 225)
            {
                if (player.isJump() == true)
                {
                    player.jump();
                    if (player.getPosition().y > 235)
                    {

                        player.setPosition(sf::Vector2f(player.getPosition().x, 225));
                        player.setJump(0);
                    }
                }

            }
            

            player.update();

            window.clear();
            menu.draw(window);
            window.setView(view);
            window.draw(bImage);
            for (int k = 0; k <= 9; k++)
            {
                window.draw(ultimate[k]);
            }
            for (int k = 0; k <= 9; k++)
            {
                window.draw(bullet[k]);
            }
            if (cdUltiValue == 1)
            {
                window.draw(cdUltimate);
            }

            window.draw(life1);
            window.draw(life2);
            window.draw(life3);
            window.draw(lblHP);
           
            platform2.Draw(window);
           
         
            for (int i = 0; i < 10; i++)
            {
                if (player.getPosition().x  > screenDimensions.x / 2 )
                {
                    window.draw(enemy[i]);
                }
            }
           
            player.drawTo(window);
            window.setView(window.getDefaultView());
            window.display();

        }
    }


    return 0;
}