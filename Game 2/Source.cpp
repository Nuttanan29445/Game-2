#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include "Platform.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemyfly.h"
#include "bulletEnemy.h"
#include <vector>
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
        sf::RectangleShape platform1;
        platform1.setSize(sf::Vector2f(400.0f, 50.0f));
        sf::Texture platform1Texture;
        platform1Texture.loadFromFile("platform.PNG");
        platform1.setTexture(&platform1Texture);
        platform1.setPosition(300.0f, 275.0f);
        
        sf::RectangleShape platform2;
        platform2.setSize(sf::Vector2f(200.0f, 50.0f));
        sf::Texture platform2Texture;
        platform2Texture.loadFromFile("platform.PNG");
        platform2.setTexture(&platform1Texture);
        platform2.setPosition(1900.0f, 275.0f);

        sf::RectangleShape platform3;
        platform3.setSize(sf::Vector2f(300.0f, 50.0f));
        sf::Texture platform3Texture;
        platform3Texture.loadFromFile("platform.PNG");
        platform3.setTexture(&platform1Texture);
        platform3.setPosition(2800.0f, 175.0f);

        sf::RectangleShape platform4;
        platform4.setSize(sf::Vector2f(400.0f, 50.0f));
        sf::Texture platform4Texture;
        platform4Texture.loadFromFile("platform.PNG");
        platform4.setTexture(&platform1Texture);
        platform4.setPosition(4850.0f, 275.0f);


        sf::RectangleShape platform5;
        platform5.setSize(sf::Vector2f(200.0f, 50.0f));
        sf::Texture platform5Texture;
        platform3Texture.loadFromFile("platform.PNG");
        platform5.setTexture(&platform1Texture);
        platform5.setPosition(6750.0f, 275.0f);


        sf::RectangleShape platform6;
        platform6.setSize(sf::Vector2f(300.0f, 50.0f));
        sf::Texture platform6Texture;
        platform6Texture.loadFromFile("platform.PNG");
        platform6.setTexture(&platform1Texture);       
        platform6.setPosition(8500.0f, 275.0f);



        std::vector<Platform> platforms;
        std::vector<Platform> platforms1;

        platforms.push_back(Platform(&platform6Texture, sf::Vector2f(400.0f, 50.0f), sf::Vector2f(500.0f, 300.0f)));
        platforms.push_back(Platform(&platform6Texture, sf::Vector2f(200.0f, 50.0f), sf::Vector2f(2000.0f, 300.0f)));
        platforms.push_back(Platform(&platform6Texture, sf::Vector2f(300.0f, 50.0f), sf::Vector2f(2950.0f, 200.0f)));
        platforms.push_back(Platform(&platform6Texture, sf::Vector2f(400.0f, 50.0f), sf::Vector2f(5050.0f, 300.0f)));
        platforms.push_back(Platform(&platform6Texture, sf::Vector2f(200.0f, 50.0f), sf::Vector2f(6850.0f, 300.0f)));
        platforms.push_back(Platform(&platform6Texture, sf::Vector2f(300.0f, 50.0f), sf::Vector2f(8650.0f, 300.0f)));
        platforms.push_back(Platform(&platform6Texture, sf::Vector2f(300.0f, 50.0f), sf::Vector2f(10050.0f, 300.0f)));
        platforms.push_back(Platform(&platform6Texture, sf::Vector2f(300.0f, 50.0f), sf::Vector2f(12550.0f, 300.0f)));
        platforms.push_back(Platform(&platform6Texture, sf::Vector2f(300.0f, 50.0f), sf::Vector2f(13850.0f, 300.0f)));
        platforms.push_back(Platform(&platform6Texture, sf::Vector2f(300.0f, 50.0f), sf::Vector2f(15550.0f, 300.0f)));
        platforms.push_back(Platform(&platform6Texture, sf::Vector2f(300.0f, 50.0f), sf::Vector2f(16650.0f, 300.0f)));
        
        
        //ground&ceiling
        platforms1.push_back(Platform(nullptr, sf::Vector2f(40000.0f, 100.0f), sf::Vector2f(500.0f, -80.0f)));
        platforms1.push_back(Platform(nullptr, sf::Vector2f(40000.0f, 200.0f), sf::Vector2f(500.0f, 610.0f)));
        
   

        sf::Vector2i screenDimensions(910, 650);
        sf::RenderWindow window;
        window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "SFML works!",sf::Style::Close);


     


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

        /*sf::Texture playerTexture;
        playerTexture.loadFromFile("Megaman.png");
        Player player(sf::Vector2f(100.0f, 100.0f), &playerTexture);*/

        sf::Texture playerTexture;
        playerTexture.loadFromFile("playerrock.png");
        Player player(&playerTexture, sf::Vector2u(3,3), 0.3f, 500.0f , 300.0f);
        float deltaTime = 0.0f;
        sf::Clock clock;

        //enemy
        std::vector<Enemy*> enemy;
        int posx[10];
        for (int i = 0; i <= 14; i++)
        {
            if (posx[i] < 3000)
            {
                posx[i] = rand() % 15000;
            }
        }
       
        

        sf::Texture enemyTexture;
        enemyTexture.loadFromFile("Enemy-Sprite.png");
        for (int i = 0; i <= 14; i++)
        enemy.push_back(new Enemy(&enemyTexture, sf::Vector2u(3, 2),0.3f,100.0f, sf::Vector2f(posx[i], 480.0f)));
         float dt = 0.0f;   
         sf::Clock clock1;
         //enemyfly
         std::vector<Enemyfly*> enemyfly;
         int posix[10];
         for (int i = 0; i <= 14; i++)
         {
             if (posix[i] < 3000)
             {
                 posix[i] = rand() % 15000;
             }
         }
        
         
       

         sf::Texture enemyflyTexture;
         enemyflyTexture.loadFromFile("enemy-spritefly.png");
         for (int i = 0; i <= 14; i++)
             enemyfly.push_back(new Enemyfly(&enemyflyTexture, sf::Vector2u(4, 1), 0.3f, 200.0f, sf::Vector2f(posix[i], 275.0f)));
         float dti = 0.0f;
         sf::Clock clock2;
         
         //bullet 
         std::vector<bulletEnemy*> bulletPlayer;

        

        
       
        
        //Jump
        sf::Sprite jumpSprite;
        sf::Texture jumpTexture;
        sf::Vector2u jumpTexturesize = jumpTexture.getSize();
        int jumpTextureCount = 0;
        jumpTexture.loadFromFile("JUMPPlayer.png");

        jumpTexturesize.x /= 4;
        jumpTexturesize.y /= 1;
        jumpSprite.setTexture(jumpTexture);
        jumpSprite.setTextureRect(sf::IntRect(0, 0, jumpTexturesize.x, jumpTexturesize.y));
        
        
       
        
       
        /*float enemySpeed = 2;
        sf::Texture enemyTexture;
        sf::Clock cdEnemy;
        sf::RectangleShape enemy[100];
        enemyTexture.loadFromFile("enemy.png");
        for (int j = 0; j <= 99; j++)
        { 
           
            enemy[j].setSize(sf::Vector2f(80.0f, 80.0f));
            enemy[j].setTexture(&enemyTexture);
        }
        
        
        for (int i = 0; i < 10; i++)
        {
            posx[i] = rand() % 15000;
        }
        for (int i = 0; i < 10; i++)
        
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
        for (int i = 0; i < 10; i++)
        enemy[i].setPosition(posx[i], 435);
        int bulletenemyvalue[10] = {};
        
        sf::CircleShape bulletEnemy[10];
        sf::Texture bulletEnemyTexture;
        bulletEnemyTexture.loadFromFile("bullet.png");
        for (int j = 0; j <= 9; j++)
        {
            bulletEnemy[j].setRadius(10.0f);
            bulletEnemy[j].setTexture(&bulletTexture);
            bulletEnemy[j].setPosition(posx[j], 435);
        }
       */

        
        
            
            


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

        const int groundHeight = 40;
        int  hpEnemy = 2;
        //const float gravitySpeed = 10;*/
        while (window.isOpen())
        {
            
            int randomTime, r;
            srand(time(NULL));
            r = rand() % 2;

            deltaTime = clock.restart().asSeconds();
            dt = clock1.restart().asSeconds();
            dti = clock2.restart().asSeconds();
            /*if (deltaTime > 1.0f / 20.0f)
                deltaTime = 1.0f / 20.0f;*/

            sf::Event evnt;
            while (window.pollEvent(evnt))
            {
                if (evnt.type == sf::Event::Closed)
                    window.close();
           }
            //sf::Time cdEnemySpawn = cdEnemy.getElapsedTime();*/

            sf::Time cdShoot = clockShoot.getElapsedTime();
            sf::Time cdUlti = clockUlti.getElapsedTime();
            sf::Time cdCdUltiValue = clockCdUltiValue.getElapsedTime();
            const float movespeed = 8;
            
            


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

    
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E) && cdShoot.asSeconds() >= 0.2)
            {
                clockShoot.restart();
                sAtk.play();
                if (player.getFaceRight() == true)
                    bulletPlayer.push_back(new bulletEnemy(&bulletTexture, 20.f, player.getPosition().x, player.getPosition().y, 1.0f, 0.0f));
                if (player.getFaceRight() == false)
                    bulletPlayer.push_back(new bulletEnemy(&bulletTexture, 20.f, player.getPosition().x, player.getPosition().y, -1.0f, 0.0f));
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
            position.x = player.getPosition().x - 150;
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

            //bullet&Ultimate
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



            //Player
            // std::cout << player.getPosition().x << " " << player.getPosition().y << "\n";
            if (player.getPosition().x < 40)
            {
                player.setPosition(40, player.getPosition().y);
            }
            if (player.getPosition().x > 16104)
            {
                player.setPosition(16104, player.getPosition().y);
            }
            player.Update(deltaTime);
            
            for (auto* bullet : bulletPlayer)
                bullet->Update();


            //Collision
            Collider playerCollision = player.GetCollider();
            sf::Vector2f direction;
            for (Platform& platform : platforms)
            {
                if (platform.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
                {
                    player.onCollision(direction);
                }

            }
            sf::Vector2f direction1;
            for (Platform& platform : platforms1)
            {
                if (platform.GetCollider().CheckCollision(playerCollision, direction1, 1.0f))
                {
                    player.onCollision(direction1);
                }

            }
            //enemy
            int counter = 0;
            for (auto* i : enemy)
            {
                for (auto* bullet : bulletPlayer)
                {
                    if (i->GetGlobalBounds().intersects(bullet->GetGlobalBounds()))
                    {
                        i->setHP(1);

                        bullet->setPosition(-50.0f, -50.0f);
                        if (i->getHP() <= 0)
                        {
                            delete enemy.at(counter);
                            enemy.erase(enemy.begin() + counter);
                            counter--;
                        }
                        std::cout << enemy.size() << std::endl;

                    }
                }
                counter++;
            }

            
           
            for (auto* i : enemy)
                i->Update(dt, &player);
           //enemyfly
         
            for (auto* k : enemyfly)
            {
                for (int j = 0; j <= 9; j++)
                {
                    if (k->GetGlobalBounds().intersects(bullet[j].getGlobalBounds()))
                    {


                        bullet[j].setPosition(-50.0f, -50.0f);

                        k->setPosition(-200.0f, -200.0f);


                    }

                }
                if (k->getPosition().y < 100)
                {
                    /*for (int j = 0; j <= 9; j++)*/
                        k->setPosition(k->getPosition().x, 100);
                        
                }
                if (k->getPosition().y > 375)
                {
                    /*for (int j = 0; j <= 9; j++)*/
                        k->setPosition(k->getPosition().x, 375);
                }
            }
            
            for (auto* k : enemyfly)
                k->Update(dti);

            
           // for (int i = 0; i < 10; i++)
           // {
           //     if (player.getPosition().x + 700 > enemy[i].getPosition().x )
           //     {
           //         
           //         for (int j = 0; j <= 3; j++)
           //         {
           //                 bulletEnemy[i].move(-5.0f, 0.0f);
           //         }
           //        
           //         
           //         
           //         
           //         /*
           //         clockShootEnemy.restart();
           //         for (int i = 0; i < 10; i++)
           //         bulletEnemy[i].move(-20.0f, 0.0f);*/
           //     }
           //        
           //        
           // }
           // //for (int i = 0; i < 10; i++)
           // //{
           // //    if (bulletenemyvalue[i] == 1 /*&& cdShootEnemy.asSeconds() >= 0.2*/)
           // //    {
           // //        /*clockShootEnemy.restart();*/
           // //        bulletEnemy[i].move(-20.0f, 0.0f);
           // //    }
           // //    bulletenemyvalue[i] == 0;
           // //}
           // 
           ///* for (int i = 0; i < 10; i++)
           // if (bulletenemyvalue[i] == 1 && cdShootEnemy.asSeconds() >= 0.2)
           // {
           //     clockShootEnemy.restart();
           //     for (int i = 0; i <= 9; i++)
           //     {
           //         bulletEnemy[i].move(-20.0f, 0.0f);
           //         
           //     }
           //     bulletenemyvalue[i] == 0;
           // }*/
           // 
            //jump
            jumpSprite.setPosition(player.getPosition().x, player.getPosition().y);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                jumpSprite.setTextureRect(sf::IntRect(jumpTextureCount * jumpTexturesize.x, jumpTexturesize.y * 0, jumpTexturesize.x, jumpTexturesize.y));
            }


            
            view.setCenter(position);
           

            window.clear();
            /*menu.draw(window);*/
            
            window.setView(view);
            
            
            
            for (Platform& platform : platforms1)
            {
                platform.Draw(window);
            }
           window.draw(bImage);
            
           
            if (cdUltiValue == 1)
            {
                window.draw(cdUltimate);
            }
           
             
            for (Platform& platform : platforms)
            {
                platform.Draw(window);
            }
            window.draw(life1);
            window.draw(life2);
            window.draw(life3);
            window.draw(lblHP);
            
            
            
            player.Draw(window); 
            /*for (int k = 0; k <= 9; k++)
            {
                window.draw(bullet[k]);
            }*/
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            window.draw(jumpSprite);
           /* for (int k = 0; k <= 9; k++)
            {
                window.draw(bulletEnemy[k]);
            }*/
            for (auto* bullet : bulletPlayer)
                bullet->Render(window);
            for (int k = 0; k <= 9; k++)
            {
                window.draw(ultimate[k]);
            } 
           
            /*if (player.getPosition().x + 500 > screenDimensions.x / 2)
            {
                for (int k = 0; k <= 9; k++)
                    window.draw(enemy[k]);

            }*/
            for (auto* i : enemy)
                i->Draw(window);
            for (auto* k : enemyfly) 
                k->Draw(window);

            
           
            
            
            //player.drawTo(window);
            window.setView(window.getDefaultView());
            window.display();

        }
    }


    return 0;
 }