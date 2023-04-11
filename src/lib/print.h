struct point {
    double x;
    double y;
};

struct circle {
    struct point point;
    double r;
};
void Print_Result(struct circle* circle, int nCircle);
void Print_Error(char* str, int n);