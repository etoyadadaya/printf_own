#include "s21_string.h"

#define TEST_ARRAY_SIZE 100

START_TEST(loop_memchr_test)
{
  static char* testUnit[5]  = {"name", "ABOBA", "543ERRoR76", "    nulloutside", ""};
  static const int testSupUnit[5] = {'a', 'a', 50, 10, 98};
  ck_assert_str_eq((memchr(testUnit[_i], testSupUnit[_i], 2)), (s21_memchr(testUnit[_i], testSupUnit[_i], 2)));
}
END_TEST

START_TEST(loop_memcmp_test_rav)
{
  static const char* mcpmTestUnit[6] = {"BIBA" ,"name", "ABOBA", "543ERRoR76", "BEAR"};
  static const char* mcpmTestUnit_STR[6] = {"BIBA" ,"name", "ABOBA", "543ERRoR76", "BEAR"};
  _ck_assert_int(s21_memcmp(mcpmTestUnit[_i], mcpmTestUnit_STR[_i], 3), == , memcmp(mcpmTestUnit[_i], mcpmTestUnit_STR[_i], 3));
}
END_TEST

START_TEST(loop_memcmp_test_minus)
{
  static const char* mcpmTestUnit[6] = {"BIBA" ,"name", "ABOBA", "543ERRoR76", "BEAR"};
  static const char* mcpmTestUnit_STR[6] = {"BOBA" ,"zero", "cuter", "NUMCOLUMN", "USECCRYCHEBEAR"};
  _ck_assert_int(s21_memcmp(mcpmTestUnit[_i], mcpmTestUnit_STR[_i], 3), >= , memcmp(mcpmTestUnit[_i], mcpmTestUnit_STR[_i], 3));
}
END_TEST

START_TEST(loop_memcmp_test_plus)
{
  static const char* mcpmTestUnit[6] = {"BOBA" ,"zero", "cuter", "NUMCOLUMN", "USECCRYCHEBEAR"};
  static const char* mcpmTestUnit_STR[6] = {"BIBA" ,"name", "ABOBA", "543ERRoR76", "BEAR"};
  _ck_assert_int(s21_memcmp(mcpmTestUnit[_i], mcpmTestUnit_STR[_i], 3), <= , memcmp(mcpmTestUnit[_i], mcpmTestUnit_STR[_i], 3));
}
END_TEST


START_TEST(loop_memcpy_test)
{
  static char* testUnit[5]  = {"name", "ABOBA", "543ERRoR76", "    nulloutside", ""};
	char str2[TEST_ARRAY_SIZE];
  ck_assert_str_eq(memcpy(str2, testUnit[_i], 2), s21_memcpy(str2, testUnit[_i], 2));
}
END_TEST

START_TEST(loop_memmove_test)
{
  static char testUnit_memmove[5][20]  = {"name", "ABOBA", "543ERRoR76", "abobish", ""};
  static char testUnit_memmove2[5][20]  = {"name", "ABOBA", "543ERRoR76", "abobish", "shushka"};
  static int numver[5]  = {3, 4, 6, 2, 3};
  static char naibor[50];
  static char naibor2[50];
  memmove(naibor, testUnit_memmove[_i], numver[_i]);
  s21_memmove(naibor2, testUnit_memmove[_i], numver[_i]);
  ck_assert_str_eq(naibor, naibor2);
}
END_TEST

START_TEST(loop_memset_test)
{
  static char testUnit_memset[5][20]  = {"name", "ABOBA", "543ERRoR76", "    nulloutside", ""};
  ck_assert_str_eq(memset(testUnit_memset[_i], '*', 2), s21_memset(testUnit_memset[_i], '*', 2));
}
END_TEST

START_TEST(loop_strcat_test)
{
  static char testUnit_memset[5][20]  = {"name", "ABOBA", "543ERRoR76", "    nulloutside", ""};
  static char testUnit_memset_MOM[5][20]  = {"NODE", "TUPESCRIPT", "JAVAGOVNO", "PITON_TOJE", "CUM"};
  ck_assert_str_eq(strcat(testUnit_memset[_i], testUnit_memset_MOM[_i]), s21_strcat(testUnit_memset[_i], testUnit_memset_MOM[_i]));
}
END_TEST

