
#include "platform/browser/PlatformBrowser.hpp"
#include "platform/desktop/PlatformDesktop.hpp"
#include "Image.hpp"
#include "Shader.hpp"
#include "Mesh.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include "Camera.hpp"

#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

Platform * global_backend = nullptr;


glm::mat4 calculateMvpMatrix(const Camera & camera) {

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f));
    model = glm::scale(model, glm::vec3(1.0f));
    model = glm::rotate(model, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));


    glm::mat4 view = camera.getView();
	auto window_size = global_backend->window->get_window_size();
    glm::mat4 projection = glm::perspective(glm::radians(30.0f),
        window_size.x/ window_size.y, 0.1f, 100.0f);

    return projection * view * model;
}
void do_game() {

    Shader shader = Shader(
        global_backend->resolve_asset_path("shader.vert"),
        global_backend->resolve_asset_path("shader.frag")
        );

	Mesh mesh = Mesh("monkey.glb" );
	glEnable(GL_DEPTH_TEST);
	Camera camera;

    global_backend->do_main_loop(
    [&]() {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    	camera.processInput(dynamic_cast<GlfwWindow &>(*global_backend->window));
    	auto mvp = calculateMvpMatrix(camera);
    	shader.pass_uniform("mvp", mvp);
        shader.use();
		mesh.draw();

        global_backend->window->update();
    }
    );

}
int main() {
#ifdef __EMSCRIPTEN__
    static PlatformBrowser backend;
#else
    static PlatformDesktop backend;
#endif
    global_backend = &backend;
    do_game();
    return 0;
}
