#include<stdio.h>


struct one{
char street[20];
int house_number[20];
int flat_number[20];
};

struct two{		
char district[20];
char sity[20];
char street[20];
int house_number[20];
int flat_number[20];
};

struct three{
char district[20];
char village_name[20];
int flat_number[20];
};

struct four{
char region[20];
union choise_2{
struct two another_sity;
struct three from_village; };
};

struct students_info{
char inform[256];
union choise_1{
struct one minsk;
struct four from_out_of_town; };
}


int main()
{

}