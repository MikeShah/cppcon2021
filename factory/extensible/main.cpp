// @directory data-driven
// g++ -std=c++17 main.cpp Factory.cpp -I./
#include <vector>
#include <memory>
#include <fstream>
#include <string>

#include "Factory.hpp"
#include "GameObjects.hpp"



// For fun, create a new type
class Ant : public IGameObject{
    public:
    Ant(int x,int y){ 
        ObjectsCreated++;
    }
    void ObjectPlayDefaultAnimation() { /* ... */}
    void ObjectMoveInGame() { /* ... */}
    void Update() { /* ... */}
    void Render() { /* ... */}
    static IGameObject* Create() {
        return new Ant(0,0);
    }
    private:
        static int ObjectsCreated;
};

int Ant::ObjectsCreated = 0;

int main(){
    // Register a Different type
    MyGameObjectFactory::RegisterObject("plane",Plane::Create);
    MyGameObjectFactory::RegisterObject("boat",Boat::Create);
    MyGameObjectFactory::RegisterObject("ant",Ant::Create);
    
    std::vector<IGameObject*> gameObjectCollection; 
    // Add the correct object to our collection
    // based on a .txt file
    std::string line;
    std::ifstream myFile("level1.txt");
    if(myFile.is_open()){
        while(std::getline(myFile,line)){
            // TODO: We'll have to iterate through 'all objects', but we can just
            //       match on the string of our objects from our configuration now.
            // FIXME: An exercise for the reader/viewer :)
            if(line=="plane"){
                gameObjectCollection.push_back(MyGameObjectFactory::CreateSingleObject("plane"));
            }
            /* You get the idea...
            else if(line==""){
            
            }
            */
        }
    }

    // Main Game Loop
    while(true){
        // Iterate through your game object
        // update them, run logic, etc.
        for(auto& e: gameObjectCollection){
            e->Update();
            e->Render();
        } 
    }

    return 0;
}
