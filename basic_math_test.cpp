/* (c) copyright 2025 Lawrence D. Kern /////////////////////////////////////// */

#include "basic_testing.h"
#include "basic_math.h"

static void Test_Vector2_Overloads(test_context *T)
{
   Start_Test(T);

   vector2 A = {1, 2};
   vector2 B = {5, 6};

   vector2 C = A + B;
   Assert(T, C.E1 == 6);
   Assert(T, C.E2 == 8);

   vector2 D = C - B;
   Assert(T, D.E1 == 1);
   Assert(T, D.E2 == 2);

   vector2 E = A * 4.0f;
   Assert(T, E.E1 == 4.0f);
   Assert(T, E.E2 == 8.0f);

   vector2 F = 4.0f * A;
   Assert(T, F.E1 == 4.0f);
   Assert(T, F.E2 == 8.0f);

   vector2 N = -F;
   Assert(T, N.E1 == -4.0f);
   Assert(T, N.E2 == -8.0f);

   F += A;
   Assert(T, F.E1 == 5.0f);
   Assert(T, F.E2 == 10.0f);

   F -= A;
   Assert(T, F.E1 == 4.0f);
   Assert(T, F.E2 == 8.0f);

   F *= 2.0f;
   Assert(T, F.E1 == 8.0f);
   Assert(T, F.E2 == 16.0f);

   End_Test(T);
}

static void Test_Vector3_Overloads(test_context *T)
{
   Start_Test(T);

   vector3 A = {1, 2, 3};
   vector3 B = {5, 6, 7};

   vector3 C = A + B;
   Assert(T, C.E1 == 6);
   Assert(T, C.E2 == 8);
   Assert(T, C.E3 == 10);

   vector3 D = C - B;
   Assert(T, D.E1 == 1);
   Assert(T, D.E2 == 2);
   Assert(T, D.E3 == 3);

   vector3 E = A * 4.0f;
   Assert(T, E.E1 == 4.0f);
   Assert(T, E.E2 == 8.0f);
   Assert(T, E.E3 == 12.0f);

   vector3 F = 4.0f * A;
   Assert(T, F.E1 == 4.0f);
   Assert(T, F.E2 == 8.0f);
   Assert(T, F.E3 == 12.0f);

   vector3 N = -F;
   Assert(T, N.E1 == -4.0f);
   Assert(T, N.E2 == -8.0f);
   Assert(T, N.E3 == -12.0f);

   F += A;
   Assert(T, F.E1 == 5.0f);
   Assert(T, F.E2 == 10.0f);
   Assert(T, F.E3 == 15.0f);

   F -= A;
   Assert(T, F.E1 == 4.0f);
   Assert(T, F.E2 == 8.0f);
   Assert(T, F.E3 == 12.0f);

   F *= 2.0f;
   Assert(T, F.E1 == 8.0f);
   Assert(T, F.E2 == 16.0f);
   Assert(T, F.E3 == 24.0f);

   End_Test(T);
}

static void Test_Vector4_Overloads(test_context *T)
{
   Start_Test(T);
   vector4 A = {1, 2, 3, 4};
   vector4 B = {5, 6, 7, 8};

   vector4 C = A + B;
   Assert(T, C.E1 == 6);
   Assert(T, C.E2 == 8);
   Assert(T, C.E3 == 10);
   Assert(T, C.E4 == 12);

   vector4 D = C - B;
   Assert(T, D.E1 == 1);
   Assert(T, D.E2 == 2);
   Assert(T, D.E3 == 3);
   Assert(T, D.E4 == 4);

   vector4 E = A * 4.0f;
   Assert(T, E.E1 == 4.0f);
   Assert(T, E.E2 == 8.0f);
   Assert(T, E.E3 == 12.0f);
   Assert(T, E.E4 == 16.0f);

   vector4 F = 4.0f * A;
   Assert(T, F.E1 == 4.0f);
   Assert(T, F.E2 == 8.0f);
   Assert(T, F.E3 == 12.0f);
   Assert(T, F.E4 == 16.0f);

   vector4 N = -F;
   Assert(T, N.E1 == -4.0f);
   Assert(T, N.E2 == -8.0f);
   Assert(T, N.E3 == -12.0f);
   Assert(T, N.E4 == -16.0f);

   F += A;
   Assert(T, F.E1 == 5.0f);
   Assert(T, F.E2 == 10.0f);
   Assert(T, F.E3 == 15.0f);
   Assert(T, F.E4 == 20.0f);

   F -= A;
   Assert(T, F.E1 == 4.0f);
   Assert(T, F.E2 == 8.0f);
   Assert(T, F.E3 == 12.0f);
   Assert(T, F.E4 == 16.0f);

   F *= 2.0f;
   Assert(T, F.E1 == 8.0f);
   Assert(T, F.E2 == 16.0f);
   Assert(T, F.E3 == 24.0f);
   Assert(T, F.E4 == 32.0f);

   End_Test(T);
}

int main(void)
{
   test_context T = {};
   T.File_Name = (char *)"basic_math.h";

   // TODO: More complete tests.
   Test_Vector2_Overloads(&T);
   Test_Vector3_Overloads(&T);
   Test_Vector4_Overloads(&T);

   Tally_Results(&T);

   return(0);
}
