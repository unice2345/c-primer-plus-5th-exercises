/* pe14.8 -- ticket.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SEATNUM 12
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
void save_seats(struct seat seats[], int n, FILE* fp);

int main(void)
{
    struct seat plane[SEATNUM];
    char choice;
    FILE* fp;
    
    // Open file
    fp = fopen("plane.dat", "r+b");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open file\n");
        exit(1);
    }
    
    // Read file content
    if (0 == fread(plane, sizeof(struct seat), SEATNUM, fp)) {
        init_seats(plane, SEATNUM);
        puts("Init plane");
    }
    
    while ((choice = show_menu()) != 'f') {
        switch (choice) {
            case 'a':
                printf("%d empty seats left.\n", get_empty_seat_number(plane, SEATNUM));
                break;
            case 'b':
                show_empty_seats(plane, SEATNUM);
                break;
            case 'c':
                show_seats(plane, SEATNUM);
                break;
            case 'd':
                assign_customer_to_seat_and_save(plane, SEATNUM, fp);
                break;
            case 'e':
                delete_seat_assignment(plane, SEATNUM, fp);
            case 'f':
            default:
                break;
        }
    }
    puts("Bye.");
    fclose(fp);
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
    
    puts("Empty seats: ");
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

void save_seats(struct seat seats[], int n, FILE* fp) {
  
    fclose(fp);
    fp = fopen("plane.dat", "w+b");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open file with w+b\n");
    }
    fwrite(seats, sizeof(struct seat), n, fp);
}