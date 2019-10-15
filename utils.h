#ifndef UTILS_H
#define UTILS_H

// Define debugging assert
#ifndef DEBUG
#define ASSERT(X)
#else
#define ASSERT(x) \
if(!(x)) { \
printf("Assert failed: %s, on %s, at %s\n", #x, __DATE__, __TIME__); \
printf("File %s, line %d\n", __FILE__, __LINE__); \
exit(-1); \
}
#endif

// Big line delimitator print
#define PRINT_DELIM printf("==============================================================\n")

#endif