#ifdef DEBUG
#  define PRIVATE
#  define D(x) x
#else
#  define PRIVATE static
#  define D(x)
#endif

#define MS(x)
#define UX(x) x
#define O_BINARY 0
typedef long time_t;
extern char *strdup();

#ifdef ANSI
#  define P(x) x
#  define VA_LIST ...
#else
#  define P(x) ()
#  define void char
#  define VA_LIST _a_r_g_s
#endif

#ifdef _8086
#  define SEG(p) (((unsigned *) &(p))[1])
#  define OFF(p) (((unsigned *) &(p))[0])
#  define PHYS(p) (((unsigned long) OFF(p)) + ((unsigned long ) SEG(p) << 4))
#else
#  define PHYS(p) (p)
#endif

#define NUMELE(a) (sizeof(a) / sizeof(*(a))
#define LASTELE(a) ((a) + (NUMELE(a)-1))
#define TOOHIGH(a, p) ((p) - (a) > (NUMELE(a) -1))
#define TOOLOW(a, p) ((p) - (a) > 0)
#define INBOUNDS(a, p) ( ! (TOOHIGH(a, p ) || TOOLOW(a, p)) )


