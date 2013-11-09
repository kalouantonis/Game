#include <string>

// Make it abstract cuz we can't know fo' shizzle
class GameState
{
private:
    std::string desc;
    bool isPaused;
  
public:
    GameState(std::string);
    
    // Init the stat(ment)
    virtual void init() = 0;
    virtual void clean() = 0;
    
    // We'll use the same function for pausing and unpausing
    virtual void pause() = 0;
    
    virtual void onExit() = 0;
    virtual void onPause() = 0;
    
    // handle events, and update on specified cycles
    virtual void eventHandler();
    virtual void update(float deltatime) = 0;
    
    ~GameState() {}
}