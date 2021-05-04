#ifndef MMATH_H
#define MMATH_H

#include <stdio.h>
#include <math.h>
#include "types.h"

#define m_sqrt(n)   sqrtf(n)
#define m_sin(n)    sinf(n)
#define m_cos(n)    cosf(n)
#define m_tan(n)    tanf(n)
#define m_cast(n)   (f32 *)&n
#define m_rads(n)   (n * 0.017453f)
#define m_degs(n)   (n * 57.29578f)

/* ============================ *
 * =====     Vector2D     ===== *
 * ============================ */

// Definition of a 2D vector
typedef struct _TAG_vec2
{
    union
    {
        struct
        {
            f32 x,
                y;
        };
        f32 elements[2];
    };
} vec2_t;

// Constructs a 2D vector given x, y components
vec2_t      vec2_ctor(f32 x, f32 y);

// Computes the sum of two 2D vectors
// (v1 + v2)
vec2_t      vec2_add(vec2_t v1, vec2_t v2);

// Computes the difference of two 2D vectors
// (v1 - v2)
vec2_t      vec2_sub(vec2_t v1, vec2_t v2);

// Computes a 2D vector multiplied by a scalar
// (vec * scalar)
vec2_t      vec2_scal(vec2_t vec, f32 scalar);

// Computes the dot product of two 2D vectors
// (v1 . v2)
f32         vec2_dot(vec2_t v1, vec2_t v2);

// Computes the magnitude (norm) of a 2D vector
// (||vec||)
f32         vec2_mag(vec2_t vec);

// Normalizes a given 2D vector
// (vec * (1 / ||vec||))
vec2_t      vec2_normalize(vec2_t vec);

// Computes a 2D vector rotated by an angle in degrees
vec2_t      vec2_rotate(vec2_t vec, f32 angle);



/* ============================ *
 * =====     Vector3D     ===== *
 * ============================ */

// Definition of a 3D vector
typedef struct _TAG_vec3
{
    union
    {
        struct
        {
            f32 x,
                y,
                z;
        };
        f32 elements[3];
    };
} vec3_t;

// Constructs a 3D vector given x, y, z components
vec3_t      vec3_ctor(f32 x, f32 y, f32 z);

// Computes the sum of two 3D vectors
// (v1 + v2)
vec3_t      vec3_add(vec3_t v1, vec3_t v2);

// Computes the difference of two 3D vectors
// (v1 - v2)
vec3_t      vec3_sub(vec3_t v1, vec3_t v2);

// Computes a 3D vector multipled by a scalar
// (vec * scalar)
vec3_t      vec3_scal(vec3_t vec, f32 scalar);

// Computes the dot product of two 3D vectors
// (v1 . v2)
f32         vec3_dot(vec3_t v1, vec3_t v2);

// Computes the cross product of two 3D vectors
// (v1 x v2)
vec3_t      vec3_cross(vec3_t v1, vec3_t v2);

// Computes the magnitude (norm) of a 3D vector
// (||vec||)
f32         vec3_mag(vec3_t vec);

// Normalizes a given 3D vector
// (vec * (1 / ||vec||))
vec3_t      vec3_normalize(vec3_t vec);



/* ============================ *
 * =====     Vector4D     ===== *
 * ============================ */

// Definition of a 4D vector
typedef struct _TAG_vec4
{
    union
    {
        struct
        {
            f32 x,
                y,
                z,
                w;
        };
        f32 elements[4];
    };
} vec4_t;



/* ============================ *
 * =====     Matrix4      ===== *
 * ============================ */

// Definition of a 4x4 matrix
typedef struct _TAG_mat4
{
    union
    {
        struct
        {
            vec4_t  col1,
                    col2,
                    col3,
                    col4;
        };
        f32 elements[16];
    };
} mat4_t;

// Returns a 4x4 identity matrix
mat4_t      mat4_identity(void);

// Returns a 4x4 translation matrix given x, y, z components
mat4_t      mat4_translate(f32 x, f32 y, f32 z);

// Returns a 4x4 translation matrix given a 3D vector
mat4_t      mat4_translate_v(vec3_t vec);

// Removes the "translation" component from a 4x4 matrix
// (col4.xyz ---> 0)
mat4_t      mat4_translate_remove(mat4_t matrix);

// Prints the given 4x4 matrix to stdout
void        mat4_print(mat4_t matrix);

// Returns a 4x4 rotation matrix given an angle in degrees and x, y, z components
mat4_t      mat4_rotate(f32 angle, f32 x, f32 y, f32 z);