START_TEST(loop_strncat_test)
{
  static char testUnit_memset[5][20]  = {"name", "ABOBA", "543ERRoR76", "    nulloutside", ""};
  static char testUnit_memset_MOM[5][20]  = {"NODE", "TUPESCRIPT", "JAVAGOVNO", "PITON_TOJE", "CUM"};
  static int intarray[5] = {2, 3, 5, 7, 0};
  ck_assert_str_eq(strncat(testUnit_memset[_i], testUnit_memset_MOM[_i], intarray[_i]), s21_strncat(testUnit_memset[_i], testUnit_memset_MOM[_i], intarray[_i]));
}
END_TEST

START_TEST(loop_strchr_test)
{
  static char testUnit_strchr[5][20]  = {"name", "ABOBA", "543ERRoR76", "    nulloutside"};
  static char testUnit_char[5] = {'e', 'O', 'o', ' '};
  ck_assert_str_eq(strchr(testUnit_strchr[_i], testUnit_char[_i]), s21_strchr(testUnit_strchr[_i], testUnit_char[_i]));
}
END_TEST


START_TEST(loop_strcmp_test)
{
  static char testUnit_strcmp[5][20]  = {"nibba", "ABOBI", "543ERRoR76", "    nul", ""};
  static char testUnit_strcmp_sec[5][20]  = {"name", "ABOBA", "543ERRoR76", "    nulloutside", "bibos"};
  ck_assert_int_eq(strcmp(testUnit_strcmp[_i], testUnit_strcmp_sec[_i]), s21_strcmp(testUnit_strcmp[_i], testUnit_strcmp_sec[_i]));
}
END_TEST

START_TEST(loop_strncmp_test)
{
  static char testUnit_strcmp[5][20]  = {"nibba", "ABOBI", "543ERRoR76", "    nul", ""};
  static char testUnit_strcmp_sec[5][20]  = {"name", "ABOBA", "543ERRoR76", "    nulloutside", "bibos"};
  static int sravSumbol[5] = {3, 5, 5, 2, 1};
  ck_assert_int_eq(strncmp(testUnit_strcmp[_i], testUnit_strcmp_sec[_i], sravSumbol[_i]), s21_strncmp(testUnit_strcmp[_i], testUnit_strcmp_sec[_i], sravSumbol[_i]));
}
END_TEST

START_TEST(loop_strcpy_test)
{
  char array[TEST_ARRAY_SIZE] = "";
  static char testUnit_strcmp[5][20]  = {"nibba", "ABOBI", "543ERRoR76", "    nul", ""};
  ck_assert_str_eq(strcpy(array, testUnit_strcmp[_i]), s21_strcpy(array, testUnit_strcmp[_i]));
}
END_TEST

START_TEST(loop_strncpy_test)
{
  char *array[20];
  static char testUnit_strncpy[5][20]  = {"nibba", "ABOBI", "543ERRoR76", "    nul", ""};
  static int sravSumbol[5] = {3, 3, 5, 2, 1};
  ck_assert_str_eq(strncpy(*array, testUnit_strncpy[_i], sravSumbol[_i]), s21_strncpy(*array, testUnit_strncpy[_i], sravSumbol[_i]));
}
END_TEST

START_TEST(loop_strcspn_test)
{
   char array[TEST_ARRAY_SIZE] = "";
   static char testUnit_strncpy[5][20]  = {"nibba", "ABOBI", "543ERRoR76", "    nul", ""};
   ck_assert_int_eq(strcspn(array, testUnit_strncpy[_i]), s21_strcspn(array, testUnit_strncpy[_i]));

}
END_TEST

//14

START_TEST(strerror_test)
{
  ck_assert_str_eq(strerror(14), s21_strerror(14));
}
END_TEST

START_TEST(loop_strlen_test)
{
  static char testUnit_strncpy[5][20]  = {"nibba", "ABOBI", "543ERRoR76", "    nul", ""};
  ck_assert_int_eq(strlen(testUnit_strncpy[_i]), s21_strlen(testUnit_strncpy[_i]));
}
END_TEST

