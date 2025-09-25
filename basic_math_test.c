/* (c) copyright 2025 Lawrence D. Kern /////////////////////////////////////// */

#include "basic_testing.h"
#include "basic_math.h"

static void Test_Vector2_Arithmetic(test_context *T)
{
   Start_Test(T);

   vector2 A = {1, 2};
   vector2 B = {5, 6};

   vector2 C = Add_Vector2(A, B);
   Assert(T, C.E1 == 6);
   Assert(T, C.E2 == 8);

   vector2 D = Sub_Vector2(C, B);
   Assert(T, D.E1 == 1);
   Assert(T, D.E2 == 2);

   vector2 E = Mul_Vector2(A, 4.0f);
   Assert(T, E.E1 == 4.0f);
   Assert(T, E.E2 == 8.0f);

   vector2 N = Neg_Vector2(E);
   Assert(T, N.E1 == -4.0f);
   Assert(T, N.E2 == -8.0f);

   vector2 Norm = Normalize_Vector2(A);
   Assert(T, Length_Vector2(Norm) > 0.99999f);
   Assert(T, Length_Vector2(Norm) < 1.00001f);

   End_Test(T);
}

static void Test_Vector3_Arithmetic(test_context *T)
{
   Start_Test(T);

   vector3 A = {1, 2, 3};
   vector3 B = {5, 6, 7};

   vector3 C = Add_Vector3(A, B);
   Assert(T, C.E1 == 6);
   Assert(T, C.E2 == 8);
   Assert(T, C.E3 == 10);

   vector3 D = Sub_Vector3(C, B);
   Assert(T, D.E1 == 1);
   Assert(T, D.E2 == 2);
   Assert(T, D.E3 == 3);

   vector3 E = Mul_Vector3(A, 4.0f);
   Assert(T, E.E1 == 4.0f);
   Assert(T, E.E2 == 8.0f);
   Assert(T, E.E3 == 12.0f);

   vector3 N = Neg_Vector3(E);
   Assert(T, N.E1 == -4.0f);
   Assert(T, N.E2 == -8.0f);
   Assert(T, N.E3 == -12.0f);

   vector3 Norm = Normalize_Vector3(A);
   Assert(T, Length_Vector3(Norm) > 0.99999f);
   Assert(T, Length_Vector3(Norm) < 1.00001f);

   End_Test(T);
}

static void Test_Vector4_Arithmetic(test_context *T)
{
   Start_Test(T);

   vector4 A = {1, 2, 3, 4};
   vector4 B = {5, 6, 7, 8};

   vector4 C = Add_Vector4(A, B);
   Assert(T, C.E1 == 6);
   Assert(T, C.E2 == 8);
   Assert(T, C.E3 == 10);
   Assert(T, C.E4 == 12);

   vector4 D = Sub_Vector4(C, B);
   Assert(T, D.E1 == 1);
   Assert(T, D.E2 == 2);
   Assert(T, D.E3 == 3);
   Assert(T, D.E4 == 4);

   vector4 E = Mul_Vector4(A, 4.0f);
   Assert(T, E.E1 == 4.0f);
   Assert(T, E.E2 == 8.0f);
   Assert(T, E.E3 == 12.0f);
   Assert(T, E.E4 == 16.0f);

   vector4 N = Neg_Vector4(E);
   Assert(T, N.E1 == -4.0f);
   Assert(T, N.E2 == -8.0f);
   Assert(T, N.E3 == -12.0f);
   Assert(T, N.E4 == -16.0f);

   vector4 Norm = Normalize_Vector4(A);
   Assert(T, Length_Vector4(Norm) > 0.99999f);
   Assert(T, Length_Vector4(Norm) < 1.00001f);

   End_Test(T);
}

int main(void)
{
   test_context T = {0};
   T.File_Name = "basic_math.h";

   // TODO: Add actual test cases for basic_math.h.
   Test_Vector2_Arithmetic(&T);
   Test_Vector3_Arithmetic(&T);
   Test_Vector4_Arithmetic(&T);

   Tally_Results(&T);

   return(0);
}
