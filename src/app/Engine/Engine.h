#ifndef ENGINE_H
#define ENGINE_H

#include "Managers/WindowManager.h"
#include "Managers/CommunicationManager.h"



class Engine{
public:
    static Engine* instance();

    void init();

    void start(int argc, char* argv[]);

     CommunicationManager* getCommunicationManager() const;

private:
    Engine() = default;
    ~Engine() = default;
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;
    static Engine* m_instance;

    std::unique_ptr<WindowManager> m_WindowManager;
    std::unique_ptr<CommunicationManager> m_CommunicationManager;
};

#endif // ENGINE_H
