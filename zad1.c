#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct rectangle_t {
    struct point_t {
        double x;
        double y;
    } A, B;
};
int COUNT;
struct rectangle_t *rectangle_list(int count) {
    struct rectangle_t *list = malloc(count * sizeof(struct rectangle_t));
    for (int i = 0; i < count; i++) {
        list[i].A.x = rand() % 21 - 10;
        list[i].A.y = rand() % 21 - 10;
        list[i].B.x = rand() % 21 - 10;
        list[i].B.y = rand() % 21 - 10;
    }
    return list;
}
double areaRects(struct rectangle_t *list) {
    double area = 0;
    for (int i = 0; i < COUNT; i++) {
        area += (list[i].B.x - list[i].A.x) * (list[i].B.y - list[i].A.y);
    }
    return area;
}
void filterRects(struct rectangle_t **list, double min, double max) {
    int count = 0;
    for (int i = 0; i < COUNT; i++) {
        if ((list[i]->A.x - list[i]->B.x) * (list[i]->A.y - list[i]->B.y) >= min && (list[i]->A.x - list[i]->B.x) * (list[i]->A.y - list[i]->B.y) <= max) {
            count++;
        }
    }
    struct rectangle_t *new_list = malloc(count * sizeof(struct rectangle_t));
    int j = 0;
    for (int i = 0; i < COUNT; i++) {
        if ((list[i]->A.x - list[i]->B.x) * (list[i]->A.y - list[i]->B.y) >= min && (list[i]->A.x - list[i]->B.x) * (list[i]->A.y - list[i]->B.y) <= max) {
            new_list[j] = *list[i];
            j++;
        }
    }
    *list = new_list;
}
void print_list(struct rectangle_t *list) {
    for (int i = 0; i < COUNT; i++) {
        printf("Rectangle %d: A(%f,%f), B(%f,%f)\n", i, list[i].A.x, list[i].A.y, list[i].B.x, list[i].B.y);
    }
}
     int main() {
        struct rectangle_t rect;
        struct point_t *p;
        p = &rect.A;
        p->x = 1.0;
        p->y = 2.0;
        p = &rect.B;
        p->x = 3.0;
        p->y = 4.0;
        printf("rectangle A: (%f, %f)\n", rect.A.x, rect.A.y);
        printf("rectangle B: (%f, %f)\n", rect.B.x, rect.B.y);
        printf("rectangle area: %f\n", (rect.B.x - rect.A.x) * (rect.B.y - rect.A.y));
        struct rectangle_t *list = rectangle_list(COUNT);
        print_list(list);
        filterRects(&list, 0, 10);
        printf("\n");
        print_list(list);
        printf("\n");
        printf("area of rectangles: %f\n", areaRects(list));
        return 0;
     }
