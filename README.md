# mmath
c99 header-only vector math library
Last updated: Jan 26th, 2021

As mentioned in the description, this is my C99 header-only vector math library.
It's fully comptabile with OpenGL 4 + GLSL 4 and likely has some compatibility with OpenGL 3 + GLSL 3 - assuming that they treat vectors/matrices they same way as version 4+.

The immediate question is: why write your own library? There are already math libraries out there, so why not use those?
This is a reasonable question, and the answer has quite a few parts to it.

## 1. Support for C
Simply put, GLM, one of the more commonly used libraries, is also header-only, but it is only compatible with C++. One of the most confusing things I faced when first
discovering OpenGL was the fact that I never saw a single tutorial/guide/reference that covered OpenGL using C. The reason for this, as I have come to learn, is that most
of these resources use GLM as their vector/matrix math library, which immediately forces you to use C++ whether you like it or not. It also doesn't help that GLM, reasonably
so, uses C++ features, ie, classes, operator/function overloading, and templates (ESPECIALLY templates - I'll get to these later). As a result, you really don't have a choice
when it comes to what language you choose. Now of course you can always just opt to write C-style C++, but the limitation on what language you have to use is still present.

## 2. GLM's size
GLM is a big library, like REALLY big. This makes some sense because GLM doesn't limit it's math support to just vectors and matrices: it also has support for quaternions, 
complex numbers, and many other mathematical constructs. So what's the price you have to pay for this extensive (and in my case, unneccessary) support? 400+ files! That's right, GLM contains over 400 files. Many of these files are completely unneccessary in my case because I don't need support for many of the mathematical constructs that GLM provides, as well as the fact that many of these files are either i) empty  ii) FILLED with blank declarations  iii) just more #includes! The result? Increased compile times and a polluted
output console when compiling. In all fairness, the compile times aren't TOO much longer and the output console isn't TOO polluted, but these negative side effects don't carrry 
any silver linings with them unfortunately, so I consider these to be unacceptable.

## 3. GLM's complexity and template abuse
These two points tie together so I will address them together. As I alluded to before, GLM has some of the ugliest C++ template abuse I've ever seen. I encourage anyone reading this to open up the GLM source code and just have a read through the files and defintions. There are templates truly EVERYWHERE, and it makes the code more complex and difficult to read. It also doesn't help that the documentation for GLM leaves a lot to be desired, so unless you want to look through the template abuse that this library enforces, have fun trying to figure out what some functions do or how some data types are defined. NOT TO MENTION the fact that the use of templates in the first place is completely unneccessary and unacceptable. The whole point of C++ templates is to write functionality with generic typing - that is, you don't need to rewrite the same code several times to accomodate for different data types. This is of course a nice feature for C++ to have, but the presence of it in a vector/matrix math library is completely absurd. Templates implies that you want to use different types for you vectors/matrices... but the only type you should be using are floats/doubles anyway! You will be doing lots of mathematical calculations with your vectors/matrices, so you need the "precision" (and by precision, I really just mean a few decimal places) that floats/doubles provide. These are the only two types that you should be using, soo the point of implementing templates in the first place doesn't even make sense! Go ahead and write a 3D program and use int vectors instead of float vectors, but don't come complaining when you see tons of distortion, artifacting, and unwanted visual effects due to the loss of precision. The result? Again, unneccessary complexity, additional compile-time overhead, and difficulty in understanding the functionality of the library, all with no silver lining. Again, I implore anyone reading this to actually have a look at the source code for GLM and see for yourself what I'm talking about.
Now, there is another library called CGLM that addresses many of the issues I've outlined above: it's written in C, it's much smaller and conciser, and it's easier to understand. However, there is still additional, unneccessary overhead in my opinion, and it supports a lot more mathematical constructs that I don't need. But regardless of these improvements that CGLM makes, it will NEVER change the final reason I have below.

## 4. Do it yourself
I like writing C code, and I find the idea of developing my own tools/libraries as something very fun. As of writing this, I've had a lot of fun developing this library over the weeks that I've spent doing so. It's taught me a lot about how to design, write, and optimize tools like this, which I think is a very valuable skill for any programmer. Working on this library also gives me a great sense of accomplishment as it's the first time I've ever written something like this before. It's also nice knowing that I've developed something that I can actually implement into future projects, and I take great pride in the work that I've done.