// Returns a 4x4 rotation matrix given an angle in degrees and 3D vector
mat4_t      mat4_rotate_v(f32 angle, vec3_t vec);

// Returns a 4x4 perspective matrix given an FOV, aspect ratio, and
// near/far plane distance values
mat4_t      mat4_perspective(f32 fov, f32 aspect_ratio, f32 near, f32 far);

// Returns a 4x4 lookat matrix given an eye, center, and up 3D vector
mat4_t      mat4_lookat(vec3_t eye, vec3_t center, vec3_t up);

// Returns a 4x4 scale matrix given a scale factor/value
mat4_t      mat4_scale(f32 scale_value);

// Computes the product of two 4x4 matrices
mat4_t      mat4_mult(mat4_t m1, mat4_t m2);



/* ============================ *
 * =====       Misc       ===== *
 * ============================ */

// Pseudo RNG for unsigned 32bit ints
u32         m_randui(u32 index);

// Pseudo RNG for 32bit floats (ranged 0 to 1)
f32         m_randf(u32 index);

// Pseudo RNG for 64bit floats (ranged 0 to 1)
f64         m_randd(u32 index);

// Pseudo RNG for 32bit floats (ranged -1 to 1)
f32         m_randnf(u32 index);

// Pseudo RNG for 64bit floats (ranged -1 to 1)
f64         m_randnd(u32 index);

// Quake III square root
f32         m_fsqrt(f32 number);

// Quake III inverse square root
f32         m_fsqrtinv(f32 number);

// Clamp function for 32bit floats
f32         m_clampf(f32 val, f32 low, f32 high);

// Clamp function for 64bit floats
f64         m_clampd(f64 val, f64 low, f64 high);



////////////////////////////////////////////////////////////////////////////////
// ====== MMATH IMPLEMENTATION ================================================/
////////////////////////////////////////////////////////////////////////////////

 #ifdef MMATH_IMPL

////////////////////////////////////////////////////////////////////////////////
// VECTOR2D IMPLEMENTATION

vec2_t
vec2_ctor(f32 x,
          f32 y)
{
    vec2_t vec;

    vec.x = x;
    vec.y = y;

    return vec;
}

vec2_t
vec2_add(vec2_t v1,
         vec2_t v2)
{
    v1.x += v2.x;
    v1.y += v2.y;

    return v1;
}

vec2_t
vec2_sub(vec2_t v1,
         vec2_t v2)
{
    v1.x -= v2.x;
    v1.y -= v2.y;

    return v1;
}

vec2_t
vec2_scal(vec2_t vec,
          f32 scalar)
{
    vec.x *= scalar;
    vec.y *= scalar;

    return vec;
}

f32
vec2_dot(vec2_t v1,
         vec2_t v2)
{
    return ((v1.x * v2.x) + (v1.y * v2.y));
}

f32
vec2_mag(vec2_t vec)
{
    return m_sqrt((vec.x * vec.x) + (vec.y * vec.y));
}

vec2_t
vec2_normalize(vec2_t vec)
{
    f32 val = m_fsqrtinv((vec.x * vec.x) + (vec.y * vec.y));

    vec.x *= val;
    vec.y *= val;

    return vec;
}

vec2_t
vec2_rotate(vec2_t vec,
            f32 angle)
{
    f32 r_angle = m_rads(angle);
    f32 c = m_cos(r_angle);
    f32 s = m_sin(r_angle);

    vec.x = ((vec.x * c) - (vec.y * s));
    vec.y = ((vec.x * s) + (vec.y * c));

    return vec;
}

////////////////////////////////////////////////////////////////////////////////
// VECTOR3D IMPLEMENTATION

vec3_t
vec3_ctor(f32 x,
          f32 y,
          f32 z)
{
    vec3_t vec;

    vec.x = x;
    vec.y = y;
    vec.z = z;

    return vec;
}

vec3_t
vec3_add(vec3_t v1,
         vec3_t v2)
{
    v1.x += v2.x;
    v1.y += v2.y;
    v1.z += v2.z;

    return v1;
}

vec3_t
vec3_sub(vec3_t v1,
         vec3_t v2)
{
    v1.x -= v2.x;
    v1.y -= v2.y;
    v1.z -= v2.z;

    return v1;
}

vec3_t
vec3_scal(vec3_t vec,
          f32 scalar)
{
    vec.x *= scalar;
    vec.y *= scalar;
    vec.z *= scalar;

    return vec;
}

