#ifndef MMATH_H
#define MMATH_H
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "types.h"

#define m_sin(n)    sinf(n)
#define m_cos(n)    cosf(n)
#define m_tan(n)    tanf(n)
#define m_sqrt(n)   sqrtf(n)
#define m_cast(n)   (f32*)&n

#define m_pi        3.1415926f

/* ===========================
 *        2D Vector
 * ===========================
 * */

typedef struct VEC2D
{
    f32 x;
    f32 y;
} vec2_t;

/*
 * Adds two 2D vectors together and returns the
 * resultant vector (a + b).
 * */
vec2_t      
vec2_add(const vec2_t a, 
         const vec2_t b)
{
    vec2_t vec;

    vec.x = a.x + b.x;
    vec.y = a.y + b.y;

    return vec;
}

/*
 * Subtracts two 2D vectors from each other and 
 * returns the resultant vector (a - b).
 * */
vec2_t      
vec2_subtract(const vec2_t a, 
         const vec2_t b)
{
    vec2_t vec;

    vec.x = a.x - b.x;
    vec.y = a.y - b.y;

    return vec;
}

vec2_t      
vec2_scal_mult(const vec2_t vec, 
               f32 scalar)
{
    vec2_t new_vec;

    new_vec.x = vec.x * scalar;
    new_vec.y = vec.y * scalar;

    return new_vec;
}

f32         
vec2_dot(const vec2_t a, 
         const vec2_t b)
{
    return (a.x * b.x + a.y * b.y);
}

f32         
vec2_mag(const vec2_t vec)
{
    return m_sqrt(vec.x * vec.x + vec.y * vec.y);
}

vec2_t      
vec2_normalize(const vec2_t vec)
{
    vec2_t norm_vec;
    f32 mag;

    mag = vec2_mag(vec);
    norm_vec.x = vec.x / mag;
    norm_vec.y = vec.y / mag;

    return norm_vec;
}

vec2_t      
vec2_rotate(const vec2_t vec, 
            const f32 angle)
{
    vec2_t rot_vec;
    f32 r_angle = (angle * m_pi) / 180; 

    rot_vec.x = ((vec.x * m_cos(r_angle)) - (vec.y * m_sin(r_angle)));
    rot_vec.y = ((vec.x * m_sin(r_angle)) + (vec.y * m_cos(r_angle)));

    return rot_vec;
}

/* ===========================
 *        3D Vector
 * ===========================
 * */

typedef struct VEC3D
{
    f32 x;
    f32 y;
    f32 z;
} vec3_t;

vec3_t      
vec3_add(const vec3_t a, 
         const vec3_t b)
{
    vec3_t vec;

    vec.x = a.x + b.x;
    vec.y = a.y + b.y;
    vec.z = a.z + b.z;

    return vec;
}

vec3_t      
vec3_subtract(const vec3_t a, 
              const vec3_t b)
{
    vec3_t vec;

    vec.x = a.x - b.x;
    vec.y = a.y - b.y;
    vec.z = a.z - b.z;

    return vec;
}

vec3_t      
vec3_scal_mult(const vec3_t vec, 
               f32 scalar)
{
    vec3_t new_vec;

    new_vec.x = vec.x * scalar;
    new_vec.y = vec.y * scalar;
    new_vec.z = vec.z * scalar;

    return new_vec;
}

f32     
vec3_dot(const vec3_t a, 
         const vec3_t b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

vec3_t      
vec3_cross(const vec3_t a,
           const vec3_t b)
{
    vec3_t cross_prod;
    
    cross_prod.x = (a.y * b.z) - (a.z * b.y);
    cross_prod.y = (a.z * b.x) - (a.x * b.z);
    cross_prod.z = (a.x * b.y) - (a.y * b.x);

    return cross_prod;
}

f32
vec3_mag(vec3_t vec)
{
    return m_sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

vec3_t 
vec3_normalize(vec3_t vec)
{
    vec3_t norm_vec;
    f32 mag;

    mag = vec3_mag(vec);
    norm_vec.x = vec.x / mag;
    norm_vec.y = vec.y / mag;
    norm_vec.z = vec.z / mag;

    return norm_vec;
}



/* ===========================
 *          Matrix4 
 * ===========================
 * */

typedef struct MAT4
{
    f32 col1[4];
    f32 col2[4];
    f32 col3[4];
    f32 col4[4];
} mat4_t;

void 
mat4_ctor_id(mat4_t* matrix, 
             f32 value)
{
    memset(matrix, 0, 16 * sizeof(f32));
    f32* ptr = (f32*)matrix;

    for(u8 i = 0; i < 4; i++)
    {
        *ptr = value;
        ptr += 5;
    }
}

void
mat4_translate(mat4_t* matrix, f32 x, f32 y, f32 z)
{
    matrix->col4[0] = x;
    matrix->col4[1] = y;
    matrix->col4[2] = z;
}

void
mat4_print(mat4_t matrix)
{
    f32* ptr = &matrix.col1[0];
    for(u8 i = 0; i < 4; i++)
    {
        ptr = &matrix.col1[i];
        for(u8 j = 0; j < 4; j++)
        {
            printf("%f ", *ptr);
            ptr += 4;
        }
        printf("\n");
    }
} 

void
mat4_rotate(mat4_t* matrix, f32 angle, f32 x, f32 y, f32 z)
{
    vec3_t vect = {x, y, z};
    vec3_t n_vect = vec3_normalize(vect);
    f32 u = n_vect.x;
    f32 v = n_vect.y;
    f32 w = n_vect.z;
    f32 r_angle = angle * 0.017453f;
    f32 cos = m_cos(r_angle);
    f32 sin = m_sin(r_angle);

    matrix->col1[0] = (u * u) + (1 - (u * u)) * m_cos(r_angle);
    matrix->col1[1] = ((u * v) * (1 - m_cos(r_angle))) + w * m_sin(r_angle);
    matrix->col1[2] = ((u * w) * (1 - m_cos(r_angle))) - v * m_sin(r_angle);

    matrix->col2[0] = ((u * v) * (1 - m_cos(r_angle))) - w * m_sin(r_angle);
    matrix->col2[1] = (v * v) + (1 - (v * v)) * m_cos(r_angle);
    matrix->col2[2] = ((v * w) * (1 - m_cos(r_angle))) + u * m_sin(r_angle);

    matrix->col3[0] = ((u * w) * (1 - m_cos(r_angle))) + v * m_sin(r_angle);
    matrix->col3[1] = ((v * w) * (1 - m_cos(r_angle))) - u * m_sin(r_angle);
    matrix->col3[2] = (w * w) + (1 - (w * w)) * m_cos(r_angle);
}

void
mat4_perspective(mat4_t* matrix, 
                 f32 fov, 
                 f32 aspect_ratio, 
                 f32 near, f32 far)
{
    f32 r_fov = fov * 0.017453f;

    matrix->col1[0] = 1 / (aspect_ratio * m_tan(r_fov / 2.0f));

    matrix->col2[1] = 1 / (m_tan(r_fov / 2.0f));

    matrix->col3[2] = -1 * ((far + near) / (far - near));
    matrix->col3[3] = -1;

    matrix->col4[2] = ((-2 * far * near) / (far - near));
    matrix->col4[3] = 0;
}

#endif // MMATH_H
