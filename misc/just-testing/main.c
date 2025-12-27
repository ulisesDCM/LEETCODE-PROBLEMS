#include <stdio.h>
#include <stdint.h>

typedef union 
{
    int a;
    int b;
}my_union;

union my_union2{
    int c;
    int d;
};

struct Book{
    char *name;
    int pages;
    float price;
};

struct bit_fields{
    uint8_t a:2;
    uint16_t b:4;
};

int main(void){
    /* **************** Union test  *****************/
    my_union un1;
    un1.a = 1;
    un1.b = 5;
    my_union *ptr_un1 = &un1;

    ptr_un1->a = 10;

    printf("un1.a = %d \t un1.b = %d\n",un1.a, un1.b);
    printf("ptr_un1->a = %d\t ptr_un1->b = %d\n",ptr_un1->a, ptr_un1->b);
    printf("&addr.ptr_un1 = %p \t addr.ptr_un1 = %p \t addr.ptr_un1->a = %p\t addr.ptr_un1->b = %p\n", &ptr_un1, ptr_un1, &ptr_un1->a, &ptr_un1->b);
    printf("un1 = %ld \t un1.a = %ld \t un1.b = %ld \n", sizeof(un1), sizeof(un1.a), sizeof(un1.b));
    printf("sizeof(ptr_un1) = %ld \t sizeof(ptr_un1->a) = %ld \t sizeof(ptr_un1->b) = %ld \n", sizeof(ptr_un1), sizeof(ptr_un1->a), sizeof(ptr_un1->b));
    printf("\n");

    /* **************** Union test 2  *****************/
    union my_union2 un2, *ptr_un2;
    un2.c = 11;
    un2.d = 15;
    ptr_un2=&un2;
    ptr_un2->c = 13;

    printf("un2.c = %d \t un2.d = %d\n",un2.c, un2.d);
    printf("ptr_un2->c = %d\t ptr_un2->d = %d\n",ptr_un2->c, ptr_un2->d);
    printf("&cddr.ptr_un2 = %p \t cddr.ptr_un2 = %p \t cddr.ptr_un2->c = %p\t cddr.ptr_un2->d = %p\n", &ptr_un2, ptr_un2, &ptr_un2->c, &ptr_un2->d);
    printf("sizeof(ptr_un2) = %ld \t sizeof(ptr_un2->c) = %ld \t sizeof(ptr_un2->d) = %ld \n", sizeof(ptr_un2), sizeof(ptr_un2->c), sizeof(ptr_un2->d));
    printf("\n");

    /* **************** Structure test  *****************/
    struct Book book1;
    book1.name = "My Book1";
    book1.pages = 14;
    book1.price = 200;
    
    printf("book1.name = %s \t, book1.pages = %d \t book1.price = %f \n",book1.name, book1.pages, book1.price);
    printf("sizeof(book1) = %ld \t sizeof(book1.name) = %ld \t sizeof(book1.pages) = %ld \t sizeof(book1.price) = %ld\n", sizeof(book1), sizeof(book1.name), sizeof(book1.pages), sizeof(book1.price));
    printf("\n");

    /* **************** Bit fields test  *****************/
    struct bit_fields my_bit_field;
    my_bit_field.a = 0b10;
    my_bit_field.b = 0b1000;
    printf("my_bit_field.a = %d \t my_bit_field = %d \n",my_bit_field.a, my_bit_field.b);
    printf("sizeof(my_bit_field) = %ld \t sizeof(my_bit_field.a) = operand of sizeof may not be a bit field C \n",sizeof(my_bit_field));

    return 1;
}