f32
vec3_dot(vec3_t v1,
         vec3_t v2)
{
    return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

vec3_t
vec3_cross(vec3_t v1,
           vec3_t v2)
{
    vec3_t cross_prod;
    
    cross_prod.x = (v1.y * v2.z) - (v1.z * v2.y);
    cross_prod.y = (v1.z * v2.x) - (v1.x * v2.z);
    cross_prod.z = (v1.x * v2.y) - (v1.y * v2.x);

    return cross_prod;
}

f32
vec3_mag(vec3_t vec)
{
    return m_sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
}

vec3_t 
vec3_normalize(vec3_t vec)
{
    f32 val = m_fsqrtinv((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));

    vec.x *= val;
    vec.y *= val;
    vec.z *= val;

    return vec;
}

////////////////////////////////////////////////////////////////////////////////
// MATRIX4 IMPLEMENTATION

mat4_t
mat4_identity(void)
{
    mat4_t matrix = {0};
    
    matrix.col1.x = 1.0f;
    matrix.col2.y = 1.0f;
    matrix.col3.z = 1.0f;
    matrix.col4.w = 1.0f;

    return matrix;
}

mat4_t
mat4_translate(f32 x,
               f32 y,
               f32 z)
{
    mat4_t matrix = mat4_identity();

    matrix.col4.x = x;
    matrix.col4.y = y;
    matrix.col4.z = z;

    return matrix;
}

mat4_t
mat4_translate_v(vec3_t vec)
{
    mat4_t matrix = mat4_identity();

    matrix.col4.x = vec.x;
    matrix.col4.y = vec.y;
    matrix.col4.z = vec.z;

    return matrix;
}

mat4_t
mat4_translate_remove(mat4_t matrix)
{
    matrix.col4.x = 0.0f;
    matrix.col4.y = 0.0f;
    matrix.col4.z = 0.0f;

    return matrix;
}

void
mat4_print(mat4_t matrix)
{
    for (u8 i = 0; i < 4; i++)
    {
        for (u8 j = 0; j < 4; j++)
        {
            printf("%f ", matrix.elements[i + j * 4]);
        }
        printf("\n");
    }
} 

mat4_t
mat4_rotate(f32 angle, 
            f32 x, 
            f32 y, 
            f32 z)
{
    vec3_t vec = {x, y, z};
    vec = vec3_normalize(vec);
    f32 c = m_cos(m_rads(angle));
    f32 s = m_sin(m_rads(angle));
    f32 c1 = 1.0f - c;

    mat4_t matrix = {0};

    matrix.col1.x = (c1 * vec.x * vec.x) + c;
    matrix.col1.y = (c1 * vec.x * vec.y) + s * vec.z;
    matrix.col1.z = (c1 * vec.x * vec.z) - s * vec.y;

    matrix.col2.x = (c1 * vec.x * vec.y) - s * vec.z;
    matrix.col2.y = (c1 * vec.y * vec.y) + c;
    matrix.col2.z = (c1 * vec.y * vec.z) + s * vec.x;

    matrix.col3.x = (c1 * vec.x * vec.z) + s * vec.y;
    matrix.col3.y = (c1 * vec.y * vec.z) - s * vec.x;
    matrix.col3.z = (c1 * vec.z * vec.z) + c;

    matrix.col4.w = 1.0f;

    return matrix;
}

mat4_t
mat4_rotate_v(f32 angle,
              vec3_t vec)
{
    vec = vec3_normalize(vec);
    f32 c = m_cos(m_rads(angle));
    f32 s = m_sin(m_rads(angle));
    f32 c1 = 1.0f - c;

    mat4_t matrix = {0};

    matrix.col1.x = (c1 * vec.x * vec.x) + c;
    matrix.col1.y = (c1 * vec.x * vec.y) + s * vec.z;
    matrix.col1.z = (c1 * vec.x * vec.z) - s * vec.y;

    matrix.col2.x = (c1 * vec.x * vec.y) - s * vec.z;
    matrix.col2.y = (c1 * vec.y * vec.y) + c;
    matrix.col2.z = (c1 * vec.y * vec.z) + s * vec.x;

    matrix.col3.x = (c1 * vec.x * vec.z) + s * vec.y;
    matrix.col3.y = (c1 * vec.y * vec.z) - s * vec.x;
    matrix.col3.z = (c1 * vec.z * vec.z) + c;

    matrix.col4.w = 1.0f;

    return matrix;
}

mat4_t
mat4_perspective(f32 fov,
                 f32 aspect_ratio,
                 f32 near,
                 f32 far)
{
    f32 t = m_tan(m_rads(fov) / 2.0f);
    f32 fdelta = far - near;
    
    mat4_t matrix = {0};

    matrix.col1.x = 1 / (aspect_ratio * t);

    matrix.col2.y = 1 / t;

    matrix.col3.z = -1 * ((far + near) / fdelta);
    matrix.col3.w = -1;

    matrix.col4.z = ((-2.0f * far * near) / fdelta);

    return matrix;
}

mat4_t
mat4_lookat(vec3_t eye, 
            vec3_t center, 
            vec3_t up)
{
    const vec3_t f = vec3_normalize(vec3_sub(center, eye));
    const vec3_t s = vec3_normalize(vec3_cross(f, up));
    const vec3_t u = vec3_cross(s, f);

    mat4_t matrix;

    matrix.col1.x = s.x;
    matrix.col1.y = u.x;
    matrix.col1.z = -f.x;
    matrix.col1.w = 0.0f;

    matrix.col2.x = s.y;
    matrix.col2.y = u.y;
    matrix.col2.z = -f.y;
    matrix.col2.w = 0.0f;

    matrix.col3.x = s.z;
    matrix.col3.y = u.z;
    matrix.col3.z = -f.z;
    matrix.col3.w = 0.0f;

    matrix.col4.x = -vec3_dot(s, eye);
    matrix.col4.y = -vec3_dot(u, eye);
    matrix.col4.z = vec3_dot(f, eye);
    matrix.col4.w = 1.0f;

    return matrix;
}

mat4_t
mat4_scale(f32 scale_value)
{
    mat4_t matrix = {0};

    matrix.col1.x = scale_value;
    matrix.col2.y = scale_value;
    matrix.col3.z = scale_value;
    matrix.col4.w = 1.0f;

    return matrix;
}

mat4_t
mat4_mult(mat4_t m1,
          mat4_t m2)
{
    mat4_t res;

    for (u8 y = 0; y < 4; y++)
    {
        for (u8 x = 0; x < 4; x++)
        {
            f32 sum = 0.0f;
            for (u8 e = 0; e < 4; e++)
            {
                sum += m1.elements[x + e * 4] * m2.elements[e + y * 4];
            }
            res.elements[x + y * 4] = sum;
        }
    }

    return res;
}

////////////////////////////////////////////////////////////////////////////////
// MISC IMPLEMENTATION

u32
m_randui(u32 index)
{
    index = (index << 13) ^ index;
    return ((index * (index * index * 15731 + 789221) + 1376312589) & 0x7FFFFFFF);
}

f32
m_randf(u32 index)
{
    index = (index << 13) ^ index;
    return (((index * (index * index * 15731 + 789221) + 1376312589) & 0x7FFFFFFF) / 1073741824.0f) * 0.5f;
}

f64
m_randd(u32 index)
{
    index = (index << 13) ^ index;
    return (((index * (index * index * 15731 + 789221) + 1376312589) & 0x7FFFFFFF) / 1073741824.0) * 0.5;
}

f32
m_randnf(u32 index)
{
    index = (index << 13) ^ index;
    return (((index * (index * index * 15731 + 789221) + 1376312589) & 0x7FFFFFFF) / 1073741824.0f) - 1.0f;
}

f64
m_randnd(u32 index)
{
    index = (index << 13) ^ index;
    return (((index * (index * index * 15731 + 789221) + 1376312589) & 0x7FFFFFFF) / 1073741824.0) - 1.0;
}

f32
m_fsqrt(f32 number)
{
    f32 x = number * 0.5f;
    f32 y = number;
    s32 i = *(s32 *)&y;             // evil floating point bit hack
    i = 0x5F3759DF - (i >> 1);      // what the fuck?
    y = *(f32 *)&i;
    y = y * (1.5f - (x * y * y));   // 1st iteration
    y = y * (1.5f - (x * y * y));   // 2nd iteration

    return number * y;              // mulitply by original num to reverse and get sqrt
}

f32
m_fsqrtinv(f32 number)
{
    f32 x = number * 0.5f;
    f32 y = number;
    s32 i = *(s32 *)&y;             // evil floating point bit hack
    i = 0x5F3759DF - (i >> 1);      // what the fuck?
    y = *(f32 *)&i;
    y = y * (1.5f - (x * y * y));   // 1st iteration
    y = y * (1.5f - (x * y * y));   // 2nd iteration

    return y;
}

f32
m_clampf(f32 val,
         f32 low,
         f32 high)
{
    if (val < low)
        return low;
    else if (val > high)
        return high;
    else
        return val;
}

f64
m_clampd(f64 val,
         f64 low,
         f64 high)
{
    if (val < low)
        return low;
    else if (val > high)
        return high;
    else
        return val;
}

 #endif // MMATH_IMPL

#endif // MMATH_H
