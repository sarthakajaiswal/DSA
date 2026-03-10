#include "list.h" 
#include "list.h" 
#include "list.h" 
#include "list.h" 
#include "list.h" 

int main(void) 
{
    data_t start_data, end_data, data; 
    len_t length; 
    status_t status; 
    list_t* p_list; 

    p_list = create_list(); 
    assert(p_list != NULL); 

    assert(is_list_empty(p_list) == TRUE); 
    assert(get_list_length(p_list) == 0); 
    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY); 
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY); 
    assert(remove_end(p_list) == LIST_EMPTY); 

    show_list(p_list, "Just after creation:"); 

    for(int i = 0; i < 5; ++i) 
        assert(insert_end(p_list, i*10) == SUCCESS); 
    show_list(p_list, "After insert_end():"); 
    for(int i = 5; i < 10; ++i) 
        assert(insert_start(p_list, i*10) == SUCCESS); 
    show_list(p_list, "After insert_start():"); 

    assert(insert_after(p_list, 7, 100) == LIST_DATA_NOT_FOUND); 
    assert(insert_before(p_list, 7, 100) == LIST_DATA_NOT_FOUND); 
    assert(insert_after(p_list, 50, 100) == SUCCESS); 
    show_list("After insert_after():"); 
    assert(insert_before(p_list, 50, 200) == SUCCESS); 
    show_list("After insert_before():"); 

    assert(get_start(p_list, &start_data) == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show_list(p_list, "After get_start():"); 
    assert(get_end(p_list, &end_data) == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show_list(p_list, "After get_end():"); 

    assert(pop_start(p_list, &start_data) == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show_list(p_list, "After pop_start():"); 
    assert(pop_end(p_list, &end_data) == SUCCESS); 
    printf("end data = %D\n", end_data); 
    show_list(p_list, "After end_data():"); 

    assert(remove_start(p_list) == SUCCESS); 
    show_list(p_list, "After remove_start():"); 
    assert(remove_end(p_list) == SUCCESS); 
    show_list(p_list, "After remove_end():"); 
    assert(remove_data(p_list, 7) == LIST_DATA_NOT_FOUND); 
    assert(remove_data(p_list, 50) == SUCCESS); 
    show_list(p_list, "After remove_data():"); 

    assert(is_list_empty(p_list) == FALSE); 
    length = get_list_length(p_list); 
    printf("length = %d\n", length); 

    assert(destroy_list(&p_list) == SUCCESS && p_list == NULL); 
    puts("List testing completed successfully"); 

    return (0); 
} 

int main(void) 
{
    list_t* p_list = NULL; 
    data_t start_data, end_data, data; 
    len_t length; 
    status_t status; 

    p_list = create_list(); 
    assert(p_list != NULL); 

    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY);
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == SUCCESS); 
    assert(remove_end(p_list) == SUCCESS); 
    assert(get_list_length(p_list) == 0); 
    assert(is_list_empty(p_list) == TRUE); 

    show_list(p_list, "Just after creation:"); 

    for(int i = 0; i < 5; ++i) 
        assert(insert_end(p_list, i*10) == SUCCESS); 
    show_list(p_list, "After insert_end():"); 
    for(int i = 5; i < 10; ++i) 
        assert(insert_start(p_list, i*10) == SUCCESS); 
    show_list(p_list, "After insert_start():"); 

    assert(insert_after(p_list, 7, 100) == LIST_DATA_NOT_FOUND); 
    assert(insert_before(p_list, 7, 200) == LIST_DATA_NOT_FOUND); 
    assert(insert_after(p_list, 50, 100) == SUCCESS); 
    show_list(p_list, "After insert_after():"); 
    assert(insert_before(p_list, 50, 200) == SUCCESS); 
    show_list(p_list, "After insert_before():"); 

    assert(get_start(p_list, &start_data) == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show_list(p_list, "After get_start():"); 
    assert(get_end(p_list, &end_data) == SUCCESS); 
    printf("end_data = %d\n", end_data); 
    show_list(p_list, "After get_end():"); 

    assert(pop_start(p_list, &start_data) == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show_list(p_list, "After pop_start():"); 
    assert(pop_end(p_list, &end_data) == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show_list(p_list, "After pop_end():"); 

    assert(remove_start(p_list) == SUCCESS); 
    show_list(p_list, "After remove_Start():"); 
    assert(remove_end(p_list) == SUCCESS); 
    show_list(p_list, "After remove_end():"); 
    assert(remove_data(p_list, 7) == LIST_DATA_NOT_FOUND); 
    assert(remove_data(p_list, 50) == SUCCESS); 
    show_list(p_list, "After remove_data():"); 

    assert(is_list_empty(p_list) == FALSE); 
    length = get_list_length(p_list); 
    printf("length = %d\n", length); 

    assert(destroy_list(&p_list) == SUCCESS && p_list == NULL); 
    puts("List testing completed successfully"); 

    return (0); 
} 

int main(void) 
{
    list_t* p_list = NULL; 
    data_t start_data, end_data, data; 
    len_t length; 
    status_t status; 

    p_list = create_list(); 
    assert(p_list != NULL); 

    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY); 
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == SUCCESS); 
    assert(remove_end(p_list) == SUCCESS); 
    assert(get_list_length(p_list) == 0); 
    assert(is_list_empty(p_list) == TRUE); 

    show_list(p_list, "Just after creation: "); 

    for(int i = 0; i < 5; ++i) 
        assert(insert_end(p_list, i*10) == SUCCESS); 
    show_list(p_list, "After insert_end():"); 
    for(int i = 5; i < 10; ++i) 
        assert(insert_start(p_list, i*10) == SUCCESS); 
    show_list(p_list, "After insert_start():"); 

    assert(insert_after(p_list, 7, 100) == LIST_DATA_NOT_FOUND); 
    assert(insert_before(p_list, 7, 200) == LIST_DATA_NOT_FOUND); 

    assert(insert_after(p_list, 50, 100) == SUCCESS); 
    show_list(p_list, "After insert_after():"); 
    assert(insert_before(p_list, 50, 200) == SUCCESS); 
    show_list(p_list, "After insert_before():"); 

    assert(get_start(p_list, &start_data) == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show_list(p_list, "After get_start():"); 
    assert(get_end(p_list, &end_data) == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show_list(p_list, "After get_end():"); 

    assert(pop_start(p_list, &start_data) == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show_list(p_list, "After pop_start():"); 
    assert(pop_end(p_list, &end_data) == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show_list(p_list, "After pop_end():"); 

    assert(remove_start(p_list) == SUCCESS); 
    show_list(p_list, "After remove_start():"); 
    assert(remove_end(p_list) == SUCCESS); 
    show_list(p_list, "After remove_end():"); 
    assert(remove_data(p_list, 7) == LIST_DATA_NOT_FOUND); 
    assert(remove_data(p_list, 50) == SUCCESS); 
    show_list(p_list, "After remove_data():"); 

    assert(is_list_empty(p_list) == FALSE);
    length = get_list_length(p_list); 
    printf("length = %d\n", length); 

    assert(destroy_list(&p_list) == SUCCESS && p_list == NULL); 
    puts("List testing completed successfully"); 
    return (SUCCESS); 
} 

int main(void) 
{
    list_t* p_list = NULL; 
    data_t start_data, end_data, data; 
    len_t length; 
    status_t status; 

    p_list = create_list(); 
    assert(p_list != NULL); 

    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY); 
    assert(remove_end(p_list) == LIST_EMPTY); 
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(get_list_length(p_list) == 0); 
    assert(is_list_empty(p_list) == TRUE); 

    show_list(p_list, "Just after creation: "); 

    for(int i = 0; i < 5; ++i) 
        assert(insert_end(p_list, i*10) == SUCCESS); 
    show_list(p_list, "After insert_end():"); 
    for(int i = 5; i < 10; ++i) 
        assert(insert_start(p_list, i*10) == SUCCESS);
    show_list(p_list, "After insert_start():"); 

    assert(insert_after(p_list, 7, 100) == LIST_DATA_NOT_FOUND); 
    assert(insert_before(p_list, 7, 200) == LIST_DATA_NOT_FOUND); 
    assert(insert_after(p_list, 50, 100) == SUCCESS);  
    show_list(p_list, "After insert_after():"); 
    assert(insert_before(p_list, 50, 200) == SUCCESS); 
    show_list(p_list, "Before insert_before():"); 

    assert(get_start(p_list, &start_data) == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show_list(p_list, "After get_start():"); 
    assert(get_end(p_list, &end_data) == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show_list(p_list, "After get_end():"); 

    assert(pop_start(p_list, &start_data) == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show_list(p_list, "After pop_start():"); 
    assert(pop_end(p_list, &end_data) == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show_list(p_list, "After pop_end():"); 

    assert(remove_start(p_list) == SUCCESS); 
    show_list(p_list, "After remove_start():"); 
    assert(remove_end(p_list) == SUCCESS); 
    show_list(p_list, "After remove_end():"); 
    assert(remove_data(p_list, 7) == LIST_DATA_NOT_FOUND); 
    assert(remove_data(p_list, 50) == SUCCESS); 
    show_list(p_list, "After remove_data():"); 

    assert(is_list_empty(p_list) == FALSE); 
    length = get_list_length(p_list); 
    printf("length = %d\n", length); 

    assert(destroy_list(&p_list) == SUCCESS && p_list == NULL); 
    puts("List testing completed successfully"); 
    return (0); 
} 

int main(void) 
{
    list_t* p_list = NULL; 
    data_t start_data, end_data, data; 
    len_t length; 
    status_t status; 

    p_list = create_list(); 
    assert(p_list != NULL); 

    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY); 
    assert(remove_end(p_list) == LIST_EMPTY); 
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(is_list_empty(p_list) == TRUE); 
    assert(get_list_length(p_list) == 0); 

    show_list(p_list, "Just after creation: "); 

    for(int i = 0; i < 5; ++i) 
        assert(insert_end(p_list, i*10) == SUCCESS); 
    show_list(p_list, "After insert_end():"); 
    for(int i = 5; i < 10; ++i) 
        assert(insert_start(p_list, i*10) == SUCCESS); 
    show_list(p_list, "After insert_start():"); 

    assert(insert_before(p_list, 7, 100) == LIST_DATA_NOT_FOUND); 
    assert(insert_after(p_list, 7, 100) == LIST_DATA_NOT_FOUND); 
    assert(insert_before(p_list, 50, 100) == SUCCESS); 
    show_list(p_list, "After insert_before():"); 
    assert(insert_after(p_list, 50, 200) == SUCCESS); 
    show_list(p_list, "After insert_after():"); 

    assert(get_start(p_list, &start_data) == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show_list(p_list, "After get_start():"); 
    assert(get_end(p_list, &end_data) == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show_list(p_list, "After get_end():"); 

    assert(pop_start(p_list, &start_data) == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show_list(p_list, "After pop_start():"); 
    assert(pop_end(p_list, &end_data) == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show_list(p_list, "After pop_end():"); 

    assert(remove_start(p_list) == SUCCESS); 
    show_list(p_list, "After remove_start():"); 
    assert(remove_end(p_list) == SUCCESS); 
    show_list(p_list, "After remove_end():"); 
    assert(remove_data(p_list, 7) == LIST_DATA_NOT_FOUND); 
    assert(remove_data(p_list, 50) == SUCCESS); 
    show_list(p_list, "After remove_data():"); 

    assert(is_list_empty(p_list) == FALSE); 
    length = get_list_length(p_list); 
    printf("length = %d\n", length); 

    assert(destroy_list(&p_list) == SUCCESS && p_list == NULL);
    puts("List testing completed successfully"); 
    return (0); 
} 
