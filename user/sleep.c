#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(argc < 2 || argc > 3){
    fprintf(2, "Usage: sleep [--snore] seconds_to_sleep\n");
    exit(1);
  }

  int sleep_arg_idx = 1;
  int snore = 0;

  if (argc == 3) {
    if (strcmp("--snore", argv[1]) == 0) {
      snore = 1;
      sleep_arg_idx = 2;
    } else {
      fprintf(2, "Usage: sleep [--snore] seconds_to_sleep\n");
      exit(1);
    }
  }

  int sleep_seconds = atoi(argv[sleep_arg_idx]);
  while(sleep_seconds-- > 0) {
    if (snore) printf("z");
    sleep(10); // comments in usertests.c indicate this `sleep()` takes the
               // time to sleep in deciseconds
  }

  if (snore) printf("\n");

  exit(0);
}
