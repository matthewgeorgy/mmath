# MMath

Last updated: Apr 11th, 2021

As mentioned in the description, this is my highly-optimized, C99 header-only/matrix vector math library, fully compatible with OpenGL / GLSL 3+ (I personally use 4.5).

Reasons for writing my own library (when plenty out there already exist):

## 1. Support for C
GLM is one of the more commonly used libraries (which I will focus on here), is also header-only, but it is only compatible with C++. One of the most confusing things I faced when first learning OpenGL was the fact that I never saw a single tutorial/guide/reference that covered OpenGL using C, despite the fact that it's a C API. The reason for this, as I have come to learn, is that almost all of these resources use GLM as their vector/matrix math library, which immediately forces you to use C++ whether you like it or not. It also doesn't help that GLM, reasonably so, uses C++ features, ie, classes, namespaces, operator/function overloading, and templates (ESPECIALLY templates - I'll get to these later). As a result, you really don't have a choice when it comes to what language to use if you choose to use GLM. Now of course you can always just opt to write C-style C++, but the limitation on what language you have to use is still present.

## 2. Size / simplicity
GLM is a VERY big library (over 400 files!) because it supports numerous mathematical constructs, such as complex numbers and quaternions. Many of these constructs aren't required in my case, so it's a waste of space having to include them all in my project. Furthermore, many of these files are either i) empty  ii) filled with blank declarations  iii) just more #includes. This results in increased compile times, a polluted console output, and an unneccessary amount of bloat in my projects, which I'd like to minimize as much as possible. By comparison, my library is only ~500 lines and only supports what __I__ need (vec2, vec3, mat4, utility funcs). Yes, of course this makes it a less powerful library, but the key point here is simplicity and ease of expansion when necessary. I also don't really like the syntax/naming schemes that GLM uses for its functions.

## 3. GLM's complexity and template abuse
These two points tie together so I will address them as one. Simply put, GLM has some of the ugliest C++ template abuse I've ever seen, and I encourage anyone reading this to open up the GLM source code and just have a read through the code. This makes the code unnecessarily bloated in my case since I only using floats for my vectors/matrices. That being said, there are cases in which it's more ideal/efficient to have vectors/matrices that use ints instead of floats, but I have yet to ever find myself in such a position.

Now, there is another library called CGLM that addresses many of the issues I've outlined above: it's written in C, it's much smaller and conciser, and it's easier to understand. However, there is still additional, unneccessary overhead in my opinion, and it supports a lot more mathematical constructs that I don't need. But regardless of these improvements that CGLM makes, it will NEVER change the final reason I have below.

## 4. Do it yourself
I like writing C code, and I find enjoyment in developing my own libraries/tools/utilities etc. Writing my own library means I have full control over it, so I can optimize it as I see fit, and I can design it the way I want (ie. syntax/naming conventions that I mentioned earlier). It's been a very rewarding experience so far and it's taught me a lot about how to develop my own libraries. It's also nice having something that I can easily integrate into future projects, as well as the understanding all the code that I write/use.
