#ifndef OBJECT_H
#define OBJECT_H
#include "Loader.h"
namespace SSJ{


    class Object
    {
    protected:

        Point mapPosition;
        Sprite sprite;

        /*for synchronization by server*/
        Point screenPosition;
        bool activity;

    public:
        void AddAction(sf::Event::EventType, Object*,  ActionEvent);
        void AddActionKeyboard(sf::Event::EventType, sf::Keyboard::Key, Object* ,ActionEvent);
    public:
        Object();
        Object(double x, double y);
        Object(Point);
        Point getMapPosition();
        void setMapPosition(double x, double y);
        void setMapPosition(Point screenPosition);
        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void SynchronizationObject(Json::Value) = 0;
        void setActivity(bool activity);
        bool isActive();
    };

	    class GameLayer
    {
    private:
        string name;
        vector <Object*> objects;
        bool dynamic;


    public:
        GameLayer(string name);
        GameLayer(string name , bool dynamic);
        string getName() const;
        void setName(string value);
        void addObject(Object *object);
        bool isEmpty() const;
        bool isDynamic() const;
        void setDynamic(bool value);
        void UpdateLayer();
        void DrawLayer();
        size_t AmountOfObjects();
    };

			class LayerContainer{
	public:
		static GameLayer* warstwa3;
	};
}
#endif // OBJECT_H
