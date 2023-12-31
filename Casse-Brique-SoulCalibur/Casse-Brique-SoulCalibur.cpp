// Casse-Brique-SoulCalibur.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Ball.h"
#include "Brick.h"
#include "Canon.h"


int main(int argc, char** argv)
{
    //création de la fenetre
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");

    int balles_max = 20;
    std::cout << "tu as " << balles_max << " balles maximum, detruits tous les blocs." << std::endl;
    std::cout << "appuie sur clic gauche pour tirer avec le canon" << std::endl;

    //liste des balles
    std::vector <Ball> oBalls; 

    //Liste des blocks
    std::vector <Brick> oBricks;

    Brick oBrick(100.f, 100.f, 60.f, 20.f, sf::Color::Red, 1);
    oBricks.push_back(oBrick);

    Brick oBrick2(200.f, 100.f, 60.f, 20.f, sf::Color::Red, 2);
    oBricks.push_back(oBrick2);

    Brick oBrick3(300.f, 100.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick3);

    Brick oBrick4(400.f, 100.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick4);

    Brick oBrick5(500.f, 100.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick5);

    Brick oBrick6(100.f, 150.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick6);

    Brick oBrick7(200.f, 150.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick7);

    Brick oBrick8(300.f, 150.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick8);

    Brick oBrick9(400.f, 150.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick9);

    Brick oBrick10(500.f, 150.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick10);

    Brick oBrick11(100.f, 200.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick11);

    Brick oBrick12(200.f, 200.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick12);

    Brick oBrick13(300.f, 200.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick13);

    Brick oBrick14(400.f, 200.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick14);

    Brick oBrick15(500.f, 200.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick15);

    Brick oBrick16(600.f, 100.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick16);

    Brick oBrick17(700.f, 100.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick17);

    Brick oBrick18(600.f, 150.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick18);

    Brick oBrick19(700.f, 150.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick19);

    Brick oBrick20(600.f, 200.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick20);

    Brick oBrick21(700.f, 200.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick21);

    //creation du canon
    Canon oCanon(400.f, 600.f, 20.f, 100.f, sf::Color::Blue);

    float minAngle = -75.f;
    float maxAngle = 75.f;

    sf::Clock oClock;
    float deltaTime = 0;
    
    sf::Clock oDelayBallSpawn;

    //GameLoop
    while (window.isOpen())
    {
        //EVENT
        sf::Event oEvent; 
        while (window.pollEvent(oEvent)) 
        {
            if (oEvent.type == sf::Event::Closed) 
                window.close(); 
            if (oEvent.type == sf::Event::MouseButtonReleased)
            {
                if (oEvent.mouseButton.button == sf::Mouse::Left && (balles_max > 0) && (oDelayBallSpawn.getElapsedTime().asSeconds() > 0.5f))
                {
                    Ball oBall((oCanon.getPosition().x), (oCanon.getPosition().y) , 10.f, sf::Color::Green, 1);
                    oBall.setDirection(oCanon.getDirection().y, oCanon.getDirection().x);
                    oBalls.push_back(oBall);
                    balles_max = balles_max - 1;
                    std::cout << "Balles restantes : " << balles_max << std::endl;

                    oDelayBallSpawn.restart().asSeconds();
                }
                else if (balles_max <= 0)
                {
                    std::cout << "tu n'a plus de balles" << std::endl;
                }
                if (oEvent.mouseButton.button == sf::Mouse::Right)
                {
                    balles_max += 10;
                    std::cout << "triche activé, 10 balles en plus" << std::endl;
                }
            }
        }
        // UPDATE

        for (int i = 0; i < oBalls.size(); i++)
        {
            oBalls[i].moveBall(deltaTime);
            oBalls[i].rebondWithScreen();

            for (int j = 0; j < oBricks.size(); j++) //collisions et degats des bricks
            {
                if (oBalls[i].OnCollisionEnter(oBalls[i].getBallRect(), oBricks[j].getRectangleRect()) == 1) // gauche
                {
                    oBalls[i].rebondWithObj(oBalls[i], 1); 
                    oBricks[j].TakeDamage(); 
                }
                else if (oBalls[i].OnCollisionEnter(oBalls[i].getBallRect(), oBricks[j].getRectangleRect()) == 2) // haut
                {
                    oBalls[i].rebondWithObj(oBalls[i], 2); 
                    oBricks[j].TakeDamage();
                }
            }
            for (int k = 0; k < oBalls.size(); k++)  //collisions entre les balles
            {
                if (i != k)
                {
                    if (oBalls[i].OnCollisionEnter(oBalls[i].getBallRect(), oBalls[k].getBallRect()) == 1) // gauche
                    {
                        oBalls[i].rebondWithObj(oBalls[i], 1);
                    }
                    else if (oBalls[i].OnCollisionEnter(oBalls[i].getBallRect(), oBalls[k].getBallRect()) == 2) // haut
                    {
                        oBalls[i].rebondWithObj(oBalls[i], 2);
                    }
                }
            }
        }       

        for (int j = 0; j < oBricks.size(); j++)
        {
            if (oBricks[j].getLife() <= 0)
            {
                oBricks.erase(oBricks.begin() + j);
            }
        }
        
        int countBrick = 0;
        for (int i = 0; i < oBricks.size(); i++)
        {
            if (oBricks[i].getLife() > 0)
            {
                countBrick += 1; //compte les bricks encore présente
            }
        }
        if (countBrick == 0) //s'il n'y a plus de bricks => victoire
        {
            std::cout << "bravo, tu as gagné !";
            sf::sleep(sf::seconds(5));
            break;
        }
      
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window); 

        float angle = atan2(mousePosition.y - oCanon.getPosition().y, mousePosition.x - oCanon.getPosition().x);
        angle = angle * 180 / 3.14159 + 90; // Conversion en degrés
        float pastAngle = angle;
        angle = std::min(75.f, std::max(-75.f, angle));

        if (pastAngle == angle)
        {
            oCanon.setDirection(mousePosition.y - oCanon.getPosition().y, mousePosition.x - oCanon.getPosition().x);
            oCanon.setRotation(angle); // Rotation du canon
        }

        //DRAW
        window.clear();

        for (int i = 0; i < oBalls.size(); i++)
        {
            oBalls[i].drawCircle(window);
        }
        for (int i = 0; i < oBricks.size(); i++)
        {
            oBricks[i].drawRect(window);
        }

        oCanon.drawRect(window); 
        
        window.display();

        deltaTime = oClock.restart().asSeconds (); 
    }

    return 0;
}