START_TEST(loop_strpbrk_test)
{
  char testUnit_strncpy[5][20]  = {"nibba", "ABOBI", "543ERRoR76", "    nul", ""};
  char testUnit_memset[5][20]  = {"name", "fdO", "o", " ", "kkp"};
  ck_assert_str_eq(strpbrk(testUnit_strncpy[_i], testUnit_memset[_i]), s21_strpbrk(testUnit_strncpy[_i], testUnit_memset[_i]));
}
END_TEST

START_TEST(loop_strrchr_test)
{
  char testUnit_strncpy[5][20]  = {"nibba", "ABOBI", "543ERRoR76", "    nul", ""};
  char testUnit_char[5] = {'b', 'O', 'o', ' '};
  ck_assert_str_eq(strrchr(testUnit_strncpy[_i], testUnit_char[_i]), s21_strrchr(testUnit_strncpy[_i], testUnit_char[_i]));
}
END_TEST

START_TEST(loop_strspn_test)
{
  char testUnit_strncpy[5][30]  = {"STRINGNUMISSOGOOD", "ABOBINAMEDISFAIL", "DANIAISNOTCOUNTRY", " IFYOURNAMEITSNIKITATHEYDIE", "POPQUIZER"};
  char testUnit_memset[5][20]  = {"NGSI", "FGDPOUI", "DAROTH", " ", "POPQUIZER"};
  ck_assert_int_eq(strspn(testUnit_strncpy[_i], testUnit_memset[_i]), s21_strspn(testUnit_strncpy[_i], testUnit_memset[_i]));
}
END_TEST

START_TEST(loop_strstr_test)
{
  char testUnit_strncpy[5][30]  = {"STRINGNUMISSOGOOD", "ABOBINAMEDISFAIL", "DANIAISNOTCOUNTRY", " IFYOURNAMEITSNIKITATHEYDIE", "POPQUIZER"};
  char testUnit_memset[5][20]  = {"STRING", "DIS", "NOTCO", " ", "POPQUIZER"};
  ck_assert_str_eq(strstr(testUnit_strncpy[_i], testUnit_memset[_i]), s21_strstr(testUnit_strncpy[_i], testUnit_memset[_i]));
}
END_TEST

START_TEST(loop_strtok_test)
{
  char testUnit_strncpy[5][30]  = {"STRINGNUMISSOGOOD", "ABOBINAMEDISFAIL", "DANIAISNOTCOUNTRY", " IFYOURNAMEITSNIKITATHEYDIE", "POPQUIZER"};
  char testUnit_memset[5][20]  = {"STRING", "DIS", "NOTCO", " ", "POPQUIZER"};
  ck_assert_str_eq(strtok(testUnit_strncpy[_i], testUnit_memset[_i]), s21_strtok(testUnit_strncpy[_i], testUnit_memset[_i]));
}
END_TEST

//  part 5

START_TEST(loop_to_upper_test)
{
  const char testUnit_toupper[5][25]  = {"ytuerwti", "abobik", "543ERRoR76", "fghjksdfhksd", "null_ti_konch?"};
  const char stACEPT[5][20]  = {"YTUERWTI", "ABOBIK", "543ERROR76", "FGHJKSDFHKSD", "NULL_TI_KONCH?"};
  ck_assert_str_eq(s21_to_upper(testUnit_toupper[_i]), stACEPT[_i]);
}
END_TEST

START_TEST(loop_to_upper_test_p)
{
  const char testUnit_toupperp[5][25]  = {"ytuerwti", "abobik", "543ERRoR76", "fghjksdfhks", "null_ti_konch?"};
  const char stACEPTp[5][20]  = {"YTUERWTI", "ABOBIK", "543ERROR76", "FGHJKSDFHKS", "NULL_TI_KONCH?"};
  ck_assert_str_eq(s21_to_upper(testUnit_toupperp[_i]), stACEPTp[_i]);
}
END_TEST

START_TEST(loop_to_lower_test)
{
  const char testUnit_tolower[5][25]  = {"ytuerwti", "abobik", "543error76", "fghjksdfhksd", "null_ti_konch?"};
  const char stACEPT[5][20]  = {"YTUERWTI", "ABOBIK", "543ERROR76", "FGHJKSDFHKSD", "NULL_TI_KONCH?"};
  ck_assert_str_eq(s21_to_lower(stACEPT[_i]), testUnit_tolower[_i]);
}
END_TEST

