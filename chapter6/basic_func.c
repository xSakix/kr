#include <stdio.h>

#define XMAX 800
#define YMAX 600
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

struct point {
    int x;
    int y;
};

struct rect{
    struct point pt1;
    struct point pt2;
};

struct point makepoint(int x, int y);
void print_point(struct point);
struct point addpoint(struct point p1, struct point p2);
int ptinrect(struct point p, struct rect r);
struct rect canonrect(struct rect r);
void print_rect(struct rect);


int main(){

    struct point p = makepoint(1,2);
    print_point(p);

    struct rect screen;
    struct point middle;

    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);
    print_point(screen.pt1);
    print_point(screen.pt2);

    middle = makepoint(
        (screen.pt1.x + screen.pt2.x)/2,
        (screen.pt1.y + screen.pt2.y)/2        
    );
    print_point(middle);

    //structures are 'send' to method by value, not by reference
    struct point pc = addpoint(p, middle);
    print_point(p);
    print_point(pc);

    printf("%d\n",ptinrect((struct point){100,200},(struct rect) {{0,0},{200,300}}));
    printf("%d\n",ptinrect((struct point){300,300},(struct rect) {{0,0},{200,300}}));

    struct rect wrong = {{100,200},{0,0}};
    print_rect(wrong);

    print_rect(canonrect(wrong));

    struct point *pp = &pc;
    printf("pointer point = (%d,%d)\n",(*pp).x, (*pp).y); //do-not-use
    printf("pointer point = (%d,%d)\n",pp->x, pp->y); //use-this
    
    //this will increment x, y and not the pointer
    ++pp->x;
    ++pp->y;
    print_point(*pp); //definition is by value here, so need to use '*'
    
    struct rect *rptr = &wrong;

    printf("rectangle from (%d,%d) -> (%d,%d)\n", rptr->pt1.x, rptr->pt1.y, rptr->pt2.x, rptr->pt2.y);

    return 0;
}

struct point makepoint(int x, int y){
    return (struct point){x,y};
}


void print_point(struct point p){
    printf("(%d,%d)\n",p.x,p.y);
}

struct point addpoint(struct point p1, struct point p2){
    //we can do this, because we get only p1 and p2 as value, not as reference
    p1.x += p2.x;
    p1.y += p2.y;

    return p1;
}

int ptinrect(struct point p, struct rect r){
    return p.x >= r.pt1.x && p.x <= r.pt2.x && p.y >= r.pt1.y && p.y <= r.pt2.y;
}

struct rect canonrect(struct rect r){
    return (struct rect){
        {min(r.pt1.x,r.pt2.x),min(r.pt1.y, r.pt2.y)},
        {max(r.pt1.x,r.pt2.x), max(r.pt1.y, r.pt2.y)}
    };
}

void print_rect(struct rect r){
    printf("rectangle\n\tfrom:");
    print_point(r.pt1);
    printf("\tto:");
    print_point(r.pt2);
}


