#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include <string>

// Make it abstract cuz we can't know fo' shizzle
class GameState
{
public:
    virtual ~GameState() {}
    
    // Init the stat(ment)
    virtual void init() = 0;
    virtual void clean() = 0;
    
    // When state is first entered
    virtual bool onEnter() = 0;
    // When state exits
    virtual bool onExit() = 0;
    // Pause event called
    virtual void onPause() = 0;
    // Resume
    virtual void onResume() = 0;
    
    virtual void update(float deltatime) = 0;

    virtual void render() = 0;

    virtual std::string getStateID() const = 0;
};

#endif
