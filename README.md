# mmath

Last updated: Mar 5th, 2021

As mentioned in the description, this is my highly-optimized, C99 header-only/matrix vector math library, fully compatible with OpenGL / GLSL 3+ (I personally use 4.5).

The immediate question is: why write your own library? There are already math libraries out there, so why not use those?
This is a reasonable question, and the answer has quite a few parts to it.

## 1. Support for C
Simply put, GLM, one of the more commonly used libraries, is also header-only, but it is only compatible with C++. One of the most confusing things I faced when first
discovering OpenGL was the fact that I never saw a single tutorial/guide/reference that covered OpenGL using C, despite the fact that it's a C API. The reason for this, as I have come to learn, is that almost all of these resources use GLM as their vector/matrix math library, which immediately forces you to use C++ whether you like it or not. It also doesn't help that GLM, reasonably so, uses C++ features, ie, classes, namespaces, operator/function overloading, and templates (ESPECIALLY templates - I'll get to these later). As a result, you really don't have a choice when it comes to what language to use if you choose to use GLM. Now of course you can always just opt to write C-style C++, but the limitation on what language you have to use is still present.

## 2. Size / simplicity
GLM is a VERY big library (over 400 files!) because it supports numerous mathematical constructs, such as complex numbers and quaternions. Many of these constructs aren't required in my case, so it's a waste of space having to include them all in my project. Furthermore, many of these files are either i) empty  ii) filled with blank declarations  iii) just more #includes. This results in increased compile times, a polluted console output, and an unneccessary amount of bloat to my project, which I'd like to minimize as much as possible. By comparison, my library is only ~460 lines and only supports what __I__ need (vec2, vec3, mat4). Yes, of course this makes it a less powerful library, but the key point here is simplicity and ease of expansion when necessary.

## 3. GLM's complexity and template abuse
These two points tie together so I will address them as one. Simply put, GLM has some of the ugliest C++ template abuse I've ever seen, and I encourage anyone reading this to open up the GLM source code and just have a read through the code. There truly are templates everywhere, and in my case, it makes the code unnecessarily complex and hard to read since I only use floats for my vectors/matrices. That being said, there are cases in which it's more ideal/efficient to have vectors/matrices that use ints instead of floats, but I have yet to ever find myself in such a position.

Now, there is another library called CGLM that addresses many of the issues I've outlined above: it's written in C, it's much smaller and conciser, and it's easier to understand. However, there is still additional, unneccessary overhead in my opinion, and it supports a lot more mathematical constructs that I don't need. But regardless of these improvements that CGLM makes, it will NEVER change the final reason I have below.

## 4. Do it yourself
I like writing C code, and I find the idea of developing my own tools/libraries to be something very fun. I've had a lot of fun developing this library over the past few months, as well and there is a strong sense of joy in seeing it work perfectly whenever I test it. It's taught me a lot about how to design, write, and optimize tools like this, which I think is a very valuable skill for any programmer. It's also nice having something that I can easily integrate into future projects, as well as the understanding all the code that I write/use.
