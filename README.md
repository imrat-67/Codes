template <class T>
long double polynomial_equation_solver(T a,T b,T c){
    long double x = (- b + sqrtl(b*b-4*a*c) ) /2 /a;
    return x;
}
