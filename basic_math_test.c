/* (c) copyright 2025 Lawrence D. Kern /////////////////////////////////////// */

#include <assert.h>
#include <stdio.h>

#include "basic_math.h"

int main(void)
{
   vector3 A = {1, 2, 3};
   vector3 B = {5, 6, 7};
   vector3 C = Add_Vector3(A, B);

   assert(C.E1 == 6);
   assert(C.E2 == 8);
   assert(C.E3 == 10);

   vector3 D = Sub_Vector3(C, B);
   assert(D.E1 == 1);
   assert(D.E2 == 2);
   assert(D.E3 == 3);

   vector3 Norm = Normalize_Vector3(A);
   assert(Length_Vector3(Norm) > 0.99999f);
   assert(Length_Vector3(Norm) < 1.00001f);

   // TODO: Add actual test cases for basic_math.h.

   printf("[basic_math.h] All tests passed.\n");

   return(0);
}
