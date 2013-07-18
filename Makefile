dirs = exp1 exp2/version2.0 exp3 exp4 exp5
MAKE = make
d
all:
	for i in $(dirs) ; do $(MAKE) -C $$i ; done 

clean:
	-for i in $(dirs) ; do $(MAKE) -C $$i clean; done