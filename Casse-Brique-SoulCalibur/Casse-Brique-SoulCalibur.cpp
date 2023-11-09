// Casse-Brique-SoulCalibur.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
//#include "Ball.h"
//#include "Brick.h"
#include "Window.h"
#include <SFML/System.hpp>


int main(int argc, char** argv)
{
    //création de la fenetre
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");

    //creation d'une balle de jeu
    GameObject oBall(200.f, 200.f, 10.f);

    //Création d'un rectangle 
    sf::RectangleShape oRectangle(sf::Vector2f(100.f, 20.f));
    //la position 
    oRectangle.setPosition(100.f, 100.f);
    //Et la couleur 
    oRectangle.setFillColor(sf::Color::Red);

    //Création d'un rectangle 
    sf::RectangleShape oRectangle1(sf::Vector2f(100.f, 20.f));
    //la position 
    oRectangle1.setPosition(350.f, 580.f);
    //Et la couleur 
    oRectangle1.setFillColor(sf::Color::Blue);

    // Création d'un canon
    //sf::RectangleShape aRectangle(sf::Vector2f(20.f, 100.f));
    //la position
    //aRectangle.setPosition(100.f, 100.f);
    // et la couleur
    //aRectangle.setFillColor(sf::Color::Red);



    sf::Clock oClock;
    float deltaTime = 0;
    //GameLoop
    while (window.isOpen())
    {
        //EVENT
        sf::Event oEvent;
        while (window.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                window.close();

            /*else if (oEvent.type == sf::Keyboard::)
            {

            }*/
        }

        //UPDATE

        oBall.move(deltaTime);

        /* 
        
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            oRectangle1.move(0.f, -1.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            oRectangle1.move(-1.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            oRectangle1.move(0.f, 1.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            oRectangle1.move(1.f, 0.f);

            */


        /*
           sf::Vector2i globalPosition = sf::Mouse::getPosition();//je recupere la position du sprite

            oRectangle1.setOrigin(10.f, 30.f);
            float angle = atan2(globalPosition.y - oRectangle1.getPosition().y, globalPosition.x - oRectangle1.getPosition().x);//calcule de l'angle
            angle = angle * 180 / 3.14159265358979323846;//convertir en degres
            float angle2 = angle;
            angle = std::min(maxAngle, std::max(minAngle, angle));
            oRectangle1.setRotation(angle);

            if (angle2==angle)
            {
                oRectangle1.setRotation(angle);
            }
        */



        //DRAW
        window.clear();

        oBall.draw(window);


        window.draw(oRectangle);
        window.draw(oRectangle1);
        //oWindow.draw(aRectangle);

        window.display();

        deltaTime = oClock.restart().asSeconds();
    }

    return 0;
}



// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
