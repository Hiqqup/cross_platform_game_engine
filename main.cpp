#include "BrowserBackend.h"
#include "DesktopBackend.h"

Backend* global_backend = nullptr;
int main() {
#ifdef __EMSCRIPTEN__
    BrowserBackend backend;
#else
    DesktopBackend backend;
#endif
    global_backend = &backend;

    global_backend->initialize_context();
    global_backend->setup_main_loop_cleanup();
    return 0;
}
