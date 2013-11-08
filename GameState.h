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
    virtual void Init() = 0;
    virtual void Clean() = 0;
    
    // Self explained, mandatory comments
    virtual void Pause() = 0;
    virtual void Resume() = 0;
    
    // This thingy handles events and the other one updates the game state
    void Events();
    void Update(float deltatime);
    
    void Draw();
}