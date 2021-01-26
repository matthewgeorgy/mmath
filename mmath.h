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
#define m_log(n)    logf(n)
#define m_cast(n)   (f32*)&n
#define m_rads(n)   (n * 0.017453f)
#define m_degs(n)   (n * 57.29578f)

#define m_pi        3.1415926f
#define m_e         2.7182818f
#define m_root2     1.1414214f
#define m_root3     1.7320251f
#define m_sin30     0.5f
#define m_sin45     0.7071068f
#define m_sin60     0.8660254f
#define m_cos30     0.8660254f
#define m_cos45     0.7071068f
#define m_cos60     0.5f

/* ===========================
 *         2D Vector
 * ===========================
 * */

typedef struct VEC2D
{
    f32 x;
    f32 y;
} vec2_t;

vec2_t      
vec2_add(const vec2_t a, 
         const vec2_t b)
{
    vec2_t vec;

    vec.x = a.x + b.x;
    vec.y = a.y + b.y;

    return vec;
}

vec2_t      
vec2_sub(const vec2_t a, 
         const vec2_t b)
{
    vec2_t vec;

    vec.x = a.x - b.x;
    vec.y = a.y - b.y;

    return vec;
}

vec2_t      
vec2_scal(const vec2_t vec, 
          const f32 scalar)
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
    f32 mag = vec2_mag(vec);

    norm_vec.x = vec.x / mag;
    norm_vec.y = vec.y / mag;

    return norm_vec;
}

vec2_t      
vec2_rotate(const vec2_t vec, 
            const f32 angle)
{
    vec2_t rot_vec;
    f32 r_angle = m_rads(angle);
    f32 c = m_cos(r_angle);
    f32 s = m_sin(r_angle);

    rot_vec.x = ((vec.x * c) - (vec.y * s));
    rot_vec.y = ((vec.x * s) + (vec.y * c));

    return rot_vec;
}

/* ===========================
 *         3D Vector
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
vec3_sub(const vec3_t a, 
         const vec3_t b)
{
    vec3_t vec;

    vec.x = a.x - b.x;
    vec.y = a.y - b.y;
    vec.z = a.z - b.z;

    return vec;
}

vec3_t      
vec3_scal(const vec3_t vec, 
          const f32 scalar)
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
vec3_mag(const vec3_t vec)
{
    return m_sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

vec3_t 
vec3_normalize(const vec3_t vec)
{
    vec3_t norm_vec;
    f32 mag = vec3_mag(vec);

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

mat4_t
mat4_ctor(void)
{
    mat4_t matrix;

    memset(&matrix, 0, 16 * sizeof(f32));

    return matrix;
}

mat4_t
mat4_identity(mat4_t matrix)
{
    f32* ptr = m_cast(matrix);

    for(u8 i = 0; i < 4; i++)
    {
        *ptr = 1.0f;
        ptr += 5;
    }

    return matrix;
}

mat4_t
mat4_translate(mat4_t matrix, 
               const f32 x,
               const f32 y,
               const f32 z)
{
    matrix.col4[0] = x;
    matrix.col4[1] = y;
    matrix.col4[2] = z;

    return matrix;
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

mat4_t
mat4_rotate(mat4_t matrix, 
            const f32 angle, 
            const f32 x, 
            const f32 y, 
            const f32 z)
{
    vec3_t vec = {x, y, z};
    vec = vec3_normalize(vec);
    f32 r_angle = m_rads(angle);
    f32 c = m_cos(r_angle);
    f32 s = m_sin(r_angle);

    matrix.col1[0] = (vec.x * vec.x) + (1 - (vec.x * vec.x)) * c;
    matrix.col1[1] = ((vec.x * vec.y) * (1 - c)) + vec.z * s;
    matrix.col1[2] = ((vec.x * vec.z) * (1 - c)) - vec.y * s;

    matrix.col2[0] = ((vec.x * vec.y) * (1 - c)) - vec.z * s;
    matrix.col2[1] = (vec.y * vec.y) + (1 - (vec.y * vec.y)) * c;
    matrix.col2[2] = ((vec.y * vec.z) * (1 - c)) + vec.x * s;

    matrix.col3[0] = ((vec.x * vec.z) * (1 - c)) + vec.y * s;
    matrix.col3[1] = ((vec.y * vec.z) * (1 - c)) - vec.x * s;
    matrix.col3[2] = (vec.z * vec.z) + (1 - (vec.z * vec.z)) * c;

    return matrix;
}

mat4_t
mat4_perspective(mat4_t matrix,
                 const f32 fov,
                 const f32 aspect_ratio,
                 const f32 near,
                 const f32 far)
{
    f32 r_fov = m_rads(fov);
    f32 t = m_tan(r_fov / 2.0f);

    matrix.col1[0] = 1 / (aspect_ratio * t);

    matrix.col2[1] = 1 / t;

    matrix.col3[2] = -1 * ((far + near) / (far - near));
    matrix.col3[3] = -1;

    matrix.col4[2] = ((-2 * far * near) / (far - near));
    matrix.col4[3] = 0;

    return matrix;
}

mat4_t
mat4_lookat(const vec3_t eye, 
            const vec3_t center, 
            const vec3_t up)
{
    const vec3_t f = vec3_normalize(vec3_sub(center, eye));  
    const vec3_t s = vec3_normalize(vec3_cross(f, up));
    const vec3_t u = vec3_cross(s, f);

    mat4_t matrix;

    matrix.col1[0] = s.x;
    matrix.col1[1] = u.x;
    matrix.col1[2] = -f.x;
    matrix.col1[3] = 0;

    matrix.col2[0] = s.y;
    matrix.col2[1] = u.y;
    matrix.col2[2] = -f.y;
    matrix.col2[3] = 0;

    matrix.col3[0] = s.z;
    matrix.col3[1] = u.z;
    matrix.col3[2] = -f.z;
    matrix.col3[3] = 0;

    matrix.col4[0] = -vec3_dot(s, eye);
    matrix.col4[1] = -vec3_dot(u, eye);
    matrix.col4[2] = vec3_dot(f, eye);
    matrix.col4[3] = 1;

    return matrix;
}

mat4_t
mat4_scale(mat4_t matrix,
           const f32 scale_value)
{
    f32* ptr = m_cast(matrix);

    for(u8 i = 0; i < 3; i++)
    {
        *ptr = scale_value;
        ptr += 5;
    }
    *ptr = 1.0f;

    return matrix;
}

mat4_t
mat4_mult(const mat4_t m1,
          const mat4_t m2)
{
    mat4_t res = mat4_ctor();
    f32* p1 = m_cast(m1);
    f32* p2 = m_cast(m2);
    f32* pres = m_cast(res);

    for(u8 y = 0; y < 4; y++)
    {
        for(u8 x = 0; x < 4; x++)
        {
            f32 sum = 0.0f;
            for(u8 e = 0; e < 4; e++)
            {
                sum += p1[x + e * 4] * p2[e + y * 4];
            }
            pres[x + y * 4] = sum;
        }
    }

    return res;
}

mat4_t
mat4_remove_translate(mat4_t matrix)
{
    for(u8 i = 0; i < 3; i++)
    {
        matrix.col4[i] = 0.0f;
    }

    return matrix;
}

mat4_t
mat4_translate_v(mat4_t matrix,
                const vec3_t vec)
{
    matrix.col4[0] = vec.x;
    matrix.col4[1] = vec.y;
    matrix.col4[2] = vec.z;

    return matrix;
}

#endif // MMATH_H
