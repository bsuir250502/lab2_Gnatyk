#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 90
#define input_buf_size 1000
#define SIZE( x ) (sizeof( x )/sizeof( *x ))
#define number_of_students 4
#define MAX_STR 60


    typedef struct{
        char street[MAX];
        char house_number[MAX];
        char flat_number[MAX];
    }one;
    typedef struct{    
        char district[MAX];
        char city[MAX];
        char street[MAX];
        char house_number[MAX];
        char flat_number[MAX];
    }two;
    typedef struct{
        char region[MAX];
        char district[MAX];
        char village_name[MAX];
        char street[MAX];
        char flat_number[MAX];
    }three;
    typedef struct{
        char region[MAX];
        char district[MAX];
        char city[MAX];
        char street[MAX];
        char house_number[MAX];
        char flat_number[MAX];
    }four;
    typedef struct students_info{
        char inform[MAX];
        char type_addr;
        union choise_1{
            one minsk;
            two regional_city;
            three village;
            four not_regional_city;
        }addr_type;
    };

    void output_string(char *information, char *input_text, int max_number_of_symbols)
    {
        while (1) {
            printf("%s", information);
            fgets(input_text, max_number_of_symbols, stdin);
            if (input_text[0] == '\n' || input_text[0] == ' ') {
                puts("Invalid input, try again.");
            }
            else {
                input_text[strlen(input_text)-1]='\0';
                break;
            }
        }
    }

    students_info enter_students_one( students_info students_list)
    {
        output_string("Street name: ", students_list.addr_type.minsk.street, MAX_STR);
        output_string("House number: ", students_list.addr_type.minsk.house_number, MAX_STR);
        output_string("Apartament number: ", students_list.addr_type.minsk.flat_number, MAX_STR);
        return students_list;
    }

    students_info enter_students_two( students_info students_list)
    {
        output_string("Name of the regional : ", students_list.addr_type.regional_city.district, MAX_STR);
        output_string("Name of the city: ", students_list.addr_type.regional_city.city, MAX_STR);
        output_string("Street name: ", students_list.addr_type.regional_city.street, MAX_STR);
        output_string("House number: ", students_list.addr_type.regional_city.house_number, MAX_STR);
        output_string("Apartament number: ", students_list.addr_type.regional_city.flat_number, MAX_STR);
        return students_list;
    }

    students_info enter_students_three( students_info students_list)
    {
        output_string("Name of the region: ", students_list.addr_type.village.region, MAX_STR);
        output_string("Name of the district: ", students_list.addr_type.village.district, MAX_STR);
        output_string("Name of the village: ", students_list.addr_type.village.village_name, MAX_STR);
        output_string("Name of the street: ", students_list.addr_type.village.street, MAX_STR);
        output_string("Number of house: ", students_list.addr_type.village.flat_number, MAX_STR);
        return students_list;
    }

    students_info enter_students_four( students_info students_list)
    {
        output_string("Name of the region: ", students_list.addr_type.not_regional_city.region, MAX_STR);
        output_string("Name of the district: ", students_list.addr_type.not_regional_city.district, MAX_STR);
        output_string("Name of the city: ", students_list.addr_type.not_regional_city.city, MAX_STR);
        output_string("Name of the stree: ",students_list.addr_type.not_regional_city.street, MAX_STR);
        output_string("Number of house: ",students_list.addr_type.not_regional_city.house_number, MAX_STR);
        output_string("Number of flat: ",students_list.addr_type.not_regional_city.flat_number, MAX_STR);
        return students_list;
    }

    students_info check_adress(students_info students_list)
    {
        switch(students_list.type_addr){
        case '1':
            students_list = enter_students_one(students_list);
            break;
        case '2':
            students_list = enter_students_two(students_list);
            break;
        case '3':
            students_list = enter_students_three(students_list);
            break;
        case '4':
            students_list = enter_students_four(students_list);
            break;
        }
        return students_list;
    }
    students_info adress(students_info students_list )
    {
        int type_addr_size=SIZE(&students_list.type_addr);
        while(1){
            printf("Enter adress of %s\nSelect the type of address\n1- Minsk\n2- Regional city\n3- Not regional city\n4- Village\n",students_list.inform);
            gets_s(&students_list.type_addr,type_addr_size);break;
        }
        students_list = check_adress(students_list);
        return students_list;
    }

    void enter_inform_students(students_info *students_list)
    {
        int i;
        int inform_size=SIZE(students_list[i].inform);
        for(i=0;i<number_of_students;i++){
            printf("Enter surname of %d student\n",i+1);
            gets_s(students_list[i].inform,inform_size);
            students_list[i] = adress(students_list[i]);
        }
    }

    void puts_minsk(students_info* students_list)
    {
        int i = 0;
        for (i = 0; i < number_of_students; i++){
            if(students_list[i].type_addr == '1'){
                printf("Student %s from %s, street %s, house %d, flat %d\n",
                    students_list[i].inform,
                    students_list[i].addr_type.minsk.street,
                    students_list[i].addr_type.minsk.house_number,
                    students_list[i].addr_type.minsk.flat_number);
            }
        }
    }

    void puts_regional_city(students_info* students_list)
    {
        int i = 0;
        for (i = 0; i < number_of_students; i++){
            if(students_list[i].type_addr == '2'){
                printf("Student %s from %s, street %s, house %s, flat %s\n",
                    students_list[i].inform,
                    students_list[i].addr_type.regional_city.district,
                    students_list[i].addr_type.regional_city.city,
                    students_list[i].addr_type.regional_city.street,
                    students_list[i].addr_type.regional_city.house_number,
                    students_list[i].addr_type.regional_city.flat_number);
            }
        }
    }

    void puts_not_regional_city(students_info* students_list)
    {
        int i = 0;
        for (i = 0; i < number_of_students; i++){
            if(students_list[i].type_addr == '3'){
                printf("Student %s from %s, street %s, house %s, flat %s\n",
                    students_list[i].inform,
                    students_list[i].addr_type.not_regional_city.region,
                    students_list[i].addr_type.not_regional_city.district,
                    students_list[i].addr_type.not_regional_city.city,
                    students_list[i].addr_type.not_regional_city.street,
                    students_list[i].addr_type.not_regional_city.house_number,
                    students_list[i].addr_type.not_regional_city.flat_number);
            }
        }
    }

    void puts_village(students_info* students_list)
    {
        int i = 0;
        for (i = 0; i < number_of_students; i++){
            if(students_list[i].type_addr == '4'){
                printf("Student %s from %s, street %s, house %s, flat %s\n",
                    students_list[i].inform,
                    students_list[i].addr_type.village.district,
                    students_list[i].addr_type.village.village_name,
                    students_list[i].addr_type.village.flat_number);
            }
        }
    }

    void puts_all_stud(students_info* students_list)
    {
        int i = 0;
        for (i = 0; i < number_of_students; i++){
            printf("Student",students_list[i].inform);
        }
    }

    void check_help(void)
    {
        printf
            ("================================================================================\n"
            "MANUAL:\n"
            "Enter information about the students: surname and address\n"
            "=================================OPTIONS=======================================\n"
            "-m list of students from Minsk\n"
            "-c list of students from the cities\n"
            "-t list of students from towns\n"
            "-v list of students from villages\n"
            "-l list of all students\n"
            "===============================================================================\n");
        return;
    }

    int main(int argc, char *argv[])
    {
        struct students_info students_list[number_of_students];
        if (argc > 1){
            if (!strcmp(argv[1], "-h")){
                check_help();
            }
        }
        enter_inform_students(students_list);
        if (argc > 1){
            if (!strcmp(argv[1], "-m")){
                puts_minsk(students_list);
            }
            if (!strcmp(argv[1], "-c")){
                puts_regional_city(students_list);
            }
            if (!strcmp(argv[1], "-t")){
                puts_not_regional_city(students_list);
            }
            if (!strcmp(argv[1], "-v")){
                puts_village(students_list);
            }
            if (!strcmp(argv[1], "-l")){
                puts_all_stud(students_list);
            }
        }
        getchar(); 
        return 0;
       
    }

#ifdef __cplusplus
}
#endif
