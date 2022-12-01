./seminit &&
# put 2 in queue
./semdown && ./semdown &&
./semstat &&
# take first from queue
./semup &&
./semstat