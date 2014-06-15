#ifndef GAMELAYER_H
#define GAMELAYER_H
#include "object.h"
namespace SSJ{
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
        virtual void DrawLayer();
        size_t AmountOfObjects();
		vector <Object*>* getObjects() { return &objects; }
    };

    class LayerContainer{
        private:
        public:
            static map <string,GameLayer*> layers;
            static void AddGameLayer(GameLayer *);
            static GameLayer* GetGameLayer(string name);
    };
}

#endif // GAMELAYER_H
