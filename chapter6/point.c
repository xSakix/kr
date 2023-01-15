#include <stdio.h>
#include <math.h>

struct point{
    int x;
    int y;
};

struct rect{
    struct point pt1;
    struct point pt2;
};

void print_point(struct point);
void print_rect(struct rect);
double dist(struct point);


int main(){

    struct point x;
    x.x = 1, x.y = 2;
    print_point(x);
    printf("distance from (0,0) = %.2f\n",dist(x));

    struct point p2 = {100,200};
    print_point(p2);
    printf("distance from (0,0) = %.2f\n",dist(p2));

    struct rect screen = {x,p2};
    print_rect(screen);

    return 0;
}

void print_point(struct point p){
    printf("(%d,%d)\n",p.x,p.y);
}

void print_rect(struct rect r){
    printf("rectangle\n\tfrom:");
    print_point(r.pt1);
    printf("\tto:");
    print_point(r.pt2);
}

double dist(struct point pt){
    return sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
}
