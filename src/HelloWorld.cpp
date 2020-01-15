#include <cstdio>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../include/WindowManager.h"
#include "unistd.h" //testcase only

int main() {

  WindowManager* window_manager = new WindowManager(640, 480, 120, "First Window");
  window_manager->createDisplay(); 
  
  while(true) {
    window_manager->updateDisplay();
    usleep(500);
  }

  window_manager->closeDisplay();

	return 0;
}
