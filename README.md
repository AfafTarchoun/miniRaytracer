# miniRT - My First RayTracer with miniLibX

![miniRT](minirt_image.jpg)

## Introduction

miniRT is a RayTracing project that allows you to generate Computer-Generated Images from different angles and positions. You will implement simple geometric objects and lighting systems to create stunning scenes.

## Requirements

- The project uses the miniLibX library. You can use the version available on your operating system or the sources provided. Make sure to follow the rules for your libft as specified in the Common Instructions part.
- The window management must be fluid, supporting window switching and minimization.
- Resizing the window should adjust the content accordingly.
- Geometric objects: The project should include at least three types - plane, sphere, and cylinder.
- Properly handle intersections and the inside of objects.
- Objects should be resizable. (from the file)
- Translation and rotation transformations can be applied to objects, lights, and cameras (except for spheres and lights that cannot be rotated).
- Implement Ambient and diffuse lighting for spot brightness, hard shadows, and ambiance lighting.
- The image should be displayed in a window, and the program must handle closing the window cleanly.

## Scene Description File

- The program takes a scene description file with the `.rt` extension as the first argument.
- Elements in the file can be separated by one or more line breaks.
- Each type of information for an element can be separated by one or more spaces.
- Elements can appear in any order within the file.
- Elements defined by a capital letter can only appear once in the scene.
- Each element is identified by a type identifier (one or two characters), followed by specific information in a strict order.

## Bonus 

For the bonus part, you can implement specular reflection to achieve a full Phong reflection model.

## Sample Images

Here are some sample images generated with miniRT:

### Basic Sphere

![Basic Sphere](basic_sphere.jpg)

### Basic Cylinder

![Basic Cylinder](basic_cylinder.jpg)

### Basic Plane

![Basic Plane](basic_plane.jpg)

### Two Spheres Intertwined

![Two Spheres Intertwined](two_spheres.jpg)

### Complex Scene

![Complex Scene](complex_scene.jpg)

## Getting Started

1. Clone the miniRT repository to your local machine:

```bash
git clone https://github.com/your-username/miniRT.git
cd miniRT
```
2. Compile the project using the provided Makefile and Run the program with a scene description file:

***for example***
```bash
make
./miniRT scenes/basic_sphere.rt
```
