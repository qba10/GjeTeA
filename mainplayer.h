#ifndef MAINPLAYER_H
#define MAINPLAYER_H
#include "player.h"
#include "WeaponFactory.h"
namespace SSJ{
    class MainPlayer : public Player
    {
    private:
        bool moveLeft;
        bool moveRight;
        bool moveForward;
        bool moveBackward;
		int currentWeaponIndex;
	protected:
		Weapon* weapon1;
		vector <Weapon*> equipWeapon;
    public:
        MainPlayer();
		void eventMouseButtonPressed(sf::Event event);
		void eventMouseButtonReleased(sf::Event event);
		void eventMouseMoved(sf::Event event);
        void eventStartMoveForward(sf::Event event);
        void eventStartMoveBackward(sf::Event event);
        void eventStartMoveLeft(sf::Event event);
        void eventStartMoveRight(sf::Event event);
        void eventStopMoveForward(sf::Event event);
        void eventStopMoveBackward(sf::Event event);
        void eventStopMoveLeft(sf::Event event);
        void eventStopMoveRight(sf::Event event);
		void eventReload(sf::Event event);
		void eventMouseWheel(sf::Event event);

		bool getMoveLeft() const;
        void setMoveLeft(const bool value);
        bool getMoveRight() const;
        void setMoveRight(const bool value);
        bool getMoveForward() const;
        void setMoveForward(const bool value);
        bool getMoveBackward() const;
        void setMoveBackward(const bool value);

        void draw();
        void update();
		Weapon* getWeapon1();
		Weapon* getSelectedWeapon(int) const ;
		
        /* JSON:
         * {
         *      mapPositionX: "",
         *      mapPositionY: "",
         *      activity: "",
         *      hp: "",
         *      maxHP: "",
         *      angle: "",
         *      targetAngle: "",
         *      velocity: ""
         *
         * }
         */
        void SynchronizationObject(Json::Value);
        Json::Value SerializeMainPlayer();
    };
}

#endif // MAINPLAYER_H
