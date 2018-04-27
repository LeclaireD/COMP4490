Daniel Leclaire A1 COMP 4490
Below is a list of completed criteria of the assignment

sphere intersection 
triangle intersection (for meshes) 
Phong illumination model (non-recursive)
multiple light sources, including both directional and point
two additional scene files
Below is a list of incomplete criteria for the assignment

box intersection (Kay-Kajiya)
distance attenuation
shadow attenuation
transmission and refraction
recursive ray tracing (reflection and refraction)
one acceleration technique
additional features (see below)

One of the main choices I made was to make the assignment Object Oriented. Meaning all shapes (Triangle, Sphere, etc.) were children of a purely virtual 
Abstract class called Shape to avoid problems later down the line with the different calculations needed for differentshapes. Likewise with Lights, 
directional lights, and point lights were both children of the Lights class. Another decision was to make a somewhat custom List class for both Shapes 
and Lights, to more easily add them into the scene. Therefor instead of instantiating ashape like so (Sphere test = Sphere();), it was done as such 
(Shape* test = new Sphere();). Then adding them to the list was easy, all that was needed was to call list.add(object), and the object was now in the list. 
That being said, the scene had to be hard coded into the example.cpp file in order for it to actually function, instead of reading in a .ray file. The scene 
that I tested with was one with 2 spheres and a triangle, the spheres of largely different radiuses, positioned on opposite sides of the window. The colours 
of the spheres and triangle were different as well to better observe changes.  No shortcuts were made in the code as far as I’m aware, although the 
calculation for the diffuse and specular illumination for triangles wouldn’t display properly, as I was unsure how calculate the normal of the triangle with 
respect to the position of the camera. Another issue that I came across was the order of which we applied the specular and diffuse lighting to the object, 
initially the values were exceeding the max of 255, so they needed to be clamped at 255, instead of exceeding it and causing odd things to display. Another 
thing that seemed to happen with the point lights, is that when they were moved very close to the sphere (or possibly inside of it?) it caused there to be 
twice as many shine points as there were point lights in the scene, I’m not sure if this is something expected or intended, or if it was just an issue with 
my code. One thing that made working with the code easier was the abundance of classes and .h files.  It helped me avoid the confusion when working 
with multiple objects, i.e. Rays, Vectors, Spheres, Triangles, Lights, Lists, etc… which in turn saved me a lot of headache when attempting to debug 
(although initially working with the purely virtual class was causing many, many issues).  Things such as shininess, or attenuation were confusing for 
me to figure out, and all in all, I just ran out of time to complete them. I’m unsure if my results with diffuse and specular lighting are ideal, but 
when comparing my output to that of others there seemed to be little to no difference. Something that was modified late in development of the program 
was exactly how ambient light worked. Initially, if ambient light didn’t exist, or was set to 0, the objects would just turn out completely black, even 
if lights were in the scene. This was due to me multiplying the ambient light by the colour of the object immediately, and then applying the diffuse and 
specular lighting effects, instead of adding the ambient light to the result of the sum of all diffuse and specular light calculations, and then multiplying 
the objects colour by those scalars. This made it much easier to apply the light’s intensity, and colour filter into the calculation of the object’s colour. 
