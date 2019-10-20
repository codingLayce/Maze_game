#include "../maze/highscores.h"
#include "../states/game.h"

#include <string.h>
#include <stdlib.h>

#include "minunit.h"

List *init_list(List *list, Highscore *h1, Highscore *h2) {
	h1->score = 1;
	strcpy(h1->pseudo, "a");
	h1->next_score = h2;

	h2->score = 3;
	strcpy(h2->pseudo, "b");
	h2->next_score = NULL;

	list = malloc(sizeof(*list));
	list->best = h1;

	return list;
}


MU_TEST(test_nb_elements) {
	List *list;
	Highscore h1;
	Highscore h2;
	int nb;

	list = init_list(list, &h1, &h2);

	nb = nb_elements(list);
	mu_check(nb == 2);
}

MU_TEST(test_insert) {
	List *list;
	Highscore h1, h2, h3, *tmp;
	int nb;
	
	list = init_list(list, &h1, &h2);
	
	h3.score = 2;
	strcpy(h3.pseudo, "c");
	h3.next_score = NULL;

	list = insert_highscore(list, &h3, 1);

	nb = nb_elements(list);
	mu_check(nb == 3);
	
	tmp = get_highscore(list, 1);
	mu_check(tmp->score == 2);
}

MU_TEST(test_check_new_highscore) {
	List *list;
	Highscore h1, h2, *tmp;
	int nb, index;

	list = init_list(list, &h1, &h2);

	index = get_insertion_index(list, 2);

	nb = nb_elements(list);

	mu_check(index == 1);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_nb_elements);
    MU_RUN_TEST(test_insert);
    MU_RUN_TEST(test_check_new_highscore);
}

int main(void) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();

    return minunit_status;
}
