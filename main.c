#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define koll 256
#define input_buf_size 1000
#define SIZE( x ) (sizeof( x )/sizeof( *x ))
#define number_of_students 4


    typedef  struct{
        char street[koll];
        char house_number[koll];
        char flat_number[koll];
    }one;
    one addr_one;

    typedef  struct{		
        char district[koll];
        char sity[koll];
        char street[koll];
        char house_number[koll];
        char flat_number[koll];
    }two;
    two addr_two;

    typedef  struct{
        char region[koll];
        char district[koll];
        char village_name[koll];
        char street[koll];
        char flat_number[koll];
    }three;
    three addr_three;

    typedef struct{
        char region[koll];
        char district[koll];
        char sity[koll];
        char street[koll];
        char house_number[koll];
        char flat_number[koll];
    }four;
    four addr_four;

    typedef struct students_info{
        char inform[koll];
        char type_addr;
        union choise_1{
            one minsk;
            two oblsnoy_gorod;
            three derevnai;
            four neoblosnoy_gorod; 
        }addr_type;
    }students_info;
    students_info students_list;


    void clear_screen()
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    char *gets_s(char *s, size_t buf_size)
    {
        char *result;
        result = fgets(s, buf_size, stdin);
        result[strlen(s) - 1] = '\0';
        return result;
    }

    students_info  enter_students_one( students_info student_list)
    {
        char input_buffer[input_buf_size];
        int name_street_size= SIZE(student_list.addr_type.minsk.street);
        int house_number_size= SIZE(student_list.addr_type.minsk.house_number);
        int flat_number_size= SIZE(student_list.addr_type.minsk.flat_number);
        clear_screen();
        printf("Enter the street name :");
        gets_s(student_list.addr_type.minsk.street,name_street_size);
        printf("Enter the house number : ");
        gets_s(student_list.addr_type.minsk.house_number,house_number_size);
        printf("enter the the apartment number :");
        gets_s(student_list.addr_type.minsk.flat_number,flat_number_size);
        return student_list;
    }

    students_info  enter_students_two( students_info students_list)
    {
        char input_buffer[input_buf_size];
        int district_size= SIZE(students_list.addr_type.oblsnoy_gorod.district);
        int sity_size= SIZE(students_list.addr_type.oblsnoy_gorod.sity);
        int name_street_size= SIZE(students_list.addr_type.oblsnoy_gorod.street);
        int house_number_size= SIZE(students_list.addr_type.oblsnoy_gorod.house_number);
        int flat_number_size= SIZE(students_list.addr_type.oblsnoy_gorod.flat_number);
        clear_screen();
        printf("Enter name of the regional city :");
        gets_s(students_list.addr_type.oblsnoy_gorod.district,district_size);
        printf("Enter the name of the city :");
        gets_s(students_list.addr_type.oblsnoy_gorod.sity,sity_size);
        printf("Enter the street name :");
        gets_s(students_list.addr_type.oblsnoy_gorod.street,name_street_size);
        printf("Enter the house number : ");
        gets_s(students_list.addr_type.oblsnoy_gorod.house_number,house_number_size);
        printf("enter the the apartment number :");
        gets_s(students_list.addr_type.oblsnoy_gorod.flat_number,flat_number_size);
        return students_list;
    }

    students_info  enter_students_three( students_info students_list)
    {
        char input_buffer[input_buf_size]; 
        int region_size=SIZE(students_list.addr_type.derevnai.region);
        int district_size= SIZE(students_list.addr_type.derevnai.district);
        int flat_number_size= SIZE(students_list.addr_type.derevnai.village_name);
        int village_name_size= SIZE(students_list.addr_type.derevnai.flat_number);
        int street_size= SIZE(students_list.addr_type.derevnai.street);
        clear_screen();
        printf("Enter name of the region :");
        gets_s(students_list.addr_type.derevnai.region,region_size);
        printf("Enter name of the district:");
        gets_s(students_list.addr_type.derevnai.district,district_size);
        printf("Enter name of the village:");
        gets_s(students_list.addr_type.derevnai.village_name,village_name_size);
        printf("Enter name of she street :");
        gets_s(students_list.addr_type.derevnai.street,street_size);
        printf("Enter the number of house:");
        gets_s(students_list.addr_type.derevnai.flat_number,flat_number_size);
        return students_list;

    }

    students_info  enter_students_four( students_info students_list)
    {
        char input_buffer[input_buf_size];
        int region_size = SIZE(students_list.addr_type.neoblosnoy_gorod.region);
        int district_size= SIZE(students_list.addr_type.neoblosnoy_gorod.district);
        int sity_size= SIZE(students_list.addr_type.neoblosnoy_gorod.sity);
        int name_street_size= SIZE(students_list.addr_type.neoblosnoy_gorod.street); 
        int house_number_size= SIZE(students_list.addr_type.neoblosnoy_gorod.house_number);
        int flat_number_size= SIZE(students_list.addr_type.neoblosnoy_gorod.flat_number);
        clear_screen();
        printf("Enter name of region: ");
        gets_s(students_list.addr_type.neoblosnoy_gorod.region,region_size);
        printf("Enter name of the district: ");
        gets_s(students_list.addr_type.neoblosnoy_gorod.district,district_size);
        printf("Entre name of the street:");
        gets_s(students_list.addr_type.neoblosnoy_gorod.sity,sity_size);
        printf("vvedite nasnvanie ylici: ");
        gets_s(students_list.addr_type.neoblosnoy_gorod.street,name_street_size);
        printf("Enter the number of house: ");
        gets_s(students_list.addr_type.neoblosnoy_gorod.house_number,house_number_size);
        printf("Enter the number of flat: ");
        gets_s(students_list.addr_type.neoblosnoy_gorod.flat_number,flat_number_size);
        return students_list;
    }

    students_info  vibor_adres(students_info students_list)
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
    students_info  vibor_adres_chek(students_info students_list )
    {
        char input_buffer[input_buf_size];
        int type_addr_size=SIZE(&students_list.type_addr);
        while(1){
            printf("Enter adress of %sSelect the type of address\n1- Minsk\n2- oblsnoygorod\n3- Neoblosnoy gorod\n4- derevnia\n",students_list.inform);
            gets_s(&students_list.type_addr,type_addr_size);break;
        }
        students_list = vibor_adres(students_list);
        return students_list;
    }

    void enter_inform_students(students_info *students_list)
    {
        int i;
        int inform_size=SIZE(students_list[i].inform);
        for(i=0;i<number_of_students;i++){
            printf("Enter surname of %d student\n",i+1);
            gets_s(students_list[i].inform,inform_size);
            students_list[i] = vibor_adres_chek(students_list[i]);
            system("clear");
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

    void puts_obls_gorod(students_info* students_list)
    {
        int i = 0;
        for (i = 0; i < number_of_students; i++){
            if(students_list[i].type_addr == '2'){
                printf("Student %s from %s, street %s, house %d, flat %d\n",
                    students_list[i].inform,
                    students_list[i].addr_type.oblsnoy_gorod.district,
                    students_list[i].addr_type.oblsnoy_gorod.sity,
                    students_list[i].addr_type.oblsnoy_gorod.street,
                    students_list[i].addr_type.oblsnoy_gorod.house_number,
                    students_list[i].addr_type.oblsnoy_gorod.flat_number);
            }
        }
    }

    void puts_neobl_gorod(students_info* students_list)
    {
        int i = 0;
        for (i = 0; i < number_of_students; i++){
            if(students_list[i].type_addr == '3'){
                printf("Student %s from %s, street %s, house %d, flat %d\n",
                    students_list[i].inform,
                    students_list[i].addr_type.neoblosnoy_gorod.region,
                    students_list[i].addr_type.neoblosnoy_gorod.district,
                    students_list[i].addr_type.neoblosnoy_gorod.sity,
                    students_list[i].addr_type.neoblosnoy_gorod.street,
                    students_list[i].addr_type.neoblosnoy_gorod.house_number,
                    students_list[i].addr_type.neoblosnoy_gorod.flat_number);
            }
        }
    }

    void puts_derev(students_info* students_list)
    {
        int i = 0;
        for (i = 0; i < number_of_students; i++){
            if(students_list[i].type_addr == '4'){
                printf("Student %s from %s, street %s, house %d, flat %d\n",
                    students_list[i].inform,
                    students_list[i].addr_type.derevnai.district,
                    students_list[i].addr_type.derevnai.village_name,
                    students_list[i].addr_type.derevnai.flat_number);
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

    void checkHelp(void)
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
        exit(0);
    }

    int main(int argc, char *argv[])
    {
        struct students_info students_list[number_of_students];
        if (argc > 1){
            if (!strcmp(argv[1], "-h")){
                checkHelp();
            }
        }
        enter_inform_students(students_list);
        if (argc > 1){
            if (!strcmp(argv[1], "-m")){
                puts_minsk(students_list);
            }
            if (!strcmp(argv[1], "-c")){
                puts_obls_gorod(students_list);
            }
            if (!strcmp(argv[1], "-t")){
                puts_neobl_gorod(students_list);
            }
            if (!strcmp(argv[1], "-v")){
                puts_derev(students_list);
            }
            if (!strcmp(argv[1], "-l")){
                puts_all_stud(students_list);
            }
        }
        return 0;
    }

#ifdef __cplusplus
}
#endif