START_TEST(loop_to_lower_test_p)
{
  const char testUnit_tolower2p[5][25]  = {"ytuerwti", "abobik", "543error76", "fghjksdfhksd", "null_ti_konch?"};
  const char stACEPT2p[5][20]  = {"YTUERWTI", "ABOBIK", "543ERROR76", "FGHJKSDFHKSD", "NULL_TI_KONCH?"};
  ck_assert_str_eq(s21_to_lower(stACEPT2p[_i]), testUnit_tolower2p[_i]);
}
END_TEST

START_TEST(loop_insert_test)
{
  const char testUnit_insert[5][45]  = {"num1", "num2", "num3", "num4", "num5"};
  const char testUnit_insert2[5][45]  = {"num1", "num2", "num3", "num4", "num5"};
  const char testElem_insert[5][40] = {"num1", "num2", "num3", "num4", "num5"};
  const int testindex[5] = {2, 2, 2, 2, 2};
  const char stACEPTinsert[5][40]  = {"nunum1m1", "nunum2m2", "nunum3m3", "nunum4m4", "nunum5m5"};
  ck_assert_str_eq(s21_insert(testUnit_insert[_i], testElem_insert[_i], testindex[_i]), stACEPTinsert[_i]);
}
END_TEST

START_TEST(loop_charreverse_test)
{
  char testUnit_TRIM[5][20]  = {"num1", "num2", "num3", "num4", "num5"};
  const char stACEPTrev[5][20]  = {"1mun", "2mun", "3mun", "4mun", "5mun"};
  s21_charreverse(testUnit_TRIM[_i]);
  ck_assert_str_eq(testUnit_TRIM[_i], stACEPTrev[_i]);
}
END_TEST

START_TEST(loop_trim_test)
{
  const char testUnit_TRIM[5][45]  = {"*/*num1*/*", "./num2,", "$num3#", "num4^", ".|.num5.|."};
  const char symbol[5][20] = {"*/*", "./,", "$#", "^", ".|."};
  const char stACEPTtrim[5][40]  = {"num1", "num2", "num3", "num4", "num5"};
  ck_assert_str_eq(s21_trim(testUnit_TRIM[_i], symbol[_i]), stACEPTtrim[_i]); 
}
END_TEST


//  sprintf
START_TEST(d_test)
{
 char result[100] = "";
 char result_s21[100] = "";
 char format_str[100] = "%f";
 float f = 7.891233;
 sprintf(result, format_str, f);
 s21_sprintf(result_s21, format_str, f);
 ck_assert_str_eq(result, result_s21);
}
END_TEST

Suite * test_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("test");

  tc_core = tcase_create("Core");

  //tcase_add_loop_test(tc_core, loop_memchr_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_memcmp_test_rav, 0, 5);
  tcase_add_loop_test(tc_core, loop_memcmp_test_minus, 0, 5);
  tcase_add_loop_test(tc_core, loop_memcmp_test_plus, 0, 5);
  tcase_add_loop_test(tc_core, loop_memcpy_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_memmove_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_memset_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_strcat_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_strncat_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_strchr_test, 0, 4);
  tcase_add_loop_test(tc_core, loop_strcmp_test, 0, 5);
  //tcase_add_loop_test(tc_core, loop_strncmp_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_strcpy_test, 0, 5);
  //tcase_add_loop_test(tc_core, loop_strncpy_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_strcspn_test, 0, 5);
  tcase_add_test(tc_core, strerror_test);
  tcase_add_loop_test(tc_core, loop_strlen_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_strpbrk_test, 0, 4);
  tcase_add_loop_test(tc_core, loop_strrchr_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_strspn_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_strstr_test, 0, 5);
  //tcase_add_loop_test(tc_core, loop_strtok_test, 0, 5);

  //  part 5
  tcase_add_loop_test(tc_core, loop_to_upper_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_to_upper_test_p, 0, 5);
  tcase_add_loop_test(tc_core, loop_to_lower_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_to_lower_test_p, 0, 5);
  tcase_add_loop_test(tc_core, loop_insert_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_charreverse_test, 0, 5);
  //tcase_add_loop_test(tc_core, loop_trim_test, 0, 5);
  
  //  sprintf
  
  tcase_add_test(tc_core, d_test);


  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = test_suite();
  sr = srunner_create(s);
  
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}