
from __future__ import print_function

import os
import sys

# parse command line arguments
output_file = sys.argv[1]
answer_file = sys.argv[2]

keyword_arguments = [xx.split('=') for xx in sys.argv[3:]]
keyword_arguments = dict([(kk.strip('-'), vv) for kk, vv in keyword_arguments])

# read output
assert os.path.isfile(output_file), "Output file not found"
outputs = [line for line in open(output_file) if line.rstrip()]

# read answer
assert os.path.isfile(answer_file), "Answer file not found"
answers = [line for line in open(answer_file) if line.rstrip()]

# check number of test cases are equal
assert len(outputs) == len(answers), "Number of lines in output and answer files don't match: %d vs %d" % (len(outputs), len(answers))

npassed, nfailed = 0, 0
for itest, output, answer in zip(range(1, len(outputs)+1), outputs, answers):
	print('Test case:', itest)

	output = output.strip().split()
	answer = answer.strip().split()

	# print('Output:', output)
	# print('Answer:', answer)

	correct = (len(output) == len(answer)) and (output == answer)
	if correct:
		print('PASSED')
		npassed += 1
	else:
		print('FAILED')
		nfailed += 1

	print('='*100)
print('TOTAL PASSED: %d. TOTAL FAILED: %d.' % (npassed, nfailed))
