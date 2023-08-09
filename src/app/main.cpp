#include "Engine/Engine.h"

int main(int argc, char* argv[]) {
    Engine* engine = Engine::instance();
    engine->init();
    engine->start(argc, argv);

    return 0;
}
