/* (c) copyright 2025 Lawrence D. Kern /////////////////////////////////////// */

// TODO: Remove dependencies on the C standard library.
#include <math.h>

typedef struct {
   float E1;
   float E2;
} vector2;

typedef struct {
   float E1;
   float E2;
   float E3;
} vector3;

typedef struct {
   float E1;
   float E2;
   float E3;
   float E4;
} vector4;

typedef struct {
   float E[4];
} matrix2;

typedef struct {
   float E[9];
} matrix3;

typedef struct {
   float E[16];
} matrix4;

#define TAU32 6.2831853f
static inline
float Sine(float Turns)
{
   float Result = sinf(TAU32 * Turns);
   return(Result);
}

static inline
float Cosine(float Turns)
{
   float Result = cosf(TAU32 * Turns);
   return(Result);
}
#undef TAU32

static inline
float Square(float Value)
{
   float Result = Value * Value;
   return(Result);
}

static inline
float Square_Root(float Value)
{
   float Result = sqrtf(Value); // TODO: Implement square root.
   return(Result);
}

static inline
vector3 Add_Vector3(vector3 A, vector3 B)
{
   vector3 Result;
   Result.E1 = A.E1 + B.E1;
   Result.E2 = A.E2 + B.E2;
   Result.E3 = A.E3 + B.E3;

   return(Result);
}

static inline
vector3 Sub_Vector3(vector3 A, vector3 B)
{
   vector3 Result;
   Result.E1 = A.E1 - B.E1;
   Result.E2 = A.E2 - B.E2;
   Result.E3 = A.E3 - B.E3;

   return(Result);
}

static inline
vector3 Mul_Vector3(vector3 Vector, float Scalar)
{
   vector3 Result;
   Result.E1 = Vector.E1 * Scalar;
   Result.E2 = Vector.E2 * Scalar;
   Result.E3 = Vector.E3 * Scalar;

   return(Result);
}

static inline
float Length_Squared_Vector3(vector3 Vector)
{
   float Result = Square(Vector.E1) + Square(Vector.E2) + Square(Vector.E3);
   return(Result);
}

static inline
float Length_Vector3(vector3 Vector)
{
   float Result = Square_Root(Length_Squared_Vector3(Vector));
   return(Result);
}

static inline
vector3 Normalize_Vector3(vector3 Vector)
{
   vector3 Result = {0};

   float Norm = Length_Vector3(Vector);
   if(Norm != 0.0f)
   {
      Result.E1 = Vector.E1 / Norm;
      Result.E2 = Vector.E2 / Norm;
      Result.E3 = Vector.E3 / Norm;
   }

   return(Result);
}

static inline
float Dot_Vector3(vector3 A, vector3 B)
{
   float Result = A.E1*B.E1 + A.E2*B.E2 + A.E3*B.E3;
   return(Result);
}

static inline
vector3 Cross_Vector3(vector3 A, vector3 B)
{
   vector3 Result;
   Result.E1 = A.E2*B.E3 - A.E3*B.E2;
   Result.E2 = A.E3*B.E1 - A.E1*B.E3;
   Result.E3 = A.E1*B.E2 - A.E2*B.E1;

   return(Result);
}

static inline
matrix4 Identity_Matrix4(void)
{
   matrix4 Result =
   {{
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 1, 0,
      0, 0, 0, 1,
   }};

   return(Result);
}

static inline
matrix4 Translate_Matrix4(float X, float Y, float Z)
{
   matrix4 Result =
   {{
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 1, 0,
      X, Y, Z, 1,
   }};

   return(Result);
}

static inline
matrix4 Scale_Matrix4(float X, float Y, float Z)
{
   matrix4 Result =
   {{
      X, 0, 0, 0,
      0, Y, 0, 0,
      0, 0, Z, 0,
      0, 0, 0, 1,
   }};

   return(Result);
}

static inline
matrix4 Rotate_X_Matrix4(float Turns)
{
   float C = Cosine(Turns);
   float S = Sine(Turns);
   float N = -S;

   matrix4 Result =
   {{
      1, 0, 0, 0,
      0, C, S, 0,
      0, N, C, 0,
      0, 0, 0, 1,
   }};

   return(Result);
}

static inline
matrix4 Rotate_Y_Matrix4(float Turns)
{
   float C = Cosine(Turns);
   float S = Sine(Turns);
   float N = -S;

   matrix4 Result =
   {{
      C, 0, N, 0,
      0, 1, 0, 0,
      S, 0, C, 0,
      0, 0, 0, 1,
   }};

   return(Result);
}

static inline
matrix4 Rotate_Z_Matrix4(float Turns)
{
   float C = Cosine(Turns);
   float S = Sine(Turns);
   float N = -S;

   matrix4 Result =
   {{
      C, S, 0, 0,
      N, C, 0, 0,
      0, 0, 1, 0,
      0, 0, 0, 1,
   }};

   return(Result);
}

static inline
matrix4 Look_At_Matrix4(vector3 Eye, vector3 Target)
{
   // NOTE: We're assuming E3 is always up in our definition of world space.
   vector3 World_Up = {0, 0, 1};

   vector3 F = Normalize_Vector3(Sub_Vector3(Target, Eye));   // +E1: forward
   vector3 R = Normalize_Vector3(Cross_Vector3(F, World_Up)); // -E2: right
   vector3 U = Cross_Vector3(R, F);                           // +E3: up

   float TR = -Dot_Vector3(R, Eye);
   float TU = -Dot_Vector3(U, Eye);
   float TF = -Dot_Vector3(F, Eye);

   matrix4 Result =
   {{
      R.E1, U.E1, -F.E1, 0,
      R.E2, U.E2, -F.E2, 0,
      R.E3, U.E3, -F.E3, 0,
      TR,   TU,   -TF,   1,
   }};

   return(Result);
}

static inline
matrix4 Perspective_Matrix4(float Width, float Height, float Near, float Far)
{
   float Focal_Length = 3.0f;

   float A = Focal_Length / (Width / Height);
   float B = -Focal_Length;
   float C = Far / (Near - Far);
   float D = (Far * Near) / (Near - Far);
   float E = -1;

   matrix4 Result =
   {{
      A, 0, 0, 0,
      0, B, 0, 0,
      0, 0, C, E,
      0, 0, D, 0,
   }};

   return(Result);
}
