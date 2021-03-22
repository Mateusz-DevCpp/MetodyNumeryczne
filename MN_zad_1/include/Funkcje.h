
#define f_o_wielomianowa "-12*x**3 + 42*x**2 - 49*x + 17"
#define f_wielomianowa -12*x*x*x + 42*x*x - 49*x + 17
#define p_f_wielomianowa -36*x*x + 84*x - 49

#define f_o_trygonometryczna "sin(x) + 3*cos(0.7*x)"
#define f_trygonometryczna sin(x) + 3*cos(0.7*x)
#define p_f_trygonometryczna cos(x) - 2.1*sin(0.7*x)

#define f_o_wykladnicza "exp(x-1)-0.25"
#define f_wykladnicza exp(x-1)-0.25
#define p_f_wykladnicza exp(x-1)

#define f_o_mieszana "exp(sin(5*x))-4*x+sin(10*x)-3"
#define f_mieszana exp(sin(5*x))-4*x+sin(10*x)-3
#define p_f_mieszana 5*exp(sin(5*x))*cos(5*x)+10*cos(10*x)-4


double wielomian(double x)
{
    return (f_wielomianowa);
}
double wielomian_p(double x)
{
    return (p_f_wielomianowa);
}

double trygon(double x)
{
    return (f_trygonometryczna);
}
double trygon_p(double x)
{
    return (p_f_trygonometryczna);
}

double wykladnicza(double x)
{
    return (f_wykladnicza);
}
double wykladnicza_p(double x)
{
    return (p_f_wykladnicza);
}

double mieszana(double x)
{
    return (f_mieszana);
}
double mieszana_p(double x)
{
    return (p_f_mieszana);
}
