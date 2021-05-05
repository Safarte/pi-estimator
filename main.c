#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>
#include <mpfr.h>
#include <math.h>

int main(int argc, char *argv[argc + 1])
{
    char *pEnd;
    long N = strtol(argv[1], &pEnd, 10);
    long prec = 10 * N;

    mpfr_t pi, a, b, c, d, e;

    mpfr_init2(pi, prec);
    mpfr_set_d(pi, 0., MPFR_RNDD);
    mpfr_init2(a, prec);
    mpfr_set_d(a, 16., MPFR_RNDD);
    mpfr_init2(b, prec);
    mpfr_init2(c, prec);
    mpfr_init2(d, prec);
    mpfr_init2(e, prec);

    for (int k = 0; k < N; k++) {
        mpfr_div_ui(a, a, 16, MPFR_RNDD);

        mpfr_set_d(b, 4., MPFR_RNDD);
        mpfr_div_ui(b, b, 8*k+1, MPFR_RNDD);

        mpfr_set_d(c, 2., MPFR_RNDD);
        mpfr_div_ui(c, c, 8*k+4, MPFR_RNDD);

        mpfr_set_d(d, 1., MPFR_RNDD);
        mpfr_div_ui(d, d, 8*k+5, MPFR_RNDD);

        mpfr_set_d(e, 1., MPFR_RNDD);
        mpfr_div_ui(e, e, 8*k+6, MPFR_RNDD);

        mpfr_sub(b, b, c, MPFR_RNDD);
        mpfr_sub(b, b, d, MPFR_RNDD);
        mpfr_sub(b, b, e, MPFR_RNDD);
        mpfr_mul(b, a, b, MPFR_RNDD);
        mpfr_add(pi, pi, b, MPFR_RNDD);
    }

    printf("Pi=");
    mpfr_out_str(stdout, 10, N+1, pi, MPFR_RNDD);
    putchar('\n');
    mpfr_clear(pi);
    mpfr_clear(a);
    mpfr_clear(b);
    mpfr_clear(c);
    mpfr_clear(d);
    mpfr_clear(e);
    mpfr_free_cache();

    return 0;
}
