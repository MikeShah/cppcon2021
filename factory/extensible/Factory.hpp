#ifndef FACTORY_HPP
#define FACTORY_HPP
// @directory extensible
#include <memory>
#include <map>
#include <string>

// Declare our one interface type
class IGameObject;

// One change is that I have removed our 'enum class'
// This is because during run-time I want to be able to
// create different types
class MyGameObjectFactory{
    public:
        // Callback function for creating an object
        typedef IGameObject *(*CreateObjectCallback)();
        // Register a new user created object type
        // Again, we also have to pass in how to 'create' an object.
        static void RegisterObject(const std::string& type, CreateObjectCallback cb){
            s_Objects[type] = cb;
        }
        // Unregister a user created object type
        // Remove from our map
        static void UnregisterObject(const std::string& type){
            s_Objects.erase(type);
        }
        // Our Previous 'Factory Method'
        //
        static IGameObject* CreateSingleObject(const std::string& type){
            CallBackMap::iterator it = s_Objects.find(type);
            if(it!=s_Objects.end()){
                // Call the callback function
                return (it->second)();
            }
            return nullptr;
        }
    private:
        // Convenience typedef
        typedef std::map<std::string, CreateObjectCallback> CallBackMap;
        // Map of all the different objects that we can create
        static CallBackMap s_Objects; 
};

#endif

