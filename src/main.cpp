#include"Render/Player.h"
#include"Shaders/Shader.h"

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

   
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        return -1;

    Player player;
    Shader shader("src/Shaders/default_vertex.vert", "src/Shaders/default_fragment.frag");
   
    while (!glfwWindowShouldClose(window))
    {  
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        player.Input(window);
        player.Draw(shader.program);
        

        glfwSwapBuffers(window);      
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}