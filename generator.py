import random
import sys

rng  = int(sys.argv[1] if len(sys.argv) > 1 else 1000)
seed = sys.argv[2] if len(sys.argv) > 2 else None

random.seed(seed)

for i in range (rng):
	print '{1}{0}>{3}{2}'.format (
		random.randrange(1,9),
		chr(ord('a') -1 + random.randrange(1,9)),
		random.randrange(1,9),
		chr(ord('a') -1 + random.randrange(1,9)),
		)

print 'display'
print 'help'
print 'exit'
