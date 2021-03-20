
#define f_wielomianowa -(((x + 1.0) * x - 2.0) * x - 1.0)
#define p_f_wielomianowa -((3 * x + 2) * x - 2)

#define f_trygonometryczna sin(x) - cos(x + 1.0)
#define p_f_trygonometryczna cos(x) + sin(x + 1.0)

#define f_wykladnicza exp(x) - 4.0 * x
#define p_f_wykladnicza exp(x) - 4.0

#define f_mieszana sin(exp(-x*x)) - 0.5
#define p_f_mieszana -2 * exp(-x*x) * x * cos(exp(-x*x))

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
