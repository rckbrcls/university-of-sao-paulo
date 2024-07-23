#include <stdio.h>
#include <math.h>

int main (){
  float delta, a, b, c, x1, x2;

  scanf ("%f %f %f", &a, &b, &c);

  delta = (b * b) - (4 * a * c);

  if (delta < 0)
    {
      printf ("Delta Negativo\n");
      return 0;
    }

    x1 = (-b + sqrt(delta))/(2*a);
    x2 = (-b - sqrt(delta))/(2*a);

  printf ("%.1f\n%.1f\n", x1, x2);
  return 0;
}