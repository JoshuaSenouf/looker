Looker
======

Looker is a C++/Vulkan rendering engine that aimed to achieve physically-based rendering.          to be
This project is currently serving as a learning sandbox for Vulkan. A possible outcome would be a software that would be used as a Look Dev tool.

Ideally, the tool would support Pixar USD for scene description, and an interactive rendering mode using Pixar Renderman (or maybe my own Tracer project).

How to use
------

Looker was written using Linux, QtCreator as the IDE, CMake as the building tool, and a C++11 compiler in mind.

Download the source, make sure that the environmnent variable "VULKAN_SDK" exists, build the project structure using CMake 3.x, open the project using your favorite IDE (tested on QtCreator), build the project, and everything should be ready to use.

Dependencies (included, aside from the LunarG Vulkan SDK)
------

- Window & Input system : GLFW
- Mathematic library : GLM
- GUI system : dear imgui
- Mesh Loading : tinyobjloader
- Image loading : stb
