cc seminit.c semaphore.c -o seminit &&
cc semdown.c semaphore.c -o semdown &&
cc semstat.c semaphore.c -o semstat &&
./seminit &&
./semdown && ./semdown &&
./semstat