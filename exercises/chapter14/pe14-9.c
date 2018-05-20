/* pe14.9 -- ticket.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SEATNUM 12
#define FLIGHT_NUM 4
struct name {
    char first[20];
    char last[20];
};

struct seat {
    int id;
    int assigned;
    struct name customer;
};

char show_menu(void);
void eat_line(void);

void init_seats(struct seat seats[], int n);
int get_empty_seat_number(struct seat seats[], int n);
void show_empty_seats(struct seat seats[], int n);
void show_seats(struct seat seats[], int n);
int assign_customer_to_seat_and_save(struct seat seats[], int n, FILE* fp);
int delete_seat_assignment(struct seat seats[], int n, FILE* fp);

char main_menu(void);
void process_flight(const char* flight_name, int flight_num);

int main(void)
{
    char flight_names[FLIGHT_NUM][20] = {
        "flight_102.dat",
        "flight_311.dat",
        "flight_444.dat",
        "flight_519.dat"
    };
    int flight_nums[FLIGHT_NUM] = {
        102, 311, 444, 519
    };
    char choice;
    
    choice = main_menu();
    while (choice != 'q') {
        process_flight(flight_names[choice-'a'], flight_nums[choice-'a']);
        choice = main_menu();
    }
    puts("Bye.");
    return 0;
}

char show_menu(void) {
    char choice;
    puts("-----------------------------------------------");
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of empty seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Quit");
    
    choice = getchar();
    eat_line();
    
    while (strchr("abcdef", choice) == NULL) {
        puts("Enter a, b, c, d, e or f:");
        choice = getchar();
        eat_line();
    }
    
    return choice;
}

void eat_line()
{
    while (getchar() != '\n')
        continue;
}

int get_empty_seat_number(struct seat seats[], int n)
{
    int num = 0;
    int i;
    
    for (i = 0; i < n; i++) {
        if (seats[i].assigned == 0)
            num++;
    }
    
    return num;
}

void init_seats(struct seat seats[], int n)
{
    int i;
    
    for (i = 0; i < n; i++) {
        seats[i].id = i;
        seats[i].assigned = 0;
    }
}

void show_empty_seats(struct seat seats[], int n)
{
    int i;
    
    for (i = 0; i < n; i++) {
        if (seats[i].assigned == 0) {
            printf("%d ", seats[i].id);
        }
    }
    putchar('\n');
}

int assign_customer_to_seat_and_save(struct seat seats[], int n, FILE* fp)
{
    struct name customer_name;
    int i;
    
    puts("Enter custom name:");
    scanf("%s %s", customer_name.first, customer_name.last);
    eat_line();
    for (i = 0; i < n; i++) {
        if (seats[i].assigned == 0) {
            seats[i].customer = customer_name;
            seats[i].assigned = 1;
            printf("Seat %d assigned to %s %s\n", seats[i].id, customer_name.first, customer_name.last);
            
            fseek(fp, i * sizeof(struct seat) * 1L, SEEK_SET);
            fwrite(&(seats[i]), sizeof(struct seat), 1, fp);
            return 1;
        }
    }
    
    puts("Sorry, seats are full.");
    return 0;
}

void show_seats(struct seat seats[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        if (seats[i].assigned == 1) {
            printf("Seat %d, Customer: %s %s\n", seats[i].id, seats[i].customer.first, seats[i].customer.last);
        }
    }
    putchar('\n');
}

int delete_seat_assignment(struct seat seats[], int n, FILE* fp)
{
    int seat_id;
    puts("Which seat do you want to delete assignment");
    scanf("%d", &seat_id);
    eat_line();
    
    if (seat_id < n) {
        seats[seat_id].assigned = 0;
        printf("Seat %d now is empty.\n", seat_id);
        
        fseek(fp, seat_id * sizeof(struct seat) * 1L, SEEK_SET);
        fwrite(&(seats[seat_id]), sizeof(struct seat), 1, fp);
        
        return 1;
    } else {
        printf("Invalid seat id: %d", seat_id);
        return 0;
    }
}

void process_flight(const char* flight_name, int flight_num)
{
    struct seat flight[SEATNUM];
    char choice;
    FILE* fp;
    
    // Open file
    fp = fopen(flight_name, "r+b");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open file %s\n", flight_name);
        exit(1);
    }
    
    // Read file content
    if (0 == fread(flight, sizeof(struct seat), SEATNUM, fp)) {
        init_seats(flight, SEATNUM);
        puts("Init flight");
    }
    
    while ((choice = show_menu()) != 'f') {
        switch (choice) {
            case 'a':
                printf("%d empty seats left for flight %d.\n", get_empty_seat_number(flight, SEATNUM), flight_num);
                break;
            case 'b':
                printf("Empty seats for flight %d: \n", flight_num);
                show_empty_seats(flight, SEATNUM);
                break;
            case 'c':
                printf("Seats for flight %d: \n", flight_num);
                show_seats(flight, SEATNUM);
                break;
            case 'd':
                printf("Assign customer to seat for flight %d: \n", flight_num);
                assign_customer_to_seat_and_save(flight, SEATNUM, fp);
                break;
            case 'e':
                printf("Delete a seat for flight %d: \n", flight_num);
                delete_seat_assignment(flight, SEATNUM, fp);
            case 'f':
            default:
                break;
        }
    }
    fclose(fp);
}

char main_menu(void)
{
    char choice;
    
    puts("Which flight would you like to travel?");
    puts("a) Flight 102               b) Flight 311");
    puts("c) Flight 444               d) Flight 518");
    puts("q) quit");
    
    choice = getchar();
    eat_line();
    
    while (strchr("abcdq", choice) == NULL) {
        puts("Enter a, b, c, d or q:");
        choice = getchar();
        eat_line();
    }
    
    return choice;
}