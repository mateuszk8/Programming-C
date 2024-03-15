#include <stdio.h>

struct Point {
    float x;
    float y;
};

void change(struct Point *p, float newX, float newY) {
    p->x = newX;
    p->y = newY;
}

struct Rectangle {
    float a;
    float b;
    
};

void liczenie(struct Rectangle r) {
    float pole = r.a * r.b;
    printf("Pole: %.1f\n", pole);
    float obwod = 2*r.a + 2*r.b;
    printf("Obwód: %.1f", obwod);
}

int main() {
   struct Point point = {1,2};
   printf("Punkt: [%.1f,%.1f]\n", point.x, point.y);
   change(&point, 2,5);
   printf("Nowy punkt: [%.1f,%.1f]\n", point.x, point.y);
   struct Rectangle prostokat = {5,10};
   liczenie(prostokat);
   return 0;
}
