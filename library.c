#include <stdio.h>
#include <math.h>

#define EPS 1e-9

int isPrime(int n) {
    int i;

    if (n < 2)
        return 0;

    for (i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

void task18() {
    int i;

    for (i = 2; i <= 20; i++) {
        printf("sin(%d) = %.6f\n", i, sin(i));
    }
}

void task34() {
    int n, i;
    double x, sum = 0, power;

    printf("Enter x: ");
    scanf("%lf", &x);

    printf("Enter n: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Incorrect n\n");
        return;
    }

    power = x;

    for (i = 1; i <= n; i++) {
        sum += sin(power);
        power *= x;
    }

    printf("Sum = %.6f\n", sum);
}

void task83() {
    int i;
    double mass, max;

    printf("Enter mass of item 1: ");
    scanf("%lf", &max);

    for (i = 2; i <= 12; i++) {
        printf("Enter mass of item %d: ", i);
        scanf("%lf", &mass);

        if (mass > max)
            max = mass;
    }

    printf("Maximum mass = %.2f\n", max);
}

void task90() {
    int i;
    double a, sum = 0;

    for (i = 1; i <= 10; i++) {
        printf("Enter a%d: ", i);
        scanf("%lf", &a);

        sum += a;
    }

    printf("Average = %.2f\n", sum / 10);
}

void task109() {
    int x, n, i, prime;

    for (x = 0; x <= 15; x++) {
        n = x * x + x + 17;
        prime = 1;

        for (i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                prime = 0;
                break;
            }
        }

        printf("%d: %d - %s\n",
               x, n, prime ? "prime" : "not prime");
    }
}

void task145() {
    int n, a, b, c, found;

    for (n = 6; n <= 100; n++) {
        found = 0;

        for (a = 2; a <= n && !found; a++) {
            for (b = 2; b <= n && !found; b++) {
                c = n - a - b;

                if (isPrime(a) && isPrime(b) && isPrime(c)) {
                    printf("%d = %d + %d + %d\n", n, a, b, c);
                    found = 1;
                }
            }
        }

        if (!found)
            printf("%d - representation not found\n", n);
    }
}

void task146() {
    int n, i;

    for (n = 4; n <= 50; n += 2) {
        for (i = 2; i <= n / 2; i++) {
            if (isPrime(i) && isPrime(n - i)) {
                printf("%d = %d + %d\n", n, i, n - i);
                break;
            }
        }
    }
}

void task207() {
    int n = 1;
    double eps, a = 1.0 / 3.0;
    double sum = 0;

    printf("Enter epsilon: ");
    scanf("%lf", &eps);

    if (eps <= 0) {
        printf("Epsilon must be positive\n");
        return;
    }

    while (fabs(a) >= eps) {
        sum += a;
        n++;
        a *= pow((double)(n - 1) / n, n - 1);
    }

    printf("Sum = %.10f\n", sum);
}

void task242() {
    double a, b, q, x, y;
    int i;

    printf("Enter a: ");
    scanf("%lf", &a);

    printf("Enter b: ");
    scanf("%lf", &b);

    printf("Enter q: ");
    scanf("%lf", &q);

    if (q <= 0 || a > b) {
        printf("Incorrect input\n");
        return;
    }

    printf("\n       x          F(x)\n");

    for (i = 0; ; i++) {
        x = a + i * q;

        if (x > b + EPS)
            break;

        y = x * x * sin(x) * sin(x) + 1;

        printf("%10.4f %12.6f\n", x, y);
    }
}

void task251() {
    double a = 0.2, b = 4, c = -3;
    double y;
    int x[] = {1, 2, 4, 7, 11, 16, 22};
    int i;

    printf("\n       x          y\n");

    for (i = 0; i < 7; i++) {
        y = a * x[i] * x[i] + b * x[i] + c;
        printf("%10d %12.2f\n", x[i], y);
    }
}

int main() {
    int choice;

    do {
        printf("\n========== MENU ==========\n");
        printf("18  - Dryk sin\n");
        printf("34  - Syma sin\n");
        printf("83  - Max masa\n");
        printf("90  - Seredne arufmet\n");
        printf("109 - Programa dla perevirku\n");
        printf("145 - Perevirka Goltbacha menshe 100\n");
        printf("146 - Perevirka Goltbacha bilshe 50\n");
        printf("207 - Suma rady\n");
        printf("242 - Tablucia funkci\n");
        printf("251 - Kvadrstuchna funkcia\n");
        printf("0   - Exit\n");
        printf("=====================================\n");

        printf("Choose task: ");
        scanf("%d", &choice);

        switch (choice) {
            case 18:
                task18();
                break;

            case 34:
                task34();
                break;

            case 83:
                task83();
                break;

            case 90:
                task90();
                break;

            case 109:
                task109();
                break;

            case 145:
                task145();
                break;

            case 146:
                task146();
                break;

            case 207:
                task207();
                break;

            case 242:
                task242();
                break;

            case 251:
                task251();
                break;

            case 0:
                printf("Program finished.\n");
                break;

            default:
                printf("There is no such task!\n");
        }

    } while (choice != 0);

    return 0;
}