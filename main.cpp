#include "BrowserBackend.h"
#include "DesktopBackend.h"
#include "Backend.h"

int main() {
    Backend* b;
    #ifdef __EMSCRIPTEN__
    BrowserBackend bb;
    b= &bb;
    #else
    DesktopBackend db;
    b = &db;
    #endif
    b->initialize_context();
    b->init();
    b->do_main_loop();
    b->cleanup();
    return 0;
}
