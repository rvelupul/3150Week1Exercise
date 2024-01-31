#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"

int zero_linked_list_elts = 0;
struct node* empty_list = build_new_linked_list(zero_linked_list_elts);

int one_element_linked_list = 1;
int data_value_of_initial_linked_list_elt = 1;
struct node* linked_list_one_elt = build_new_linked_list(one_element_linked_list);

int two_element_linked_list = 2;
int data_value_of_second_elt = 2;
struct node* linked_list_two_elts = build_new_linked_list(two_element_linked_list);

int three_element_linked_list = 3;
int data_value_of_third_elt = 3;
struct node* linked_list_three_elts = build_new_linked_list(three_element_linked_list);

int four_element_linked_list = 4;
int data_value_of_fourth_elt = 4;
int node_number_does_not_exist = 5;
struct node* linked_list_four_elts = build_new_linked_list(four_element_linked_list);

TEST_CASE("linked_list testing") {
    SUBCASE("build_new_linked_list") {
        CHECK_EQ(build_new_linked_list(zero_linked_list_elts), nullptr);
        CHECK_EQ(linked_list_one_elt->data, data_value_of_initial_linked_list_elt);
        CHECK_EQ(linked_list_two_elts->next->data, data_value_of_second_elt);
        CHECK_EQ(linked_list_three_elts->next->next->data, data_value_of_third_elt);
    }

    SUBCASE("get_linked_list_data_item_value") {
        CHECK_EQ(get_linked_list_data_item_value(linked_list_one_elt, one_element_linked_list, one_element_linked_list), data_value_of_initial_linked_list_elt);
        CHECK_EQ(get_linked_list_data_item_value(linked_list_two_elts, two_element_linked_list, two_element_linked_list), data_value_of_second_elt);
        CHECK_EQ(get_linked_list_data_item_value(linked_list_three_elts, three_element_linked_list, three_element_linked_list), data_value_of_third_elt);
        CHECK_EQ(get_linked_list_data_item_value(linked_list_four_elts, node_number_does_not_exist, four_element_linked_list), -1);
        CHECK_EQ(get_linked_list_data_item_value(empty_list, 1, zero_linked_list_elts), -1);
    }

    SUBCASE("update_data_in_linked_list") {
        CHECK(update_data_in_linked_list(linked_list_two_elts, 2, 4, 2));
        CHECK_FALSE(update_data_in_linked_list(linked_list_three_elts, 4, 5, 3));
        WARN(update_data_in_linked_list(linked_list_four_elts, 3, 5, 4));
    }

    SUBCASE("delete_linked_list") {
        REQUIRE(linked_list_three_elts != nullptr);
        delete_linked_list(linked_list_three_elts);

        REQUIRE(linked_list_four_elts != nullptr);
        delete_linked_list(linked_list_four_elts);
    }
}
