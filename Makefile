MODULES = fuzzering
EXTENSION = fuzzering 		# the extersion's name
DATA = fuzzering--0.0.1.sql	# script file to install
REGRESS = fuzzering_test  	# the test script file
 
# for posgres build
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
