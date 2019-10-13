#include "minunit"

MU_TEST(test_check) {
    mu_check(5 == 7);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_check);
}

int main(void) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();

    return minunit_status;
}