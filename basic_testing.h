/* (c) copyright 2025 Lawrence D. Kern /////////////////////////////////////// */

#include <stdio.h>

typedef struct {
   char *File_Name;
   int Error_Count_For_Test;
   int Test_Count;
   int Pass_Count;
} test_context;

#define Start_Test(T) Start_Test_With_Label(T, (char *)__func__)

static inline
void Start_Test_With_Label(test_context *T, char *Label)
{
   printf("[%s] %s:", T->File_Name, Label);
   T->Test_Count++;
}

#define Assert(T, Condition)                                            \
   do {                                                                 \
      if(!(Condition))                                                  \
      {                                                                 \
         printf("\n");                                                  \
         printf("  FAILED " #Condition " on line %d", __LINE__);        \
         (T)->Error_Count_For_Test++;                                   \
      }                                                                 \
   } while(0)

static inline
void End_Test(test_context *T)
{
   if(T->Error_Count_For_Test == 0)
   {
      printf(" PASSED\n");
      T->Pass_Count++;
   }
   else
   {
      printf("\n");
      T->Error_Count_For_Test = 0;
   }
}

static inline
void Tally_Results(test_context *T)
{
   printf("[%s] ===== %d of %d TESTS PASSED =====\n", T->File_Name, T->Pass_Count, T->Test_Count);
}
